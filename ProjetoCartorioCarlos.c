#include <stdio.h> //Biblioteca de Comunicação com o Usuário
#include <stdlib.h> //Biblioteca de Alocação de Espaços em Memória
#include <locale.h> //Biblioteca de Alocação de Texto por Região
#include <string.h> //Biblioteca responsável por cuidar das string

int registrar() // Início do registro de nomes
{   
    //Definindo variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Menu do registro de nomes
	printf("Registro de nomes:\n");
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copiando os valores das string
	
	FILE *file; //Criando arquivo
	file = fopen(arquivo, "w"); //Abrindo arquivo
	fprintf(file, cpf); //Salvando valor da variável
	fclose(file); //Fechando arquivo
	
	file = fopen(arquivo, "a"); //Colocando vírgula
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado: "); //Cadastrando nome
	scanf("%s", nome); //Salvando resposta do usuário
	
	file = fopen(arquivo, "a"); //Salvando nome
	fprintf(file, nome);
	fclose(file); 
	
	file = fopen(arquivo, "a"); //Colocando vírgula
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado: "); //Cadastrando sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Salvando sobrenome
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //Colocando vírgula
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado: "); //Cadastrando cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Salvando cargo
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n"); //Soltando uma linha
	system("pause"); //Pausando sistema
	
} // Fim do registro de nomes

int consultar() //Início da consulta de nomes
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Definindo variáveis
	char cpf[40];
	char conteudo[200];
	
	//Menu da consulta de nomes
	printf("Consulta de nomes:\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //Criando arquivo
	file = fopen(cpf, "r"); //Abrindo e lendo arquivo
	
	if(file == NULL) //Caso o arquivo não seja encontrdo
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n\n"); //Avisando usuário
	}
	
    while(fgets(conteudo, 200, file) != NULL) //Consultando o arquivo
	{
		//Mostrando informações ao usuário
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fechando arquivo
	system("pause"); //Pausando sistema
	
} //Fim da consulta de nomes

int deletar() //Início da deleta de nomes
{
	//Definindo variável
	char cpf[50];
	
	//Menu da deleta de usuário
	printf("Digite o cpf a ser deletado:\n\n");
	scanf("%s",cpf);
	
	FILE *file; //Abrindo arquivo
	file = fopen(cpf,"r"); //Lendo arquivo

    if(file == NULL) //Caso o arquivo não seja encontrado
	{
	    printf("\nO usuário não foi encontrado no sistema!\n\n"); //Mensagem de aviso ao usuário
	    system("pause"); //Pausando sistema
    }
	else //Caso o arquivo seja encontrado
    {
    	printf("\nO usuário foi deletado\n\n"); //Mensagem de aviso ao usuário
    	system("pause"); //Pausando sistema
	}    
        fclose(file); //Fechando arquivo
     	remove(cpf); //Deletando arquivo
    
} //Fim da deleta de nomes

int main() //Início do programa
{
	//Definindo variáveis
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;) //Sistema de retorno ao menu
	{
		system("cls"); //Limpando a tela

    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    	
    	//Início do menu
	  	printf("### Cartório da EBAC ###\n\n");
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: ");
	    //Fim do Menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); //Limpando a tela
    	
    	switch(opcao) //Definindo o sistema de escolhas do menu
    	{
    		case 1:
			registrar();
	     	break;
	     	
	     	case 2:
	     	consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n\n");
    	    system("pause");
    	    break;
        } //Fim do sistema de escolhas do menu
    	    
	} //Fim do sistema de retorno ao menu
} //Fim do programa
