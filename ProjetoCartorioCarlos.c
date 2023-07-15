#include <stdio.h> //Biblioteca de Comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por rgi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registrar() // In�cio do registro de nomes
{   
    //Definindo vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da defini��o de vari�veis
	
	//Menu do registro de nomes
	printf("Registro de nomes:\n");
	printf("\nDigite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copiando os valores das string // Utilizando cpf como identificador
	
	FILE *file; //Criando arquivo
	file = fopen(arquivo, "w"); //Abrindo arquivo
	fprintf(file, cpf); //Salvando valor da vari�vel
	fclose(file); //Fechando arquivo
	
	//Colocando v�rgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//Cadastrando nome
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	//Salvando nome
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file); 
	
    //Colocando v�rgula	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//Cadastrando sobrenome
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	//Salvando sobrenome
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	//Colocando v�rgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	//Cadastrando cargo
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	//Salvando cargo
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n"); //Soltando uma linha
	system("pause"); //Pausando sistema
	
} // Fim do registro de nomes

int consultar() //In�cio da consulta de nomes
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Definindo vari�veis
	char cpf[40];
	char conteudo[200];
	//Fim da defini��o de vari�veis
	
	//Menu da consulta de nomes
	printf("Consulta de nomes:\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //Criando arquivo
	file = fopen(cpf, "r"); //Abrindo e lendo arquivo
	
	//Caso o arquivo n�o seja encontrdo
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!.\n\n"); //Avisando usu�rio
	}
	
	//Caso arquivo seja encontrado
    while(fgets(conteudo, 200, file) != NULL) //Consultando o arquivo
	{
		//Mostrando informa��es ao usu�rio
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //Fechando arquivo
	system("pause"); //Pausando sistema
	
} //Fim da consulta de nomes

int deletar() //In�cio da deleta de nomes
{
	//Definindo vari�vel
	char cpf[50];
	
	//Menu da deleta de usu�rio
	printf("Digite o cpf a ser deletado:\n\n");
	scanf("%s",cpf);
	
	FILE *file; //Abrindo arquivo
	file = fopen(cpf,"r"); //Lendo arquivo

    //Caso o arquivo n�o seja encontrado
    if(file == NULL)
	{
	    printf("\nO usu�rio n�o foi encontrado no sistema!\n\n"); //Mensagem de aviso ao usu�rio
	    system("pause"); //Pausando sistema
    }
    //Caso o arquivo seja encontrado
	else
    {
    	printf("\nO usu�rio foi deletado\n\n"); //Mensagem de aviso ao usu�rio
    	system("pause"); //Pausando sistema
	}    
        fclose(file); //Fechando arquivo
     	remove(cpf); //Deletando arquivo
    
} //Fim da deleta de nomes

int main() //In�cio do programa
{
	//Definindo vari�veis
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	//Fim da defini��o de vari�veis
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	 
	//Menu de Login
	printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de Administrador!\n\n");
    printf("Digite sua Senha: ");
    scanf("%s",senhadigitada); //Salvando senha digitada pelo usu�rio
    
    comparacao = strcmp(senhadigitada, "admin"); //Transformando senha correta em 0
	
	if(comparacao == 0) //Sistema de valida��o de senha
    {
    	for(laco=1;laco=1;) //Sistema de retorno ao menu
    	{
	    	system("cls"); //Limpando a tela

    	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    	
        	//In�cio do menu
	      	printf("### Cart�rio da EBAC ###\n\n");
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
    	    printf("\t3 - Deletar nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Op��o: ");
    	    //Fim do Menu
	
        	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
        	system("cls"); //Limpando a tela
    	
        	switch(opcao) //Definindo o sistema de escolhas do menu
    	    {
    		    case 1:
			    registrar(); //Chamando fun��o
	         	break;
	     	
	        	case 2:
	        	consultar(); //Chamando fun��o
			    break;
			
    			case 3:
	    		deletar(); //Chamando fun��o
		    	break;
			
		    	case 4:
		    	printf("Obrigado por utilizar o sistema!\n\n"); //Mensagem de encerramento
			    return 0;
			    break;
			
			    default:
			    printf("Essa op��o n�o est� disponivel!\n\n"); //Caso o usu�rio insira uma op��o inexistente
    	        system("pause");
    	        break;
             } //Fim do sistema de escolhas do menu
        } //Fim do sistema de retorno ao menu
    } //Fim do sistema de valida��o de senha
    
    else //Caso a senha esteja incorreta
        printf("\nSenha incoreta");
        
} //Fim do programa
