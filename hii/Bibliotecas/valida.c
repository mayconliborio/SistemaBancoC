int validaNome(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if( (x >= 65 && x <= 90 ) || (x >= 97 && x <= 122) || x==32){
			i++;
		}else
		return 1;
	}
	return 0;
}

int validaLogin(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if( (x >= 65 && x <= 90 ) || (x >= 97 && x <= 122) || (x >= 48 && x <= 57)){
			i++;
		}else
		return 1;
	}
	return 0;
}

int validaSenha(char string[]){
	int i=0;

	while(string[i]!='\0'){
		int x=(int)string[i];
		if(x<33 || x>126){
			return 1;
		}
		i++;
	}
	return 0;
}

char corrigeString(char string[]){
	int x=strlen(string)-1;
	if(string[x]=='\n'){
		string[x]='\0';
	}
}

void limpaBuffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}