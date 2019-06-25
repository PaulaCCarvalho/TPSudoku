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


void Imprime_tabuleiro(int m[TAMANHO][TAMANHO], int atualx, int atualy, char informacao[45]){
        int i, j;
        system("cls");

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,187); 

        for(i=0; i<TAMANHO; i++){
                printf("\n%c ",186);                            // M: pimeiro elemento das linhas que têm numeros

                for(j=0; j<TAMANHO; j++){
                        if(i == atualy && j == atualx)          // M: Se a posicão atual for o local do quadradinho
                                printf("%c ",219);              
                        else if(m[i][j] == 0)                   // M: Se a posição estiver vazia (zero), mostra um espaço
                                printf("%c ",32);               
                        else
                                printf("%c ",m[i][j]+48);       // M: Se não, mostra o número

                        if(j == 2 || j == 5)                    // M: Aqui vai a "divisão vertical"
                                printf("%c ",179);
                        if(j == 8)                              // M: último caracter das linhas que têm numeros (igual ao 1°)
                                printf("%c",186);
                }
                if(i == 5)
                    printf("\t\tDigite \"v\" para verificar");
                if(i == 6)
                    printf("\tOBS: SE ISSO ACONTECER ^^ E O SUDOKU ESTIVER COMPLETO, SAI DO LACO WHILE");
                if(i ==7)
                    printf("\t\t%s",informacao);       //M: Vai digitar alguma informação especial
                if(i == 2 || i == 5)                            // M: Ao final da 3° linha e da 5°, irá mostar esta linha "divisão horizontal"
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,185);
        }

        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188); 
}

void Preencher_matriz(int m[TAMANHO][TAMANHO], int m_teste[TAMANHO][TAMANHO], char informacao[45]){             
        int atualx = 0, atualy = 0;
        unsigned char tecla;
        Informacao_vazia(informacao);
        Imprime_tabuleiro(m, 0, 0, informacao);
        while((tecla=getch()) != 13){         // M: 27=espaço     13=enter

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

        if(tecla == 118){
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
                
        if(atualx == -1) atualx=8;       // M: Quando o elemento selecionado passa do limite (linha ou coluna), ele "faz a volta"
        if(atualx == 9)  atualx=0;
        if(atualy == -1) atualy=8;
        if(atualy == 9)  atualy=0;

        Imprime_tabuleiro(m, atualx, atualy, informacao);    // M: Passa a matriz, numero de elementos e a posição que pode ser modificada
    }
    /*if (tecla==13)
        printf("Jogo pausado");              M: Talvez dê para inventar coisa aqui tipo isso ;)*/
}

void Meu_sudoku(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO]){  // M: Para o usuario digitar seu sudoku
        int i, j;
        char informacao[45];
        Informacao_vazia(informacao);
        Zerar_matriz(matriz_original);
        Zerar_matriz(matriz_final);        
        Imprime_tabuleiro(matriz_original, 0, 0, informacao);
        Preencher_matriz(matriz_original, matriz_final, informacao);             

        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        matriz_final[i][j] = matriz_original[i][j];

        Preencher_matriz(matriz_final, matriz_original, informacao);
}

void Vetor_para_matriz(char vetor[81],int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO]){
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
        
        Preencher_matriz(matriz_final, matriz_original, informacao); 
}

void Gera_jogo_aleatorio(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO]){
        int escolha = 0, sorteio = 0, aux = 0, x = 0;
        char num = 0, vetor[81];
        FILE *p;
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
        printf( "%c \t(1)F%ccil\t\t%c\n" 
                "%c \t(2)M%cdio\t\t%c\n" 
                "%c \t(3)Dif%ccil\t\t%c\n" 
                "%c \t(4)Terr%cvel\t\t%c\n"
                "%c\t\t\t\t%c\n"
                ,186,160,186,186,130,186,186,161,186,186,161,186,186,186);

        printf( "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c%c%c%c%c%c%c%c"
                "%c%c%c\n"
        ,200,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,205,205,205,205,205,205,205,205
        ,205,205,188);

        scanf("%d",&escolha);
        setbuf(stdin,NULL);

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
                Gera_jogo_aleatorio(matriz_original, matriz_final);
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
        Vetor_para_matriz(vetor, matriz_original, matriz_final);
        fclose(p);
}

void Ranking(){
    FILE *p;
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

void Tela_inicial(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO]){
        int escolha;
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

        printf( "%c    Digite: \t\t\t\t\t\t%c\n",186,186);
        printf( "%c    (1)Para carregar um jogo aleat%crio.\t\t%c \n"
                "%c    (2)Para carregar um jogo previamente definido.\t%c \n"
                "%c    (3)Ranking\t\t\t\t\t\t%c\n",186,162,186,186,186,186,186);

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

        scanf("%d",&escolha);
        setbuf(stdin,NULL);

        if(escolha == 1){
                Gera_jogo_aleatorio(matriz_original, matriz_final);
              

        //}else if(escolha == 2){
               // carregaJogoPreviamenteDefinido();
        }else if(escolha == 2){                  // M: se digitar 3 tbm, n alterei pq povavelmente mudaremos para as setinhas
                Meu_sudoku(matriz_original, matriz_final); // M: estava->telaDeBoasVindas(matriz_original,matriz_final);
        }else{
                Ranking();
        }
}

int main(){
        int matriz_original[TAMANHO][TAMANHO];
        int matriz_final[TAMANHO][TAMANHO]; 

        Tela_inicial(matriz_original, matriz_final);
        
        return 0;
}
