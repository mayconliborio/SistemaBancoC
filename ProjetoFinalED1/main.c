#include<stdio.h>
#include<string.h>
#include"aluno.c"

int verificaLogin(char login[80], char senha[80]){
    char loginProf[80]={"Professor"}, loginAlun[80]={"Student"}, loginGeren[80]={"Gerenciador"}, senhaGeral[80]={"BCC%20#19&*"};

    if(strcmp(senha, senhaGeral) != 0){
        return 0;
    }else{
        if(strcmp(login, loginAlun) == 0){
            return 1;
        }

        if(strcmp(login, loginProf) == 0){
            return 2;
        }

        if(strcmp(login, loginGeren) == 0){
            return 3;
        }
    }
}

int cadastroLogin(){
    FILE *alunos = fopen("alunos.txt", "w");

}

int main(){

    char login[80], senha[80];

    /*printf("BCC%%20#19&*");*/

    printf("Login: ");
    scanf("%s", &login);

    printf("Senha: ");
    scanf("%s", &senha);
    int a=verificaPrimAcesso(login, senha);

    if(a==0){
        printf("\n\nLogin e/ou Senha incorreto(s)!");
    }

    if(a == 1){
        printf("\n\nLogin de novo Aluno efetuado com sucesso! ");
        printf("Agora vamos cadastrar seu login proprio!\n\n");
        if(buscaAluno(listaAlunos, ra)!=NULL){
        printf("Novo Login: ");
        scanf("%s", &login);
        printf("Nova Senha: ");
        scanf("%s", &senha);
        }else{
            printf("RA nao encontrado, nao sera possivel concluir o cadastro!");
        }
    }
    if(a == 2){
        printf("\n\nLogin de novo Professor efetuado com sucesso! ");
        printf("Agora vamos cadastrar seu login proprio!\n\n");
        printf("Informe seu ra: ");
        scanf("%ud", &ra);     
        printf("Novo Login: ");
        scanf("%s", &login);
        printf("Nova Senha: ");
        scanf("%s", &senha);
        
    }
    if(a == 3){
        printf("\n\nLogin de novo Gerenciador efetuado com sucesso! ");
         printf("Agora vamos cadastrar seu login proprio!\n\n");
        printf("Novo Login: ");
        scanf("%s", &login);
        printf("Nova Senha: ");
        scanf("%s", &senha);
    }


}
