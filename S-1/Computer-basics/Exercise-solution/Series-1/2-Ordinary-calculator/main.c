#include <stdio.h>

int main()
{
    double n,m;
    char op;
    scanf("%lf %lf %c",&n,&m,&op);
    if(op=='+' || op=='-' || op=='*' || op=='/') // n>=0 && m>=0 && n<=1000 && m<=1000
    {
        if(op=='+')
        {
            printf("%.2lf",n+m);
        }
        else if(op=='-')
        {
            printf("%.2lf",n-m);
        }
        else if(op=='/')
        {
            if(m==0)
            {
                printf("Can not divide on 0");
            }
            else
            {
                printf("%.2lf",n/m);
            }
        }
        else
        {
            printf("%.2lf",n*m);
        }
    }
    else
    {
        printf("Invalid operator");
    }
    return 0;
}
