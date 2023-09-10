#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposavél por cuidar das strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado:\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //salva o valor da variável 
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastro:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);

	printf("Agora digite o sobrenome:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
if (file == NULL)
	{
		printf("Nenhum resultado obtido, arquivo não localizado!");
		system("pause");
	}
	
while (fgets(conteudo, 100, file) !=NULL)
	{
	
		printf("Essas foram as informações obtidas sobre o úsuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}


int deletar()
{
	char cpf[40];
	
	printf("  ATENÇÃO\nVocê deseja mesmo continuar?\n");

	system("pause");
	
	printf("Digite o CPF a ser excluído:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Nenhum dado encontrado!\n");
		system("pause");
	}
	
	else
	{
		remove(cpf);
		printf("\nCPF deletado com seucesso!\n");
		system("pause");
	}
}
		
int main()
{		

	int opcao=0;//definindo variáveis
	int rep=1;
	
	for(rep=1;rep=1;)

{
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");//definição de linguagem 
	
	printf("\tCartório da EBAC\n\n");

	printf("Escolha a opção que você deseja:\n\n");//inicio do menu
	printf("\t1- Registro de nomes\n");
	printf("\t2- Cunsulta de nomes\n");
	printf("\t3- Deletar nomes\n\n\n");
	printf("Digite a opção desejada:");//fim do menu
	
	//inicio da lógica
	
	scanf("%d", &opcao);//Armazenando a escolha do usuário
	
	system("cls");
	
	
switch(opcao)
{
	case 1:
		registro();
		break;
					
	case 2:
		consulta();
		break;
		
	case 3:
		deletar();
		break;
		
	default:
		printf("Essa opção não esta disponivel!\n");
		system("pause");
		break;
		

}
}


}
	

