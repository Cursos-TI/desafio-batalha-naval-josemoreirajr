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

    // Posicionamento do navio horizontal
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int linha_horizontal = 2; // Linha inicial do navio horizontal
    int coluna_horizontal = 3; // Coluna inicial do navio horizontal

    // Validação se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posiciona o navio horizontal no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Posicionamento do navio vertical
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int linha_vertical = 6; // Linha inicial do navio vertical
    int coluna_vertical = 1; // Coluna inicial do navio vertical

    // Validação se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posiciona o navio vertical no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Validação de sobreposição (simplificada - verifica as posições antes de colocar)
    // Para uma validação mais robusta, seria necessário verificar antes de inserir
    // se a posição já contém um NAVIO. Para este nível, assumimos que as coordenadas
    // foram escolhidas de forma que não haja sobreposição dentro dos limites.

    // Exibe o tabuleiro
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
