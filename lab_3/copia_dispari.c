/* ==================================================================================

Esercizio 1 – Copia dispari
Scrivere una funzione in C che data una matrice Mat1 di interi NxN, con N costante
opportunamente definita, copia i soli elementi dispari in una nuova matrice Mat2 della
stessa dimensione, senza lasciare posizioni vuote intermedie.
Implementare un main() che, dopo aver richiamato la funzione implementata, stampa a
video la nuova matrice, visualizzando gli elementi per righe.

================================================================================== */
#include "stdio.h"
#define N 3

int Mat1[N][N] =
    {1, 5, 3,
     3, 4, 4,
     17, 26, 13};

int Mat2[N][N];

//attenzione non funziona
void copia_dispari_p(int Mat1[][N], int Mat2[][N])
{
    int n = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (Mat1[i][j] % 2 != 0)
            {
                n++;
                **Mat2 = Mat1[i][j];
                Mat2++;
                if (n >= N)
                {
                    n = 0;
                    *Mat2++;
                }
            }
        }
}

void copia_dispari(int Mat1[][N], int Mat2[][N])
{
    int n = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (Mat1[i][j] % 2 != 0)
            {
                Mat2[n / 3][n % N] = Mat1[i][j];
                n++;
            }
        }
}
void print_mat2d(int Mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", Mat[i][j]);
        printf("\n");
    }
}

int main()
{
    copia_dispari(Mat1, Mat2);
    print_mat2d(Mat1);
    printf("\n Mat2: \n");
    print_mat2d(Mat2);
}
 
