#include "utils.h"

// Função para ler um número inteiro
int lerNumero(const char *mensagem) {
    int num;
    while (1) { 
        printf("%s", mensagem);
        if (scanf("%d", &num) == 1) { 
            limparBuffer(); // Limpa o buffer de entrada
            return num;
        } else {
            printf("\033[1;31mErro: Entrada invalida. Digite um numero inteiro.\033[0m\n");
            limparBuffer(); // Limpa o buffer de entrada
        }
    }
}


// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n'); 
}