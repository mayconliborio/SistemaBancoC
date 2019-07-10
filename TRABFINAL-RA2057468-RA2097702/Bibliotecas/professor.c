//Professor

void inserirNotas(aproveitamento *oAproveitamento, float *aNota){

    for(int i=0; i<3; i++){ 
        if(oAproveitamento->notas[i]==-1){
            oAproveitamento->notas[i]=aNota[i];
        }
        else{
            printf("Nota ja inserida!\nPara alterar uma nota selecione a opçao correta no menu!");
            break;
        }
    }

}

void alterarNotas(aproveitamento *oAproveitamento, float *novaNota){

    for(int i=0; i<3; i++){ 
        if(oAproveitamento->notas[i]!=-1){
            oAproveitamento->notas[i]=novaNota[i];
        }else{
            printf("Insira uma nota antes de altera-la!");
            break;
        }
    }

}

void inserirFrequencia(aproveitamento *oAproveitamento, float aFrequencia){

    if(oAproveitamento->frequencia==0.0){
        oAproveitamento->frequencia=aFrequencia;
    }
    else{
        printf("Frequencia ja inserida!\nPara alterar a frequencia selecione a opçao correta no menu!");
    }

}

void alterarFrequencia(aproveitamento *oAproveitamento, float novaFrequencia){

    if(oAproveitamento->frequencia!=0.0){
        oAproveitamento->frequencia=novaFrequencia;
    }else{
        printf("Insira uma frequencia antes de altera-la!");
    }
}

void desempenhoAlunoSemestre(aluno *oAluno, int ano, char semestre){
    aproveitamento *aux;
    int cont=0;

    printf("%s\n", oAluno->nome);
    aux=oAluno->aproveitamento;

    while(aux!=NULL){
        float media;
        char sitAluno[15];
        if(aux->turma->ano==ano && aux->turma->semestre==semestre){

            media=(aux->notas[0]+aux->notas[1]+aux->notas[2])/3.0;

            if(media>=6){
                strcpy(sitAluno, "Aprovado");
            }else{
                strcpy(sitAluno, "Reprovado");
            }

            printf("%s %d\n%.2f %s\n\n", aux->turma->disciplina->nome, aux->turma->ano, media, sitAluno);
            cont++;
        }
        aux=aux->prox;
    }
    if(cont==0){
        printf("Nenhuma disciplina cursada no ano/semestre informado");
    }
    cont=0;
}


void desempenhoTurmaSemestre(turma *listaTurmas, int cod, int ano, char semestre){
    turma *aux=listaTurmas;
    aproveitamento *aux2;
    int j=0;

    while(aux!=NULL){
        if(aux->situacao!='P' && aux->codigo==cod && aux->ano==ano && aux->semestre==semestre){
            break;
        }
        aux=aux->prox;
    }

    if(aux!=NULL){
        while(aux->alunos[j]!=NULL){
            aux2=aux->alunos[j]->aproveitamento;
            while(aux2!=NULL){
                if(aux2->turma==aux){
                    break;
                }
                aux2=aux2->prox;
            }
            if(aux2!=NULL){
                char sitAluno[15];
                float media=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3.0;

                if(media>=6){
                    strcpy(sitAluno, "Aprovado");
                }else{
                    strcpy(sitAluno, "Reprovado");
                }
                printf("%s %.2f %s\n\n",aux->alunos[j]->nome, media, sitAluno);
            }
            j++;
        }
    }else{
        printf("Nao ha dados a serem apresentados!");
    }
}

void alunosAprovadosPorDisciplina(aluno *listaAlunos, turma *listaTurmas, professor *oProfessor){
    aluno *aux=listaAlunos;
    aproveitamento *aux2;
    turma *aTurma=listaTurmas;

    while(aTurma!=NULL){
        if(aTurma->professor==oProfessor){
            printf("%s\n\n", aTurma->disciplina->nome);
            while(aux!=NULL){
                aux2=aux->aproveitamento;
                while(aux2!=NULL){
                    if(aux2->turma==aTurma){
                        float media=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3.0;
                        if(media>=6.0){
                            printf("%s %.2f\n", aux->nome, media);
                        }
                    }
                    aux2=aux2->prox;
                }
                aux=aux->prox;
            }
            printf("\n");
        }
        aTurma=aTurma->prox;
    }
}

void alunosReprovadosPorDisciplina(aluno *listaAlunos, turma *listaTurmas, professor *oProfessor){
    aluno *aux=listaAlunos;
    aproveitamento *aux2;
    turma *aTurma=listaTurmas;

    while(aTurma!=NULL){
        if(aTurma->professor==oProfessor){
            printf("%s\n\n", aTurma->disciplina->nome);
            while(aux!=NULL){
                aux2=aux->aproveitamento;
                while(aux2!=NULL){
                    if(aux2->turma==aTurma){
                        float media=(aux2->notas[0]+aux2->notas[1]+aux2->notas[2])/3.0;
                        if(media<6.0){
                            printf("%s %.2f\n", aux->nome, media);
                        }
                    }
                    aux2=aux2->prox;
                }
                aux=aux->prox;
            }
            printf("\n");
        }
        aTurma=aTurma->prox;
    }
}

void relatorioCompleto(turma *listaTurmas, professor *oProfessor){
    turma *aTurma=listaTurmas;

    while(aTurma!=NULL){
        if(aTurma->professor==oProfessor){
            printf("%s ano: %d semestre: %c\n\n", aTurma->disciplina->nome, aTurma->ano, aTurma->semestre);
        }
        aTurma=aTurma->prox;
    }
}


professor* buscaProfessor(professor* listaProfessores, char nome[80]){
    professor *aux=listaProfessores;

    while(aux!=NULL){
        if(strcmp(aux->nome, nome)==0){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}