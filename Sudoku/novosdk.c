#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include "colors.h"
//#include <conio.c>
// M: falta arrumar um erro que ALGUMAS VEZES aparece e manda todos os elementos pra uma casa depois (precisamos achar o padrão de quando isso acontece)
// M: Só coloquei esse comentario aqui porque com certeza vão mecher nessa parte haha 

#define TAMANHO 9


void Controla_tempo(int tempo, int escolha, char user[20]){
        FILE *p;
        int atualx = 0, atualy = 0, selecaolateral = 0;	        
        int aux_tempo_01, aux_tempo_02,aux_tempo_03;
        char aux_tempostr_01[20], aux_tempostr_02[20], aux_tempostr_03[20], nome01[100], nome02[100], nome03[100];
        printf("/nO seu tempo foi de:\t %i:%i\n", tempo / 60, tempo % 60);
        switch(escolha){
                        case 1:
                                p = fopen("temposfacil.txt", "r");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                        }
                                break;
                        case 2:
                                p = fopen("temposmedio.txt", "r");
                                if(p == NULL){

                                         printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 3:
                                p = fopen("temposdificil.txt", "r");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 4:
                                p = fopen("temposterrivel.txt", "r");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 0:
                                p = fopen("temposMeuSudoku.txt", "r");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempos\n");
                                        exit(1);
                                }
                                break;
                }
                if(escolha != 5){
                        fgets(aux_tempostr_01, 20, p);
                        fgets(nome01, 100, p);
                        fgets(aux_tempostr_02, 20, p);
                        fgets(nome02, 100, p);
                        fgets(aux_tempostr_03, 20, p);
                        fgets(nome03, 100, p);
                        aux_tempo_01 = atoi(aux_tempostr_01);
                        aux_tempo_02 = atoi(aux_tempostr_02);
                        aux_tempo_03 = atoi(aux_tempostr_03);
                        fclose(p);
                }
                switch(escolha){
                        case 1:
                                p = fopen("temposfacil.txt", "w");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                        }
                                break;
                        case 2:
                                p = fopen("temposmedio.txt", "w");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 3:
                                p = fopen("temposdificil.txt", "w");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 4:
                                p = fopen("temposterrivel.txt", "w");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempo\n");
                                        exit(1);
                                }
                                break;
                        case 0:
                                p = fopen("temposMeuSudoku.txt", "w");
                                if(p == NULL){
                                        printf("Erro ao abrir arquivo de tempos\n");
                                        exit(1);
                                }
                }
                if(escolha != 5){
                        if (aux_tempo_01 == 0){
                                aux_tempo_01 = tempo;
                                strcpy(nome01, user);
                        }
                        else if(aux_tempo_02 == 0){
                                if(tempo < aux_tempo_01){
                                        aux_tempo_02 = aux_tempo_01;
                                        strcpy(nome02, nome01);
                                        aux_tempo_01 = tempo;
                                        strcpy(nome01, user);
                                }
                                else{    
                                        aux_tempo_02 = tempo;
                                        strcpy(nome02, user);
                                }
                        }
                        else if(aux_tempo_03 == 0){
                                if(tempo < aux_tempo_01){
                                        aux_tempo_03 = aux_tempo_02;
                                        strcpy(nome03, nome02);
                                        aux_tempo_02 = aux_tempo_01;
                                        strcpy(nome02, nome01);
                                        aux_tempo_01 = tempo;
                                        strcpy(nome01, user);
                                }
                                else if(tempo < aux_tempo_02){
                                        aux_tempo_03 = aux_tempo_02;
                                        strcpy(nome03, nome02);
                                        aux_tempo_02 = tempo;
                                        strcpy(nome02, user);
                                }
                                else{ 
                                        aux_tempo_03 = tempo;
                                        strcpy(nome03, user);
                                }
                        }
                        else if(tempo < aux_tempo_01){
                                aux_tempo_03 = aux_tempo_02;
                                strcpy(nome03, nome02);
                                aux_tempo_02 = aux_tempo_01;
                                strcpy(nome02, nome01);
                                aux_tempo_01 = tempo;
                                strcpy(nome01, user);
                        }
                        else if(tempo < aux_tempo_02){
                                aux_tempo_03 = aux_tempo_02;
                                strcpy(nome03, nome02);
                                aux_tempo_02 = tempo;
                                strcpy(nome02, user);
                        }
                        else if(tempo < aux_tempo_03){
                                aux_tempo_03 = tempo;
                                strcpy(nome03, user);
                        }
                        else printf("Lamento %s\tMas o seu tempo nao entrou no RANKING\n", user);
                        sprintf(aux_tempostr_01, "%i", aux_tempo_01);
                        sprintf(aux_tempostr_02, "%i", aux_tempo_02);
                        sprintf(aux_tempostr_03, "%i", aux_tempo_03);
                        fputs(aux_tempostr_01, p);
                        fputc('\n', p);
                        fputs(nome01, p);
                        fputs(aux_tempostr_02, p);
                        fputc('\n', p);
                        fputs(nome02, p);
                        fputs(aux_tempostr_03, p);
                        fputc('\n', p);
                        fputs(nome03, p);
                        fclose(p);
                }
                if(escolha == 5){
                        system("cls");
                        printf("Jogo continuado");
                }
}

