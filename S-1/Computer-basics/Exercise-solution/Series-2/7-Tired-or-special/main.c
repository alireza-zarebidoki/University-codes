#include <stdio.h>

int main()
{
    int x;
    int r;
    int s = 0;
    int c = 0;
    int i = 1;
    scanf("%d",&x);

    while (i<=x)
    {
        if(x%i == 0) r = i;
        if(r*r == x) s = 1;
        if(r*r*r == x) c = 1;
        i++;
    }


    if(s==1 && c==1) printf("super number");
    else if(s==1) printf("square");
    else if(c==1) printf("cube");
    else printf("boring number");
}
