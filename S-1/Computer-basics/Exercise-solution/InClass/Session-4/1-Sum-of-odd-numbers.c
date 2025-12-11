#include <stdio.h>

int main()
{
    int n = 0;
    int sum = 0;
    int i ;
    scanf("%d",&n);
    for(i=1 ; i<=n ; i+=2)
    {
        sum += i;
    }
    printf("%d",sum);

}
