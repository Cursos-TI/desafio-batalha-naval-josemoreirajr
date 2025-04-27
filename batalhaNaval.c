#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Representação do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todo o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- Posicionamento dos Navios ---

    // Navio Horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 1;
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
    }

    // Navio Vertical
    int linha_vertical = 6;
    int coluna_vertical = 3;
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
    }

    // Navio Diagonal (da esquerda para a direita)
    int linha_diagonal1 = 0;
    int coluna_diagonal1 = 0;
    if (linha_diagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_diagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] == AGUA) {
                tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = NAVIO;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar navio diagonal 1.\n");
                // Desfaz o posicionamento parcial (opcional)
                for (int j = 0; j < i; j++) {
                    tabuleiro[linha_diagonal1 + j][coluna_diagonal1 + j] = AGUA;
                }
                break;
            }
        }
    } else {
        printf("Erro: Navio diagonal 1 fora dos limites.\n");
    }

    // Navio Diagonal (da direita para a esquerda)
    int linha_diagonal2 = 0;
    int coluna_diagonal2 = TAMANHO_TABULEIRO - 1;
    if (linha_diagonal2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_diagonal2 - TAMANHO_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] == AGUA) {
                tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = NAVIO;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar navio diagonal 2.\n");
                // Desfaz o posicionamento parcial (opcional)
                for (int j = 0; j < i; j++) {
                    tabuleiro[linha_diagonal2 + j][coluna_diagonal2 - j] = AGUA;
                }
                break;
            }
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites.\n");
    }

    // --- Exibição do Tabuleiro ---
    printf("\nTabuleiro do Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
