#include <stdio.h>

int main()
{
    int n = 1;
    int i = 1;
    int j = 1;

    printf("Enter N : ");
    scanf("%d",&n);

    if(n>=1 && n<=10)
    {
        while (j<=n)
        {
            while (i<=n)
            {
                printf("%3d ",i*j);
                i++;
            }
            printf("\n");
            i = 1;
            j++;
        }
    }
    else
    {
        printf("Invalid value.");
    }

    return 0;
}