void Zerar_matriz(int m[TAMANHO][TAMANHO]){              // M: n=9
        int i, j;
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        m[i][j] = 0;
}

void Informacao_vazia(char informacao[45]){
        int i;
        for(i=0; i<44 ; i++)
                informacao[i]=' ';
}

int Pronto(int m[TAMANHO][TAMANHO]){
        int i, j;
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        if(m[i][j] == 0)
                                return 0;
        return 1;         
}
void resolver(char resolucao[81]){
        int matriz[9][9],posicaoPreenchida[9][9],verificacao_linha=1,verificacao_coluna=1,verificacao_submatriz=1,flag=1,i,j,k,l;
        FILE *p;
//transforma a matriz char em inteira
        for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                        matriz[i][j] = toascii(resolucao[9*i+j]) - 48;
                if(matriz[i][j]==0){
                        posicaoPreenchida[i][j]=0;
                }else{
                        posicaoPreenchida[i][j]=1;
            }
        }
    }

//verifica se tem erro e resolve coloca em uma função diferente 
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(posicaoPreenchida[i][j]==0){
                do{
                    flag = 0;
                    while((verificacao_linha==1 || verificacao_coluna==1 || verificacao_submatriz==1) && matriz[i][j]<=9){
                        verificacao_linha=0; verificacao_coluna=0; verificacao_submatriz=0;
                        matriz[i][j]++;
                        for(k=0;k<9;k++){
                            if(k!=j && matriz[i][j]==matriz[i][k]){
                                verificacao_linha=1;
                                break;
                            }
                        }

                        if(verificacao_linha==0){
                            for(l=0;l<9;l++){
                                if(l!=i && matriz[i][j]==matriz[l][j]){
                                    verificacao_coluna=1;
                                    break;
                                }
                            }
                        }

                        if(verificacao_linha==0 && verificacao_coluna==0){
                            for(k=0;k<9;k++){
                                for(l=0;l<9;l++){
                                    if(k!=j && l!=i && (10*(i/3)+j/3==10*(l/3)+k/3) && matriz[i][j]==matriz[l][k]){
                                        verificacao_submatriz=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    verificacao_linha = 1;
                    verificacao_coluna = 1;
                    verificacao_submatriz = 1;

                    if(matriz[i][j]>9){
                        matriz[i][j]=0;
                        do{
                            j--;
                            if(j<0){
                                j=8; i--;
                            }
                        }while(posicaoPreenchida[i][j]==1);
                        flag=1;
                    }
                }while(flag==1);
            }
        }
    }
//parte da resolução final indo para o arquivo
    p = fopen("resolucao.txt","w");
    k = 0;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++,k++){
            resolucao[k] = matriz[i][j] + 48;
        }
    }

    fputs(resolucao,p);
    fflush(p);
    fclose(p);
}

int Verificar(int Sudoku[TAMANHO][TAMANHO]){
         int i, j, teste_i, teste_j, ti, tj;
        for(i=0; i<TAMANHO; i++){
                for(j=0; j<TAMANHO; j++){
                        // D: Essa parte testa os se os elemntos dos quadrados 3x3 são iguais
                        if(i%3 == 0 && j%3 == 0){
                                teste_i = i;
                                teste_j = j;
                                ti = teste_i;
                                tj = teste_j;
                                for(; teste_i<i+3; teste_i++)
                                        for(; teste_j<j+3; teste_j++)
                                                for(; ti<i+3; ti++)
                                                        for(; tj<j+3; tj++){
                                                                if(ti != teste_i || tj != teste_j){
                                                                        if(Sudoku[ti][tj] != 0 && Sudoku[teste_i][teste_j] != 0){
                                                                                if(Sudoku[ti][tj] == Sudoku[teste_i][teste_j])
                                                                                        return 0;
                                                                                else continue;
                                                                        }else continue;
                                                                }
                                                        }
                        }
                        // D: Esse parte testa se os elementos nas mesmas linhas são iguais
                        if(i == 0){    
                                for(teste_i=0; teste_i<TAMANHO; teste_i++)
                                        for(ti=teste_i+1; ti<TAMANHO; ti++){
                                                if(Sudoku[ti][j] != 0 && Sudoku[teste_i][j] != 0){
                                                        if(Sudoku[ti][j] == Sudoku[teste_i][j])
                                                                return 0;
                                                        else continue;
                                                }else continue;
                                        }
                        }
                        // D: Essa parte testa se os elementos em uma mesma coluna são iguais
                        if(j == 0){
                                for(teste_j=0; teste_j<TAMANHO; teste_j++)
                                        for(tj=teste_j+1; tj<TAMANHO; tj++){
                                                if(Sudoku[i][tj] != 0 && Sudoku[i][teste_j] != 0){
                                                        if(Sudoku[i][tj] == Sudoku[i][teste_j])
                                                                return 0;
                                                        else continue;
                                                } else continue;
                                        }
                        }
                }
        }
        return 1;
}

