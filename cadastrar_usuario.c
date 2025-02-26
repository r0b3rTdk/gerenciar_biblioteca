#include "cadastrar_usuario.h"
#include "utils.h"
#include <ctype.h>
#include <windows.h>
// funcao para validar o CPF
int validarCPF(const char *cpf) {
    int soma = 0, resto;
    int digito1, digito2;

    if (strlen(cpf) != 11) {
        return 0;
    }

    // calculo do primeiro digito verificador
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : 11 - resto;

    // reseta a soma para calcular o segundo digito
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : 11 - resto;

    // verifica se os digitos verificadores estao corretos
    return (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0'));
}
// funcao para validar o endereço
int validarEndereco(const char *endereco) {
    return strlen(endereco) >= 5;
}

void cadastrarUsuario(struct usuarios *usuario) {
    char nome[100];
    char endereco[100];
    char CPF[14]; 
    
    // validacao do nome
    while(1){
        printf("\ndigite o nome do usuario: ");
        fgets(nome, 100, stdin);
        nome[strcspn(nome, "\n")] = '\0'; // remove a quebra de linha
        if(strlen(nome) >= 5){
            usuario->nome = (char *) malloc(strlen(nome) + 1);
            strcpy(usuario->nome, nome);
            break;
        }else{
            printf("\033[1;31mnome invalido. O nome deve ter pelo menos 5 caracteres.\033[0m\n");        }
    }

    // validacao do endereço
    while(1){
        printf("digite o endereco do usuario: ");
        fgets(endereco, 100, stdin);
        endereco[strcspn(endereco, "\n")] = '\0';
        if(validarEndereco(endereco)){
            usuario->endereco = (char *) malloc(strlen(endereco) + 1);
            strcpy(usuario->endereco, endereco);
            break;
        }else{
            printf("\033[1;31mendereco invalido. O endereco deve ter pelo menos 5 caracteres.\033[0m\n");         }
    }

    // validacao do CPF
    while (1) {
        printf("digite o CPF do usuario: ");
        scanf("%s", CPF); // ler o CPF como string
        limparBuffer(); // limpar o buffer de entrada
        // remove espaços e hifens
        char sanitizar_CPF[14]; 
        int j = 0;
        for (int i = 0; CPF[i] != '\0'; i++) {
            if (isdigit(CPF[i]) || (CPF[i] == 'X' && i == 9)) { // verifica se é um dígito ou 'X' na última posição
                sanitizar_CPF[j++] = CPF[i];
            }
        }
        sanitizar_CPF[j] = '\0'; // adiciona o terminador nulo

        if (validarCPF(sanitizar_CPF)) {
            usuario->CPF = atoll(sanitizar_CPF); // converte a string para long long
            break; // ISBN válido, sair do loop
        } else {
            printf("\033[1;31mCPF invalido.\033[0m\n");
        }
    }
    
    printf("\n\033[1;32mUsuario cadastrado com sucesso!\033[0m\n");

    Sleep(1500);
}