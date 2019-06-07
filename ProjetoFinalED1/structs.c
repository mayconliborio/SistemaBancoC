#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoAluno{
    char nome [80];
    unsigned long int ra;
    struct tipoAluno *prox;
    struct tipoAproveitamento *aproveitamento;
}aluno;

typedef struct tipoAproveitamento{
    float notas[3];
    float frequencia;
    struct tipoTurma *turma;
    struct tipoAproveitamento *prox;
}aproveitamento;

typedef struct tipoTurma{
    int codigo;
    int ano;
    char semestre[20];
    char situacao[20];
    struct tipoProfessor *professor;
    struct tipoDisciplina *disciplina;
    struct tipoAluno *alunos;
    struct tipoTurma *prox;
}turma;

typedef struct tipoDisciplina{
    int codigo;
    int cargaHoraria;
    char nome[20];
    struct tipoDisciplina *prox;
}disciplina;


typedef struct tipoProfessor{
    char nome[80];
    int anoEntrada;
    int anoSaida;
    struct tipoTurma *turmas;
    struct tipoProfessor *prox;
}professor;


aluno* insereAluno(aluno* listaAluno,char nome[],unsigned long int ra){
    if(listaAluno==NULL){
        listaAluno=(aluno*)malloc(sizeof(aluno));
        strcpy(listaAluno->nome, nome);
        listaAluno->ra=ra;
        listaAluno->prox=NULL;
        listaAluno->aproveitamento=NULL;
        return listaAluno;
    }
    aluno *aux=listaAluno;
    while(aux->prox!=NULL){
        if(aux->ra==ra){
            printf("Aluno já existe \n");
            return listaAluno;
        }
        aux=aux->prox;
    }
    aux->prox=(aluno*)malloc(sizeof(aluno));
    aux=aux->prox;
    strcpy(aux->nome,nome);
    aux->ra=ra;
    aux->prox=NULL;
    aux->aproveitamento=NULL;
    return listaAluno;
}



disciplina* insereDisciplina(disciplina *listaDisciplina, int codigo, int cargaHoraria, char nome[]){
    if(listaDisciplina==NULL){
        listaDisciplina=(disciplina*)malloc(sizeof(disciplina));
        listaDisciplina->codigo=codigo;
        listaDisciplina->cargaHoraria=cargaHoraria;
        strcpy(listaDisciplina->nome, nome);
        listaDisciplina->prox=NULL;
        return listaDisciplina;
    }
    disciplina *aux=listaDisciplina;
    while(aux->prox!=NULL) {
        aux=aux->prox;
    }
    aux->prox=(disciplina*)malloc(sizeof(disciplina));
    aux=aux->prox;
    aux->codigo=codigo;
    aux->cargaHoraria=cargaHoraria;
    strcpy(aux->nome,nome);
    aux->prox=NULL;
    return listaDisciplina;
}

professor* insereProfessor(professor *listaProfessor,char nome[80], int anoEntrada){
    if(listaProfessor==NULL){
        listaProfessor=(professor*)malloc(sizeof(professor));
        strcpy(listaProfessor->nome, nome);
        listaProfessor->anoEntrada=anoEntrada;
        listaProfessor->prox=NULL;
        return listaProfessor;
    }
    professor *aux=listaProfessor;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=(professor*)malloc(sizeof(professor));
    aux=aux->prox;
    strcpy(aux->nome,nome);
    aux->anoEntrada=anoEntrada;
    aux->prox=NULL;
    return listaProfessor;
}

turma* criaTurma(turma *listaTurmas, int codigo, int ano, char semestre[], char situacao[],professor *oProfessor, disciplina *aDisciplina){
    if(listaTurmas==NULL){
        listaTurmas=(turma*)malloc(sizeof(turma));
        listaTurmas->codigo=codigo;
        listaTurmas->ano=ano;
        strcpy(listaTurmas->semestre,semestre);
        strcpy(listaTurmas->situacao,situacao);
        listaTurmas->professor=oProfessor;
        listaTurmas->prox=NULL;
        return listaTurmas;
    }
    turma *aux=listaTurmas;
    while(aux->prox!=NULL){
        if(aux->codigo=codigo){
            printf("Turma já existe \n");
            return listaTurmas;
        }
        aux=aux->prox;

    }
    aux->prox=(turma*)malloc(sizeof(turma));
    aux=aux->prox;
    aux->codigo=codigo;
    aux->ano=ano;
    strcpy(aux->semestre,semestre);
    strcpy(aux->situacao,situacao);
    aux->professor=oProfessor;
    aux->prox=NULL;
    return listaTurmas;
}





















aproveitamento* insereAproveitamentonoAluno(aluno* oAluno, turma* aTurma){
    if(oAluno->aproveitamento==NULL){
        oAluno->aproveitamento=(aproveitamento*)malloc(sizeof(aproveitamento));
        (oAluno->aproveitamento)->frequencia=0.00;
        (oAluno->aproveitamento)->turma=aTurma;
        (oAluno->aproveitamento)->prox=NULL;
        return oAluno;
    }
    aproveitamento *aux=(oAluno->aproveitamento);
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=(aproveitamento*)malloc(sizeof(aproveitamento));
    aux=aux->prox;
    aux->frequencia=0;
    aux->turma=aTurma;
    aux->prox=NULL;
    return oAluno;
}