void Tela_inicial(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char user[20]);
void Tela_entrar(int matriz_original[9][9], int matriz_final[9][9], char user[20]);

void Imprime_login(char user[20], int tamanho_senha){
		system("cls");
        int i;
        char strsenha[20]="                  ";
        for(i=0; i<tamanho_senha; i++)
        	strsenha[i]='*';
        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c\n"
                ,201,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205,
                205,205,205,205,205,187);

        printf("%c\t\t\t\t   %c\n%c\tLogin:\t\t\t   %c\n",186,186,186,186);
        printf("%c  Usu%crio: %s    %c\n",186,160,user,186);
        printf("%c  Senha: %s \t   %c\n",186,strsenha,186);
              

        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                ,200,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,188);

        setbuf(stdin,NULL);
}

void Tela_login(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char userk[20]){
        int i=0, posicao=0,existe=0;
        char user[20]="                   ", senha[20]="                   ",userArq[20],senhaArq[20];
        
        unsigned char tecla;
        Imprime_login(user,0);
        FILE *p,*s;
		while((tecla=getch()) != 13){
				if(tecla == 8 && i >= 0){
                	i--;
                	user[i]=' ';
                }else{
	                user[i] = tecla;
	                setbuf(stdin,NULL);
	                i++;
	            }
                Imprime_login(user,0);
        }
        tecla=1;
        setbuf(stdin,NULL);
        i=0;
        while((tecla=getch()) != 13){           
                if(tecla == 8 && i >= 0){
                	i--;
                	senha[i]=' ';
                }
				else{
					senha[i] = tecla;
					i++;
				}
				Imprime_login(user,i);
				setbuf(stdin,NULL);
        }
        
        p = fopen("usuarios.txt","r");
        s = fopen("senhas.bin","rb");
        if(p == NULL || s == NULL){
                printf("Erro ao abrir o arquivo!");
                exit(1);
        }
        while(!feof(p)){
                fgets(userArq,20,p);
                if((strcmp(user,userArq)) == 0){
                        posicao++;
                        existe++;
                        break;
                }else{
                        i++;
                        if(i==2){
                                posicao++;
                                i=0;
                        }
                }
        }
        if(existe == 0){
                printf("\nUsuario nao cadastrado!");
                Sleep(1000);
                Tela_entrar(matriz_original,matriz_final,user);               
        }
        while(!feof(s)){
                fread(senhaArq,sizeof(char),20,s);
                posicao--;
                if(posicao == 0){
                        if((strcmp(senha, senhaArq)) == 0){
                                Tela_inicial(matriz_original, matriz_final,user);
                        }else{
                                printf("\n\nSenha incorreta.Tente Novamente!");
                                Sleep(1000);
                                Tela_login(matriz_original,matriz_final,userk);
                        }
                }
        }
        fclose(p);
        fclose(s);
        printf("\n%c\n",200);
}

