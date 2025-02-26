#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pesquisar_livro.h"

void pesquisarLivro(struct livros *livro, int num_livros) {
    char pesquisa[100];

    printf("\ndigite o titulo, autor ou ISBN do livro: ");
    fgets(pesquisa, 100, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = 0; 

    // Tente converter a entrada para long long
    long long ISBN_input = strtoll(pesquisa, NULL, 10);
    int found = 0;

    for (int i = 0; i < num_livros; i++) {
        if (strcmp(livro[i].titulo, pesquisa) == 0 || 
            strcmp(livro[i].autor, pesquisa) == 0 || 
            livro[i].ISBN == ISBN_input) { 
            printf("\n\033[1;32mLivro encontrado:\033[0m\n");
            printf("Titulo: %s\n", livro[i].titulo);
            printf("Autor: %s\n", livro[i].autor);
            printf("ISBN: %lld\n", livro[i].ISBN); 
            printf("Ano de publicacao: %d\n", livro[i].ano_Publicacao);
            printf("Quantidade: %d\n", livro[i].quantidade);
            found = 1; 
            break; 
        }
    }

    
    if (found) {
        printf("\npressione qualquer tecla para continuar...\n");
        getchar(); 
    } else {
        printf("\n\033[1;31mLivro nao encontrado.\033[0m\n");
        printf("pressione qualquer tecla para continuar...\n");
        getchar();
    }
}
