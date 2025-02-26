# Sistema de Gerenciamento de Biblioteca em C

Este é um projeto de sistema de gerenciamento de biblioteca desenvolvido em linguagem C por **Robert Emanuel**. O objetivo é consolidar conhecimentos em programação C, abordando conceitos como estruturas (`structs`), alocação dinâmica de memória, manipulação de arquivos, funções, ponteiros e organização modular de código.

## Funcionalidades

O sistema oferece as seguintes funcionalidades:

1. **Cadastro de Livros**:
   - Cadastro de livros com informações como título, autor, ISBN, ano de publicação e quantidade disponível.
   - Validação de ISBN e ano de publicação.

2. **Cadastro de Usuários**:
   - Cadastro de usuários com informações como nome, CPF e endereço.
   - Validação de CPF.

3. **Empréstimos**:
   - Realização de empréstimos, associando um livro a um usuário e registrando a data de empréstimo.
   - Verificação da disponibilidade do livro.

4. **Devoluções**:
   - Registro de devoluções, atualizando a disponibilidade do livro.

5. **Pesquisas**:
   - Pesquisa de livros por título, autor ou ISBN.
   - Pesquisa de usuários por nome ou CPF.

6. **Relatórios**:
   - Geração de relatórios de livros mais emprestados.
   - Geração de relatórios de usuários com mais empréstimos.

7. **Persistência de Dados**:
   - Salvar e carregar dados de livros, usuários e empréstimos em arquivos binários.

## Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

- **`main.c`**: Contém o menu principal e a lógica de controle do sistema.
- **`cadastrar_livro.c`**: Implementa as funções para cadastrar e validar livros.
- **`cadastrar_usuario.c`**: Implementa as funções para cadastrar e validar usuários.
- **`emprestimo.c`**: Implementa as funções para realizar empréstimos e devoluções.
- **`pesquisar_livro.c`**: Implementa as funções para pesquisar livros.
- **`pesquisar_usuario.c`**: Implementa as funções para pesquisar usuários.
- **`relatorios.c`**: Implementa as funções para gerar relatórios.
- **`salvar_carregar.c`**: Implementa as funções para salvar e carregar dados em arquivos.
- **`utils.c`**: Contém funções utilitárias, como limpeza de buffer e leitura de números.
- **`cadastrar_livro.h`**, **`cadastrar_usuario.h`**, **`emprestimo.h`**, **`pesquisar_livro.h`**, **`pesquisar_usuario.h`**, **`relatorios.h`**, **`salvar_carregar.h`**, **`utils.h`**: Arquivos de cabeçalho com as declarações das funções e estruturas.

## Como Executar o Projeto

### Pré-requisitos

- Compilador C (como GCC).
- Sistema operacional compatível (Windows, Linux ou macOS).

### Passos para Compilar e Executar

1. Clone o repositório ou baixe os arquivos do projeto.
2. Abra o terminal na pasta do projeto.
3. Compile o projeto usando o seguinte comando:

   ```bash
   gcc main.c cadastrar_livro.c cadastrar_usuario.c emprestimo.c pesquisar_livro.c pesquisar_usuario.c relatorios.c salvar_carregar.c utils.c -o biblioteca
   ```

4. Execute o programa gerado:

   - No Linux/macOS:
     ```bash
     ./biblioteca
     ```
   - No Windows:
     ```bash
     biblioteca.exe
     ```

5. Siga as instruções do menu para interagir com o sistema.

## Exemplo de Uso

1. **Cadastrar Livro**:
   - No menu principal, selecione a opção "Cadastrar livro".
   - Insira os dados do livro (título, autor, ISBN, ano de publicação, quantidade).

2. **Cadastrar Usuário**:
   - No menu principal, selecione a opção "Cadastrar usuário".
   - Insira os dados do usuário (nome, CPF, endereço).

3. **Realizar Empréstimo**:
   - No menu principal, selecione a opção "Realizar empréstimo".
   - Pesquise o livro e o usuário, e registre o empréstimo.

4. **Gerar Relatórios**:
   - No menu principal, selecione a opção "Gerar relatórios".
   - Escolha entre relatórios de livros mais emprestados ou usuários com mais empréstimos.

## Dados Salvos

Os dados são salvos em um arquivo binário chamado `dados.bin`. Esse arquivo armazena informações sobre livros, usuários e empréstimos, permitindo que os dados persistam entre execuções do programa.

## Autor

- **Robert Emanuel**: Desenvolvedor do projeto.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests com melhorias, correções de bugs ou novas funcionalidades.
