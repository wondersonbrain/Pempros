// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson

#include <stdio.h>
#include <stdlib.h> 

int main(int _argc, char **_argv) 
{   
    int *bilangan;
    int n, max, min;
    scanf ("%d", &n);
    bilangan = (int*) malloc(sizeof(int)*n);
    int x;
    for ( x = 0 ; x < n; x++)
    {
        scanf("%d", &bilangan[x]);
    }

    max=bilangan[0];
    min=bilangan[0];
    for(int x=0; x<n; x++)
    {
        if (bilangan[x]>max)
        {
            max=bilangan[x];
        }
        if (bilangan[x]<min)
        {
            min=bilangan[x];
        }
    }
    printf("%d\n", min);
    printf("%d\n", max);
    
    return 0;
}

