//Aluno
#include "login.c"

void alteraDadosAlunos(aluno **oAluno, char nome[], char login[], char ant[], char nov[], int esc){
    if(esc==1){
        strcpy((*oAluno)->nome, nome);
    }

    if(esc==2){
        alterarSenha(login, ant, nov);
    }
}

void cancelarDisciplina(aluno *oAluno, char nome[]){
    aproveitamento *aux=oAluno->aproveitamento;
    aproveitamento *aux2;
    int v=0;

    while(aux!=NULL){
        if(strcmp(aux->turma->disciplina->nome, nome)==0){
            if(aux->notas[0]==-1 && aux->notas[1]==-1 && aux->notas[2]==-1){
                for(int i=0; i<45; i++){
                    if(aux->turma->alunos[i]==oAluno){
                        aux->turma->alunos[i]=NULL;
                        v=1;
                        break;
                    }
                }
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

void verHistoricoCompleto(aluno* oAluno){
    aproveitamento *aux=oAluno->aproveitamento;
    while(aux!=NULL){
        printf("notas: %f %f %f \nfrequencia: %f \n turma: %s\n\n",
            aux->notas[0],
            aux->notas[1],
            aux->notas[2],
            aux->frequencia,
            ((aux->turma)->disciplina)->nome);
        aux=aux->prox;
    }
}

void verHistoricoPorSemestre(aluno* oAluno, int ano, char semestre){

    aproveitamento *aux=oAluno->aproveitamento;
    while(aux!=NULL){
        if(((aux->turma)->semestre) == semestre && aux->turma->ano==ano){
            printf("notas: %f %f %f \nfrequencia: %f \n turma: %s\n\n",
                aux->notas[0],
                aux->notas[1],
                aux->notas[2],
                aux->frequencia,
                ((aux->turma)->disciplina)->nome);
        }
        aux=aux->prox;
    }
}


void insereAlunonaTurma(aluno* oAluno, turma* listaTurmas, int cod){
    turma  *aTurma=buscaTurmaDisponivel(listaTurmas, cod);

    if(aTurma==NULL){
        printf("Nenhuma turma encontrada ou disponivel!");
        return;
    }

    int i=0;
    for(; aTurma->alunos[i]!=NULL; i++){
        if(strcmp(aTurma->alunos[i]->ra, oAluno->ra)==0){
            printf("Aluno já matriculado nesta turma\n");
            return;
        }  
    }
    
    aTurma->alunos[i]=oAluno;
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

