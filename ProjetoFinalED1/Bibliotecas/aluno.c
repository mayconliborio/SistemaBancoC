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

void matriculaDisciplina(turma *tur, aluno *oAluno, char nome[]){
    turma *aux=tur;

    while(aux!=NULL){
        if(aux->situacao=='P' && strcmp(aux->disciplina->nome, nome)==0 && contaAlunos(aux->alunos)<45){
            insereAluno(aux->alunos, oAluno->nome, oAluno->ra);
            insereAproveitamentoAluno(oAluno, aux);
            printf("Matricula na turma %d realizada com sucesso!\n\n", aux->codigo);
            return;
        }
        aux=aux->prox;
    }
    printf("Nao ha vaga para a disciplina informada!\n\n");
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