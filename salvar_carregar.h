#ifndef SALVAR_CARREGAR_H
#define SALVAR_CARREGAR_H

#include "cadastrar_usuario.h"
#include "cadastrar_livro.h"
#include "emprestimo.h"

void salvarDados(struct usuarios *usuarios, int num_usuarios, struct livros *livros, int num_livros, struct emprestimo *emprestimos, int num_emprestimos, const char *filename);

void carregarDados(struct usuarios *usuarios, int *num_usuarios, struct livros *livros, int *num_livros, struct emprestimo *emprestimos, int *num_emprestimos, const char *filename);

#endif