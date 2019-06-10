#include<stdio.h>
#include<string.h>
#include"aluno.c"

int verificaPrimLogin(char login[80], char senha[80]){
	char loginProf[80]={"Professor"}, loginAlun[80]={"Student"}, loginGeren[80]={"Gerenciador"}, senhaGeral[80]={"BCC%20#19&*"};

	if(strcmp(senha, senhaGeral) != 0){
		return 0;
	}else{
		if(strcmp(login, loginAlun) == 0){
			return 1;
		}

		if(strcmp(login, loginProf) == 0){
			return 2;
		}

		if(strcmp(login, loginGeren) == 0){
			return 3;
		}
	}
	return 0;
}

int cadastroLogin(){
	FILE *alunos = fopen("alunos.txt", "w");

}

int main(){

	aluno *listaAlunos=NULL;
	int a;
	char login[80], senha[80];
	system("clear");

	printf("Login: ");
	scanf("%s", login);

	printf("Senha: ");
	scanf("%s", senha);
	a=verificaPrimLogin(login, senha);

	switch(a){

		case 0:{
			break;
		}

		case 1: {
			unsigned long int ra;
			printf("\n\nLogin de novo Aluno efetuado com sucesso! ");
			printf("Agora vamos cadastrar seu login proprio!\n\n");

			printf("Digite seu RA: ");
			scanf("%lu", &ra);

			if(buscaAluno(listaAlunos, ra)!=NULL){
				printf("Novo Login: ");
				scanf("%s", login);
				printf("Nova Senha: ");
				scanf("%s", senha);
			}else{
				printf("RA nao encontrado, nao sera possivel concluir o cadastro!");
				break;
			}
		}

		case 2: {
			printf("\n\nLogin de novo Professor efetuado com sucesso! ");
			printf("Agora vamos cadastrar seu login proprio!\n\n");
			printf("Informe seu nome completo: ");
		//	scanf("%ud", &ra);     
			printf("Novo Login: ");
			scanf("%s", login);
			printf("Nova Senha: ");
			scanf("%s", senha);
			break;
		}
		case 3: {
			printf("\n\nLogin de novo Gerenciador efetuado com sucesso! ");
			printf("Agora vamos cadastrar seu login proprio!\n\n");
			printf("Novo Login: ");
			scanf("%s", login);
			printf("Nova Senha: ");
			scanf("%s", senha);
			break;
		}
	}
}