int verificaPrimLogin(char login[], char senha[]){
	char loginProf[80] = {"Professor"}, loginAlun[80] = {"Student"}, loginGeren[80] = {"Gerenciador"}, senhaGeral[80] = {"BCC%20#19&*"};

	if (strcmp(senha, senhaGeral) != 0){
		return 0;
	}
	else{
		if (strcmp(login, loginAlun) == 0){
			return 1;
		}

		if (strcmp(login, loginProf) == 0){
			return 2;
		}

		if (strcmp(login, loginGeren) == 0){
			return 3;
		}
	}
	return 0;
}

int verificaLogin(char login[], char senha[]){
	char login1[80], senha1[80];
	FILE *arq;

	arq = fopen("Login/loginAlunos.txt", "r");

	while (!feof(arq)){
		fscanf(arq, "%s %s\n", login1, senha1);
		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 1;
			}else{
				return 2;
			}
		}
	}
	fclose(arq);

	arq = fopen("Login/loginProfessores.txt", "r");

	while (!feof(arq)){
		fgets(senha1, 80, arq);
		fscanf(arq, "%s %s\n", login1, senha1);

		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 3;
			}else{
				return 4;
			}
		}
	}
	fclose(arq);

	arq = fopen("Login/loginGerenciadores.txt", "r");

	while (!feof(arq)){
		fscanf(arq, "%s %s\n", login1, senha1);
		if (strcmp(login1, login) == 0){
			if(strcmp(senha1, senha)==0){
				return 5;
			}else{
				return 6;
			}
		}
	}
	fclose(arq);
	return 0;
}

int cadastroLogin(int a, char nome[], char login[], char senha[]){
	FILE *arq;

	if (a == 1){
		int v=verificaLogin(login, senha);

		if(v==0){
			arq = fopen("Login/loginAlunos.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!");
				exit(1);
			}

			fprintf(arq, "%s %s\n", login, senha); 
			
			fclose(arq);
			return 0;
		}
		if(v==1 || v==2){
			return 1;
		}
		
	}

	if (a == 2){
		int v=verificaLogin(login, senha);

		if(v==0){
			arq = fopen("Login/loginProfessores.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!");
				exit(1);
			}

			fprintf(arq, "%s\n%s %s\n", nome, login, senha);

			fclose(arq);
			return 0;
		}
		if(v==3 || v==4){
			return 1;
		}
	}

	if (a == 3){
		int v=verificaLogin(login, senha);
		if(v==0){
			arq = fopen("Login/loginGerenciadores.txt", "a+");
			if (arq == NULL){
				printf("\n\nErro ao carregar arquivo!\n\nEncerrando o programa!");
				exit(1);
			}

			fprintf(arq, "%s %s\n", login, senha);

			fclose(arq);
			return 0;
		}
		if(v==5 || v==6){
			return 1;
		}
	}
}


char *cifraCesar(char string[]){
	int i=0;

	while (string[i] != '\0'){
		string[i] += (-3+i*i);
		i++;
	}

	return string;
}

char *cifraReversa(char string[]){
	int i=0;

	while (string[i] != '\0'){
		string[i] -= (-3+i*i);
		i++;
	}

	return string;
}

char *loginProfessor(char loginProfessor[], char senhaProfessor[]){
	FILE *arq = fopen("Login/loginProfessores.txt", "r");
	char nome[80], login[80], senha[80];

	if (arq == NULL){
		printf("\n\nErro ao carregar arquivo!");
		exit(1);
	}

	while(!feof(arq)){
		fscanf(arq, "%s\n%s %s\n", nome, login, senha);
		if(strcmp(loginProfessor, login)==0 && strcmp(senhaProfessor, senha)==0){
			return cifraReversa(nome);
		}
	}
	fclose(arq);
	return "...";
}

typedef struct login{
	char login[80];
	char senha[80];
	struct login *prox;
}login;

login *alocaLogin(){
	login *no=(login*)malloc(sizeof(login));
}

void insereLogin(login **lista, char log[], char sen[]){
	login *aux=(*lista);
	login *no=alocaLogin();

	strcpy(no->login, log);
	strcpy(no->senha, sen);
	no->prox=NULL;

	if((*lista)==NULL){
		(*lista)=no;
		return;
	}
	
	if(aux->prox!=NULL){
		aux=aux->prox;
	}

	aux->prox=no;
}

void carregaLogin(login **lista){
	FILE *arq=fopen("Login/loginAlunos.txt", "r");
	if(arq==NULL){
		exit(1);
	}

	char log[80], sen[80];

	while(!feof(arq)){
		fscanf(arq, "%s %s\n", log, sen);
		insereLogin(&(*lista), log, sen);
	}

	fclose(arq);
}

login *buscaLogin(login **lista, char log[], char sen[]){
	login *aux=(*lista);

	if(aux==NULL){
		return NULL;
	}

	while(aux!=NULL){
		if(strcmp(aux->login, log)==0 && strcmp(aux->senha, sen)==0){
			return aux;
		}
		aux=aux->prox;
	}
	return NULL;
}

void alteraLogin(login **lista, login *alt, char nov[]){
	if(alt==NULL){
		return;
	}
	strcpy(alt->senha, nov);
}

void salvaLogin(login **lista){
	FILE *arq=fopen("Login/loginAlunos.txt", "w");
	login *aux=(*lista);

	if(arq==NULL){
		exit(1);
	}

	if((*lista)==NULL){
		fclose(arq);
		return;
	}

	while(aux!=NULL){
		fprintf(arq, "%s %s\n", aux->login, aux->senha);
		aux=aux->prox;
	}

	fclose(arq);
}

void alterarSenha(char log[], char ant[], char nov[]){
	login *lista=NULL;

	carregaLogin(&lista);

	if(lista!=NULL){
		alteraLogin(&lista, buscaLogin(&lista, log, ant), nov);
		salvaLogin(&lista);
	}

}
