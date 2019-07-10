void carregaAlunos(aluno **listaAlunos){
	FILE *arq=fopen("Banco/alunos.txt", "r");
	if(arq==NULL){
		printf("\n\nErro inexperado, fechando o programa!\n\n");
		exit(1);
	}
	char nome[80], ra[11], null[5];

	while(!feof(arq)){
		fscanf(arq, "%s %s %s %s\n", nome, ra, null, null);
		(*listaAlunos)=insereAluno(*listaAlunos, nome, ra);
	}
	fclose(arq);
}	

void carregaProfessores(professor **listaProfessores){
	FILE *arq=fopen("Banco/professores.txt", "r");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	char nome[80], null[5];
	int anoEntrada, anoSaida;
	
	while(!feof(arq)){
		fscanf(arq, "%s %d %d %s %s\n", nome, &anoEntrada, &anoSaida, null, null);
		(*listaProfessores)=insereProfessor(*listaProfessores, nome, anoEntrada, anoSaida);
	}
	fclose(arq);
}

void carregaDisciplinas(disciplina **listaDisciplinas){
	FILE *arq=fopen("Banco/disciplinas.txt", "r");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	char nome[80], null[5];
	int cod, cargaHora;
	
	while(!feof(arq)){
		fscanf(arq, "%d %d %s %s\n", &cod, &cargaHora, nome, null);
		(*listaDisciplinas)=insereDisciplina(*listaDisciplinas, cod, cargaHora, nome);
	}
	fclose(arq);
}

void carregaTurmas(turma **tur, aluno **alu, professor **pro, disciplina **dis){
	FILE *arq=fopen("Banco/turmas.txt", "r");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	char semestre, situacao, nome[80], null[10], ra[3][11];
	int cod, ano; 
	professor *oProfessor;
	disciplina *aDisciplina;
	turma *aux=NULL;
	aluno *aluno;
	
	while(!feof(arq)){
		fscanf(arq, "%d %d", &cod, &ano);
		fscanf(arq, " %c %c ", &semestre, &situacao);
		fscanf(arq, " %s %s %s %s %s %s\n", nome, null, ra[0], ra[1], ra[2], null);
		
		printf("\nnome: %s\n", nome);

		oProfessor=buscaProfessor((*pro), nome);
		if(oProfessor==NULL){
			printf("\n\nNULL");
		}
		
		aDisciplina=buscaDisciplina((*dis), cod);

		(*tur)=criaTurma(*tur, cod, ano, semestre, situacao, oProfessor, aDisciplina);

		if(aux==NULL)
			aux=(*tur);
		else
			aux=aux->prox;

		for(int i=0, j=0; i<3; i++){
			aluno=buscaAluno((*alu), ra[i]);
			if(aluno!=NULL){
				aux->alunos[j]=aluno;
				j++;
			}
		}
	}
	fclose(arq);
}

void carregaArquivos(aluno **alu, professor **pro, disciplina **dis, turma **tur){

	carregaAlunos(&(*alu));
	carregaProfessores(&(*pro));
	carregaDisciplinas(&(*dis));	
	carregaTurmas(&(*tur), &(*alu), &(*pro), &(*dis));
	
}