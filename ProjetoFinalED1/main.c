#include <stdio.h>
#include <string.h>
#include "aluno.c"

int verificaPrimLogin(char login[], char senha[])
{
	char loginProf[80] = {"Professor"}, loginAlun[80] = {"Student"}, loginGeren[80] = {"Gerenciador"}, senhaGeral[80] = {"BCC%20#19&*"};

	if (strcmp(senha, senhaGeral) != 0)
	{
		return 0;
	}
	else
	{
		if (strcmp(login, loginAlun) == 0)
		{
			return 1;
		}

		if (strcmp(login, loginProf) == 0)
		{
			return 2;
		}

		if (strcmp(login, loginGeren) == 0)
		{
			return 3;
		}
	}
	return 0;
}

int cadastroLogin(int a, char nome[], char login[], char senha[])
{
	FILE *arq;

	if (a == 1)
	{
		char login1[80], senha1[80];
		arq = fopen("loginAlunos.txt", "r");

		while(!feof(arq){
			fscanff(arq, "%s %s\n", login1, senha1);
			if (strcmp(login1, login) == 0)
			{
				return 1;
			}
		}
		fclose(arq);


		arq = fopen("loginAlunos.txt", "a+");
		if (arq == NULL)
		{
			printf("Erro ao carregar arquivo!");
			exit(1);
		}

		fprintf(arq, "%s %s\n", login, senha);
		fclose(arq);
	}

	if (a == 2)
	{
		char nome1[80], login1[80], senha1[80];
		arq = fopen("loginAlunos.txt", "r");

		while(!feof(arq){
			fprintf(arq, "%s %s %s\n", nome1, login1, senha1);
			if (strcmp(nome1, nome) == 0)
			{
				return 1;
			}
			if (strcmp(login1, longin) == 0)
			{
				return 2;
			}
		}
		fclose(arq);

		arq = fopen("loginProfessores.txt", "a+");
		if (arq == NULL)
		{
			printf("Erro ao carregar arquivo!");
			exit(1);
		}

		fprintf(arq, "%s %s %s\n", nome, login, senha);

		fclose(arq);
		return 0;
	}

	if (a == 3)
	{

		char login1[80], senha1[80];
		arq = fopen("loginAlunos.txt", "r");

		while(!feof(arq){
			fprintf(arq, "%s %s\n", login1, senha1);
			if (strcmp(login, login) == 0)
			{
				return 1;
			}
		}
		fclose(arq);

		arq = fopen("loginGerenciadores.txt", "a+");
		if (arq == NULL)
		{
			printf("Erro ao carregar arquivo!");
			exit(1);
		}

		fprintf(arq, "%s %s\n", login, senha);

		fclose(arq);
		return 1;
	}
}

int main()
{

	aluno *listaAlunos = NULL;
	int a;
	char login[80], senha[80];
	system("clear");

	printf("Login: ");
	scanf("%s", login);

	setbuf(stdin, NULL);

	printf("Senha: ");
	scanf("%s", senha);
	a = verificaPrimLogin(login, senha);

	switch (a)
	{

	case 0:
	{
		break;
	}

	case 1:
	{
		char ra[11];
		printf("\n\nLogin de novo Aluno efetuado com sucesso! ");
		printf("Agora vamos cadastrar seu login pessoal!\n\n");

		printf("Digite seu RA: ");
		scanf("%lu", &ra);

		if (buscaAluno(listaAlunos, ra) != NULL)
		{
			printf("Nova Senha: ");
			scanf("%s", senha);
			cadastroLogin(a, "nome", ra, senha);
		}
		else
		{
			printf("RA nao encontrado, nao sera possivel concluir o cadastro!");
			break;
		}
	}

	case 2:
	{
		char nome[80];
		printf("\n\nLogin de novo Professor efetuado com sucesso! ");
		printf("Agora vamos cadastrar seu login proprio!\n\n");
		printf("Informe seu nome completo: ");
		scanf("%s", nome);
		printf("Novo Login: ");
		scanf("%s", login);
		printf("Nova Senha: ");
		scanf("%s", senha);

		cadastroLogin(a, nome, ra, senha);
		break;
	}
	case 3:
	{
		printf("\n\nLogin de novo Gerenciador efetuado com sucesso! ");
		printf("Agora vamos cadastrar seu login proprio!\n\n");
		printf("Novo Login: ");
		scanf("%s", login);
		printf("Nova Senha: ");
		scanf("%s", senha);

		cadastroLogin(a, "nome", ra, senha);
		break;
	}
	}
}