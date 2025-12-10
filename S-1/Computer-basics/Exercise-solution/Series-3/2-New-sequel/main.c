#include <stdio.h>
int main()
{
    int n;
    int old[10000];
    int new[10000];
    int i,j,z;

    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&old[i]);
    }

    new[0] = old[0];
    for(j=1 ; j<n ; j++)
    {
        new[j] = old[j]-old[j-1];
    }

    for(z=0 ; z<n ; z++)
    {
        printf("%d ",new[z]);
    }
}
