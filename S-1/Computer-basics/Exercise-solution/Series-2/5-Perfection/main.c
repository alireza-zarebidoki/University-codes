#include <stdio.h>

int main()
{
    int n;
    int d = 0;
    int i = 1;
    scanf("%d",&n);
    while(i<n)
    {
        if(n%i == 0)
        {
            d +=i;
        }
        i++;
    }
    if(n==d) printf("Yes");
    else printf("No");
}
