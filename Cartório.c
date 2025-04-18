#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar cada usu�rio no sistema
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Armazena a vari�vel CPF "%s se refere a string"

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo "W de escrita"
	fprintf(file,cpf); //Salva o valor da varial	
	fprintf(file,","); //Colocar virgula entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); //Armazena a vari�vel Nome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o nome
	fprintf(file,nome);
	fprintf(file,","); //Colocar virgula entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //Armazena a vari�vel sobrenome
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informa��o
	fprintf(file,sobrenome);
	fprintf(file,",");//Colocar virgula entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //Armazena a vari�vel cargo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informa��o
	fprintf(file,cargo);
	fclose(file); //Fecha o arquivo
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuquese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //Armazena o valor do CPF digitado
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrindo e lendo "r" o arquivo CPF
		
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localiado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fecha o arquivo ap�s a consulta
			
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //Salvando o valor CPF
	
	remove(cpf); //comando para deletar CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrindo e lendo "r" o arquivo
		
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema !. \n");
		system("pause");
	}

}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //Definindo que o programa volte ao inicio ap�s uma escolha
	char senhadigitada[10]="a"; //Criando a vari�vel senha
	int comparacao; 
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada); //Armazenando a senha digitada
	
	comparacao = strcmp(senhadigitada, "admin"); //Comparando a senha digitada com a j� salva no sistema "admin"
	
	if(comparacao == 0) 
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
			system("cls"); //Limpando a tela para aparecer o Menu inicial
		
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:"); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando escolha do usu�rio
	
			system("cls"); //Limpando a tela do menu ap�s selecionar uma op��o
		
		
			switch(opcao) //Come�o da escolha das op��es
			{
				case 1:
				registro(); //Chamada da fun��o registro	
				break;
			
				case 2:
				consulta(); //Chamada da fun��o consulta
				break;
			
				case 3:
				deletar(); //Chamada da fun��o consultar
				break;
			
				case 4:
			
				printf("Obrigado por usar o sistema!\n");
				return 0;
				break;
						
				default:
				printf("Op��o n�o dispon�vel\n");
				system("pause");
				break; //Fim da escolha das op��es
				
			}	
		}
	}
	else
		printf("Senha incorreta!");
}
