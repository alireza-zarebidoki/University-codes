#include <stdio.h>

int main()
{
    //Variables
    int n;

    int i,j;

    //Input
    scanf("%d",&n);


    //Calculation & Output
    for (i = 1; i <= n; i++)//UP
    {
        for (j = 0; j < n-i ; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= (i*2)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = n-1; i >= 1; i--)
    {
        for (j = 0; j < n-i ; j++)
        {
            printf(" ");
        }
        for (j = (i*2)-1; j >= 1; j--)
        {
            printf("*");
        }
        printf("\n");
    }



    return 0;
}
