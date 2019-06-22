typedef struct tipoAluno{
    char nome [80];
    char ra[11];
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
    char semestre;
    char situacao;
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

aluno *alocaAluno(){
    aluno *no=(aluno*)malloc(sizeof(aluno));
    return no;
}

professor *alocaProfessor(){
    professor *no=(professor*)malloc(sizeof(professor));
    return no;
}

disciplina *alocaDisciplina(){
    disciplina *no=(disciplina*)malloc(sizeof(disciplina));
    return no;
}

turma *alocaTurma(){
    turma *no=(turma*)malloc(sizeof(turma));
    return no;
}

aluno* insereAluno(aluno* listaAluno, char nome[], char ra[]){
    aluno *no=alocaAluno();
    aluno *aux=listaAluno;

    strcpy(no->nome, nome);
    strcpy(no->ra,ra);
    no->prox=NULL;
    no->aproveitamento=NULL;

    if(listaAluno==NULL){
        printf("\n\nAluno cadastrado com sucesso!\n");
        listaAluno=no;
        return listaAluno;
    }

    while(aux->prox!=NULL){
        if(strcmp(aux->ra,ra)==0){
            printf("\n\nAluno já existe \n");
            free(no);
            return listaAluno;
        }
        aux=aux->prox;
    }

    aux->prox=no;

    printf("\n\nAluno cadastrado com sucesso!\n");
    return listaAluno;
}

disciplina* insereDisciplina(disciplina *listaDisciplina, int codigo, int cargaHoraria, char nome[]){
    disciplina *no=alocaDisciplina();
    disciplina *aux=listaDisciplina;

    no->codigo=codigo;
    no->cargaHoraria=cargaHoraria;
    strcpy(no->nome, nome);
    no->prox=NULL;

    if(listaDisciplina==NULL){
        listaDisciplina=aux;
        return listaDisciplina;
    }

    while(aux->prox!=NULL) {
        if(aux->codigo == codigo){
            printf("Disciplina ja cadastrada! \n");
            free(no);
            return listaDisciplina;
        }

        aux=aux->prox;
    }

    aux->prox=no;
    return listaDisciplina;
}

professor* insereProfessor(professor *listaProfessor,char nome[80], int anoEntrada, int anoSaida){
    professor *no=alocaProfessor();
    professor *aux=listaProfessor;

    strcpy(no->nome, nome);
    no->anoEntrada=anoEntrada;
    no->anoSaida=anoSaida;
    no->turmas=NULL;
    no->prox=NULL;

    if(listaProfessor==NULL){
        listaProfessor=no;
        return listaProfessor;
    }
    
    while(aux->prox!=NULL){
        if(strcmp(aux->nome, nome)==0){
            free(no);
            return listaProfessor;
        }
        aux=aux->prox;
    }

    no->prox=no;
    return listaProfessor;
}

turma* criaTurma(turma *listaTurmas, int codigo, int ano, char semestre, char situacao, professor *oProfessor, disciplina *aDisciplina){
    turma *no=alocaTurma();
    turma *aux=listaTurmas;

    no->codigo=codigo;
    no->ano=ano;
    no->semestre=semestre;
    no->situacao=situacao;
    no->disciplina=aDisciplina;
    no->professor=oProfessor;
    no->alunos=NULL;
    no->prox=NULL;

    if(listaTurmas==NULL){
        listaTurmas=no;
        return listaTurmas;
    }

    while(aux->prox!=NULL){
      //  if(aux->codigo=codigo &&){
        //    printf("Turma já existe \n");
          //  free(no);
            //return listaTurmas;
        //}
        aux=aux->prox;
    }

    aux->prox=no;
    return listaTurmas;
}

void imprimeTurma(turma* aTurma){
    if(aTurma==NULL){
        printf("Deu ruim!");
    }

    printf("codigo: %d \nano: %d \nsemestre: %c \nsituação: %c \nprofessor: %s \ndisciplina %s \n",
       aTurma->codigo,
       aTurma->ano,
       aTurma->semestre,
       aTurma->situacao,
       (aTurma->professor)->nome,
       (aTurma->disciplina)->nome);
}

turma* buscaTurma(turma* listaTurmas, int cod){
    turma *aux=listaTurmas;
    while(aux!=NULL){
        if(aux->codigo==cod){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

void insereAproveitamentonoAluno(aluno* oAluno, turma* aTurma){
    if(oAluno->aproveitamento==NULL){
        oAluno->aproveitamento=(aproveitamento*)malloc(sizeof(aproveitamento));
        (oAluno->aproveitamento)->frequencia=0.00;
        (oAluno->aproveitamento)->turma=aTurma;
        (oAluno->aproveitamento)->prox=NULL;
        return;
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
    return;
}

disciplina* buscaDisciplina(disciplina* listaDisciplinas, int cod){
    disciplina *aux=listaDisciplinas;
    while(aux!=NULL){
        if(aux->codigo==cod){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}