#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contMercadorias = 0, contOperadores = 0, contSetores = 0;

struct mercadoria {
		int codigo, setor;
		char descricao[50];
		float precoCusto, precoVenda, porcLucro;
	} mercadoria[100];
	
struct operador {
	int codigo, senha;
	bool permissaoMercadoria, permissaoOperador;
	char nome[50];
} operador[100];

void menuMercadorias(){
	
	int opcao;
	
	do{
		system("CLS");
		printf("------MENU MERCADORIAS------\n");
		printf("|1 - Cadastrar mercadoria  |\n");
		printf("|2 - Listar mercadorias    |\n");
		printf("|3 - Alterar mercadoria    |\n");
		printf("|4 - Excluir mercadoria    |\n");
		printf("|0 - Voltar                |\n");
		printf("----------------------------\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				
				break;
			
			case 2:
				
				break;
			
			case 3:
				
				break;
			
			case 4:
				
				break;
			
			case 0:
				printf("Voce sera redirecionado ao menu principal!\n");
				system("PAUSE");
				break;
			
			default:
				printf("Opcao invalida!\n");
				system("PAUSE");
		}
	}while(opcao != 0);
}

void cadastrarOperadorMestre(){
	int senha;
	
	do{
		system("CLS");
		printf("-----CADASTRO DE OPERADOR MESTRE-----\n");
		printf("Codigo: 1\n");
		printf("Insira a senha: ");
		scanf("%d", &senha);
		
		if(!senha){
			printf("Insira uma senha valida!\n");
			system("PAUSE");
		}else{
			printf("Insira o nome: ");
			scanf("%s", &operador[contOperadores].nome);
			operador[contOperadores].codigo = 1;
			operador[contOperadores].senha = senha;
			operador[contOperadores].permissaoMercadoria = true;
			operador[contOperadores].permissaoOperador = true;
			contOperadores++;
			printf("\nOperador mestre cadastrado com sucesso!\n");
			system("PAUSE");
		}
	}while(!senha);
}

void cadastrarOperador(){
	
	int codigoOperador = contOperadores + 1;
	int senhaOperador;
	char nomeOperador[50], permissaoMercadoriaOperador[1], permissaoOperadoresOperador[1];
	
	system("CLS");
	printf("-----CADASTRO DE OPERADOR-----\n");
	printf("Codigo: %d\n", codigoOperador);
	printf("Insira o nome do operador: ");
	scanf("%s", &nomeOperador);
	
	do{
		system("CLS");
		printf("-----CADASTRO DE OPERADOR-----\n");
		printf("Codigo: %d\n", codigoOperador);
		printf("Insira a senha: ");
		scanf("%d", &senhaOperador);
		if(!senhaOperador){
			printf("Insira uma senha valida!\n");
			system("PAUSE");
		}
	}while(!senhaOperador);
	
	do{
		system("CLS");
		printf("-----CADASTRO DE OPERADOR-----\n");
		printf("Codigo: %d\n", codigoOperador);
		printf("Insira a senha: %d\n", senhaOperador);
		printf("Permitir cadastrar mercadoria? (S ou N): ");
		scanf("%s", &permissaoMercadoriaOperador);
		
		if(strcmp(permissaoMercadoriaOperador, "S") != 0 && strcmp(permissaoMercadoriaOperador, "s") != 0 && strcmp(permissaoMercadoriaOperador, "N") != 0 && strcmp(permissaoMercadoriaOperador, "n") != 0){
			printf("Insira uma opcao valida!\n");
			system("PAUSE");
		}
		
	}while(strcmp(permissaoMercadoriaOperador, "S") != 0 && strcmp(permissaoMercadoriaOperador, "s") != 0 && strcmp(permissaoMercadoriaOperador, "N") != 0 && strcmp(permissaoMercadoriaOperador, "n") != 0);
	
	do{
		system("CLS");
		printf("-----CADASTRO DE OPERADOR-----\n");
		printf("Codigo: %d\n", codigoOperador);
		printf("Insira a senha: %d\n", senhaOperador);
		printf("Permitir cadastrar mercadoria? (S ou N): %s\n", permissaoMercadoriaOperador);
		printf("Permitir cadastrar operadores? (S ou N): ");
		scanf("%s", &permissaoOperadoresOperador);
		
		if(strcmp(permissaoOperadoresOperador, "S") != 0 && strcmp(permissaoOperadoresOperador, "s") != 0 && strcmp(permissaoOperadoresOperador, "N") != 0 && strcmp(permissaoOperadoresOperador, "n") != 0){
			printf("Insira uma opcao valida!\n");
			system("PAUSE");
		}
		
	}while(strcmp(permissaoOperadoresOperador, "S") != 0 && strcmp(permissaoOperadoresOperador, "s") != 0 && strcmp(permissaoOperadoresOperador, "N") != 0 && strcmp(permissaoOperadoresOperador, "n") != 0);
	
	operador[contOperadores].codigo = codigoOperador;
	strcpy(operador[contOperadores].nome, nomeOperador);
	operador[contOperadores].senha = senhaOperador;
	operador[contOperadores].permissaoMercadoria = (strcmp(permissaoMercadoriaOperador,"S") == 0 || strcmp(permissaoMercadoriaOperador, "s") == 0);
	operador[contOperadores].permissaoOperador = (strcmp(permissaoOperadoresOperador, "S") == 0 || strcmp(permissaoOperadoresOperador, "s") == 0);
	contOperadores++;
	printf("Operador cadastrado com sucesso!\n");
	system("PAUSE");
}

