#include "cadastrar_livro.h"
#include "cadastrar_usuario.h"
#include "pesquisar_usuario.h"
#include "pesquisar_livro.h"
#include "salvar_carregar.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    struct livros livro[100];
    int num_livros = 0;
    struct usuarios usuario[100];
    int num_usuarios = 0;
    const char *filename = "dados.bin";

    while (1) {
        system("cls");
        char menu[10][50] = {
            "1. Cadastrar livro",
            "2. Cadastrar usuario",
            "3. Realizar emprestimo",
            "4. Realizar devolucao",
            "5. Pesquisar livro",
            "6. Pesquisar usuario",
            "7. Gerar relatorios",
            "8. Salvar dados",
            "9. Carregar dados",
            "0. Sair"
        };
        printf("\n\033[1;34m--- BIBLIOTECA ---\033[0m\n\n");

        for (int i = 0; i < 10; i++) {
            if (i == 9) {
                printf("\033[1;31m%s\033[0m\n", menu[i]);
            } else {
                printf("\033[1;32m%s\033[0m\n", menu[i]);
            }
        }

        int op = lerNumero("\nDigite sua opcao: ");
        switch (op) {
            case 1:
                system("cls");
                printf("\n\033[1;34mDigite os dados do livro\033[0m\n");
                cadastrarLivro(&livro[num_livros]);
                num_livros++;
                break;
            case 2:
                system("cls");
                printf("\n\033[1;34mDigite os dados do usuario\033[0m\n");
                cadastrarUsuario(&usuario[num_usuarios]);
                num_usuarios++;
                break;
            case 5:
                system("cls");
                printf("\n\033[1;34mPesquisa dos dados do livro\033[0m\n");
                pesquisarLivro(livro, num_livros);
                break;
            case 6:
                system("cls");
                printf("\n\033[1;34mPesquisa dos dados do usuario\033[0m\n");
                pesquisarUsuario(usuario, num_usuarios);
                break;
            case 8: // Salvar dados
                salvarDados(usuario, num_usuarios, livro, num_livros, filename);
                Sleep(1500);
                break;
            case 9: // Carregar dados
                carregarDados(usuario, &num_usuarios, livro, &num_livros, filename);
                Sleep(1500);
                break;
            case 0:
                printf("\n\033[1;31mENCERRANDO BIBLIOTECA\033[0m\n");
                return 0;
            default:
                printf("\033[1;31mopcao invalida! tente novamente.\033[0m\n");
                Sleep(1000);
                break;
        }
    }
}