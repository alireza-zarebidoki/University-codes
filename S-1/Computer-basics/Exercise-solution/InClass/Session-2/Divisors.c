#include <stdio.h>

int main()
{
    int n;
    int i = 1;
    printf("Enter N : ");
    scanf("%d",&n);

    printf("Divisors of %d : ",n);
    while (i<=n)
    {
        if (n%i == 0)
        {
            printf("%d ",i);
        }
        i++;
    }
}
