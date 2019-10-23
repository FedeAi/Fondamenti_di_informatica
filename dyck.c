/*

Nella teoria del linguaggi formali, il linguaggio di Dyck consiste in stringhe bilanciate di parentesi
quadre ‘[‘ e ‘]’. Codificare un programma C che sappia riconoscere se una stringa inserita
dall’utente appartenga al linguaggio di Dyck o meno.
Esempio:
La stringa [[[][]][]] appartiene al linguaggio di Dyck.
La stringa [[[]][]]]] non appartiene al linguaggio di Dyck.

*/

#include "stdio.h"
#include "string.h"


int main(int argc, char const *argv[])
{
    
    char dyck[20];

    printf("Enter your dyck expression:");
    scanf("%s", dyck); 
    int count = 0, status=1;
    int i=0;
    while(i<strlen(dyck) && status){
        if(dyck[i] == '[')
            count++;
        else if(dyck[i]== ']')
            count--;

        
        if( count < 0){
            printf("\nwrong expression _s !!!\n");
            status=0;
            return 0;
        }
        i++;
    }
    if( count > 0)
        printf("\nwrong expression %d!!!\n", count);
        
    else
    {
        printf("correct expression!\n");
    }
    

    return 0;
}