void Imprime_cadastro(char user[20], int tamanho_senha, int tamanho_confirm){
	system("cls");
	int i;
	char strsenha[20]="                  ", strconfirm[20]="                  ";
	for(i=0; i<tamanho_senha; i++)
		strsenha[i]='*';
	for(i=0; i<tamanho_confirm; i++)
		strconfirm[i]='*';
	printf( "%c%c%c%c%c%c%c%c%c%c"
			"%c%c%c%c%c%c%c%c%c%c%c%c%c"
			"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
			,201,205,205,205,205,205,205,205,205,205
			,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
			,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	
	printf("%c\t\t\t\t\t%c\n%c\tCadastro\t\t\t%c\n",186,186,186,186);
	printf("%c  Usu%crio: %s\t\t%c\t\n",186,160,user,186);
	printf("%c  Senha: %s \t\t%c\n",186,strsenha,186);
	printf("%c  Confirmar senha: %s  %c\n",186,strconfirm,186);
	
	printf( "%c%c%c%c%c%c%c%c%c%c"
			"%c%c%c%c%c%c%c%c%c%c"
			"%c%c%c%c%c%c%c%c%c%c"
			"%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			,200,205,205,205,205,205,205,205,205,205
			,205,205,205,205,205,205,205,205,205,205
			,205,205,205,205,205,205,205,205,205,205
			,205,205,205,205,205,205,205,205,205,205,188);
			
	setbuf(stdin,NULL);
}

void Tela_cadastro(int matriz_original[9][9], int matriz_final[9][9], char user[20]){
	int i=0, tamanho_senha=0;
	char senha[20]="                   ",confirmar[20]="                   ",userArq[20];
	unsigned char tecla;
        FILE *p;
	p = fopen("usuarios.txt","a+");
        if(p == NULL){
                printf("Erro ao abrir o arquivo!");
                exit(1);
        }
	
	strcpy(user,"                   ");
	Imprime_cadastro(user,0,0);
	
	while((tecla=getch()) != 13){
			if(tecla == 8 && i >= 0){
            	i--;
            	user[i]=' ';
            }else{
                user[i] = tecla;
                setbuf(stdin,NULL);
                i++;
            }
            Imprime_cadastro(user,0,0);
    }
    
    tecla=1;
    setbuf(stdin,NULL);
    i=0;
    while((tecla=getch()) != 13){           
            if(tecla == 8 && tamanho_senha >= 0){
            	tamanho_senha--;
            	senha[tamanho_senha]=' ';
            }
			else{
				senha[tamanho_senha] = tecla;
				tamanho_senha++;
			}
			Imprime_cadastro(user,tamanho_senha,0);
			setbuf(stdin,NULL);
    }
    if ((strcmp(senha,"                   ") == 0)) senha[0]='\0';
    
    if(senha[0]== '\0'){
    	system("cls");
        printf("\nPrecisa-se de uma senha para continuar.Tente novamente!");
        Sleep(2000);
        Tela_cadastro(matriz_original,matriz_final,user);
    }
        
	tecla = 1,i=0;
	
	while((tecla=getch()) != 13){           
            if(tecla == 8 && i >= 0){
            	i--;
            	confirmar[i]=' ';
            }
			else{
				confirmar[i] = tecla;
				i++;
			}
			Imprime_cadastro(user,tamanho_senha,i);
			setbuf(stdin,NULL);
    }
	

	
	//printf("\n%c\n",200);
                
	if(strcmp(senha, confirmar) == 0){
                p = fopen("usuarios.txt","a+");
                if(p == NULL){
                        printf("Erro ao abrir o arquivo!");
                        exit(1);
                }
                while(!feof(p)){
                        fgets(userArq,20,p);
                        if((strcmp(userArq,user))==0){
                                printf("\nUsuario ja cadastrado!");
                                Sleep(1000);
        			strcpy(user,"Login / Sair       ");
                                Tela_inicial(matriz_original,matriz_final,user);
                        }
                }
                fputs(user,p);
                fputs("\n",p);
                fflush(p);
                fclose(p);
                p = fopen("senhas.bin","a+b");
                if(p == NULL){
                        printf("Erro ao abrir o arquivo!");
                        exit(1);
                }
                fwrite(confirmar,sizeof(char),20,p);
                
                fclose(p);
		Tela_inicial(matriz_original, matriz_final,user);
	}else{
                printf("\n\tErro ao fazer o cadastro\n %c Tentar novamente\n",175);  
                while(1){
                     tecla=getch(); 
                     if(tecla == 13){
                             strcpy(user,"Login / Sair       ");
                             Tela_cadastro(matriz_original, matriz_final, user);
                     }

                }
		 
	}

	
}

void Imprime_entrar(int escolha){
        system("cls");
        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c\n"
        ,201,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205,
        205,205,187);

        printf(	"%c\t\t\t\t%c\n%c\tBem Vindo!\t\t%c\n",186,186,186,186);
        printf(	"%c \t%c Login\t\t\t%c\n"
                "%c \t%c Cadastro\t\t%c\n"    
                "%c\t\t\t\t%c\n"
                ,186,(escolha==1)?175:32,186,186,(escolha==2)?175:32,186,186,186);

        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c\n"
                ,200,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,188);	
}

void Tela_entrar(int matriz_original[9][9], int matriz_final[9][9], char user[20]){
	int escolha=1;
	unsigned char tecla;
	system("cls");
	Imprime_entrar(escolha);
	while((tecla=getch()) != 13){        
		
                if(tecla == 80) escolha++;              // M: Seta para cima
                if(tecla == 72) escolha--;              // M: Seta para baixo

                if(escolha == 3) escolha = 1;           // M: Retorno
                if(escolha == 0) escolha = 2;
                Imprime_entrar(escolha);
        	
    }  
    
	if(escolha == 1)
		Tela_login(matriz_original, matriz_final, user);
	else
		Tela_cadastro(matriz_original, matriz_final, user);
		
}

void Matriz_Resolucao(int matriz_resolucao[TAMANHO][TAMANHO]){
        int i,j;
        char c;
        FILE *p;
        p = fopen("resolucao.txt","r");
        if(p == NULL){
                printf("Erro ao abrir o arquivo");
                exit(1);
        }else{
                for(i=0;i<TAMANHO;i++){
                        for(j=0;j<TAMANHO;j++){
                                c = fgetc(p);
                                matriz_resolucao[i][j] = (int)(c - 48);
                        }
                }
        }
        fclose(p);
}

