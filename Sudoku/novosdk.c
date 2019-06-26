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


void Imprime_tabuleiro(int m[TAMANHO][TAMANHO], int atualx, int atualy, char informacao[45], int opcoes){
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
                /*
                if(opcoes == 0) quando as opçoes se referem ao preenchimento da matriz original
                if(opcoes == 1) quando as opçoes se referem ao preenchimento da matriz de jogo
                */
                if(i == 1)
                        printf("\t\t\t%c Verificar (Atalho: v)",(atualx == 9 && atualy == 0)?175:32);
                if(i == 2)
                        printf("\t\t\t%c Fim (Atalho: f)",(atualx == 9 && atualy == 1)?175:32);
                
                if(i == 6)
                    printf("\tOBS: SE ISSO ACONTECER ^^ E O SUDOKU ESTIVER COMPLETO, SAI DO LACO WHILE");
                if(i ==7)
                    printf("\t\t%s",informacao);       //M: Vai digitar alguma informação especial
                if(i == 2 || i == 5)                            // M: Ao final da 3° linha e da 5°, irá mostar esta linha "divisão horizontal"
                printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196,196,185);
        }

        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188); 
}

void Preencher_matriz(int m[TAMANHO][TAMANHO], int m_teste[TAMANHO][TAMANHO], char informacao[45], int opcoes){             
        int atualx = 0, atualy = 0, selecaolateral = 0;
        unsigned char tecla;
        Informacao_vazia(informacao);
        Imprime_tabuleiro(m, 0, 0, informacao, opcoes);
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

                if(selecaolateral == -1) selecaolateral = 1;              // M: Modificar de acordo com a quantidade de botoes
                if(selecaolateral == 2) selecaolateral = 0;                    
                
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

        if((atualx == 9 && selecaolateral == 1 && tecla == 13) || (tecla == 102))
                break;
                
        if(atualx == -1) atualx=9;       // M: Quando o elemento selecionado passa do limite (linha ou coluna), ele "faz a volta"
        if(atualx == 10)  atualx=0;
        if(atualy == -1) atualy=8;
        if(atualy == 9)  atualy=0;

        // M: Quando for adicionado novos botoes, ajustar onde vai depois que passarpara a coluna 9 ex: if(atualy == 1)

        if(atualx != 9)           //coluna de botões
                Imprime_tabuleiro(m, atualx, atualy, informacao, opcoes);    // M: Passa a matriz, numero de elementos e a posição que pode ser modificada
        else
        {
                Imprime_tabuleiro(m,9,selecaolateral,informacao, opcoes);
        }
        
        
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
        Imprime_tabuleiro(matriz_original, 0, 0, informacao, 0);
        Preencher_matriz(matriz_original, matriz_final, informacao, 0);             

        for(i=0; i<TAMANHO; i++)
                for(j=0; j<TAMANHO; j++)
                        matriz_final[i][j] = matriz_original[i][j];

        Preencher_matriz(matriz_final, matriz_original, informacao, 1);
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
        
        Preencher_matriz(matriz_final, matriz_original, informacao, 1); 
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

void Gera_jogo_aleatorio(int matriz_original[TAMANHO][TAMANHO], int matriz_final[TAMANHO][TAMANHO]){
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

void Imprime_inicio(int escolha){
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
                "%c    %c Ranking\t\t\t\t\t\t%c\n",186,(escolha==1)?175:32,162,186,186,(escolha==2)?175:32,186,186,(escolha==3)?175:32,186);

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
        int escolha = 1;
        unsigned char tecla;
        Imprime_inicio(escolha);
        while((tecla=getch()) != 13){        

                if(tecla == 80) escolha++;              // M: Seta para cima
                if(tecla == 72) escolha--;              // M: Seta para baixo

                if(escolha == 4) escolha = 1;           // M: Retorno
                if(escolha == 0) escolha = 3;

                Imprime_inicio(escolha);
        }        

        if(escolha == 1){
                Gera_jogo_aleatorio(matriz_original, matriz_final);
            
        }else if(escolha == 2){                  
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
