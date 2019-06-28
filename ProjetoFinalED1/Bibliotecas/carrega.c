void carregaAlunos(aluno **listaAlunos){
	FILE *arq=fopen("Banco/alunos.txt", "r");
	char nome[80], ra[11], null[5];

	while(!feof(arq)){
		fscanf(arq, "%s %s %s %s\n", nome, ra, null, null);
		(*listaAlunos)=insereAluno(*listaAlunos, nome, ra);
	}
	fclose(arq);
}	

void carregaProfessores(professor **listaProfessores){
	FILE *arq=fopen("Banco/professores.txt", "r");
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
	char nome[80], null[5];
	int cod, cargaHora;
	
	while(!feof(arq)){
		fscanf(arq, "%d %d %s %s\n", &cod, &cargaHora, nome, null);
		(*listaDisciplinas)=insereDisciplina(*listaDisciplinas, cod, cargaHora, nome);
	}
	fclose(arq);
}

void carregaTurmas(turma **listaTurmas){
	FILE *arq=fopen("Banco/turmas.txt", "r");
	char semestre, situacao, null[5];
	int cod, ano;
	
	while(!feof(arq)){
		fscanf(arq, "%d %d %c %c %s %s %s %s\n", &cod, &ano, &semestre, &situacao, null, null, null, null);
		(*listaTurmas)=criaTurma(*listaTurmas, cod, ano, semestre, situacao, NULL, NULL);
	}
	fclose(arq);
}

void carregaArquivos(aluno **alu, professor **pro, disciplina **dis, turma **tur){
	carregaAlunos(&(*alu));
	carregaProfessores(&(*pro));
	carregaDisciplinas(&(*dis));
	carregaTurmas(&(*tur));
	
}