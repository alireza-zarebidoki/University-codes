#include <stdio.h>

int main()
{
    int a,b;
    int i = 1;


    printf("Enter a^b : ");
    scanf("%d^%d",&a,&b);

    if(a>=0 && a<=10 && a>=0 && a<=10)
    {
        while (i<=b)
        {
            a = a*a;
            i++;
        }
        printf("a^b = %d",a);
    }
    else
    {
        printf("Invalid value.");
    }

    return 0;
}
