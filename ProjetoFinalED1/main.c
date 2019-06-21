#include <stdio.h>
#include <string.h>
#include "aluno.c"
#include "professor.c"

int verificaPrimLogin(char login[], char senha[]){
	char loginProf[80] = {"Professor"}, loginAlun[80] = {"Student"}, loginGeren[80] = {"Gerenciador"}, senhaGeral[80] = {"BCC%20#19&*"};

	if (strcmp(senha, senhaGeral) != 0){
		return 0;
	}
	else{
		if (strcmp(login, loginAlun) == 0){
			return 1;
		}

		if (strcmp(login, loginProf) == 0){
			return 2;
		}

		if (strcmp(login, loginGeren) == 0){
			return 3;
		}
	}
	return 0;
}

int verificaLogin(char login[], char senha[]){
	char login1[80], senha1[80];
	FILE *arq;

	arq = fopen("loginAlunos.txt", "r");

	while (!feof(arq)){
		fscanf(arq, "%s %s\n", login1, senha1);
		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 1;
			}else{
				return 2;
			}
		}
	}
	fclose(arq);

	arq = fopen("loginProfessores.txt", "r");

	while (!feof(arq)){
		fgets(senha1, 80, arq);
		fscanf(arq, "%s %s\n", login1, senha1);

		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 3;
			}else{
				return 4;
			}
		}
	}
	fclose(arq);

	arq = fopen("loginGerenciadores.txt", "r");

	while (!feof(arq)){
		fscanf(arq, "%s %s\n", login1, senha1);
		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 5;
			}else{
				return 6;
			}
		}
	}
	fclose(arq);
	return 0;
}

int cadastroLogin(int a, char nome[], char login[], char senha[]){
	FILE *arq;

	if (a == 1){
		int v=verificaLogin(login, senha);

		if(v==0){
			arq = fopen("loginAlunos.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!");
				exit(1);
			}

			fprintf(arq, "%s %s\n", login, senha); 
			
			fclose(arq);
			return 0;
		}
		if(v==1 || v==2){
			return 1;
		}
		
	}

	if (a == 2){
		int v=verificaLogin(login, senha);

		if(v==0){
			arq = fopen("loginProfessores.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!");
				exit(1);
			}

			fprintf(arq, "%s\n%s %s\n", nome, login, senha);

			fclose(arq);
			return 0;
		}
		if(v==3 || v==4){
			return 1;
		}
	}

	if (a == 3){
		int v=verificaLogin(login, senha);
		if(v==0){
			arq = fopen("loginGerenciadores.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!\n\nEncerrando o programa!");
				exit(1);
			}

			fprintf(arq, "%s %s\n", login, senha);

			fclose(arq);
			return 0;
		}
		if(v==5 || v==6){
			return 1;
		}
	}
}

int validaNome(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if( (x >= 65 && x <= 90 ) || (x >= 97 && x <= 122) || x==32){
			i++;
		}else
		return 1;
	}
	return 0;
}

int validaLogin(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if( (x >= 65 && x <= 90 ) || (x >= 97 && x <= 122) || (x >= 48 && x <= 57)){
			i++;
		}else
		return 1;
	}
	return 0;
}

int validaSenha(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if(x<33 || x>126){
			return 1;
		}
		i++;
	}
	return 0;
}

char *cifraCesar(char string[]){
	int i=0;

	while (string[i] != '\0'){
		string[i] += i + 1;
		i++;
	}

	return string;
}

char corrigeString(char string[]){
	int x=strlen(string)-1;
	if(string[x]=='\n'){
		string[x]='\0';
	}
}

void carregaAlunos(){
}

void carregaProfessores(){
}

void carregaDisciplinas(){
}

void carregaTurmas()
{
}