void Imprime_tabuleiro(int m[TAMANHO][TAMANHO], int matriz_original[TAMANHO][TAMANHO], int atualx, int atualy, char informacao[45], int opcoes, char user[20]){
        int i, j, matriz_resolucao[TAMANHO][TAMANHO];
        char resolucao[81],c;
        Matriz_Resolucao(matriz_resolucao);
        if(opcoes == 0)Zerar_matriz(matriz_resolucao);
        system("cls");
	printf("\n\n\n\n");
        foreground(BLUE);
        printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,187); 
        style(RESETALL);
        for(i=0; i<TAMANHO; i++){
                foreground(BLUE);
                printf("\n\t%c ",186);                            // M: pimeiro elemento das linhas que tÃªm numeros
                style(RESETALL);
                for(j=0; j<TAMANHO; j++){
                        if(i == atualy && j == atualx){          // M: Se a posicÃ£o atual for o local do quadradinho
                               foreground(YELLOW);
                               if(m[i][j]!=0) printf("%c ",m[i][j]+48);
                               else printf("%c ",219);
                               style(RESETALL);     
                        }         
                        else if(m[i][j] == 0)                   // M: Se a posiÃ§Ã£o estiver vazia (zero), mostra um espaÃ§o
                                printf("%c ",32);               
                         else if(m[i][j]==matriz_original[i][j]){
                                foreground(BLUE);
                                printf("%c ",m[i][j]+48);       // M: Se nÃ£o, mostra o nÃºmero
                                style(RESETALL);
                        } 
                        else if(m[i][j] !=matriz_resolucao[i][j]){
                                foreground(RED);
                                printf("%c ",m[i][j]+48);
                                style(RESETALL);
                        }else{
                                foreground(GREEN);
                                printf("%c ",m[i][j]+48);
                                style(RESETALL);
                        }       
                        foreground(BLUE);
                        if(j == 2 || j == 5 || j == 8)                    // M: Aqui vai a "divisÃ£o vertical"
                                printf("%c ",186);
                        else
                                printf("%c ",179);
                        style(RESETALL);
                }

                /*
                if(opcoes == 0) quando as opÃ§oes se referem ao preenchimento da matriz original
                if(opcoes == 1) quando as opÃ§oes se referem ao preenchimento da matriz de jogo
                */
                if(i == 1)
                        printf("\t\t\t%c Verificar (Atalho: v)",(atualx == 9 && atualy == 0)?175:32);
                if(i == 2)
                        printf("\t\t\t%c Fim (Atalho: f)",(atualx == 9 && atualy == 1)?175:32);
                if(i == 3)
                        printf("\t\t\t%c Voltar",(atualx == 9 && atualy == 2)?175:32);
                
                if(i == 2 || i == 5){ 
                        foreground(BLUE);                           // M: Ao final da 3Â° linha e da 5Â°, irÃ¡ mostar esta linha "divisÃ£o horizontal"
                        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,185);
                        style(RESETALL);
                }else if(i != 8){
                        foreground(BLUE);
                        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",186,196,196,196,197,196,196,196,197,196,196,196,186,196,196,196,197,196,196,196,197,196,196,196,186,196,196,196,197,196,196,196,197,196,196,196,186);              
                style(RESETALL);
        }
        }
        foreground(BLUE);
        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,188); 
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c  %c %s %c",186,(strcmp(user,"Login / Sair       " ) == 0)?175:32,user,186);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        style(RESETALL);


}

