#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR_USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Estrutura para representar um livro
struct usuarios {
    char *nome;
    long long CPF;
    char *endereco;
};

// Protótipos das funções
void cadastrarUsuario(struct usuarios *usuario);

#endif // CADASTRAR_LIVRO_H