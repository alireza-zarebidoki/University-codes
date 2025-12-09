#include <stdio.h>

int main()
{
    long long int n;
    long long int f = 1;
    long long int f1 = 1;
    long long int f2 = 1;
    long long int i = 1;
    scanf("%lld",&n);
    printf("%lld ",f1);
    while(i<n)
    {
        printf("%lld ",f);
        f = f1+f2;
        f1 = f2;
        f2 = f;
        i++;
    }

}
