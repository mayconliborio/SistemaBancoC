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
#include "Bibliotecas/salva.c"



int main(){

	aluno *listaAlunos = NULL;
	professor *listaProfessores = NULL;
	disciplina *listaDisciplinas = NULL;
	turma *listaTurmas = NULL;
	int a;
	char login[80], senha[80], enter;

	carregaArquivos(&listaAlunos, &listaProfessores, &listaDisciplinas, &listaTurmas);
	
	while(1){
		system("clear");

		do{
			printf("Login: ");
			fgets(login, 80, stdin);
			corrigeString(login);

			if (validaLogin(login) == 1){
				printf("\nLogin invalido, digite novamente!\n\n");
			}
		} while (validaLogin(login) == 1);

		do{
			printf("Senha: ");
			fgets(senha, 80, stdin);
			corrigeString(senha);
			if (validaSenha(senha) == 1){
				printf("\nSenha invalida, digite novamente!\n\n");
			}
		} while (validaSenha(senha) == 1);

		a = verificaPrimLogin(login, senha);

		switch (a){

			case 0:{
				cifraCesar(login);
				cifraCesar(senha);

				int x = verificaLogin(login, senha);

				switch (x){
					case 1:{
						int esc = 1;
						aluno *oAluno = buscaAluno(listaAlunos, cifraReversa(login));
						if (oAluno == NULL){
							printf("Erro critico, programa encerrado!\n\n");
							salvaArquivos(&listaAlunos, &listaProfessores, &listaDisciplinas, &listaTurmas);
							exit(1);
						}
						while (esc != 6){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Alterar dados\n2 - Realizar matricula em uma disciplina");
							printf("\n3 - Cancelar matricula em uma disciplina\n4 - Ver historico completo");
							printf("\n5 - Ver historico por semestre\n6 - Sair\n\nDigite sua escolha: ");
							scanf("%d", &esc);
							limpaBuffer();

							switch (esc){
								case 1:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);	
									break;
								}

								case 2:{
									int cod;

									printf("Digite o codigo da disciplina: ");
									scanf("%d", &cod);
									limpaBuffer();

									insereAlunonaTurma(oAluno, listaTurmas, cod);

									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

								case 3:{
									char disciplina[80];

									printf("Digite o nome da disciplina: ");
									fgets(disciplina, 80, stdin);
									corrigeString(disciplina);
									cancelarDisciplina(oAluno, disciplina);
									break;
								}

								case 4:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);									break;
								}
								case 5:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);									break;
								}
								case 6:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);									break;
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
						int esc = 1;

						while (esc != 10){
							system("clear");
							printf("Menu de Professor: ");

							printf("\n\n1 - Inserir notas\n2 - Alterar notas");
							printf("\n3 - Inserir Frequencia\n4 - Alterar Frequencia");
							printf("\n5 - Desempenho de um aluno por semestre\n6 - Desempenho de uma turma por semestre");
							printf("\n7 - Ver alunos aprovados em todas as disciplinas lecionadas\n8 - Ver alunos reprovados em todas as disciplinas que lecionou");
							printf("\n9 - Gerar relatorio completo\n0 - Sair\n\nDigite sua escolha: ");

							scanf("%d", &esc);
							limpaBuffer();

							switch (esc){
								case 1:{
							/*		printf("Insira o ra do aluno: ");
									printf("Insira o codigo da turma do aluno: ");
									printf("Insira o numero da prova a ser inserida a nota: ")
									printf("Insira a nota do aluno: ");

									inserirNotas(oAluno, aNota, aTurma, ordemNota); */
									
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

								case 2:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

								case 3:{

									inserirFrequencia(oAluno, aTurma);
									alterarFrequencia(oAluno, aTurma, frequencia);

									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

								case 4:{

									alterarFrequencia(oAluno, aTurma, frequencia);

									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 5:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 6:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 7:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 8:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 9:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 0:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
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

						int esc = 1;

						while (esc != 9){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Cadastrar Aluno\n2 - Cadastrar Disciplina");
							printf("\n3 - Cadastrar Turma\n4 - Cadastrar Professor");
							printf("\n5 - Excluir Aluno\n6 - Excluir Disciplina");
							printf("\n7 - Excluir Turma\n8 - Excluir Professor");
							printf("\n9 - Sair do menu\n\nDigite sua escolha: ");

							scanf("%d", &esc);
							limpaBuffer();

							switch (esc){
								case 1:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}
								case 2:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 3:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 4:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);				
									break;
								}
								case 5:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 6:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 7:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 8:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);									
									break;
								}
								case 9:{
									printf("Nao implementado\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
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
				char ra[11], nome[80]={"Nome"};
				int v;

				do{
					system("clear");

					printf("Login de novo Aluno efetuado com sucesso!");
					printf("\nAgora vamos cadastrar seu login proprio: ");

					printf("\n\nDigite seu RA: ");
					fgets(ra, 11, stdin);
					corrigeString(ra);
				} while (validaLogin(ra));
				aluno *oAluno=buscaAluno(listaAlunos, ra);
				if (oAluno!= NULL){
					do{
						printf("\n\nNova Senha: ");
						fgets(senha, 80, stdin);
						corrigeString(senha);
					} while (validaSenha(senha) == 1);

					cifraCesar(ra);
					cifraCesar(senha);

					v = cadastroLogin(a, nome, ra, senha);

					if (v == 1){
						printf("\n\nLogin ja cadastrado!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
					if (v == 0){
						printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
						system("clear");
						printf("Agora vamos fazer sua matricula no curso de Ciencia da Computacao!!\n\nDigite seu RA: ");
						scanf("%s", ra);
						printf("Digite seu nome: ");
						fgets(nome, 80, stdin);
						corrigeString(nome);
						if(strcmp(nome, oAluno->nome)==0 && strcmp(ra, oAluno->ra)){
							system("clear");
							printf("Matricula realizada com sucesso!\n\nTecle enter para continuar! ");
							scanf("%c", &enter);
						}else{
							FILE *arq=fopen("Login/loginAlunos.txt", "w");
							fclose(arq);
						}
					}
				}
				else{
					printf("\n\nAluno nao encontrado, nao sera possivel cadastrar um login!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
				}
				break;
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
				} while (validaNome(nome) == 1);

				if (buscaProfessor(listaProfessores, nome) != NULL){
					do{
						printf("\n\nNovo Login: ");
						fgets(login, 80, stdin);
						corrigeString(login);
					} while (validaLogin(login) == 1);
					cifraCesar(login);

					do{
						printf("\nNova Senha: ");
						fgets(senha, 80, stdin);
						corrigeString(senha);
					} while (validaSenha(senha) == 1);

					cifraCesar(senha);

					v = cadastroLogin(a, nome, login, senha);

					if (v == 0){
						printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar!");
						scanf("%c", &enter);
					}
					if (v == 1){
						printf("\n\nVoce ja cadastrou seu login!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
					if (v == 2){
						printf("\n\nLogin ja cadastrado, tente novamente!\n\nTecle enter para continuar! ");
						scanf("%c", &enter);
					}
				}
				else{
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
				} while (validaLogin(login) == 1);

				cifraCesar(login);

				do{
					printf("\nNova Senha: ");
					fgets(senha, 80, stdin);
					corrigeString(senha);
				} while (validaSenha(senha) == 1);

				cifraCesar(senha);

				v = cadastroLogin(a, "nome", login, senha);

				if (v == 0){
					printf("\n\nLogin cadastrado com sucesso!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
				}
				if (v == 1){
					printf("\n\nLogin ja cadastrado, tente novamente!\n\nTecle enter para continuar! ");
					scanf("%c", &enter);
				}
				break;
			}
		}
	}
}