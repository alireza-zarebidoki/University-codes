#include <stdio.h>

int main()
{
    //Variables
    int in[10000];
    int out[10000];
    int n;
    int i;
    int j = 0;
    int z = 0;

    //Input
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&in[i]);
    }

    //Calculation
    for(i=0 ; i<n ; i++)
    {
        if(in[i] != in[i+1])
        {
            out[j] = in[i];
            j++;
            z++;
        }
    }

    //Output
    for(i=0 ; i<z ; i++)
    {
        printf("%d ",out[i]);
    }
}
