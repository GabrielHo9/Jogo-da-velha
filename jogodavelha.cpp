#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

 while (1) {
        printf("\nEscolha como prosseguir: \n");
        printf("Digite as seguintes opções:\n|| Novo | rank | cred | sair ||\n");
        scanf("%s", escolha);

        if (strcmp(escolha, "Novo") == 0) {
            printf("Iniciando um novo jogo...\n");
            iniciarT();


        } else if (strcmp(escolha, "rank") == 0) {
            printf("Mostrando a tabela de ranking...\n");
    
        } else if (strcmp(escolha, "cred") == 0) {
            printf("Exibindo os créditos...\n");
            printf("Desenvolvido por: Gabriel Pereira Ho\nPedro Henrique de Macedo Oliveira\nArthur Lobo Freitas\nJoão Vitor Amaral");
        } else if (strcmp(escolha, "sair") == 0) {
            printf("Saindo do jogo. Até logo, %s!\n", nome);
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }



return 0;
}
 
  

