#include "stdio.h"
#define N_DAYS 7
int main(int argc, char const *argv[])
{   
    float temperatures[N_DAYS];

    for(int i=0; i<N_DAYS; i++ ){
        printf("insert measured temperature on day %d: ",i);
        scanf("%f",&temperatures[i]);
    }
    
    printf("DAY\tVALUE\tHISTOGRAM\n");
    for(int i=0; i<N_DAYS; i++){
        printf("%3d \t%3.2f", i, temperatures[i]);
        if(temperatures[i]>34)
            printf("\t%9.*s", (int)temperatures[i]-34, "***************");
        printf("\n");
        printf("\a");
    }

    float mean=0, max=0, min=temperatures[0];

    for(int i=0;i<N_DAYS; i++){
        mean+=temperatures[i];
        if(temperatures[i]>max)
            max=temperatures[i];
        else if(temperatures[i]< min)
            min=temperatures[i];

    }

    printf("mean value: %.2f \nmax value: %.2f \nmin value: %.2f \n", mean/N_DAYS, max, min );
    
    return 0;
}
