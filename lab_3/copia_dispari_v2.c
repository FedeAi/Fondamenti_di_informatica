/* ==================================================================================

Esercizio 2 – Copia dispari v. 2.0
Modificare il programma dell'Esercizio 1 in modo che la matrice Mat1 di interi NxN, con N
costante opportunamente definita, venga letta da un file di testo chiamato 'matrice.txt'
nel formato:
1,2,3
4,5,6
7,8,9
Il programma, prima di procedere con la copia, verifica che la matrice definita nel file
abbia le dimensioni richieste. Se la matrice non è di dimensioni NxN allora deve
comparire un messaggio di errore a video e il programma viene terminato.
Come nell'Esercizio 1, la funzione copia i soli elementi dispari in una nuova matrice Mat2
della stessa dimensione, senza lasciare posizioni vuote intermedie.
Implementare un main() che, dopo aver richiamato la funzione implementata, scriva in
un file di testo 'matrice_dispari.txt' la nuova matrice Mat2, rispettando il formato
riportato sopra.

================================================================================== */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define N 3

int Mat1[N][N];

int Mat2[N][N];

void copia_dispari(int Mat1[][N], int Mat2[][N])
{
    int n = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (Mat1[i][j] % 2 != 0)
            {
                Mat2[n / N][n % N] = Mat1[i][j];
                n++;
            }
        }
}

int leggi_mat(int Mat[N][N])
{
    FILE *fp;
    fp = fopen("matrice.txt", "r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return -1;
    }
    for (int i = 0; i < N * N; i++)
    {
        fscanf(fp, "%d,", &Mat[i / N][i % N]);
    }
}
void print_mat2d(int Mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d,", Mat[i][j]);
        printf("\n");
    }
}

int main()
{
    leggi_mat(Mat1);
    copia_dispari(Mat1, Mat2);
    print_mat2d(Mat1);
    printf("\n Mat2: \n");
    print_mat2d(Mat2);
}
