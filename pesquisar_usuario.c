#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pesquisar_usuario.h"

void pesquisarUsuario(struct usuarios *usuarios, int num_usuarios) {
    char CPFouNome[100];

    printf("digite o CPF ou Nome do usuario: ");
    fgets(CPFouNome, 100, stdin);
    CPFouNome[strcspn(CPFouNome, "\n")] = 0;

    // tenta converter a entrada para long long
    long long cpf_input = strtoll(CPFouNome, NULL, 10);
    int found = 0;

    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].CPF == cpf_input || 
            strcmp(usuarios[i].nome, CPFouNome) == 0) {
            printf("\n\033[1;32mUsuario encontrado:\033[0m\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("CPF: %lld\n", usuarios[i].CPF); 
            printf("Endereco: %s\n", usuarios[i].endereco);
            found = 1; 
            break;
        }
    }

    if (found) {
        printf("\npressione qualquer tecla para continuar...\n");
        getchar(); 
    } else {
        printf("\n\033[1;31mUsuario nao encontrado.\033[0m\n");
        printf("pressione qualquer tecla para continuar...\n");
        getchar();
    }
}