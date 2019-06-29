//Professor

void inserirNotas(aluno *oAluno, float aNota, turma *aTurma, int ordemNota){
    int j;
    int n;
    for(j=0;j<45;j++){
        if((aTurma->alunos[j]!=NULL){
            n=strcasecmp((aTurma->alunos[j])->ra,oAluno->ra);
            if(n==0){
                    tipoAproveitamento *aux=oAluno->aproveitamento;
                     
                    while(aux!=NULL){
                        if((aux->turma)->codigo==aTurma->codigo)
                        {
                            aux->notas[ordemNota]=aNota;
                            return;
                        }
                        aux=aux->prox;
                    }            
            }
        }
    }
    printf("\nAluno não cadastrado nesta turma!\n");
}

void alterarNotas(aluno *oAluno, float novaNota,turma *aTurma,int ordemNota){
    int j;
    int n;
    for(j=0;j<45;j++){
        if((aTurma->alunos[j]!=NULL){
            n=strcasecmp((aTurma->alunos[j])->ra,oAluno->ra);
            if(n==0){
                    tipoAproveitamento *aux=oAluno->aproveitamento;
                     
                    while(aux!=NULL){
                        if((aux->turma)->codigo==aTurma->codigo)
                        {   if(aux->notas[ordemNota]!=-1){
                                aux->notas[ordemNota]=aNota;
                                return;
                            }
                            printf("\nA nota não existe para ser alterada!\n");
                            return;
                        }
                        aux=aux->prox;
                    }            
            }
        }
    }
    printf("\nAluno não cadastrado nesta turma!\n");
}

void inserirFrequencia(aluno *oAluno,turma *aTurma){
    int j;
    int n;
    for(j=0;j<45;j++){
        if((aTurma->alunos[j]!=NULL){
            n=strcasecmp((aTurma->alunos[j])->ra,oAluno->ra);
            if(n==0){
                    tipoAproveitamento *aux=oAluno->aproveitamento;
                     
                    while(aux!=NULL){
                        if((aux->turma)->codigo==aTurma->codigo)
                        {
                            (aux->frequencia)++;
                            return;
                        }
                        aux=aux->prox;
                    }            
            }
        }
    }
    printf("\nAluno não cadastrado nesta turma!\n");
}

void alterarFrequencia(aluno *oAluno,turma *aTurma, float novaFrenquencia){
    int j;
    int n;
    for(j=0;j<45;j++){
        if((aTurma->alunos[j]!=NULL){
            n=strcasecmp((aTurma->alunos[j])->ra,oAluno->ra);
            if(n==0){
                    tipoAproveitamento *aux=oAluno->aproveitamento;
                     
                    while(aux!=NULL){
                        if((aux->turma)->codigo==aTurma->codigo)
                        {
                            (aux->frequencia)=novaFrequencia;
                            return;
                        }
                        aux=aux->prox;
                    }            
            }
        }
    }
    printf("\nAluno não cadastrado nesta turma!\n");
}

void desempenhoAlunoSemestre(){

}

void desempenhoTurmaSemestre(){

}

void alunosAprovadosPorDisciplina(){

}

void alunosReprovadosPorDisciplina(){

}

void relatorioCompleto(){
	
}

professor* buscaProfessor(professor* listaProfessores, char nome[80]){
    professor *aux=listaProfessores;
    int j=5;
    while(aux!=NULL){
        j=strcasecmp(aux->nome,nome);
        if(j==0){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}