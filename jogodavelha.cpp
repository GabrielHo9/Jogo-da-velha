#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


//fazer um jogo da velha funcional com tela inicial,(novo,creditos,ranking,sair).

//variaveis
char jogov[3][3];
char jogador1 = 'X';
int i,j,linha,coluna;
//struct do ranking
typedef struct Ranking
    {
         char   j1[265],j2[265];
         int vitoriaj1,vitoriaj2,empates;
    }Rank;
    

    Rank ranking;
//void do jogov
void iniciarT() {
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            jogov[i][j] = ' ';
        }
    }
      
}
//void pra abrir o arquivo de ranking
void arqranking() {
    FILE *arquivo = fopen("rank.txt", "w");
    
    if (!arquivo) {
        printf("erro no arquivo\n");
        return;
    }

    fprintf(arquivo, "J1: %s (Vitorias: %d)\n", ranking.j1, ranking.vitoriaj1);
    fprintf(arquivo, "J2: %s (Vitorias: %d)\n", ranking.j2, ranking.vitoriaj2);
    fprintf(arquivo, "Empates: %d\n", ranking.empates);
    fclose(arquivo);

    printf("Ranking salvo!\n");
    fclose;
}

//void de exibir o jogo no terminal
void mostrarT() {
    printf("\n");
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            printf(" %c ", jogov[i][j]);
            if (j < 2) 
            printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

//if pra determinar tipo de jogada(por algum motivo se eu tirar o int da linha e coluna a coluna vira void(???????))
int jogada(int linha, int coluna) {
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || jogov[linha - 1][coluna - 1] != ' ') {
        return 0; //-->inválida
    }
    jogov[linha - 1][coluna - 1] = jogador1;
    return 1; //-->válida

}


//condicao de vitoria
int victory() {
   
      //linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (jogov[i][0] != ' ' && jogov[i][0] == jogov[i][1] && jogov[i][1] == jogov[i][2])
            return 1; 
        if (jogov[0][i] != ' ' && jogov[0][i] == jogov[1][i] && jogov[1][i] == jogov[2][i])
            return 1;  
    }

    //diagonais
    if (jogov[0][0] != ' ' && jogov[0][0] == jogov[1][1] && jogov[1][1] == jogov[2][2])
        return 1; 
    if (jogov[0][2] != ' ' && jogov[0][2] == jogov[1][1] && jogov[1][1] == jogov[2][0])
        return 1; 


                return 0;
            }

            


int errodestring(int *linha, int *coluna) {
    char entrada[100];
    printf("Sua vez %c (linha e coluna): ", jogador1);

    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

        if (sscanf(entrada, "%d %d", linha, coluna) == 2) {
            return 1; //-->válida
        }
    }

    printf("Entrada inválida. Por favor, insira dois números separados por espaço.\n");
    return 0; //-->inválida
}

//void de alternar jogadores
void alternar() {
    jogador1 = (jogador1 == 'X') ? 'O' : 'X';
}

int empate() {
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (jogov[i][j] == ' ')
                return 0;//--tem espaco
        }
    }
    return 1; // --n tem espaco logo: Empate
}




//main
int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char escolha[265];

    //setando o ranking a 0
    ranking.vitoriaj1 = 0;
    ranking.vitoriaj2 = 0;
    ranking.empates = 0;
    //interface inicial
    printf("Digite seu nome: ");
    scanf("%s", ranking.j1);
    printf("Bem vindo, %s!\n",ranking.j1);
    
    printf("Digite seu nome: ");
    scanf("%s", ranking.j2);
    printf("Bem vindo, %s\n",ranking.j2);
    
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

    // obter entrada válida do jogador
    while (1) {
        if (errodestring(&linha, &coluna)) {
            if (jogada(linha, coluna)) {
                break; // jogada valida
            } else {
                printf("Jogada invalida. Tente novamente.\n");
            }
        }
    }

    if (victory()) {
        mostrarT();
        if (jogador1 == 'X') {
            printf("Parabéns, %s! Você venceu!\n", ranking.j1);
            ranking.vitoriaj1++;
        } else {
            printf("Parabéns, %s! Você venceu!\n", ranking.j2);
            ranking.vitoriaj2++;
        }
         arqranking(); // Salva o ranking ao final do jogo
        
        break;
    }

    if (empate()) {
        mostrarT();
        printf("Empate!\n");
        ranking.empates++;
        break;
    }

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
 
  
