#include <stdio.h>

int main()
{
    int n,k;
    int f;
    int i = 1;
    scanf("%d %d",&n,&k);
    f = n;
    while(i<=k)
    {
        if(f<0 && f%2 != 0)
        {
            f = (f/2)-1;
        }
        else
        {
            f = f/2;
        }
        i++;
    }
    printf("%d",f);
}
