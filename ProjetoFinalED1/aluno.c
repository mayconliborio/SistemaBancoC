//Aluno
#include "structs.c"
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

void verHistoricoPorSemestre(aluno* oAluno,char semestre[20]){
    int j=10;
    int cont=0;
    aluno *aux=oAluno;
    while(aux->aproveitamento!=NULL){
        j=strcasecmp(((aux->aproveitamento)->turma)->semestre,semestre);
        if(j==0){
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

void insereAlunonaTurma(aluno* oAluno, turma* aTurma){
    int i=0;
    int j=10;
    int z=5;
    j=strcasecmp(aTurma->situacao,"cancelada");
    z=strcasecmp(aTurma->situacao,"encerrada");
    if(j==0||z==0){
        printf("Turmas indisponíveis para matricula\n");
        return;
    }
    if(aTurma->alunos==NULL){
        aTurma->alunos=(aluno*)malloc(sizeof(aluno)*45);
<<<<<<< HEAD
        aTurma->alunos[i]=oAluno;
        for(i=1;i<45;i++){
            aTurma->alunos[i]=NULL;
=======
        aTurma->alunos=oAluno;
        for(i=1;i<45;i++){
            aTurma->alunos+i=NULL;
>>>>>>> b21b2d83da4918935f40ccb9b72f97221f22fb81
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
            return;
        }
    }
    printf("Turma está cheia\n");
    return;
}


aluno* buscaAluno(aluno* listaAlunos, unsigned long int ra){
    aluno *aux=listaAlunos;
    while(aux!=NULL){
        if(aux->ra==ra){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

void imprimeTurmasDisponiveis(turma* listaTurmas){
    if(listaTurmas==NULL) return;
    int j=5;
    int z=5;
    int i=0;
    int controle=0;
    while(listaTurmas->prox!=NULL){
        j=strcasecmp(listaTurmas->situacao,"cancelada");
        z=strcasecmp(listaTurmas->situacao,"encerrada");        
        if(j!=0 && z!=0){
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