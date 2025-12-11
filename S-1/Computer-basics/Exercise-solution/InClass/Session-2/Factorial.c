#include <stdio.h>

int main()
{
    int n = 0;
    int i = 1;
    int f = 1;
    printf("Enter N : ");
    scanf("%d",&n);

    if (n>=0 && n<=12)
    {
        while (i<=n)
        {
            f = f*i;
            i++;
        }
        printf("!n = %d",f);
    }
    else
    {
        printf("Invalid value.");
    }
    return 0;
}
