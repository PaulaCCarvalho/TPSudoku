#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <conio.c>
// M: falta arrumar um erro que ALGUMAS VEZES aparece e manda todos os elementos pra uma casa depois (precisamos achar o padrão de quando isso acontece)
// M: Só coloquei esse comentario aqui porque com certeza vão mecher nessa parte haha 
#include <time.h>

#define TAMANHO 9

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

void Tela_login(){
        int i=0;
        char user[20], senha[20];
        unsigned char tecla;

        system("cls");
        printf( "%c\n%c\n%c\tLogin\n",201,186,186);
        printf("%c   Usu%crio: ",186,160);
        scanf("%s",user);
        setbuf(stdin,NULL);
        printf("%c   Senha: ",186);
        while((tecla=getch()) != 13){
                senha[i] = tecla;
                printf("*");
                setbuf(stdin,NULL);
                i++;
        }
        senha[i]='\0';

        printf("\n%c\n",200);
}

void Tela_inicial(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO],char user[20]);

void Tela_cadastro(int matriz_original[9][9], int matriz_final[9][9], char user[20]){
	int i=0;
	char senha[20],confirmar[20];
	unsigned char tecla;
	
	system("cls");
	printf( "%c\n%c\n%c\tCadastro\n",201,186,186);

	printf("%c   Usu%crio: ",186,160);
	scanf("%s",user);
	printf("%c   Senha: ",186);
	while((tecla=getch()) != 13){
		senha[i] = tecla;
		printf("*");
		setbuf(stdin,NULL);
		i++;
	}
	senha[i]='\0';
	setbuf(stdin,NULL);
	tecla = 1,i=0;
	printf("\n%c   Confirmar senha: ",186);
	while((tecla=getch()) != 13){
		confirmar[i] = tecla;
		printf("*");
		setbuf(stdin,NULL);
		i++;
	}
	confirmar[i]='\0'; 
	
	printf("\n%c\n",200);
                
	if(strcmp(senha, confirmar) == 0)
		Tela_inicial(matriz_original, matriz_final,user);
	else{
                printf("\n\tErro ao fazer o cadastro\n %c Tentar novamente\n",175);  
                while(1){
                     tecla=getch(); 
                     if(tecla == 13){
                             strcpy(user,"Login / Sair");
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
		Tela_login();
	else
		Tela_cadastro(matriz_original, matriz_final, user);
		
}

void Imprime_tabuleiro(int m[TAMANHO][TAMANHO], int atualx, int atualy, char informacao[45], int opcoes, char user[20]){
        int i, j;
        system("cls");
		printf("\n\n\n\n");
        printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,187); 

        for(i=0; i<TAMANHO; i++){
                printf("\n\t%c ",186);                            // M: pimeiro elemento das linhas que tÃªm numeros

                for(j=0; j<TAMANHO; j++){
                        if(i == atualy && j == atualx)          // M: Se a posicÃ£o atual for o local do quadradinho
                                printf("%c ",219);              
                        else if(m[i][j] == 0)                   // M: Se a posiÃ§Ã£o estiver vazia (zero), mostra um espaÃ§o
                                printf("%c ",32);               
                        else
                                printf("%c ",m[i][j]+48);       // M: Se nÃ£o, mostra o nÃºmero

                        if(j == 2 || j == 5 || j == 8)                    // M: Aqui vai a "divisÃ£o vertical"
                                printf("%c ",186);
                        else
                                printf("%c ",179);
                        
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
                
                if(i == 6)
                    printf("\tOBS: SE ISSO ACONTECER ^^ E O SUDOKU ESTIVER COMPLETO, SAI DO LACO WHILE");
                if(i ==7)
                    printf("\t\t%s",informacao);       //M: Vai digitar alguma informaÃ§Ã£o especial
                if(i == 2 || i == 5)                            // M: Ao final da 3Â° linha e da 5Â°, irÃ¡ mostar esta linha "divisÃ£o horizontal"
                        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,185);
                else if(i != 8)
                        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",186,196,196,196,197,196,196,196,197,196,196,196,186,196,196,196,197,196,196,196,197,196,196,196,186,196,196,196,197,196,196,196,197,196,196,196,186);              
        }

        printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,188); 
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%c",201);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c  %c %s    ",186,(atualx == 9 && atualy == 3)?175:32,user);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c\n",200);
}

