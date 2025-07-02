#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sol = 0;

void rainha(int tabuleiro[], int n, int linha);
void impressao(int tabuleiro[], int n);
int verifica(int linha, int coluna, int tabuleiro[]);


void impressao(int tabuleiro[], int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j <n; j++){
                if(tabuleiro[i] == j)
                    printf("R ");
                else
                    printf("- ");

            }
            printf("\n");
        }
        printf("\nAperte Enter para prosseguir.\n");
        getchar();

}


int verifica(int linha, int coluna, int tabuleiro[]){ // funcao que verifica se a posiçao do tabuleiro é válida ----
    // retorna 1 se for válido, 0 se não

    // verifica a coluna ----------------------------------------
    for (int l = 0; l < linha; l++) // l de 0 até linha, apenas as linhas anteriores
        if (tabuleiro[l] == coluna) // verifica a coluna
            return 0;

    // diagonais: superior esquerda e superior direita -----------------------   

    // verifica a diagonal esquerda -----------------------------     
    int c = coluna-1;
    for (int l = linha-1; l >= 0; l--){ // l de linha-1 até 0, na ordem inversa
        if(tabuleiro[l] == c) // verifica a diagonal
            return 0;
        c--; // anda para a esquerda
    }

    // verifica a diagonal direita -----------------------------
    c = coluna+1;
    for (int l = linha-1; l >= 0; l--){ // l de linha-1 até 0, na ordem inversa
        if(tabuleiro[l] == c) // verifica a diagonal
            return 0;
        c++; // anda para a direita
    }

    return 1; // caso não satisfaça as restrições, a posição é válida
}


void rainha(int tabuleiro[], int n, int linha){ // funcao recursiva que posiciona uma rainha em uma linha, imprime a solução caso o tabuleiro esteja completo
    if(linha == n){ // se todas as rainhas foram colocadas, imprime a solucao
        sol++;
        printf("Solucao No %d encontrada:\n", sol);
        impressao(tabuleiro, n);
        return;
    }

    for (int coluna = 0; coluna < n; coluna++){
        if(verifica(linha, coluna, tabuleiro)){
            tabuleiro[linha] = coluna; // coloca a rainha na linha e coluna avaliadas

            rainha(tabuleiro, n, linha+1); // chama a funcao para a próxima linha

            tabuleiro[linha] = -1;
        }
    }
}


int main(){
    int n;
    printf("\n\n__--__--__--__ Trabalho 2 AED 2 __--__--__--__\n\n");
    printf("Problema das N rainhas em um tabuleiro N x N\n");
    printf("Insira o valor de N: ");
    scanf("%d", &n);
    printf("\nO programa posicionara %d rainhas em um tabuleiro de %d x %d\nAperte Enter para prosseguir.\n",n,n,n);
    getchar(); getchar();
    printf("Iniciando...\n\n");

    // inicializa o tabuleiro -----------------------
    int *tabuleiro = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)//                           O(n)
        tabuleiro[i] = -1;

    // chama a função principal ---------------------
    rainha(tabuleiro, n, 0);

    // imprime um aviso caso não haja soluções ------------
    if(sol == 0)
        printf("\n----------------------------------------\nAtencao!!\nExistem solucoes apenas para valores de N maiores que 3.\nTente Novamente!!\n----------------------------------------\n");
    else
        printf("Numero de Solucoes: %d\n\n__--__--__--__--__--__ FIM __--__--__--__--__--__\n\n", sol);


    return 0;
}
