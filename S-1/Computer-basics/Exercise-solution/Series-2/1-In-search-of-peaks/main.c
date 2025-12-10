#include <stdio.h>
int main()
{
    int n;
    int in[1000];
    int i,j;
    int z = 0;
    int out[1000];

    scanf("%d",&n);

    for(j=0 ; j<n ; j++)
    {
        scanf("%d",&in[j]);
    }

    for(i=1 ; i<n-1 ;i++)
    {
        if(in[i]>in[i-1] && in[i] > in[i+1])
        {
        out[z] = i;
        z++;
        }
    }

    for(i=0 ; i<z ; i++)
        printf("%d ",out[i]);
}
