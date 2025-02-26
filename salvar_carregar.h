#ifndef SALVAR_CARREGAR_H
#define SALVAR_CARREGAR_H

#include "cadastrar_usuario.h"
#include "cadastrar_livro.h"

// Função para salvar usuários e livros em um arquivo
void salvarDados(struct usuarios *usuarios, int num_usuarios, struct livros *livros, int num_livros, const char *filename);

// Função para carregar usuários e livros de um arquivo
void carregarDados(struct usuarios *usuarios, int *num_usuarios, struct livros *livros, int *num_livros, const char *filename);

#endif