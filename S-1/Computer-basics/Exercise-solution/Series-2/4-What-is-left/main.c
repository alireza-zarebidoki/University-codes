#include <stdio.h>

int main()
{
    int a,b,r;
    scanf("%d %d",&a,&b);
    r = a-((a/b)*b);
    printf("%d",r);
}
