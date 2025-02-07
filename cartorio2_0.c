#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar um novo usuário
int registro() {
    // Define a localidade para Português
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis para armazenar os dados do usuário
    char cpf[40], nome[40], sobrenome[40], cargo[40];
    char arquivo[50];  // Variável que armazenará o nome do arquivo (ex: "CPF.txt")

    // Solicita o CPF e lê o valor (limitado a 39 caracteres para evitar overflow)
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%39s", cpf);

    // Define o nome do arquivo a partir do CPF, adicionando a extensão ".txt"
    sprintf(arquivo, "%s.txt", cpf);

    // Abre o arquivo para escrita e verifica se ele foi aberto corretamente
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita!\n", arquivo);
        return -1;
    }

    // Solicita o nome do usuário, permitindo a entrada de espaços
    printf("Digite o nome a ser cadastrado:\n");
    scanf(" %39[^\n]", nome);  // O espaço antes do formato ignora quebras de linha pendentes

    // Solicita o sobrenome do usuário
    printf("Agora, digite o sobrenome:\n");
    scanf(" %39[^\n]", sobrenome);

    // Solicita o cargo do usuário
    printf("Digite o cargo:\n");
    scanf(" %39[^\n]", cargo);

    // Escreve os dados no arquivo com o formato: CPF, Nome Sobrenome, Cargo
    fprintf(file, "%s, %s %s, %s", cpf, nome, sobrenome, cargo);

    // Fecha o arquivo
    fclose(file);

    printf("\nRegistro concluído com sucesso!\n");
    return 0;
}

// Função para consultar os dados de um usuário pelo CPF
int consulta() {
    // Define a localidade para Português
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char arquivo[50];   // Nome do arquivo a ser lido (ex: "CPF.txt")
    char conteudo[200]; // Buffer para armazenar o conteúdo lido

    // Solicita o CPF a ser consultado
    printf("Digite o CPF a ser consultado:\n");
    scanf("%39s", cpf);

    // Define o nome do arquivo com base no CPF informado
    sprintf(arquivo, "%s.txt", cpf);

    // Abre o arquivo para leitura e verifica se ele existe
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Nenhum resultado obtido, arquivo não localizado!\n");
        return -1;
    }

    // Exibe o cabeçalho da consulta
    printf("\nEssas foram as informações obtidas sobre o usuário:\n");

    // Lê e exibe o conteúdo do arquivo linha a linha
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n");

    // Fecha o arquivo
    fclose(file);

    return 0;
}

// Função para deletar um usuário pelo CPF
int deletar() {
    char cpf[40];
    char arquivo[50];

    // Exibe mensagem de atenção e aguarda confirmação do usuário
    printf("ATENÇÃO\nVocê deseja mesmo continuar?\n");
#ifdef _WIN32
    system("pause");
#else
    printf("Pressione ENTER para continuar...");
    while (getchar() != '\n'); // Limpa o buffer
    getchar();                // Aguarda o usuário pressionar ENTER
#endif

    // Solicita o CPF a ser deletado
    printf("Digite o CPF a ser excluído:\n");
    scanf("%39s", cpf);

    // Define o nome do arquivo com base no CPF informado
    sprintf(arquivo, "%s.txt", cpf);

    // Verifica se o arquivo existe tentando abri-lo para leitura
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Nenhum dado encontrado!\n");
        return -1;
    }
    fclose(file);

    // Tenta remover o arquivo e verifica se a remoção foi bem-sucedida
    if (remove(arquivo) == 0) {
        printf("\nCPF deletado com sucesso!\n");
    } else {
        printf("\nErro ao deletar o CPF!\n");
        return -1;
    }

    return 0;
}

// Função principal
int main() {
    // Define a localidade para Português
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    // Loop principal do programa
    while (1) {
        // Limpa a tela de acordo com o sistema operacional
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // Exibe o menu principal
        printf("\tCartório da EBAC\n\n");
        printf("Escolha a opção que você deseja:\n\n");
        printf("\t1 - Registro de nomes\n");
        printf("\t2 - Consulta de nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Digite a opção desejada: ");

        // Lê a opção do usuário e verifica se a entrada é válida
        if (scanf("%d", &opcao) != 1) {
            // Caso a entrada seja inválida, limpa o buffer e continua o loop
            printf("Entrada inválida!\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        // Processa a opção escolhida utilizando um switch-case
        switch (opcao) {
            case 1:
                printf("\nVocê escolheu registro de nomes!\n");
                registro();
                break;
            case 2:
                printf("\nVocê selecionou a consulta de nomes!\n");
                consulta();
                break;
            case 3:
                printf("\nVocê selecionou a opção de deletar nomes!\n");
                deletar();
                break;
            case 4:
                printf("\nObrigado por utilizar o nosso sistema!\n");
                return 0;
            default:
                printf("\nEssa opção não está disponível!\n");
                break;
        }

        // Pausa para que o usuário possa visualizar o resultado da operação
        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n'); // Limpa o buffer de entrada
        getchar();                // Aguarda o usuário pressionar ENTER
    }

    return 0;
}
