#include "utils.h"

int lerNumero(const char *mensagem) {
    int num;
    while (1) { 
        printf("%s", mensagem);
        if (scanf("%d", &num) == 1) { 
            limparBuffer(); // limpar o buffer de entrada
            return num;
        } else {
            printf("\033[1;31mErro: Entrada invalida. Digite um numero inteiro.\033[0m\n");
            limparBuffer(); // limpar o buffer de entrada
        }
    }
}


void limparBuffer() {
    while (getchar() != '\n'); 
}