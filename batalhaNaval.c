#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar o navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }

    // Verifica se o navio se sobrepõe a outra posição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0;
        }
    }

    // Posiciona o navio horizontalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    
    return 1;
}

// Função para posicionar o navio vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }

    // Verifica se o navio se sobrepõe a outra posição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0;
        }
    }

    // Posiciona o navio verticalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1; // Navio posicionado com sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas para posicionamento dos navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 7;

    // Posiciona o navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Posiciona o navio vertical
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro do Jogo de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
