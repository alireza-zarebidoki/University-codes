#include <stdio.h>

int main()
{
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if((x2-x1)==0 && (y2-y1)>=0)
    printf("+infinite");
    else if((x2-x1)==0 && (y2-y1)<=0)
    printf("-infinite");
    else
    printf("%d",(y2-y1)/(x2-x1));
}
