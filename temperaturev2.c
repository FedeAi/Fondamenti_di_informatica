/**************************************************************
Modificare l'esercizio precedente in modo che i risultati vengano stampati sotto forma di un
istogramma verticale, usando come carattere un asterisco (inserire un * per ogni valore di
temperatura superiore a 34 con approssimazione per difetto), scrivendo in basso il valore relativo a
ogni colonna.
Esempio:
* *
* * *
* * *
* * *
* * * *
* * * *
39 40 36 40

***************************************************************/


#include "stdio.h"
#define N_DAYS 7

int main(int argc, char const *argv[])
{   
    float temperatures[N_DAYS];
    float temperatures_cp[N_DAYS];

    for(int i=0; i<N_DAYS; i++ ){
        printf("insert measured temperature on day %d: ",i);
        scanf("%f",&temperatures[i]);
        temperatures_cp[i]= temperatures[i];
    }

    float mean=0, max=0, min=temperatures[0];

    for(int i=0;i<N_DAYS; i++){
        mean+=temperatures[i];
        if(temperatures[i]>max)
            max=temperatures[i];
        else if(temperatures[i]< min)
            min=temperatures[i];

    }
    
    int indexTemp=max-34;
    while(indexTemp>0){
        for(int i=0; i<N_DAYS; i++){
            int overTemp = (int) temperatures_cp[i]-34;
            printf("\t");
            if(overTemp==indexTemp){
                printf("*");
                temperatures_cp[i]--;
            }
            
        }
        printf("\n");
        indexTemp--;
    }

    for(int i=0; i<N_DAYS; i++)
        printf("\t%.2f",temperatures[i]);

    

    printf("\nmean value: %.2f \nmax value: %.2f \nmin value: %.2f \n", mean/N_DAYS, max, min );
    
    return 0;
}
