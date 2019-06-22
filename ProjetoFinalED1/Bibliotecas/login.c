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

	arq = fopen("loginAlunos.txt", "r");

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

	arq = fopen("loginProfessores.txt", "r");

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

	arq = fopen("loginGerenciadores.txt", "r");

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
			arq = fopen("loginAlunos.txt", "a+");
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
			arq = fopen("loginProfessores.txt", "a+");
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
			arq = fopen("loginGerenciadores.txt", "a+");
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
		string[i] += (i + 1);
		i++;
	}

	return string;
}

char *cifraReversa(char string[]){
	int i=0;

	while (string[i] != '\0'){
		string[i] -= (i + 1);
		i++;
	}

	return string;
}
