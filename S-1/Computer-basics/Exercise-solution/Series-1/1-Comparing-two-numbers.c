#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b) printf("a is bigger than b");
    else if(b>a) printf("b is bigger than a");
    else printf("a and b are equal");

    return 0;
}
