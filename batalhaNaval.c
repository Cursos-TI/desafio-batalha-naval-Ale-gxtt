#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main() {
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int navio1_linha = 2;
    int navio1_coluna = 1;
    
    int navio2_linha = 5;
    int navio2_coluna = 7;
    
    int navio[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    printf("--- Batalha Naval - Desafio Novato ---\n\n");

    
    if (navio1_coluna < 0 || navio1_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro de Validação: As coordenadas do Navio 1 (Horizontal) estão fora dos limites do tabuleiro.\n");
        return 1;
    }

    if (navio2_linha < 0 || navio2_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro de Validação: As coordenadas do Navio 2 (Vertical) estão fora dos limites do tabuleiro.\n");
        return 1;
    }

    
    printf("Posicionando Navio 1 (Horizontal) em Linha %d, Coluna %d...\n", navio1_linha, navio1_coluna);
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        
        tabuleiro[navio1_linha][navio1_coluna + i] = navio[i];
    }

    
    printf("Posicionando Navio 2 (Vertical) em Linha %d, Coluna %d...\n\n", navio2_linha, navio2_coluna);
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        
        tabuleiro[navio2_linha + i][navio2_coluna] = navio[i];
    }

    
    exibirTabuleiro(tabuleiro);

    return 0;
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("-------------------------------------------\n");
    printf("           Tabuleiro de Batalha Naval      \n");
    printf("-------------------------------------------\n");
    printf("   | 0 1 2 3 4 5 6 7 8 9 (Coluna)\n");
    printf("---|------------------\n");

    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        
        printf("%d  |", i);

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    printf("(Linha)\n");
    printf("-------------------------------------------\n");
    printf("Legenda: 0 = Água, 3 = Navio\n");
}
