#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar cada usuário no sistema
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Armazena a variável CPF "%s se refere a string"

	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo "W de escrita"
	fprintf(file,cpf); //Salva o valor da varial
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informação
	fprintf(file,","); //Colocar virgula entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); //Armazena a variável Nome
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para "a" atualizar informação
	fprintf(file,","); //Colocar virgula entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //Armazena a variável sobrenome
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informação
	fprintf(file,sobrenome);
	fclose(file); //Fecha o arquivo 
	
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informação
	fprintf(file,",");//Colocar virgula entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //Armazena a variável cargo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo para atualizar informação
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
		printf("Não foi possivel abrir o arquivo, não localiado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fecha o arquivo após a consulta
			
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //Salvando o valor CPF
	
	remove(cpf); //comando para deletar CPF
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrindo e lendo "r" o arquivo
		
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema !. \n");
		system("pause");
	}

}

int main()
	{
	int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo que o programa volte ao inicio após uma escolha
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpando a tela para aparecer o Menu inicial
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usuário
	
		system("cls"); //Limpando a tela do menu após selecionar uma opção
		
		
		switch(opcao) //Começo da escolha das opções
		{
			case 1:
			registro(); //Chamada da função registro	
			break;
			
			case 2:
			consulta(); //Chamada da função consulta
			break;
			
			case 3:
			deletar(); //Chamada da função consultar
			break;
						
			default:
			printf("Opção não disponível\n");
			system("pause");
			break; //Fim da escolha das opções
				
		}	
	}
}
