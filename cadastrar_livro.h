#ifndef CADASTRAR_LIVRO_H
#define CADASTRAR_LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct livros {
    char *titulo;
    char *autor;
    long long ISBN;
    int ano_Publicacao;
    int quantidade;
};

void cadastrarLivro(struct livros *livro);

#endif 