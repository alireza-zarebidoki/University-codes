#include <stdio.h>

int main()
{
    float a;
    printf("Score: ");
    scanf("%f",&a);
    if(a>=0 && a<=20)
    {
        if(a<=20 && a>= 17)
        {
            printf("A");
        }
        else if(a<17 && a>=14)
        {
            printf("B");
        }
        else if(a<14 && a>=12)
        {
            printf("C");
        }
        else
        {
            printf("D");
        }
    }
    else
    {
        printf("Invalid");
    }

}
