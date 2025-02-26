#include "cadastrar_livro.h"
#include "utils.h"
#include <ctype.h>
#include <windows.h>
//validar ISBN 10
int validar_isbn10(const char *isbn) {
    int total = 0; 
    for (int i = 0; i < 10; i++) {
        if (isbn[i] == 'X' && i == 9) {  // verifica se 'X' está na última posição e se é um dígito
            total += 10; // 'X' vale 10
        } else if (isdigit(isbn[i])) {
            total += (isbn[i] - '0') * (10 - i); // converte o caractere para inteiro
        } else {
            return 0; 
        }
    }
    return total % 11 == 0;
}
// validar ISBN 13
int validar_isbn13(const char *isbn) {
    int total = 0;
    for (int i = 0; i < 13; i++) {
        if (isdigit(isbn[i])) {
            if (i % 2 == 0) {
                total += (isbn[i] - '0'); // converte o caractere para inteiro
            } else {
                total += (isbn[i] - '0') * 3; // converte o caractere para inteiro e multiplica por 3
            }
        } else {
            return 0;  // Retorna 0 se o caractere não for um dígito
        }
    }
    return total % 10 == 0;
}
// verificar o comprimento do ISBN e chamar a funcao de validacao correta
int validar_isbn(const char *isbn) {
    if (strlen(isbn) == 10) {
        return validar_isbn10(isbn);
    } else if (strlen(isbn) == 13) {
        return validar_isbn13(isbn);
    } else {
        return 0; 
    }
}

void cadastrarLivro(struct livros *livro) {
    char titulo[100];
    char autor[100];
    char isbn[14]; 
    
    //validacao do titulo
    while(1){
        printf("\ndigite o titulo do livro: ");
        fgets(titulo, 100, stdin);
        titulo[strcspn(titulo, "\n")] = '\0';
        if(strlen(titulo) >= 5){
            livro->titulo = (char *) malloc(strlen(titulo) + 1);
            strcpy(livro->titulo, titulo);
            break;
        }else{
            printf("\033[1;31mtitulo invalido. O titulo deve ter pelo menos 5 caracteres.\033[0m\n");        }
    }
    
    //validacao do autor
    while(1){
        printf("digite o autor do livro: ");
        fgets(autor, 100, stdin);
        autor[strcspn(autor, "\n")] = '\0';
        if(strlen(autor) >= 5){
            livro->autor = (char *) malloc(strlen(autor) + 1);
            strcpy(livro->autor, autor);
            break;
        }else{
            printf("\033[1;31mautor invalido. O autor deve ter pelo menos 5 caracteres.\033[0m\n");        }
    }

    // Validação do ISBN
    while (1) {
        printf("digite o ISBN do livro (10 ou 13 digitos): ");
        scanf("%s", isbn); // ler o ISBN como string
        limparBuffer(); // limpar o buffer de entrada
        // remove espaços e hifens
        char sanitizar_isbn[14]; 
        int j = 0;
        for (int i = 0; isbn[i] != '\0'; i++) {
            if (isdigit(isbn[i]) || (isbn[i] == 'X' && i == 9)) { // verifica se é um dígito ou 'X' na última posição
                sanitizar_isbn[j++] = isbn[i];
            }
        }
        sanitizar_isbn[j] = '\0'; // adiciona o terminador nulo

        if (validar_isbn(sanitizar_isbn)) {
            livro->ISBN = atoll(sanitizar_isbn); // converte a string para long long
            break; // ISBN válido, sair do loop
        } else {
            printf("\033[1;31mISBN invalido.\033[0m\n");
        }
    }

    //validacao do ano de publicacao
    while(1){
        time_t t = time(NULL); 
        struct tm *tm_info = localtime(&t);
        int anoAtual = tm_info->tm_year + 1900; 
        livro->ano_Publicacao = lerNumero("digite o ano de publicacao do livro: ");
        if (livro->ano_Publicacao > anoAtual){
            printf("\n\033[1;31mano invalido\033[0m");
        }
        else
            break;
    }
    
    //validacao da quantidade
    while (1)
    {
        livro->quantidade = lerNumero("digite a quantidade de livros: ");
        if (livro->quantidade < 0)
        {
            printf("\n\033[1;31mquantidade invalida.\033[0m\n");        
        }
        else
            break;
    }
    
    printf("\n\033[1;32mLivro cadastrado com sucesso!\033[0m\n");

    Sleep(1500);
}
