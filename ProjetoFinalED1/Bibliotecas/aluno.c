//Aluno
void cancelarDisciplina(aluno *oAluno, char nome[]){
    aproveitamento *aux=oAluno->aproveitamento;
    aproveitamento *aux2;
    int v=0;

    while(aux!=NULL){
        if(strcmp(aux->turma->disciplina->nome, nome)==0){
            if(aux->notas[0]==-1 && aux->notas[1]==-1 && aux->notas[2]==-1){
                removeAluno(aux->turma->alunos, oAluno->ra);
                v=1;
                break;
            }
        }
        aux2=aux;
        aux=aux->prox;
    }
    if(v=1){
        aux2->prox=aux->prox;
        free(aux);
    }
}

int contaAlunos(aluno *alunos){
    aluno *aux=alunos;
    int cont=0;

    while(aux!=NULL){
        cont++;
        aux=aux->prox;
    }
    return cont;
}

void verHistoricoCompleto(aluno* oAluno){
    aproveitamento *aux=oAluno->aproveitamento;
    while(aux!=NULL){
        printf("notas: %f %f %f \nfrequencia: %f \n turma: %s",
            aux->notas[0],
            aux->notas[1],
            aux->notas[2],
            aux->frequencia,
            ((aux->turma)->disciplina)->nome);
        aux=aux->prox;
    }
}

void verHistoricoPorSemestre(aluno* oAluno, char semestre){
    int cont=0;
    aproveitamento *aux=oAluno->aproveitamento;
    while(aux!=NULL){
        if(((aux->turma)->semestre) == semestre){
            printf("notas: %f %f %f \nfrequencia: %f \n turma: %s",
                aux->notas[0],
                aux->notas[1],
                aux->notas[2],
                aux->frequencia,
                ((aux->turma)->disciplina)->nome);
        }
        aux=aux->prox;
        cont++;
    }
}


void insereAlunonaTurma(aluno* oAluno, turma* listaTurmas, int cod){
    turma *aux=listaTurmas;
    turma  *aTurma=NULL;
    while(aux!=NULL){
        if(((aux->disciplina)->cod)==cod){
            aTurma=aux;
        }
        aux=aux->prox;
    }
    if(aTurma==NULL){
        printf("\nTurma não encontrada!\n");
        return;
    }
    int i=0;
    int j=10;
    int z=5;
    j=strcasecmp(aTurma->situacao,"P");
    if(j!=0){
        printf("Turmas indisponíveis para matricula\n");
        return;
    }
    if(aTurma->alunos[i]==NULL){
        aTurma->alunos[i]=oAluno;
        for(i=1;i<45;i++){
            aTurma->alunos[i]=NULL;
        }
        return;
    }
    for(i=0;i<45;i++){
        if((aTurma->alunos[i])->ra==oAluno->ra){
            printf("Aluno já matriculado nesta turma\n");
            return;
        }
        if(aTurma->alunos[i]==NULL){
            aTurma->alunos[i]=oAluno;
            insereAproveitamentonoAluno(oAluno, aTurma);
            return;
        }
    }
    printf("Turma está cheia\n");
    return;
}

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