void Preencher_matriz(int m[TAMANHO][TAMANHO], int m_teste[TAMANHO][TAMANHO], char informacao[45], int opcoes, char user[20], int escolha){             
        style(RESETALL);
        int atualx = 0, atualy = 0, selecaolateral = 0, tempo, i, j, x = 0;
        unsigned char tecla;
        FILE *p;
        char userArq[50], v;
        clock_t tempo_gasto;
        Informacao_vazia(informacao);
        tempo_gasto = clock();
        Imprime_tabuleiro(m,m_teste, 0, 0, informacao, opcoes, user);
        while(1){         // M: 27=esc     13=enter
                tecla=getch();
                Informacao_vazia(informacao);
        
                system("cls");                      // M: Ver como é no linux     #if...
                
                if(tecla == 77) atualx++;           // M: X=Coluna (0 a 8)
                if(tecla == 75) atualx--;
                if(tecla == 80) atualy++;           // M: Y=Linha (0 a 8)
                if(tecla == 72) atualy--;
                
                if(tecla >= 49 && tecla <= 57 && m_teste[atualy][atualx] == 0)  // M: Se for numero ou estiver vazio o local na matriz original
                        m[atualy][atualx] = tecla-48;               // M: Colocar na matriz de numeros inteiros
                if(tecla == 8 && m_teste[atualy][atualx] == 0)  // M: Acrescentei isso, se o usuario der back-space apaga o numero
                        m[atualy][atualx] = 0;

                if(atualx == 9){
                        if(tecla == 80) selecaolateral++;
                        if(tecla == 72) selecaolateral--;

                        if(selecaolateral == -1) selecaolateral = 3;              // M: Modificar de acordo com a quantidade de botoes
                        if(selecaolateral == 4) selecaolateral = 0;                    
                
        }   
        if((atualx == 9 && selecaolateral == 0 && tecla == 13) || (tecla == 118)){
            if(Verificar(m) == 1){
                    strcpy(informacao,"Parabens! Voce manja :p haha");
                    if(Pronto(m) == 1){
                            tempo_gasto = clock() - tempo_gasto;
                            tempo = tempo_gasto/CLOCKS_PER_SEC;
                            Controla_tempo(tempo, escolha, user);
                            printf("\n\n\n******PARABENS***\n");
                            break;
                    }
            }
            else
                strcpy(informacao,"Voce fracassou.. quem sabe na proxima");
        }

        if((atualx == 9 && selecaolateral == 2 && tecla == 13)){
                if(opcoes == 1){
                        p = fopen("Continua.txt","w");
                        if(p == NULL){
                                printf("Erro ao abrir o arquivo!");
                                exit(1);
                        }
                        for(i=0;i<TAMANHO;i++){
                                for(j=0;j<TAMANHO;j++,x++){
                                        v = m_teste[i][j] + 48; 
                                        fprintf(p,"%c",v);  
                                        fflush(p);     
                                }
                        }
                        fputc('\n',p);
                        fflush(p);
                        x = 0;
                        for(i=0;i<TAMANHO;i++){
                                for(j=0;j<TAMANHO;j++,x++){
                                        v = m[i][j] + 48;
                                        fprintf(p,"%c",v);  
                                        fflush(p);         
                                }
                        }
                        fputc('\n', p);
                        fflush(p);
                        fclose(p);               
                }
                Zerar_matriz(m);
                Zerar_matriz(m_teste);
                tempo_gasto = clock() - tempo_gasto;
                if(opcoes == 1)
                        Tela_inicial(m_teste,m, user);
                else
                        Tela_inicial(m, m_teste, user);
        }

        if((atualx == 9 && selecaolateral == 1 && tecla == 13) || (tecla == 102)){
                if(opcoes == 1){
                        p = fopen("Continua.txt","w");
                        if(p == NULL){
                                printf("Erro ao abrir o arquivo!");
                                exit(1);
                        }
                        for(i=0;i<TAMANHO;i++){
                                for(j=0;j<TAMANHO;j++,x++){
                                        v = m_teste[i][j] + 48; 
                                        fprintf(p,"%c",v);  
                                        fflush(p);     
                                }
                        }
                        fputc('\n',p);
                        fflush(p);
                        x = 0;
                        for(i=0;i<TAMANHO;i++){
                                for(j=0;j<TAMANHO;j++,x++){
                                        v = m[i][j] + 48;
                                        fprintf(p,"%c",v);  
                                        fflush(p);         
                                }
                        }
                        fputc('\n', p);
                        fflush(p);
                        fclose(p);               
                }
                tempo_gasto = clock() - tempo_gasto;
                break;
        }
                
        if(atualx == -1) atualx=9;       // M: Quando o elemento selecionado passa do limite (linha ou coluna), ele "faz a volta"
        if(atualx == 10)  atualx=0;
        if(atualy == -1) atualy=8;
        if(atualy == 9)  atualy=0;

        // M: Quando for adicionado novos botoes, ajustar onde vai depois que passarpara a coluna 9 ex: if(atualy == 1)

        if(atualx != 9)           //coluna de botões
                Imprime_tabuleiro(m, m_teste, atualx, atualy, informacao, opcoes, user);    // M: Passa a matriz, numero de elementos e a posição que pode ser modificada
        else
        {
                Imprime_tabuleiro(m, m_teste, 9,selecaolateral,informacao, opcoes, user);
        }
        
        
    }
    /*if (tecla==13)
        printf("Jogo pausado");              M: Talvez dê para inventar coisa aqui tipo isso ;)*/
}

void Continua_jogo(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char user[20]){
        FILE *p;
        int i, x = 0, j;
        char userArq[30], vetor[81], informacao[45];
        Informacao_vazia(informacao);
        p = fopen("Continua.txt", "r");
        if(p == NULL){
                printf("Errinho...\n");
                exit(1);
        }
        fgets(vetor, 81, p);
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++,x++)
                        matriz_original[i][j] = vetor[x] - 48; 
                
        x = 0;
        fgets(vetor, 81, p);
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++,x++)
                        matriz_final[i][j] = vetor[x] - 48;
        fclose(p);
        Preencher_matriz(matriz_original, matriz_final, informacao,1,user,5);
}

void Meu_sudoku(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO], char user[20]){  // M: Para o usuario digitar seu sudoku
        int i, j,x=0;
        char informacao[45],resolucao[81];
        Informacao_vazia(informacao);
        Zerar_matriz(matriz_original);
        Zerar_matriz(matriz_final);        
        Imprime_tabuleiro(matriz_original, matriz_final, 0, 0, informacao, 0, user);
        Preencher_matriz(matriz_original, matriz_final, informacao, 0, user, 0);             

        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++, x++)
                       resolucao[x] = matriz_final[i][j] = matriz_original[i][j];
        resolver(resolucao);
        Preencher_matriz(matriz_final, matriz_original, informacao, 1, user, 0);
}

