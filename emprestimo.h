#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "cadastrar_livro.h"
#include "cadastrar_usuario.h"
#include <time.h>

struct emprestimo {
    long long CPF_usuario; 
    long long ISBN_livro;  
    time_t data_emprestimo; 
};

void realizarEmprestimo(struct usuarios *usuarios, int num_usuarios, struct livros *livros, int num_livros, struct emprestimo *emprestimos, int *num_emprestimos);
void devolverLivro(struct emprestimo *emprestimos, int *num_emprestimos);

#endif