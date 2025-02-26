#include "relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// compara dois livros pelo numero de emprestimos
int compararLivros(const void *a, const void *b) {
    struct livros *livroA = (struct livros *)a;
    struct livros *livroB = (struct livros *)b;
    return livroB->num_emprestimos - livroA->num_emprestimos;
}
// compara dois usuarios pelo numero de emprestimos
int compararUsuarios(const void *a, const void *b) {
    struct usuarios *usuarioA = (struct usuarios *)a;
    struct usuarios *usuarioB = (struct usuarios *)b;
    return usuarioB->num_emprestimos - usuarioA->num_emprestimos;
}

// compara dois autores pelo numero de emprestimos
void gerarRelatorioLivrosMaisEmprestados(struct emprestimo *emprestimos, int num_emprestimos, struct livros *livros, int num_livros) {

    for (int i = 0; i < num_livros; i++) {
        livros[i].num_emprestimos = 0;
    }


    for (int i = 0; i < num_emprestimos; i++) {
        for (int j = 0; j < num_livros; j++) {
            if (emprestimos[i].ISBN_livro == livros[j].ISBN) {
                livros[j].num_emprestimos++;
                break;
            }
        }
    }


    qsort(livros, num_livros, sizeof(struct livros), compararLivros);

    // exibe os livros mais emprestados
    printf("\n\033[1;34mRelatorio de Livros Mais Emprestados:\033[0m\n");
    for (int i = 0; i < num_livros && i < 10; i++) { // Exibe os top 10
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("ISBN: %lld\n", livros[i].ISBN);
        printf("Numero de emprestimos: %d\n", livros[i].num_emprestimos);
        printf("--------------------\n");
    }
}

// compara dois usuarios pelo numero de emprestimos
void gerarRelatorioUsuariosComMaisEmprestimos(struct emprestimo *emprestimos, int num_emprestimos, struct usuarios *usuarios, int num_usuarios) {

    for (int i = 0; i < num_usuarios; i++) {
        usuarios[i].num_emprestimos = 0;
    }


    for (int i = 0; i < num_emprestimos; i++) {
        for (int j = 0; j < num_usuarios; j++) {
            if (emprestimos[i].CPF_usuario == usuarios[j].CPF) {
                usuarios[j].num_emprestimos++;
                break;
            }
        }
    }


    qsort(usuarios, num_usuarios, sizeof(struct usuarios), compararUsuarios);

    // exibe os usuarios com mais emprestimos
    printf("\n\033[1;34mRelatorio de Usuarios com Mais Emprestimos:\033[0m\n");
    for (int i = 0; i < num_usuarios && i < 10; i++) { // Exibe os top 10
        printf("Nome: %s\n", usuarios[i].nome);
        printf("CPF: %lld\n", usuarios[i].CPF);
        printf("Numero de emprestimos: %d\n", usuarios[i].num_emprestimos);
        printf("--------------------\n");
    }
}