
/*

Sia data una matrice quadrata A di ordine N contenente valori interi 0 e 1.
Sia data una seconda matrice quadrata, B, di ordine 3.
Si scriva un programma in C che, letti in input gli elementi delle matrici A e B, verifichi se in
A esiste una sottomatrice identica a B (è sufficiente individuarne una - la prima). In caso
affermativo il programma deve stampare le coordinate di riga e colonna in A nelle quali si
trova l'elemento B[0][0].
Esempio: Consideriamo le due seguenti matrice:
A =
1 1 0 1 1 1 0 . . .B = 1 0 1
1 0 0 0 0 0 1 . . .
0 0 0
1 1 0 0 1 0 1 . . .
1 0 0
1 1 0 1 1 1 0 . . .
La matrice B può essere collocata in A a partire dalla riga di indice 0 e la colonna di indice
1.


*/

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define KERNEL_D 3



void getMat(int dim, int mat[dim][dim]);
int matchMat(int i, int j, int MatDim,  int Mat[MatDim][MatDim], int Kernel[KERNEL_D][KERNEL_D]);
int notFound = 1;


int main(int argc, char const *argv[])
{
    int dimensione;
    srand(time(0));
    printf("insert array dimension: ");
    scanf("%d", &dimensione);

    int mat[dimensione][dimensione];
    int kernelMat[KERNEL_D][KERNEL_D];

    getMat(dimensione, mat);
    printf("kernel: \n");
    getMat(KERNEL_D, kernelMat);
    while(notFound==1){
        for(int i=0; i< dimensione- KERNEL_D; i++)
            for(int j=0; j<dimensione- KERNEL_D; j++)
                notFound = matchMat(i,j, dimensione, mat, kernelMat);
            
        
        notFound=0;
    }
    
    return 0;
}

void getMat(int Dim, int mat[Dim][Dim]){
    for(int i = 0; i< Dim; i++){
        for(int j= 0; j<Dim; j++){
            mat[i][j]= rand()%2;
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }
    return;
}

int matchMat(int i, int j, int MatDim,  int Mat[MatDim][MatDim], int Kernel[KERNEL_D][KERNEL_D]){
    int notMatch=1;
    for(int x=0; x<(int)KERNEL_D; x++)
        for(int y=0; y<(int)KERNEL_D; y++)
            if(Mat[i+x][j+y] != Kernel[x][y])
                return notMatch;
    printf("match found starting from position: [%d] [%d] \n", i,j);
    return 0;
}