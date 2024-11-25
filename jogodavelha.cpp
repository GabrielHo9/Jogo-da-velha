#include <stdio.h>
//fazer um jogo da velha funcional com tela inicial,

//variaveis
char tabuleiro[3][3];
char jogador1 = 'X';

//void do tabuleiro
void iniciarT() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
      
}
 int main(){
    int linha, coluna;
    char nome[50], escolha[265];

    printf("Bem-vindo, Novo Jogador!\n");
    printf("Digite seu nome para sua identificação: ");
    scanf("%s", nome);



return 0;
}
 
  

