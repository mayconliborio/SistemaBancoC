//Professor

void inserirNotas(){

}

void alterarNotas(){

}

void inserirFrequencia(){

}

void alterarFrequencia(){

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