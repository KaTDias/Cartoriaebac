#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca responsável pela alocação de espaços em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informaçõo do usuário
	scanf("%s", cpf); //%s refere-se a strings // salvar uma string

	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados (computador)
	file = fopen(arquivo, "w"); // cria o arquivo na pasta e o "w" significa escrever
	fprintf(file, cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // a para atualizar a informação
	fprintf(file,","); // salvar a vírgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo na pasta e o "a" significa atualizar a informação
	fprintf(file, nome); // salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // a para atualizar a informação
	fprintf(file,","); // salvar a vírgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo na pasta e "a" atualiza
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // a para atualizar a informação
	fprintf(file,","); // salvar a vírgula para separar
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo na pasta e atualiza
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra  no sistema!.\n");
		system("pause");
		
	}
	
}

int main()
{
  int opcao=0; //Definindo variáveis
  int laco=1;
    
  for(laco=1;laco=1;)	
  {
    system("cls"); //responsável por limpar a tela
   	 		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Início do Menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); //Fim do Menu
	printf("Opção:");
	
	scanf("%d", &opcao); //Armazenando a escolha do usuáro
	
    system("cls");
			
    switch(opcao) // inicio da seleção do menu
  	{
  		case 1:
    	registro();//chamada de funções
		break;
			
		case 2:
		consulta();
		break;
			
		case 3:
		deletar();
		break;
			
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;	
	  } //fim da seleção
  	
   }
  
}
