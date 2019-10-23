/*
Si codifichi un programma C che legge due stringhe inserite dall'utente che rappresentano due
parole e verifica se le parole sono anagrammi, cioè se è possibile ottenere l’una dall’altra tramite
permutazione delle loro lettere. Stampa infine a schermo il risultato della verifica.
Esempio:
Le parole POLENTA e PENTOLA sono anagrammi
Le parole TAPPO e PATTO non sono anagrammi
*/


#include "stdio.h"
#include "string.h"

#define STR_LEN 20
int main(int argc, char const *argv[])
{
    
    char word1[STR_LEN];
    char word2[STR_LEN];

    int table[26] = {0};

    printf("Enter your first anaWord:");
    scanf("%s", word1); 
    printf("\nEnter your second anaWord:");
    scanf("%s", word2); 
    int len = strlen(word1);
    if(len-strlen(word2)!=0){
        printf("not anagramma I'm sorry \n");
        return 0;
    }
        
    for(int i=0; i<len; i++){
        table['z'-word1[i]] +=1;
        table['z'-word2[i]] -=1;
    }

    for(int i=0; i<26; i++){
        if(table[i]){
            printf("not anagramma I'm sorry \n");
            return 0;
        }
    }
  
    printf("Correct!! \n");
   

    return 0;
}
