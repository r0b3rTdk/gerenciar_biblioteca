#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR_USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
struct emprestimo {
    long long ISBN_livro; // ISBN do livro emprestado
    char data_emprestimo[11]; // Data no formato "dd/mm/aaaa"
};
// Estrutura para representar um livro
struct usuarios {
    char *nome;
    long long CPF;
    char *endereco;
    struct emprestimo emprestimos[10]; // Lista de empréstimos
    int num_emprestimos;
};

// Protótipos das funções
void cadastrarUsuario(struct usuarios *usuario);

#endif // CADASTRAR_LIVRO_H