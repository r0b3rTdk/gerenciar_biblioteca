#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "cadastrar_livro.h"
#include "cadastrar_usuario.h"
#include "emprestimo.h"

void gerarRelatorioLivrosMaisEmprestados(struct emprestimo *emprestimos, int num_emprestimos, struct livros *livros, int num_livros);

void gerarRelatorioUsuariosComMaisEmprestimos(struct emprestimo *emprestimos, int num_emprestimos, struct usuarios *usuarios, int num_usuarios);

#endif