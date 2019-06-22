//Aluno
void cancelarDisciplina(){

}

void verHistoricoCompleto(aluno* oAluno){
    aluno *aux=oAluno;
    while(aux->aproveitamento!=NULL){
        printf("notas: %f %f %f \nfrequencia: %f \n turma: %s",
        (aux->aproveitamento)->notas[0],
        (aux->aproveitamento)->notas[1],
        (aux->aproveitamento)->notas[2],
        (aux->aproveitamento)->frequencia,
        (((aux->aproveitamento)->turma)->disciplina)->nome);
        aux->aproveitamento=(aux->aproveitamento)->prox;
    }
}

void verHistoricoPorSemestre(aluno* oAluno, char semestre){
    int cont=0;
    aluno *aux=oAluno;
    while(aux->aproveitamento!=NULL){
        if((((aux->aproveitamento)->turma)->semestre) == semestre){
            printf("notas: %f %f %f \nfrequencia: %f \n turma: %s",
            (aux->aproveitamento)->notas[0],
            (aux->aproveitamento)->notas[1],
            (aux->aproveitamento)->notas[2],
            (aux->aproveitamento)->frequencia,
            (((aux->aproveitamento)->turma)->disciplina)->nome);
        }
        aux->aproveitamento=(aux->aproveitamento)->prox;
        cont++;
    }
}
/*
void insereAlunonaTurma(aluno* oAluno, turma* aTurma){
    int i=0;
    char sit;
    sit=aTurma->situacao;

    if( sit == 'C' || sit == 'E'){
        printf("Turmas indisponíveis para matricula\n");
        return;
    }
    if(aTurma->alunos==NULL){
        aTurma->alunos[i]=oAluno;
        for(i=1;i<45;i++){
            aTurma->alunos[i]=NULL;
        }
        return;
    }
    for(i=0;i<45;i++){
        if(strcmp((aTurma->alunos[i])->ra, oAluno->ra)==0){
            printf("Aluno já matriculado nesta turma\n");
            return;
        }
        if(aTurma->alunos[i]==NULL){
            aTurma->alunos[i]=oAluno;
            return;
        }
    }
    printf("Turma está cheia\n");
    return;
}
*/

aluno* buscaAluno(aluno* listaAlunos, char ra[]){
    aluno *aux=listaAlunos;
    while(aux!=NULL){
        if(strcmp(aux->ra, ra)==0){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

/*
void imprimeTurmasDisponiveis(turma* listaTurmas){
    if(listaTurmas==NULL) return;
    char sit;
    int i=0;
    int controle=0;

    while(listaTurmas->prox!=NULL){
       
       if(sit != 'C' && sit != 'E'){
            for(i=0;i<45;i++){
                if(listaTurmas->alunos[i]==NULL){
                    controle=1;
                    i=45;
                }
            }
            if(controle==1){
                imprimeTurma(listaTurmas);
            }
        }
        listaTurmas=listaTurmas->prox;
    }
}
*/