void listarOperadores(){
	
	system("CLS");
	
	for(int i = 0; i<contOperadores; i++){
		printf("--------------------------------------\n");
		printf("Codigo: %d\n", operador[i].codigo);
		printf("Nome: %s\n", operador[i].nome);
		printf("Permissao cadastrar mercadoria: %s\n", (operador[i].permissaoMercadoria) ? "Sim" : "Nao");
		printf("Permissao cadastrar operador: %s\n", (operador[i].permissaoOperador) ? "Sim" : "Nao");
		printf("--------------------------------------\n");
	}
	
	system("PAUSE");
	
}

void menuCadastroDeOperador(){
	
	int opcao;
	
	do{
		system("CLS");
		printf("-----MENU CADASTRO DE OPERADORES-----\n");
		printf("|1 - Cadastrar operador             |\n");
		printf("|2 - Listar operadores              |\n");
		printf("|3 - Alterar operador               |\n");
		printf("|4 - Excluir operador               |\n");
		printf("|0 - Voltar                         |\n");
		printf("-------------------------------------\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				cadastrarOperador();
				break;
			
			case 2:
				listarOperadores();
				break;
			
			case 3:
				
				break;
			
			case 4:
				
				break;
			
			case 0:
				printf("Voce sera redirecionado ao menu principal!\n");
				system("PAUSE");
				break;
			
			default:
				printf("Opcao invalida!\n");
				system("PAUSE");
		}
		
	}while(opcao != 0);
	
}

void requestLogin(int opcao){
	
	switch(opcao){
		case 1:
			
			break;
		
		case 2:
			if(contOperadores == 0){
				cadastrarOperadorMestre();
			}else{
				int login, senha;
				printf("Insira o login: ");
				scanf("%d", &login);
				printf("Insira a senha: ");
				scanf("%d", &senha);
				
				for(int i=0; i<contOperadores; i++){
					if(operador[i].codigo == login){
						if(operador[i].senha == senha){
							menuCadastroDeOperador();
						}else{
							printf("Login e/ou senha invalido(s)\n");
							system("PAUSE");
						}
					}
				}
			}
			break;
		
		case 3:
			
			break;
	}
	
}

int main(){
	
	int opcao = 0;
	
	do{
		system("cls");
		printf("--------MENU PRINCIPAL--------\n");
		printf("|1 - Cadastro de mercadorias |\n");
		printf("|2 - Cadastro de operadores  |\n");
		printf("|3 - Cadastro de setores     |\n");
		printf("|0 - Sair                    |\n");
		printf("------------------------------\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				requestLogin(1);
				break;
			
			case 2:
				requestLogin(2);
				break;
			case 3:
				requestLogin(3);
				break;
			
			case 0:
				printf("Ate logo!\n");
				system("PAUSE");
				break;
			
			default:
				printf("Opcao invalida!\n");
				system("PAUSE");
		}
	}while(opcao != 0);
	
	return 0;
}
