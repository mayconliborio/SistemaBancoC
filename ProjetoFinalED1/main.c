#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bibliotecas/structs.c"
#include "Bibliotecas/aluno.c"
#include "Bibliotecas/professor.c"
#include "Bibliotecas/gerenciador.c"
#include "Bibliotecas/login.c"
#include "Bibliotecas/valida.c" 
#include "Bibliotecas/carrega.c"

int main(){

	aluno *listaAlunos = NULL;
	professor *listaProfessores = NULL;
	disciplina *listaDisciplinas = NULL;
	turma *listaTurmas = NULL;
	int a;
	char login[80], senha[80], enter;

	carregaArquivos(&listaAlunos, &listaProfessores, &listaDisciplinas, &listaTurmas);

	imprimeTurma(listaTurmas);
	
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
				int x=verificaLogin(login, senha);

				cifraCesar(login);
				cifraCesar(senha);

				switch(x){
					case 1:{
						int esc=1;
						aluno *oAluno=buscaAluno(listaAlunos, cifraReversa(login));
						if(oAluno == NULL){
							printf("Erro critico, programa encerrado!\n\n");
							exit(1);
						}
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