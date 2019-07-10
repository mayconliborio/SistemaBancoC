//Gerenciador

void excluirAluno(aluno **listaAlunos,char ra[11]){
    int j = strcasecmp((*listaAlunos)->ra,ra);
    if(j==0){
        aluno *aux=(*listaAlunos);
        (*listaAlunos)=(*listaAlunos)->prox;
        free(aux);
        return;
    }
    aluno *aux=(*listaAlunos);
    while(aux->prox!=NULL){
        j=strcasecmp((aux->prox)->ra,ra);
        if(j==0){
            aluno *aux2=aux->prox;
            aux->prox=aux2->prox;
            free(aux2);
            return;
        }
        aux=aux->prox;
    }
    printf("\nNão existe aluno com este RA!\n");
    return;
}


void excluirDisciplina(disciplina **listaDisciplinas, turma **listaTurmas, int cod){
    disciplina *aux=(*listaDisciplinas), *aux2;
    turma *aux3=(*listaTurmas);

    if(aux->codigo!=cod){
        aux2=aux;
        while(aux->prox!=NULL){
            if(aux->codigo==cod){
                break;
            }
            aux2=aux;
            aux=aux->prox;
        }
    }
    
    if(aux->prox==NULL){
        printf("Disciplina nao encontrada!");
        return;
    }

    while(aux3!=NULL){
        if(aux3->codigo==cod){
            return;
        }
        aux3=aux3->prox;
    }

    aux2->prox=aux->prox;
    free(aux);
}

void excluirTurma(turma **listaTurmas, aluno **listaAlunos, professor **listaProfessores, int cod){
    turma *aux=(*listaTurmas), *aux1;
    aluno *aux2=(*listaAlunos);
    aproveitamento *ap;
    professor *aux3=(*listaProfessores);

    if(aux->codigo!=cod){
        aux1=aux;
        while(aux->prox!=NULL){
            if(aux->codigo==cod){
                break;
            }
            aux1=aux;
            aux=aux->prox;
        }
    }
    if(aux->prox==NULL){
        printf("Turma nao encontrada!");
        return;
    }

    while(aux2!=NULL){
        ap=aux2->aproveitamento;
        while(ap!=NULL){
            if(ap->turma->codigo==cod){
                return;
            }
            ap=ap->prox;
        }
        aux2=aux2->prox;
    }

    while(aux3!=NULL){
        if(aux3->turmas==aux){
            return;
        }
        aux3=aux3->prox;
    }

    aux1->prox=aux->prox;
    free(aux);
}

void excluirProfessor(professor **listaProfessores, professor *oProfessor,turma **listaTurmas, char nome[80]){
    professor *aux=(*listaProfessores), *aux1;
    turma *aux2=(*listaTurmas);

    if(strcmp(aux->nome, nome)==0){
        aux1=aux;
        while(aux->prox!=NULL){
            if(strcmp(aux->nome, nome)==0){
                break;
            }
            aux1=aux;
            aux=aux->prox;
        }
    }

    while(aux2->prox!=NULL){
        if(aux2->professor==oProfessor);
        aux=aux->prox;
    }
    aux1->prox=aux->prox;
    free(aux);
    
}