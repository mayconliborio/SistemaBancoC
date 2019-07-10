#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bibliotecas/structs.c"
#include "Bibliotecas/aluno.c"
#include "Bibliotecas/professor.c"
#include "Bibliotecas/gerenciador.c"
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

//	carregaArquivos(&listaAlunos, &listaProfessores, &listaDisciplinas, &listaTurmas);
	carregaAlunos(&listaAlunos);
	carregaProfessores(&listaProfessores);
	carregaDisciplinas(&listaDisciplinas);	
	carregaTurmas(&listaTurmas, &listaAlunos, &listaProfessores, &listaDisciplinas);
	imprimeTudo(listaAlunos, listaProfessores, listaDisciplinas, listaTurmas);
	limpaBuffer();
	limpaBuffer();
	
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
						while (esc != 0){
							system("clear");
							printf("Menu de Aluno: ");

							printf("\n\n1 - Alterar dados\n2 - Realizar matricula em uma disciplina");
							printf("\n3 - Cancelar matricula em uma disciplina\n4 - Ver historico completo");
							printf("\n5 - Ver historico por semestre\n0 - Sair\n\nDigite sua escolha: ");
							scanf("%d", &esc);
							limpaBuffer();

							switch (esc){
								case 1:{
									int opc=0;
									char nome[80]={"aaa"}, ant[80]={"aaa"}, nov[80]={"aaa"};

									printf("1 - Nome\n2 - Senha\n\nDigite sua escolha: ");
									scanf("%d", &opc);
									limpaBuffer();

									switch(opc){
										case 1:{

											printf("Digite seu nome atualizado: ");
											fgets(nome, 80, stdin);
											corrigeString(nome);
											alteraDadosAlunos(&oAluno, nome, login, ant, nov, opc);
											break;
										}
										case 2:{

											printf("Digite sua senha atual: ");
											scanf("%s", ant);

											printf("\n\nDigite sua senha nova: ");
											scanf("%s", nov);

											alteraDadosAlunos(&oAluno, nome, cifraCesar(login), cifraCesar(ant), cifraCesar(nov), opc);
											limpaBuffer();
											printf("\n\nTecle enter para continuar! ");
											scanf("%c", &enter);

											break;
										}
										default:{
											printf("Entrada invalida!");
											break;
										}
										
									}
									break;
								}

								case 2:{
									int cod;

									printf("Digite o codigo da disciplina: ");
									scanf("%d", &cod);
									limpaBuffer();

									insereAlunonaTurma(oAluno, listaTurmas, cod);
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
									verHistoricoCompleto(oAluno);
									break;
								}
								case 5:{
									int ano;
									char sem;

									printf("Digite o ano que deseja consultar: ");
									scanf("%d", &ano);
									limpaBuffer();
									printf("\nDigite o ano que deseja consultar: ");
									scanf("%c", &sem);
									verHistoricoPorSemestre(oAluno, ano, sem);			
									
									break;
								}
								case 0:{
									printf("Deseja mesmo deslogar do sistema?\n\n1 - Sim\n2 - Nao\n\nDigite sua escolha: ");
									scanf("%d", &esc);
									limpaBuffer();
									if(esc==1){
										esc=0;
									}

									break;
								}
								default:{
									printf("\nEntrada invalida!");
									
									break;
								}
								printf("\n\nTecle enter para continuar! ");
								scanf("%c", &enter);
							}
						}
						break;
					}

					case 3:{
						int esc = 1;

						while (esc != 0){
							professor *oProfessor = buscaProfessor(listaProfessores, loginProfessor(login, senha));
							if(oProfessor==NULL){
								printf("Erro critico!\n\n");
								exit(1);							
							}

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
									turma *aTurma;
									aproveitamento *oAproveitamento;
									char ra[11];
									int codTurma;
									float aNota[3];

									printf("Insira o codigo da turma do aluno: ");
									scanf("%d", &codTurma);
									limpaBuffer();

									aTurma=buscaTurmaAndamento(listaTurmas, oProfessor, codTurma);

									if(aTurma==NULL){
										printf("Nenhuma turma em andamento encontrada!");
									}else{
										int j=0;
										while(aTurma->alunos[j]!=NULL){
											for(int l=0; l<3; l++){
												printf("Digite a nota da P%d: ", l+1);
												scanf("%f", &aNota[l]);

											}
											oAproveitamento=buscaTurmaComAluno(oProfessor, aTurma->alunos[j], codTurma);
											inserirNotas(oAproveitamento, aNota);
											j++;
										}
									}
									
									break;
								}

								case 2:{
									aluno *oAluno;

									char ra[11];

									printf("Insira o ra do aluno: ");
									scanf("%s", ra);

									oAluno=buscaAluno(listaAlunos, ra);

									if(oAluno==NULL){
										printf("Aluno nao cadastrado!");
									}else{
										aproveitamento *oAproveitamento;
										int codTurma;
										float aNota[3];

										printf("Insira o codigo da turma do aluno: ");
										scanf("%d", &codTurma);
										limpaBuffer();

										oAproveitamento = buscaTurmaComAluno(oProfessor, oAluno, codTurma);
										if(oAproveitamento==NULL){
											printf("Aluno nao encontrado em nenhuma turma em andamento!");
										}else{
											for(int l=0; l<3; l++){
												printf("Digite a nova nota da P%d: ", l+1);
												scanf("%f", &aNota[l]);

												inserirNotas(oAproveitamento, aNota); 
											}
										}
									}
									break;
								}

								case 3:{
									turma *aTurma;
									aproveitamento *oAproveitamento;
									char ra[11];
									int codTurma;
									float aFrequencia;

									printf("Insira o codigo da turma do aluno: ");
									scanf("%d", &codTurma);
									limpaBuffer();

									aTurma=buscaTurmaAndamento(listaTurmas, oProfessor, codTurma);

									if(aTurma==NULL){
										printf("Nenhuma turma em andamento encontrada!");
									}else{
										int j=0;
										while(aTurma->alunos[j]!=NULL){

											printf("Digite a nova frequencia do aluno em porcentagem (Ex.: 80.2%%): ");
											scanf("%f", &aFrequencia);

											oAproveitamento=buscaTurmaComAluno(oProfessor, aTurma->alunos[j], codTurma);
											inserirFrequencia(oAproveitamento, aFrequencia);
											j++;
										}
									}
									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);
									break;
								}

								case 4:{
									aluno *oAluno;

									char ra[11];

									printf("Insira o ra do aluno: ");
									scanf("%s", ra);

									oAluno=buscaAluno(listaAlunos, ra);

									if(oAluno==NULL){
										printf("Aluno nao cadastrado!");
									}else{
										aproveitamento *oAproveitamento;
										float aFrequencia;
										int codTurma;

										printf("Insira o codigo da turma do aluno: ");
										scanf("%d", &codTurma);
										limpaBuffer();

										oAproveitamento = buscaTurmaComAluno(oProfessor, oAluno,codTurma);
										if(oAproveitamento==NULL){
											printf("Aluno nao encontrado em nenhuma turma em andamento!");
										}else{
											printf("Digite a nova frequencia do aluno em porcentagem (Ex.: 80.2%%): ");
											scanf("%f", &aFrequencia);
											inserirFrequencia(oAproveitamento, aFrequencia);
											limpaBuffer();
										}
									}

									break;
								}
								case 5:{
									char ra[11];
									aluno *oAluno;

									printf("Insira o ra do aluno: ");
									scanf("%s", ra);

									oAluno=buscaAluno(listaAlunos, ra);
									if(oAluno==NULL){
										printf("Aluno nao cadastrado!");
									}else{
										int ano;
										char semestre;

										printf("Digite o ano a ser buscado: ");
										scanf("%d", &ano);
										printf("Digite o semestre a ser buscado: ");
										scanf("%c", &semestre);
										desempenhoAlunoSemestre(oAluno, ano, semestre);
									}

									break;
								}
								case 6:{
									int codTurma, ano;
									char semestre;

									printf("Insira o codigo da turma: ");
									scanf("%d", &codTurma);

									printf("Digite o ano a ser buscado: ");
									scanf("%d", &ano);

									printf("Digite o semestre a ser buscado: ");
									scanf("%c", &semestre);

									desempenhoTurmaSemestre(listaTurmas, codTurma, ano, semestre);



									break;
								}
								case 7:{
									alunosAprovadosPorDisciplina(listaAlunos, listaTurmas, oProfessor);

									break;
								}
								case 8:{
									alunosReprovadosPorDisciplina(listaAlunos, listaTurmas, oProfessor);
									break;
								}
								case 9:{
									relatorioCompleto(listaTurmas, oProfessor);
									break;
								}
								case 0:{
									printf("Deseja mesmo deslogar do sistema?\n\n1 - Sim\n2 - Nao\n\nDigite sua escolha: ");
									scanf("%d", &esc);
									limpaBuffer();
									if(esc==1){
										esc=0;
									}
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
						char nome[80];
						char ra[11];
						int cod;
						int carga;
						professor *oProfessor;

						while (esc != 0){
							system("clear");
							printf("Menu de Gerenciador: ");

							printf("\n\n1 - Cadastrar Aluno\n2 - Cadastrar Disciplina");
							printf("\n3 - Cadastrar Turma\n4 - Cadastrar Professor");
							printf("\n5 - Excluir Aluno\n6 - Excluir Disciplina");
							printf("\n7 - Excluir Turma\n8 - Excluir Professor");
							printf("\n0 - Sair do menu\n\nDigite sua escolha: ");

							scanf("%d", &esc);
							limpaBuffer();

							switch (esc){
								case 1:{
									printf("\nDigite o nome do Aluno\n");
									fgets(nome,80,stdin);
									corrigeString(nome);

									printf("\nDigite o ra do aluno\n");
									fgets(ra,11,stdin);
									corrigeString(ra);

									listaAlunos =insereAluno(listaAlunos,nome,ra);
									break;
								}
								case 2:{
									printf("\nDigite o nome da disciplina\n");
									fgets(nome,80,stdin);
									corrigeString(nome);

									printf("\nDigite o código da disciplina\n");
									scanf("%d",&cod);
									limpaBuffer();

									printf("\nDigite a carga horária da disciplina\n");
									scanf("%d",&carga);
									limpaBuffer();

									listaDisciplinas=insereDisciplina(listaDisciplinas,cod,carga,nome);								
									break;
								}
								case 3:{
									char semestre;
									disciplina *aDisciplina;
									int ano;

									printf("\nDigite o ano da turma\n");
									scanf("%d",&ano);
									limpaBuffer();

									printf("\nDigite o semestre da turma\n");
									scanf("%c",&semestre);

									printf("\nDigite o nome do professor\n");
									fgets(nome,80,stdin);
									corrigeString(nome);

									printf("\nDigite o código da turma\n");
									scanf("%d", &cod);
									limpaBuffer();		

									oProfessor=buscaProfessor(listaProfessores,nome);

									aDisciplina=buscaDisciplina(listaDisciplinas,cod);

									listaTurmas=criaTurma(listaTurmas, cod, ano, semestre, 'A', oProfessor, aDisciplina);
									break;
								}
								case 4:{
									int anoEntrada, anoSaida;

									printf("Digite o nome do professor: ");
									fgets(nome, 80, stdin);
									corrigeString(nome);

									printf("Digite o ano de entrada do professor: ");
									scanf("%d", &anoEntrada);

									printf("Digite o ano de saida do professor: ");
									scanf("%d", &anoSaida);

									listaProfessores=insereProfessor(listaProfessores, nome, anoEntrada, anoSaida);

									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);				
									break;
								}
								case 5:{
									printf("Digite o codigo da turma: ");
									scanf("%d", &cod);

									excluirDisciplina(&listaDisciplinas, &listaTurmas, cod);
									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 6:{
									printf("Digite o codigo da turma: ");
									scanf("%d", &cod);
									excluirTurma(&listaTurmas, &listaAlunos, &listaProfessores, cod);
									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 7:{
									printf("Digite o nome do professor: ");
									fgets(nome, 80, stdin);
									corrigeString(nome);
									oProfessor=buscaProfessor(listaProfessores, nome);
									excluirProfessor(&listaProfessores, oProfessor, &listaTurmas, nome);
									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);								
									break;
								}
								case 8:{
									printf("Digite o ra: ");
									scanf("%s", ra);

									excluirAluno(&listaAlunos, ra);
									printf("\n\nTecle enter para continuar! ");
									scanf("%c", &enter);									
									break;
								}
								case 0:{
									printf("\n\nTecle enter para continuar! ");
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
						system("clear");
						printf("Agora vamos fazer sua matricula no curso de Ciencia da Computacao!!\n\nDigite seu RA: ");
						scanf("%s", ra);
						printf("Digite seu nome: ");
						fgets(nome, 80, stdin);
						corrigeString(nome);
						if(strcmp(nome, oAluno->nome)==0 && strcmp(ra, oAluno->ra)){
							system("clear");
							printf("Matricula realizada com sucesso!");
							
						}else{

							FILE *arq=fopen("Login/loginAlunos.txt", "w");
							fclose(arq);
						}
					}
				}
				else{
					printf("\n\nAluno nao encontrado, nao sera possivel cadastrar um login!");
				}
				printf("\n\nTecle enter para continuar! ");
				scanf("%c", &enter);
				break;
			}

			case 2:{
				char nome[80];
				int v;

				do{
					system("clear");

					printf("Login de novo Professor efetuado com sucesso!");
					printf("\nAgora vamos cadastrar seu login proprio: ");

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
					cifraCesar(nome);

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
						printf("\n\nLogin ja utilizado, tente novamente!\n\nTecle enter para continuar! ");
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
					printf("\nAgora vamos cadastrar seu login proprio: ");
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
		salvaArquivos(&listaAlunos, &listaProfessores, &listaDisciplinas, &listaTurmas);
	}
}