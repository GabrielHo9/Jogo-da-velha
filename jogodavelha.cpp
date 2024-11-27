#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fazer um jogo da velha funcional com tela inicial,

//variaveis
char tabuleiro[3][3];
char jogador1 = 'X';

//struct do ranking
typedef struct Ranking
    {
         char   j1[265],j2[265];
         int vitoriaj1,vitoriaj2,empates;
    }Rank;
    

    Rank ranking;
//void do tabuleiro
void iniciarT() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
      
}

//void de exibir o tabuleiro no terminal
void mostrarT() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}
//void pra abrir o arquivo de ranking
void arqranking() {
    FILE *arquivo = fopen("ranking.txt", "w");
    if (!arquivo) {
        printf("erro no arquivo\n");
        return;
    }

    fprintf(arquivo, "J1: %s (Vitorias: %d)\n", ranking.j1, ranking.vitoriaj1);
    fprintf(arquivo, "J2: %s (Vitorias: %d)\n", ranking.j2, ranking.vitoriaj2);
    fprintf(arquivo, "Empates: %d\n", ranking.empates);
    fclose(arquivo);

    printf("Ranking salvo em 'ranking.txt'!\n");
}

//if pra determinar tipo de jogada
int jogada(int linha, int coluna) {
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
        return 0; //-->inválida
    }
    tabuleiro[linha - 1][coluna - 1] = jogador1;
    return 1; //-->válida
}


//condicao de vitoria
int victory() {
    //linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1; 
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;  
    }

    //diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1; 
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1; 

    return 0; 
}



//void de alternar jogadores
void alternar() {
    jogador1 = (jogador1 == 'X') ? 'O' : 'X';
}

int empate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;//--tem espaco
        }
    }
    return 1; // --n tem espaco logo: Empate
}




//main
 int main(){
    int linha, coluna;
    char escolha[265];

    //setando o ranking a 0
    ranking.vitoriaj1 = 0;
    ranking.vitoriaj2 = 0;
    ranking.empates = 0;
    //interface inicial
    printf("Bem vindo, J1!\n");
    printf("Digite seu nome: ");
    scanf("%s", ranking.j1);
    printf("Bem vindo, J2!\n");
    printf("Digite seu nome: ");
    scanf("%s", ranking.j2);
//loop da interface
 while (1) {
        printf("\nescolha como prosseguir: \n");
        printf("digite as seguintes opções:\n|| Novo | rank | cred | sair ||\n");
        scanf("%s", escolha);

        if (strcmp(escolha, "novo") == 0) {
            printf("iniciando um novo jogo!\n");
            iniciarT();
            
            while (1) {
                mostrarT();
                printf(" sua vez %c, (linha e coluna): ", jogador1);
                scanf("%d %d", &linha, &coluna);

                if (!jogada(linha, coluna)) {
                    printf("jogada ta errada tente de novo.\n");
                    continue;
                    }

                if (victory()) {
                     mostrarT();
                if (jogador1 == 'X') {
                        printf("congratulation, %s! Jogador %c venceu!\n",  ranking.j1);
                        ranking.vitoriaj1++;
                }else {
                        printf("congratulation, %s! Jogador %c venceu!\n",  ranking.j2);
                        ranking.vitoriaj2++;
                }
                        break;
                }

                    if (empate()) {
                    mostrarT();
                    printf("empate!\n");
                    break;
                    }

                //alternar entre os jogadores X e O
            alternar();
            }
//mostrando o ranking no terminal
        } else if (strcmp(escolha, "rank") == 0) {
            printf("Mostrando a tabela de ranking...\n");
            printf("\n!!Ranking!!\n");
            printf("Jogador 1: %s (Vitórias: %d)\n", ranking.j1, ranking.vitoriaj1);
            printf("Jogador 2: %s (Vitórias: %d)\n", ranking.j2, ranking.vitoriaj2);
            printf("Empates: %d\n", ranking.empates);
    //mostrando os creditos
        } else if (strcmp(escolha, "cred") == 0) {
            printf("Exibindo os créditos...\n");
            printf("Desenvolvido por: Gabriel Pereira Ho\nPedro Henrique de Macedo Oliveira\nArthur Lobo Freitas\nJoão Vitor Amaral");
            //saindo
        } else if (strcmp(escolha, "sair") == 0) {
            printf("Saindo. Bye bye, %s!\n", ranking.j1,ranking.j2);
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }


    


return 0;
}
 
  

