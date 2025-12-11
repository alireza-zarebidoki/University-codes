#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int i,j,r;
    for(i=1;i<=n;i++)
    {
        if(i%2 == 0)
        {
            for(j=1;j<=n;j++)
            {
                if(j%2 == 0) printf("O");
                else printf("X");
            }
        }
        else
        {
            for(r=1;r<=n;r++)
            {
                if(r%2 == 0) printf("X");
                else printf("O");
            }
        }
        printf("\n");
    }
}