void Preencher_matriz(int m[TAMANHO][TAMANHO], int m_teste[TAMANHO][TAMANHO], char informacao[45], int opcoes, char user[20]){             
        int atualx = 0, atualy = 0, selecaolateral = 0;
        unsigned char tecla;
        Informacao_vazia(informacao);
        Imprime_tabuleiro(m, 0, 0, informacao, opcoes, user);
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
                            printf("\n\n\n******PARABENS***\n");
                            break;
                    }
            }
            else
                strcpy(informacao,"Voce fracassou.. quem sabe na proxima");
        }

        if((atualx == 9 && selecaolateral == 2 && tecla == 13)){
                Zerar_matriz(m);
                Zerar_matriz(m_teste);
                if(opcoes == 1)
                        Tela_inicial(m_teste,m, user);
                else
                        Tela_inicial(m, m_teste, user);
        }

        if((atualx == 9 && selecaolateral == 1 && tecla == 13) || (tecla == 102))
                break;
                
        if(atualx == -1) atualx=9;       // M: Quando o elemento selecionado passa do limite (linha ou coluna), ele "faz a volta"
        if(atualx == 10)  atualx=0;
        if(atualy == -1) atualy=8;
        if(atualy == 9)  atualy=0;

        // M: Quando for adicionado novos botoes, ajustar onde vai depois que passarpara a coluna 9 ex: if(atualy == 1)

        if(atualx != 9)           //coluna de botões
                Imprime_tabuleiro(m, atualx, atualy, informacao, opcoes, user);    // M: Passa a matriz, numero de elementos e a posição que pode ser modificada
        else
        {
                Imprime_tabuleiro(m,9,selecaolateral,informacao, opcoes, user);
        }
        
        
    }
    /*if (tecla==13)
        printf("Jogo pausado");              M: Talvez dê para inventar coisa aqui tipo isso ;)*/
}

void Meu_sudoku(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO], char user[20]){  // M: Para o usuario digitar seu sudoku
        int i, j;
        char informacao[45];
        Informacao_vazia(informacao);
        Zerar_matriz(matriz_original);
        Zerar_matriz(matriz_final);        
        Imprime_tabuleiro(matriz_original, 0, 0, informacao, 0, user);
        Preencher_matriz(matriz_original, matriz_final, informacao, 0, user);             

        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        matriz_final[i][j] = matriz_original[i][j];

        Preencher_matriz(matriz_final, matriz_original, informacao, 1, user);
}

void Vetor_para_matriz(char vetor[81],int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO], char user[20]){
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
        
        Preencher_matriz(matriz_final, matriz_original, informacao, 1, user); 
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
        char num = 0, vetor[81];
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
                        vetor[x] = num;
                        x++;
                }else if(num == '\n'){
                        aux++;
                }
                if(x == 81)
                        break;
        }
        Vetor_para_matriz(vetor, matriz_original, matriz_final, user);
        fclose(p);
}

void Ranking(){
        FILE *p;
        system("cls");
        char tempo_e_nome[500];
        int i;
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
        printf("%c\tTempos Facil:\t\t\t\t\t%c\n",186,186);
        for(i=0; i<3; i++){
                fgets(tempo_e_nome, 500, p);
                tempo_e_nome[strlen(tempo_e_nome) - 1] = '\0';
                printf("%c\t\t%s\t\t\t\t%c\n",186,tempo_e_nome, 186);
        }
        fclose(p);
        p = fopen("temposmedio.txt","r");
        if(p == NULL){
                printf("O arquivo nao foi aberto como desejado");
                exit(1);
        }
        printf("%c\tTempos Medio:\t\t\t\t\t%c\n",186,186);
        for(i=0; i<3; i++){
                fgets(tempo_e_nome, 500, p);
                tempo_e_nome[strlen(tempo_e_nome) - 1] = '\0';
                printf("%c\t\t%s\t\t\t\t%c\n",186,tempo_e_nome, 186);
        }
        fclose(p);
        p = fopen("temposdificil.txt","r");
        if(p == NULL){
                printf("O arquivo nao foi aberto como desejado");
                exit(1);
        }
        printf("%c\tTempos Dificil:\t\t\t\t\t%c\n",186,186);
        for(i=0; i<3; i++){
                fgets(tempo_e_nome, 500, p);
                tempo_e_nome[strlen(tempo_e_nome) - 1] = '\0';
                printf("%c\t\t%s\t\t\t\t%c\n",186,tempo_e_nome, 186);
        }
        fclose(p);
        p = fopen("temposterrivel.txt","r");
        if(p == NULL){
                printf("O arquivo nao foi aberto como desejado");
                exit(1);
        }
        printf("%c\tTempos Terrivel:\t\t\t\t%c\n",186,186);
        for(i=0; i<3; i++){
                fgets(tempo_e_nome, 500, p);
                tempo_e_nome[strlen(tempo_e_nome) - 1] = '\0';
                printf("%c\t\t%s\t\t\t\t%c\n",186,tempo_e_nome, 186);
        }
        fclose(p);
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
                "%c    %c Nova opcao pro Diego Aqui.\t\t\t%c \n"
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t%c",201);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c  %c %s    ",186,(escolha==6)?175:32,user);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t%c\n",200);
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
                printf("P/ Diego: Coloque as coisas da nova opcao aqui\n"); 
        }else if(escolha == 4){
                Ranking();
        }else if(escolha == 5){
                exit(0);
        }if(escolha == 6){
                Tela_entrar(matriz_original, matriz_final, user);
        }
}

int main(){
        int matriz_original[TAMANHO][TAMANHO];
        int matriz_final[TAMANHO][TAMANHO]; 
        char user[20] = "Login / Sair";
        Tela_inicial(matriz_original, matriz_final,user);
        
        return 0;
}
