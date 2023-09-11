#include <stdio.h>
#include <stdlib.h>
#include  <locale.h>
#include <string.h>

int registro()//função para cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/str
	char arquivo[40];//variaveis
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variaveis/str
	printf("digite seu CPF a ser cadastrado: ");//coletando inf do usario
	scanf("%s", CPF);//salvar em um arquivo
	
	strcpy(arquivo, CPF);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo 
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,CPF);//salva o valor da variavel 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a se cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	char CPF[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consutado: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("CPF nao encontrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informaçoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	char CPF[40];
	
	printf("digite o CPF do usuario a ser deletado: ");
	scanf("%s",CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("o usuario nao se encontra no sistema!. \n");
		
	}
	
	system("pause");
	
}


int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//inicio de menu de opçoes
	
		setlocale(LC_ALL, "portuguese");
		
		printf(" CARTORIO DO JOÃO \n\n");
		printf(" escolha as opçoes do menu:\n");
		printf("\t1- registros de nomes\n");
		printf("\t2- consultar nomes\n");
		printf("\t3- deletar nomes\n");
		printf("\t4- sair do sistema\n\n");
		printf("opção:");//fim do menu
	
		scanf("%d", &opcao);

		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema");
			return 0;
			break;	
			
			default:
				printf("essa opcao não está indisponivel!\n");
			system("pause");
			break;	
		}

//fim da seleção
	}
}