void Vetor_para_matriz(char vetor[81],int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO], char user[20], int escolha){
        int i, j, x = 0;
        char informacao[45];
        Informacao_vazia(informacao);
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++,x++)
                        matriz_original[i][j] = vetor[x]-48; 
        if ((int)vetor[0] == 10)          // M: estava dando erro no primeiro elemento quando ele era 0 (aparecia -38) continua dando ero as vezes, mas é um bug melhor haha
                matriz_original[0][0] = 0;            
        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        matriz_final[i][j] = matriz_original[i][j];
        
        Preencher_matriz(matriz_final, matriz_original, informacao, 1, user, escolha); 
}

void Imprime_dificuldades(int escolha){
        system("cls");
        //textcolor(9);
        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c\n"
                ,201,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205,
                205,205,187);

        printf("%c\t\t\t\t%c\n%c\tEscolha o n%cvel:\t%c\n",186,186,186,161,186);
        printf( "%c \t%c F%ccil\t\t\t%c\n" 
                "%c \t%c M%cdio\t\t\t%c\n" 
                "%c \t%c Dif%ccil\t\t%c\n" 
                "%c \t%c Terr%cvel\t\t%c\n"
                "%c\t\t\t\t%c\n"
                ,186,(escolha==1)?175:32,160,186,186,(escolha==2)?175:32,130,186,186,(escolha==3)?175:32,161,186,186,(escolha==4)?175:32,161,186,186,186);

        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c\n"
                ,200,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,205,205,205,205,205,205,205,205
                ,205,205,188);

        setbuf(stdin,NULL);

}



void Gera_jogo_aleatorio(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO], char user[20]){
        int escolha = 1, sorteio = 0, aux = 0, x = 0;
        unsigned char tecla;
        char num = 0, vetor[81],resolucao[81];
        FILE *p;
        Imprime_dificuldades(escolha);
        while((tecla=getch()) != 13){        

                if(tecla == 80) escolha++;              // M: Seta para cima
                if(tecla == 72) escolha--;              // M: Seta para baixo

                if(escolha == 5) escolha = 1;           // M: Retorno
                if(escolha == 0) escolha = 4;

                Imprime_dificuldades(escolha);
        }

        switch (escolha){
        case 1:
                p = fopen("facil.txt","r");
                if(p == NULL){
                        printf("Nao foi possivel abrir o arquivo!\n");
                }
                break;
        case 2:
                p = fopen("medio.txt","r");
                if(p == NULL){
                        printf("Nao foi possivel abrir o arquivo!\n");
                }
                break;
        case 3: 
                p = fopen("dificil.txt","r");
                if(p == NULL){
                        printf("Nao foi possivel abrir o arquivo!\n");
                }
                break;
        case 4: 
                p = fopen("terrivel.txt","r");
                if(p == NULL){
                        printf("Nao foi possivel abrir o arquivo!\n");
                }
                break;
        default:
                Gera_jogo_aleatorio(matriz_original, matriz_final, user);
                break;
        }
        srand((unsigned)(time(NULL)));
        if(escolha == 4){
                sorteio = rand()%2;

        }else{
                sorteio = rand()%4;
        }

        while((num = fgetc(p)) != EOF){
                if(aux == sorteio){
                        resolucao[x] = vetor[x] = num;
                        x++;
                }else if(num == '\n'){
                        aux++;
                }
                if(x == 81)
                        break;
        }

        resolver(resolucao);
        Vetor_para_matriz(vetor, matriz_original, matriz_final, user, escolha);
        fclose(p);
}

