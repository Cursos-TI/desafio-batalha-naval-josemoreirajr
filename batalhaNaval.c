#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio (horizontal ou vertical)
void posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal) {
        if (coluna + tamanho <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
        } else {
            printf("Erro: Navio horizontal fora dos limites.\n");
        }
    } else {
        if (linha + tamanho <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        } else {
            printf("Erro: Navio vertical fora dos limites.\n");
        }
    }
}

// Função para criar a matriz de habilidade em Cone
void criarHabilidadeCone(int habilidade[][7], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i >= centro && j >= centro - i + centro && j <= centro + i - centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em Cruz
void criarHabilidadeCruz(int habilidade[][7], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em Octaedro (Losango)
void criarHabilidadeOctaedro(int habilidade[][7], int tamanho) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[][TAMANHO_TABULEIRO], int habilidade[][7], int origemLinha, int origemColuna, int tamanhoHabilidade) {
    int offset = tamanhoHabilidade / 2;
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = origemLinha - offset + i;
                int colunaTabuleiro = origemColuna - offset + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                    }
                    // Se houver um navio, podemos marcá-lo de forma diferente se quisermos
                    // else if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == NAVIO) {
                    //     tabuleiro[linhaTabuleiro][colunaTabuleiro] = ALGUM_OUTRO_VALOR;
                    // }
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro do Batalha Naval com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos navios
    posicionarNavio(tabuleiro, 2, 1, TAMANHO_NAVIO, 1); // Horizontal
    posicionarNavio(tabuleiro, 6, 3, TAMANHO_NAVIO, 0); // Vertical
    // (Opcional: Posicionar navios diagonais aqui, se desejar)

    // --- Criação e Aplicação das Habilidades ---
    int tamanhoHabilidade = 7;
    int habilidadeCone[tamanhoHabilidade][tamanhoHabilidade];
    int habilidadeCruz[tamanhoHabilidade][tamanhoHabilidade];
    int habilidadeOctaedro[tamanhoHabilidade][tamanhoHabilidade];

    criarHabilidadeCone(habilidadeCone, tamanhoHabilidade);
    criarHabilidadeCruz(habilidadeCruz, tamanhoHabilidade);
    criarHabilidadeOctaedro(habilidadeOctaedro, tamanhoHabilidade);

    // Pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1;
    int origemConeColuna = 1;
    int origemCruzLinha = 5;
    int origemCruzColuna = 5;
    int origemOctaedroLinha = 8;
    int origemOctaedroColuna = 8;

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna, tamanhoHabilidade);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna, tamanhoHabilidade);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctaedroLinha, origemOctaedroColuna, tamanhoHabilidade);

    // Exibe o tabuleiro com as habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
