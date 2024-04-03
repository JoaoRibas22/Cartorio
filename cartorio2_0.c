#include <stdio.h> // Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings

// Fun��o para registrar um novo usu�rio
int registro()
{
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Portugu�s
    
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
    fprintf(file, ", "); // Escreve uma v�rgula no arquivo
    fclose(file); // Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:\n");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, nome); // Escreve o nome no arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, " "); // Escreve um espa�o no arquivo
    fclose(file); // Fecha o arquivo

    printf("Agora digite o sobrenome:\n");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, sobrenome); // Escreve o sobrenome no arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, ", "); // Escreve uma v�rgula no arquivo
    fclose(file); // Fecha o arquivo
    
    printf("Digite o cargo:\n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de escrita (append)
    fprintf(file, cargo); // Escreve o cargo no arquivo
    fclose(file); // Fecha o arquivo
    
    return 0; // Retorna 0 para indicar sucesso
}

// Fun��o para consultar um usu�rio pelo CPF
int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Portugu�s
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:\n");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura
    
    if (file == NULL)
    {
        printf("Nenhum resultado obtido, arquivo n�o localizado!\n");
        return -1; // Retorna -1 para indicar falha
    }
    
    while (fgets(conteudo, 100, file) !=NULL)
    {
        printf("Essas foram as informa��es obtidas sobre o usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo
    
}

// Fun��o para deletar um usu�rio pelo CPF
int deletar()
{
    char cpf[40];
    
    printf("ATEN��O\nVoc� deseja mesmo continuar?\n");
    system("pause");
    
    printf("Digite o CPF a ser exclu�do:");
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

// Fun��o principal
int main()
{        
    int opcao = 0; // Define a vari�vel de op��o
    int rep = 1; // Define a vari�vel de repeti��o
    
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para Portugu�s
    
    // Loop principal
    for (rep = 1; rep == 1; )
    {
        system("cls"); // Limpa a tela
        
        printf("\tCart�rio da EBAC\n\n");
        printf("Escolha a op��o que voc� deseja:\n\n");
        printf("\t1- Registro de nomes\n");
        printf("\t2- Consulta de nomes\n");
        printf("\t3- Deletar nomes\n");
        printf("\t4- Sair do sistema\n\n");
        printf("Digite a op��o desejada: ");
        
        scanf("%d", &opcao); // L� a op��o do usu�rio
        
        system("cls"); // Limpa a tela
        
        switch(opcao) // Realiza a��es baseadas na op��o escolhida
        {
            case 1:
                printf("Voc� escolheu registro de nomes!\n");
                registro(); // Chama a fun��o de registro
                break;
            case 2:
                printf("Voc� selecionou a consulta de nomes!\n");
                consulta(); // Chama a fun��o de consulta
                break;
            case 3:
                printf("Voc� selecionou a op��o de deletar nomes!\n");
                deletar(); // Chama a fun��o de deletar
                break;
            case 4:
            	printf("Obrigado por ultilizar o nosso sistema!\n");
            	return 0;
            	break;
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                break;
        }
        
        
    }

    return 0; // Indica que o programa terminou sem erros
}

