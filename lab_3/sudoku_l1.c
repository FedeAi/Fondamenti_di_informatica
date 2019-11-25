/*

Esercizio 3 – Sudoku
Si realizzi un programma che verifichi la corretta soluzione della griglia di un Sudoku.
Un Sudoku è una griglia 9x9 che rispetta queste caratteristiche:
    – tutti i valori devono essere singoli numeri tra 1 e 9
    – su ciascuna delle 9 righe non devono esserci valori ripetuti
    – su ciascuna delle 9 colonne non devono esserci valori ripetuti
    – in ciascuno dei 9 blocchi 3x3 che compongono la griglia non devono esserci valori
ripetuti
L'esercizio è da risolvere svolgendo un livello dopo l'altro, secondo questa sequenza:
Livello 1 – Utilizzare il file sudoku_template.c fornito assieme a questo testo come
punto di partenza: il file contiene la dichiarazione di due matrici Sudoku da verificare (unacorretta e l'altra sbagliata). Il programma deve verificare la validità di queste due matrici e
stampare a video il risultato del controllo. In questo livello il programma va scritto senza
utilizzare le funzioni (quindi completando solo il main() già esistente).
*/

#include <stdio.h>

#define N 9

int sudoku_corretto[N][N] = {{5, 8, 6, 4, 2, 1, 3, 7, 9}, {3, 2, 7, 9, 6, 5, 4, 8, 1}, {9, 1, 4, 3, 7, 8, 6, 2, 5}, {1, 6, 3, 5, 8, 4, 7, 9, 2}, {2, 4, 5, 1, 9, 7, 8, 6, 3}, {8, 7, 9, 6, 3, 2, 5, 1, 4}, {7, 5, 8, 2, 1, 3, 9, 4, 6}, {6, 3, 1, 7, 4, 9, 2, 5, 8}, {4, 9, 2, 8, 5, 6, 1, 3, 7}};

int sudoku_sbagliato[N][N] = {{5, 8, 6, 4, 2, 1, 3, 7, 9}, {3, 2, 7, 9, 1, 5, 4, 8, 1}, {9, 1, 4, 3, 7, 8, 6, 2, 5}, {1, 6, 3, 5, 8, 4, 7, 9, 2}, {2, 4, 5, 1, 9, 7, 8, 6, 3}, {8, 7, 4, 6, 3, 2, 5, 1, 4}, {7, 5, 8, 2, 1, 3, 9, 4, 6}, {6, 8, 1, 7, 4, 9, 2, 5, 8}, {4, 9, 2, 8, 5, 2, 1, 3, 7}};

int controllo_riga(int array[9])
{
    int ck[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        ck[array[i]]++;
        if (ck[i] > 1)
        {
            printf("errore nella riga-colonna");
            return 0;
        }
    }
    return 1;
}

int controllo_r_c(int array[N][N]){
    for(int i=0; i<9; i++){
        controllo_riga(array[i]);
        
    }
}
int controllo_blocchi(int array[N][N])
{
    //int n_blocchi = N / 3;
    for(int i = 0; i< N; i++){
        int ck[9] = {0};
        for(int j=0; j<9; j++){

            ck[array[i*3 % 3 + j / 3][i / 3 + j % 3]]++;
            if (ck[i] > 1)
            {
                printf("errore nella riga-colonna");
                return 0;
            }
        }
    }
    return 1;
}
int main()
{   
    controllo_blocchi(sudoku_corretto);
    controllo_r_c(sudoku_corretto);
    return 0;
}