int main(){

	aluno *listaAlunos = NULL;
	professor *listaProfessores = NULL;
	disciplina *listaDisciplinas = NULL;
	turma *listaTurmas = NULL;

	int a;
	char login[80], senha[80], enter;
	
	while(1){
		system("clear");

		do{
			printf("Login: ");
			fgets(login, 80, stdin);
			corrigeString(login);

			if(validaLogin(login)==1){
				printf("\nLogin invalido, digite novamente!\n\n");
			}
		}while(validaLogin(login)==1);


		setbuf(stdin, NULL);
		do{
			printf("Senha: ");
			fgets(senha, 80, stdin);
			corrigeString(senha);
			if(validaSenha(senha)==1){
				printf("\nSenha invalida, digite novamente!\n\n");
			}
		}while(validaSenha(senha)==1);

		a = verificaPrimLogin(login, senha);

		switch (a){

			case 0:{
				cifraCesar(login);
				cifraCesar(senha);

				switch(verificaLogin(login, senha)){

					case 1:{
						int esc=1;

						while(esc!=6){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Alterar dados\n2 - Realizar matricula em uma disciplina");
							printf("\n3 - Cancelar matricula em uma disciplina\n4 - Ver historico completo");
							printf("\n5 - Ver historico por semestre\n6 - Sair\n\nDigite sua escolha: ");
							scanf("%d", &esc);
							setbuf(stdin, NULL);

							switch(esc){
								case 1:{

									break;
								}

								case 2:{

									break;
								}

								case 3:{

									break;
								}

								case 4:{

									break;
								}

								case 5:{

									break;
								}

								case 6:{

									break;
								}

								default:{
									printf("\nEntrada invalida!\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

							}

						}
						break;
					}

					case 3:{
						int esc=1;

						while(esc!=10){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Inserir notas\n2 - Alterar notas");
							printf("\n3 - Inserir Frequencia\n4 - Alterar Frequencia");
							printf("\n5 - Desempenho de um aluno por semestre\n6 - Desempenho de uma turma por semestre");
							printf("\n7 - Ver alunos aprovados em todas as disciplinas lecionadas\n8 - Ver alunos reprovados em todas as disciplinas que lecionou");
							printf("\n9 - Gerar relatorio completo\n10 - Sair\n\nDigite sua escolha: ");

							scanf("%d", &esc);
							setbuf(stdin, NULL);

							switch(esc){
								case 1:{

									break;
								}

								case 2:{

									break;
								}

								case 3:{

									break;
								}

								case 4:{

									break;
								}

								case 5:{

									break;
								}

								case 6:{

									break;
								}

								case 7:{

									break;
								}

								case 8:{

									break;
								}

								case 9:{

									break;
								}

								case 10:{

									break;
								}

								default:{
									printf("\nEntrada invalida!\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

							}

						}


						break;
					} 

					case 5:{

						int esc=1;

						while(esc!=9){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Cadastrar Aluno\n2 - Cadastrar Disciplina");
							printf("\n3 - Cadastrar Turma\n4 - Cadastrar Professor");
							printf("\n5 - Excluir Aluno\n6 - Excluir Disciplina");
							printf("\n7 - Excluir Turma\n8 - Excluir Professor");
							printf("\n9 - Sair\n\nDigite sua escolha: ");

							scanf("%d", &esc);
							setbuf(stdin, NULL);

							switch(esc){
								case 1:{

									break;
								}

								case 2:{

									break;
								}

								case 3:{

									break;
								}

								case 4:{

									break;
								}

								case 5:{

									break;
								}

								case 6:{

									break;
								}

								case 7:{

									break;
								}

								case 8:{

									break;
								}

								case 9:{

									break;
								}

								default:{
									printf("\nEntrada invalida!\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

							}

						}

						break;
					}

					default:{
						printf("\nLogin e/ou Senha invalido(s)!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
						break;
					}

				}

				break;
			}

			case 1:{
				char ra[11];
				int v;

				do{
					system("clear");

					printf("Login de novo Aluno efetuado com sucesso!");
					printf("\nAgora vamos cadastrar seu login proprio: ");

					printf("\n\nDigite seu RA: ");
					fgets(ra, 11, stdin);
					corrigeString(ra);
				}while(validaLogin(ra));

				cifraCesar(ra);


				if (buscaAluno(listaAlunos, ra) != NULL){
					do{
						printf("\n\nNova Senha: ");
						fgets(senha, 80, stdin);
						corrigeString(senha);
					}while(validaSenha(senha)==1);

					cifraCesar(senha);

					v=cadastroLogin(a, "nome", ra, senha);

					if(v==1){
						printf("\n\nLogin ja cadastrado!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
					if(v==0){
						printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
				}else{
					printf("\n\nAluno nao encontrado, nao sera possivel cadastrar um login!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
					break;
				}
			}

			case 2:{
				char nome[80];
				int v;

				do{
					system("clear");

					printf("Login de novo Professor efetuado com sucesso!");
					printf("\nAgora vamos cadastrar seu login priorio: ");


					printf("\n\nInforme seu nome completo: ");
					fgets(nome, 80, stdin);
					corrigeString(nome);
				}while(validaNome(nome)==1);

				if(buscaProfessor(listaProfessores, nome)!=NULL){
					do{
						printf("\n\nNovo Login: ");
						fgets(login, 80, stdin);
						corrigeString(login);
					}while(validaLogin(login)==1);
					cifraCesar(login);

					do{
						printf("\nNova Senha: ");
						fgets(senha, 80, stdin);
						corrigeString(senha);
					}while(validaSenha(senha)==1);

					cifraCesar(senha);

					v=cadastroLogin(a, nome, login, senha);

					if(v==0){
						printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar!");
						scanf("%c", &enter);
					}
					if(v==1){
						printf("\n\nVoce ja cadastrou seu login!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
					if(v==2){
						printf("\n\nLogin ja cadastrado, tente novamente!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}

				}else{
					printf("\n\nProfessor nao encontrado, nao sera possivel cadastrar um login!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
				}
				break;
			}

			case 3:{
				int v;
				do{
					system("clear");

					printf("Login de novo Gerenciador efetuado com sucesso! ");
					printf("\nAgora vamos cadastrar seu login priorio: ");
					printf("\n\nNovo Login: ");
					fgets(login, 80, stdin);
					corrigeString(login);
				}while(validaLogin(login)==1);

				cifraCesar(login);

				do{
					printf("\nNova Senha: ");
					fgets(senha, 80, stdin);
					corrigeString(senha);
				}while(validaSenha(senha)==1);

				cifraCesar(senha);

				v=cadastroLogin(a, "nome", login, senha);

				if(v==0){
					printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);

				}
				if(v==1){
					printf("\n\nLogin ja cadastrado, tente novamente!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
				}
				break;
			}
		}
	}
}