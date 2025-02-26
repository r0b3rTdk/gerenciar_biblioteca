#include "salvar_carregar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvarDados(struct usuarios *usuarios, int num_usuarios, struct livros *livros, int num_livros, struct emprestimo *emprestimos, int num_emprestimos, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("\033[1;31mErro ao abrir o arquivo para salvar.\033[0m\n");
        return;
    }

    // salva o numero de usuarios, livros e emprestimos
    fwrite(&num_usuarios, sizeof(int), 1, file);
    fwrite(&num_livros, sizeof(int), 1, file);
    fwrite(&num_emprestimos, sizeof(int), 1, file);

    // salva os usuarios
    for (int i = 0; i < num_usuarios; i++) {
        int nome_len = strlen(usuarios[i].nome) + 1;
        fwrite(&nome_len, sizeof(int), 1, file);
        fwrite(usuarios[i].nome, sizeof(char), nome_len, file);

        int endereco_len = strlen(usuarios[i].endereco) + 1;
        fwrite(&endereco_len, sizeof(int), 1, file);
        fwrite(usuarios[i].endereco, sizeof(char), endereco_len, file);

        fwrite(&usuarios[i].CPF, sizeof(long long), 1, file);
        fwrite(&usuarios[i].num_emprestimos, sizeof(int), 1, file);
    }

    // salva os livros
    for (int i = 0; i < num_livros; i++) {
        int titulo_len = strlen(livros[i].titulo) + 1;
        fwrite(&titulo_len, sizeof(int), 1, file);
        fwrite(livros[i].titulo, sizeof(char), titulo_len, file);

        int autor_len = strlen(livros[i].autor) + 1;
        fwrite(&autor_len, sizeof(int), 1, file);
        fwrite(livros[i].autor, sizeof(char), autor_len, file);

        fwrite(&livros[i].ISBN, sizeof(long long), 1, file);
        fwrite(&livros[i].ano_Publicacao, sizeof(int), 1, file);
        fwrite(&livros[i].quantidade, sizeof(int), 1, file);
        fwrite(&livros[i].num_emprestimos, sizeof(int), 1, file);
    }

    // salva os emprestimos
    for (int i = 0; i < num_emprestimos; i++) {
        fwrite(&emprestimos[i].CPF_usuario, sizeof(long long), 1, file);
        fwrite(&emprestimos[i].ISBN_livro, sizeof(long long), 1, file);
        fwrite(&emprestimos[i].data_emprestimo, sizeof(time_t), 1, file);
    }

    fclose(file);
    printf("\033[1;32mDados salvos com sucesso!\033[0m\n");
}

void carregarDados(struct usuarios *usuarios, int *num_usuarios, struct livros *livros, int *num_livros, struct emprestimo *emprestimos, int *num_emprestimos, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("\033[1;31mErro ao abrir o arquivo para carregar.\033[0m\n");
        return;
    }

    // carrega o numero de usuarios, livros e emprestimos
    fread(num_usuarios, sizeof(int), 1, file);
    fread(num_livros, sizeof(int), 1, file);
    fread(num_emprestimos, sizeof(int), 1, file);

    // carrega os usuarios
    for (int i = 0; i < *num_usuarios; i++) {
        int nome_len;
        fread(&nome_len, sizeof(int), 1, file);
        usuarios[i].nome = (char *)malloc(nome_len);
        fread(usuarios[i].nome, sizeof(char), nome_len, file);

        int endereco_len;
        fread(&endereco_len, sizeof(int), 1, file);
        usuarios[i].endereco = (char *)malloc(endereco_len);
        fread(usuarios[i].endereco, sizeof(char), endereco_len, file);

        fread(&usuarios[i].CPF, sizeof(long long), 1, file);
        fread(&usuarios[i].num_emprestimos, sizeof(int), 1, file);
    }

    // carrega os livros
    for (int i = 0; i < *num_livros; i++) {
        int titulo_len;
        fread(&titulo_len, sizeof(int), 1, file);
        livros[i].titulo = (char *)malloc(titulo_len);
        fread(livros[i].titulo, sizeof(char), titulo_len, file);

        int autor_len;
        fread(&autor_len, sizeof(int), 1, file);
        livros[i].autor = (char *)malloc(autor_len);
        fread(livros[i].autor, sizeof(char), autor_len, file);

        fread(&livros[i].ISBN, sizeof(long long), 1, file);
        fread(&livros[i].ano_Publicacao, sizeof(int), 1, file);
        fread(&livros[i].quantidade, sizeof(int), 1, file);
        fread(&livros[i].num_emprestimos, sizeof(int), 1, file);
    }

    // carrega os emprestimos
    for (int i = 0; i < *num_emprestimos; i++) {
        fread(&emprestimos[i].CPF_usuario, sizeof(long long), 1, file);
        fread(&emprestimos[i].ISBN_livro, sizeof(long long), 1, file);
        fread(&emprestimos[i].data_emprestimo, sizeof(time_t), 1, file);
    }

    fclose(file);
    printf("\033[1;32mDados carregados com sucesso!\033[0m\n");
}