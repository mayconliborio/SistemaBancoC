void salvaAlunos(aluno **alu){
	FILE *arq=fopen("Banco/alunos.txt", "w");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	aluno *aux=(*alu);

	while(aux!=NULL){
		fprintf(arq, "%s %s %s %s\n", aux->nome, aux->ra, "NULL", "NULL");
		aux=aux->prox;
	}
	fclose(arq);
}	

void salvaProfessores(professor **pro){
	FILE *arq=fopen("Banco/professores.txt", "w");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	professor *aux=(*pro);

	while(aux!=NULL){
		fprintf(arq, "%s %d %d %s %s\n", aux->nome, aux->anoEntrada, aux->anoSaida, "NULL", "NULL");
		aux=aux->prox;
	}
	fclose(arq);
}

void salvaDisciplinas(disciplina **dis){
	FILE *arq=fopen("Banco/disciplinas.txt", "w");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	disciplina *aux=(*dis);
	
	while(aux!=NULL){
		fprintf(arq, "%d %d %s %s\n", aux->codigo, aux->cargaHoraria, aux->nome, "NULL");
		aux=aux->prox;
	}
	fclose(arq);
}

void salvaTurmas(turma **tur){
	FILE *arq=fopen("Banco/turmas.txt", "w");
	if(arq==NULL){
		printf("Erro inexperado, fechando o programa");
		exit(1);
	}
	turma *aux=(*tur);
	
	while(aux!=NULL){

		fprintf(arq, "%d %d %c %c ", aux->codigo, aux->ano, aux->semestre, aux->situacao);

		if(aux->professor==NULL){
			fprintf(arq, "%s ", "NULL");
		}
		else{
			fprintf(arq, "%s ", aux->professor->nome);
		}

		if(aux->disciplina==NULL){
			fprintf(arq, "%s ", "NULL");
		}
		else{
			fprintf(arq, "%s ", aux->disciplina->nome);
		}

		if(aux->alunos[0]==NULL){
			fprintf(arq, "%s %s %s %s\n", "NULL", "NULL", "NULL", "NULL");
		}else if(aux->alunos[1]==NULL){
			fprintf(arq, "%s %s %s %s\n", aux->alunos[0]->ra, "NULL", "NULL", "NULL");
		}else if(aux->alunos[1]==NULL){
			fprintf(arq, "%s %s %s %s\n", aux->alunos[0]->ra, aux->alunos[1]->ra, "NULL", "NULL");
		}else{
			fprintf(arq, "%s %s %s %s\n", aux->alunos[0]->ra, aux->alunos[1]->ra, aux->alunos[2]->ra, "NULL");
		}
		aux=aux->prox;
	}
	fclose(arq);
}

void salvaArquivos(aluno **alu, professor **pro, disciplina **dis, turma **tur){
	salvaAlunos(&(*alu));

	salvaProfessores(&(*pro));

	salvaDisciplinas(&(*dis));

	salvaTurmas(&(*tur));

}