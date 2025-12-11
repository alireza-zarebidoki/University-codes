#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(i%2 == 0)
        {
            for(j=1;j<=n;j++)
            {
                if(i%2 == 0)
                {
                if(j%2 == 0) printf("O");
                else printf("X");
                }
                else
                {
                if(j%2 == 0) printf("X");
                else printf("O");
                }
            }
        }
        printf("\n");
    }
}
