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

void desempenhoAlunoSemestre(aluno *oAluno,turma *aTurma){
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
                            if(aux->notas[0]==-1||aux->notas[1]==-1||aux->notas[2]==-1){
                                printf("\nDesempenho do aluno não concluido!\n");
                                return;
                            }
                            printf("\nNota1:%f\n",aux->notas[0]);
                            printf("\nNota2:%f\n",aux->notas[1]);
                            printf("\nNota3:%f\n",aux->notas[2]);
                            
                            return;
                        }
                        aux=aux->prox;
                    }            
            }
        }
    }
    printf("\nAluno não cadastrado nesta turma!\n");

}

void desempenhoTurmaSemestre(turma *aTurma){
       
    int i;
    for(i=0;i<45;i++){
        if((aTurma->alunos[i])!=NULL){
            aproveitamento *aux=(aTurma->alunos[i])->aproveitamento;
            aproveitamento *aux2=NULL;
            while(aux->prox!=NULL){
                if((aux->turma)->codigo==aTurma->codigo){
                    printf("\nTurma encontrada\n");
                    aux2=aux;
                }
                aux=aux->prox;
            }
            if(aux2==NULL){
                printf("\nAluno não possui um aproveitamento com esta turma!\n");
                return;
            }
            printf("\nNota do aluno: %sProva1:%f\nProva2:%f\nProva3:%f",
            (aTurma->alunos[i])->nome,
            (aux2->notas[0],aux2->notas[1],aux2->notas[3]);
        }
        else{
            printf("\nFim de Turma\n");
            return;           
        }
        
    }

}

void alunosAprovadosPorDisciplina(turma *aTurma){
    int i;
    for(i=0;i<45;i++){
        if((aTurma->alunos[i])!=NULL){
            aproveitamento *aux=(aTurma->alunos[i])->aproveitamento;
            aproveitamento *aux2=NULL;
            while(aux->prox!=NULL){
                if((aux->turma)->codigo==aTurma->codigo){
                    printf("\nTurma encontrada\n");
                    aux2=aux;
                }
                aux=aux->prox;
            }
            if(aux2==NULL){
                printf("\nAluno não possui um aproveitamento com esta turma!\n");
                return;
            }
            if(aux2->notas[0]==-1||aux2->notas[1]==-1||aux2->notas[2]==-1){
                printf("\nAluno com notas incompletas!\n");
            }
            else{
                float m=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3;
                if(m>=6){
                    printf("\nAluno: %sAprovado!\n",(aTurma->alunos[i])->nome);
                }
               
            }
        }
        else{
            printf("\nFim de Turma\n");
            return;           
        }
        
    }

}

void alunosReprovadosPorDisciplina(turma *aTurma){
    int i;
    for(i=0;i<45;i++){
        if((aTurma->alunos[i])!=NULL){
            aproveitamento *aux=(aTurma->alunos[i])->aproveitamento;
            aproveitamento *aux2=NULL;
            while(aux->prox!=NULL){
                if((aux->turma)->codigo==aTurma->codigo){
                    printf("\nTurma encontrada\n");
                    aux2=aux;
                }
                aux=aux->prox;
            }
            if(aux2==NULL){
                printf("\nAluno não possui um aproveitamento com esta turma!\n");
                return;
            }
            if(aux2->notas[0]==-1||aux2->notas[1]==-1||aux2->notas[2]==-1){
                printf("\nAluno com notas incompletas!\n");
            }
            else{
                float m=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3;
                if(m<6){
                    printf("\nAluno: %sReprovado!\n",(aTurma->alunos[i])->nome);
                }
               
            }
        }
        else{
            printf("\nFim de Turma\n");
            return;           
        }
        
    }

}

void relatorioCompleto(turma *aTurma){
    int i;
    for(i=0;i<45;i++){
        if((aTurma->alunos[i])!=NULL){
            aproveitamento *aux=(aTurma->alunos[i])->aproveitamento;
            aproveitamento *aux2=NULL;
            while(aux->prox!=NULL){
                if((aux->turma)->codigo==aTurma->codigo){
                    printf("\nTurma encontrada\n");
                    aux2=aux;
                }
                aux=aux->prox;
            }
            if(aux2==NULL){
                printf("\nAluno não possui um aproveitamento com esta turma!\n");
                return;
            }
            if(aux2->notas[0]==-1||aux2->notas[1]==-1||aux2->notas[2]==-1){
                printf("\nAluno: %scom notas incompletas!\n",(aTurma->alunos[i])->nome);
            }
            else{
                float m=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3;
                if(m>=6){
                    printf("\nNota do aluno: %sProva1:%f\nProva2:%f\nProva3:%f",
                    (aTurma->alunos[i])->nome,
                    (aux2->notas[0],aux2->notas[1],aux2->notas[3]);
                    printf("\nFrequencia do aluno: %s%f horas aulas assistidas\n",(aTurma->alunos[i])->nome,aux2->frequencia);
                    printf("\nAluno: %s aprovado!\n",(aTurma->alunos[i])->nome);
                }
                else{
                    printf("\nNota do aluno: %sProva1:%f\nProva2:%f\nProva3:%f",
                    (aTurma->alunos[i])->nome,
                    (aux2->notas[0],aux2->notas[1],aux2->notas[3]);
                    printf("\nFrequencia do aluno: %s%f horas aulas assistidas\n",(aTurma->alunos[i])->nome,aux2->frequencia);
                    printf("\nAluno: %s reprovado!\n",(aTurma->alunos[i])->nome);
                }
               
            }
        }
        else{
            printf("\nFim de Turma\n");
            return;           
        }
        
    }
	
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