void Ranking(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char user[20]){
    FILE *p;
    char tempostr[20], nome[100];
    int i, tempo;
    unsigned char tecla;
    system("cls");
    printf( "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c\n"
        ,201,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,187);
    p = fopen("temposfacil.txt","r");
    if(p == NULL){
        printf("O arquivo nao foi aberto como desejado");
        exit(1);
    }
    printf("%c\tTempos F%ccil:\t\t\t\t\t%c\n",186,160,186);
    for(i=0; i<3; i++){
        fgets(tempostr, 20, p);
        fgets(nome, 100, p);
        nome[strlen(nome) - 1] = '\0';
        tempo = atoi(tempostr);
        printf("%c\t\t%i:%i\t%s\t\t%c\n",186,tempo/60, tempo % 60, nome, 186);
    }
    fclose(p);
    p = fopen("temposmedio.txt","r");
    if(p == NULL){
        printf("O arquivo nao foi aberto como desejado");
        exit(1);
    }
    printf("%c\tTempos M%cdio:\t\t\t\t\t%c\n",186,130,186);
        for(i=0; i<3; i++){
        fgets(tempostr, 20, p);
        fgets(nome, 100, p);
        nome[strlen(nome) - 1] = '\0';
        tempo = atoi(tempostr);
        printf("%c\t\t%i:%i\t%s\t\t%c\n",186,tempo/60, tempo % 60, nome, 186);
    }
    fclose(p);
    p = fopen("temposdificil.txt","r");
    if(p == NULL){
        printf("O arquivo nao foi aberto como desejado");
        exit(1);
    }
    printf("%c\tTempos Dif%ccil:\t\t\t\t\t%c\n",186,161,186);
        for(i=0; i<3; i++){
        fgets(tempostr, 20, p);
        fgets(nome, 100, p);
        nome[strlen(nome) - 1] = '\0';
        tempo = atoi(tempostr);
        printf("%c\t\t%i:%i\t%s\t\t%c\n",186,tempo/60, tempo % 60, nome, 186);
    }
    fclose(p);
    p = fopen("temposterrivel.txt","r");
    if(p == NULL){
        printf("O arquivo nao foi aberto como desejado");
        exit(1);
    }
    printf("%c\tTempos Terr%cvel:\t\t\t\t%c\n",186,161,186);
        for(i=0; i<3; i++){
        fgets(tempostr, 20, p);
        fgets(nome, 100, p);
        nome[strlen(nome) - 1] = '\0';
        tempo = atoi(tempostr);
        printf("%c\t\t%i:%i\t%s\t\t%c\n",186,tempo/60, tempo % 60, nome, 186);
    }
    fclose(p);
    p = fopen("temposMeuSudoku.txt","r");
    if(p == NULL){
        printf("O arquivo nao foi aberto como desejado");
        exit(1);
    }
    printf("%c\tTempos Meu Sudoku:\t\t\t\t%c\n",186,186);
        for(i=0; i<3; i++){
        fgets(tempostr, 20, p);
        fgets(nome, 100, p);
        nome[strlen(nome) - 1] = '\0';
        tempo = atoi(tempostr);
        printf("%c\t\t%i:%i\t%s\t\t%c\n",186,tempo/60, tempo % 60, nome, 186);
    }
    fclose(p);
    printf("%c\t\t\t\t\t\t\t%c\n%c\t\t\tPrecione ENTER para voltar\t%c\n",186,186,186,186);
    printf( "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c%c%c%c"
        "%c%c%c%c%c%c%c\n"
        ,200,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,188);
        do{
        if((tecla = getch()) == 13)
                Tela_inicial(matriz_original, matriz_final, user);
        }while (tecla != 13);
        
        
}

void Imprime_inicio(int escolha, char user[20]){
    system("cls");
        //textcolor(9);
        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c\n"
        ,201,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,187);
        printf("%c\t\t\t\t\t\t\t%c\n%c    Sudoku\t\t\t\t\t\t%c\n",186,186,186,186);
        printf( "%c    %c Carregar um jogo aleat%crio.\t\t\t%c \n"
                "%c    %c Carregar um jogo previamente definido.\t\t%c \n"
                "%c    %c Continuar jogo.\t\t\t\t\t%c \n"
                "%c    %c Ranking\t\t\t\t\t\t%c\n",186,(escolha==1)?175:32,162,186,186,(escolha==2)?175:32,186,186,(escolha==3)?175:32,186,186,(escolha==4)?175:32,186);
        printf("%c    %c Sair\t\t\t\t\t\t%c\n",186,(escolha==5)?175:32,186);
        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c\n"
        ,200,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,188);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c  %c %s %c",186,(escolha==6)?175:32,user,186);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void Tela_inicial(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char user[20]){
        int escolha = 1;
        unsigned char tecla;
        
        Imprime_inicio(escolha, user);
        while((tecla=getch()) != 13){        

                if(tecla == 80) escolha++;              // M: Seta para cima
                if(tecla == 72) escolha--;              // M: Seta para baixo

                if(escolha == 7) escolha = 1;           // M: Retorno
                if(escolha == 0) escolha = 6;

                Imprime_inicio(escolha, user);
        }        

        if(escolha == 1){
                Gera_jogo_aleatorio(matriz_original, matriz_final, user);

        }else if(escolha == 2){                  
                Meu_sudoku(matriz_original, matriz_final, user); // M: estava->telaDeBoasVindas(matriz_original,matriz_final);
        }else if(escolha == 3){ 
                Continua_jogo(matriz_original, matriz_final, user); 
        }else if(escolha == 4){
                Ranking(matriz_original, matriz_final,user);
        }else if(escolha == 5){
                exit(0);
        }if(escolha == 6){
                Tela_entrar(matriz_original, matriz_final, user);
        }
}

int main(){
        int matriz_original[TAMANHO][TAMANHO];
        int matriz_final[TAMANHO][TAMANHO]; 
        char user[20] = "Login / Sair       ";
        Tela_inicial(matriz_original, matriz_final,user);
        
        return 0;
}
