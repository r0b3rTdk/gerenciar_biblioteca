#include "emprestimo.h"
#include "pesquisar_livro.h"
#include "pesquisar_usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void realizarEmprestimo(struct usuarios *usuarios, int num_usuarios, struct livros *livros, int num_livros, struct emprestimo *emprestimos, int *num_emprestimos) {
    char pesquisa[100];
    int usuario_index = -1, livro_index = -1;

    // pesquisar usuario por CPF ou nome
    printf("\ndigite o CPF ou nome do usuario: ");
    fgets(pesquisa, 100, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = '\0';

    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].CPF == atoll(pesquisa) || strcmp(usuarios[i].nome, pesquisa) == 0) {
            usuario_index = i;
            break;
        }
    }

    if (usuario_index == -1) {
        printf("\033[1;31musuario nao encontrado.\033[0m\n");
        return;
    }

    // pesquisar livro por titulo ou ISBN
    printf("digite o titulo ou ISBN do livro: ");
    fgets(pesquisa, 100, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = '\0';

    for (int i = 0; i < num_livros; i++) {
        if (livros[i].ISBN == atoll(pesquisa) || strcmp(livros[i].titulo, pesquisa) == 0) {
            livro_index = i;
            break;
        }
    }

    if (livro_index == -1) {
        printf("\033[1;31mlivro nao encontrado.\033[0m\n");
        return;
    }

    // verificar disponibilidade do livro
    if (livros[livro_index].quantidade <= 0) {
        printf("\033[1;31mlivro nao disponivel para emprestimo.\033[0m\n");
        return;
    }

    // registro do emprestimo
    emprestimos[*num_emprestimos].CPF_usuario = usuarios[usuario_index].CPF;
    emprestimos[*num_emprestimos].ISBN_livro = livros[livro_index].ISBN;
    emprestimos[*num_emprestimos].data_emprestimo = time(NULL); 

    livros[livro_index].quantidade--;

        // Incrementa o número de empréstimos do livro
    livros[livro_index].num_emprestimos++;

    // Incrementa o número de empréstimos do usuário
    usuarios[usuario_index].num_emprestimos++;

    (*num_emprestimos)++;
    printf("\033[1;32memprestimo realizado com sucesso!\033[0m\n");
    Sleep(1500);
}

void devolverLivro(struct emprestimo *emprestimos, int *num_emprestimos) {
    long long CPF, ISBN;
    printf("\ndigite o CPF do usuario: ");
    scanf("%lld", &CPF);
    printf("digite o ISBN do livro: ");
    scanf("%lld", &ISBN);

    for (int i = 0; i < *num_emprestimos; i++) {
        if (emprestimos[i].CPF_usuario == CPF && emprestimos[i].ISBN_livro == ISBN) {
            // Remove o empréstimo
            for (int j = i; j < *num_emprestimos - 1; j++) {
                emprestimos[j] = emprestimos[j + 1];
            }
            (*num_emprestimos)--;
            printf("\033[1;32mlivro devolvido com sucesso!\033[0m\n");
            return;
        }
    }

    printf("\033[1;31memprestimo nao encontrado.\033[0m\n");
    Sleep(1500);
}