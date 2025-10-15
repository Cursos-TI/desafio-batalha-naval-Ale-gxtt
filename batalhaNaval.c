#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define ERRO 1

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha_inicial, 
                    int coluna_inicial, 
                    int orientacao) {

    if (linha_inicial < 0 || linha_inicial >= TAMANHO_TABULEIRO || 
        coluna_inicial < 0 || coluna_inicial >= TAMANHO_TABULEIRO) {
        printf("Erro de Validação: A coordenada inicial (%d, %d) está fora dos limites do tabuleiro.\n", linha_inicial, coluna_inicial);
        return ERRO;
    }

    switch (orientacao) {
        case 0:
            if (coluna_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
                printf("Erro de Validação: Navio Horizontal de L%d, C%d excede o limite (Tamanho %d).\n", linha_inicial, coluna_inicial, TAMANHO_NAVIO);
                return ERRO;
            }
            break;
        case 1:
            if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
                printf("Erro de Validação: Navio Vertical de L%d, C%d excede o limite (Tamanho %d).\n", linha_inicial, coluna_inicial, TAMANHO_NAVIO);
                return ERRO;
            }
            break;
        case 2:
            if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
                printf("Erro de Validação: Navio Diagonal (L+, C+) de L%d, C%d excede o limite (Tamanho %d).\n", linha_inicial, coluna_inicial, TAMANHO_NAVIO);
                return ERRO;
            }
            break;
        case 3:
            if (linha_inicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_inicial - TAMANHO_NAVIO < -1) {
                printf("Erro de Validação: Navio Diagonal (L+, C-) de L%d, C%d excede o limite (Tamanho %d).\n", linha_inicial, coluna_inicial, TAMANHO_NAVIO);
                return ERRO;
            }
            break;
        default:
            printf("Erro: Orientação de navio inválida.\n");
            return ERRO;
    }
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;

        switch (orientacao) {
            case 0:
                c += i;
                break;
            case 1:
                l += i;
                break;
            case 2:
                l += i;
                c += i;
                break;
            case 3:
                l += i;
                c -= i;
                break;
        }

        if (tabuleiro[l][c] == NAVIO) {
            printf("Erro de Sobreposição: Célula (%d, %d) já está ocupada por outro navio.\n", l, c);
            return ERRO;
        }
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;

        switch (orientacao) {
            case 0:
                c += i;
                break;
            case 1:
                l += i;
                break;
            case 2:
                l += i;
                c += i;
                break;
            case 3:
                l += i;
                c -= i;
                break;
        }
        tabuleiro[l][c] = NAVIO;
    }
    
    return 0;
}


int main() {
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int n1_l = 2;
    int n1_c = 1;
    int n1_o = 0;

    int n2_l = 5;
    int n2_c = 7;
    int n2_o = 1;
    
    int n3_l = 0;
    int n3_c = 6;
    int n3_o = 2;
    
    int n4_l = 4;
    int n4_c = 5;
    int n4_o = 3;

    printf("--- Batalha Naval - Desafio Aventureiro ---\n\n");
    
    int erro = 0;

    printf("Posicionando Navio 1 (Horizontal) em L%d, C%d...\n", n1_l, n1_c);
    if (posicionarNavio(tabuleiro, n1_l, n1_c, n1_o) == ERRO) {
        erro = 1;
    }
    
    printf("Posicionando Navio 2 (Vertical) em L%d, C%d...\n", n2_l, n2_c);
    if (posicionarNavio(tabuleiro, n2_l, n2_c, n2_o) == ERRO) {
        erro = 1;
    }
    
    printf("Posicionando Navio 3 (Diagonal Principal) em L%d, C%d...\n", n3_l, n3_c);
    if (posicionarNavio(tabuleiro, n3_l, n3_c, n3_o) == ERRO) {
        erro = 1;
    }
    
    printf("Posicionando Navio 4 (Diagonal Secundária) em L%d, C%d...\n\n", n4_l, n4_c);
    if (posicionarNavio(tabuleiro, n4_l, n4_c, n4_o) == ERRO) {
        erro = 1;
    }

    if (erro) {
        printf("\nO programa encontrou um ou mais erros de validação e não pode exibir o tabuleiro final corretamente.\n");
        return ERRO;
    }
    
    exibirTabuleiro(tabuleiro);

    return 0;
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("-------------------------------------------\n");
    printf("         Tabuleiro de Batalha Naval        \n");
    printf("-------------------------------------------\n");
    printf("    | 0 1 2 3 4 5 6 7 8 9 (Coluna)\n");
    printf("----|------------------------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        
        printf("%d   |", i);

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("(Linha)\n");
    printf("-------------------------------------------\n");
    printf("Legenda: 0 = Água, 3 = Navio\n");
}
