#include <stdio.h>

int main()
{
    int a,b,k;
    int x = 0;
    scanf("%d %d %d",&a,&b,&k);
    while (a<=b)
    {
        if(a%k==0)
        {
            x +=a;
        }
        a++;
    }
    printf("%d",x);
}
