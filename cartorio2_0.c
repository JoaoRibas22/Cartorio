#include <stdio.h> // Biblioteca de comunicação com o usuário 
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings

// Função para registrar um novo usuário
int registro()
{
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Português
    
    char arquivo[40];                                                      
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Abre o arquivo em modo de escrita
    fprintf(file, cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo
    
    file=fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, ", "); // Escreve uma vírgula no arquivo
    fclose(file); // Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:\n");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, nome); // Escreve o nome no arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, " "); // Escreve um espaço no arquivo
    fclose(file); // Fecha o arquivo

    printf("Agora digite o sobrenome:\n");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, ", "); // Escreve uma vírgula no arquivo
    fclose(file); // Fecha o arquivo
    
    printf("Digite o cargo:\n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, cargo); // Escreve o cargo no arquivo
    fclose(file); // Fecha o arquivo
    
    return 0; // Retorna 0 para indicar sucesso
}

// Função para consultar um usuário pelo CPF
int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Português
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:\n");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura
    
    if (file == NULL)
    {
        printf("Nenhum resultado obtido, arquivo não localizado!\n");
        return -1; // Retorna -1 para indicar falha
    }
    
    while (fgets(conteudo, 100, file) !=NULL)
    {
        printf("Essas foram as informações obtidas sobre o usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo
    
}

// Função para deletar um usuário pelo CPF
int deletar()
{
    char cpf[40];
    
    printf("ATENÇÃO\nVocê deseja mesmo continuar?\n");
    system("pause");
    
    printf("Digite o CPF a ser excluído:");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura
    
    if(file == NULL)
    {
        printf("Nenhum dado encontrado!\n");
        
    }
    
    fclose(file); // Fecha o arquivo
    
    remove(cpf); // Remove o arquivo
    printf("\nCPF deletado com sucesso!\n");
    
}

// Função principal
int main()
{        
    int opcao = 0; // Define a variável de opção
    int rep = 1; // Define a variável de repetição
    
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Português
    
    // Loop principal
    for (rep = 1; rep == 1; )
    {
        system("cls"); // Limpa a tela
        
        printf("\tCartório da EBAC\n\n");
        printf("Escolha a opção que você deseja:\n\n");
        printf("\t1- Registro de nomes\n");
        printf("\t2- Consulta de nomes\n");
        printf("\t3- Deletar nomes\n");
        printf("\t4- Sair do sistema\n\n");
        printf("Digite a opção desejada: ");
        
        scanf("%d", &opcao); // Lê a opção do usuário
        
        system("cls"); // Limpa a tela
        
        switch(opcao) // Realiza ações baseadas na opção escolhida
        {
            case 1:
                printf("Você escolheu registro de nomes!\n");
                registro(); // Chama a função de registro
                break;
            case 2:
                printf("Você selecionou a consulta de nomes!\n");
                consulta(); // Chama a função de consulta
                break;
            case 3:
                printf("Você selecionou a opção de deletar nomes!\n");
                deletar(); // Chama a função de deletar
                break;
            case 4:
            	printf("Obrigado por ultilizar o nosso sistema!\n");
            	return 0;
            	break;
            default:
                printf("Essa opção não está disponível!\n");
                break;
        }
        
        
    }

    return 0; // Indica que o programa terminou sem erros
}

