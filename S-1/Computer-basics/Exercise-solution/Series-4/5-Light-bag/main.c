#include <stdio.h>

int main()
{
    //Variables
    int n;
    int out = 0;



    //Input
    scanf("%d",&n);


    //Calculation
    if (n/10 != 0)
    {
        out += n/10;
        n -= 10*(n/10);
    }
    if (n/5 != 0)
    {
        out += n/5;
        n -= 5*(n/5);
    }
    if (n != 0)
    {
        out += n;
        n -= n;
    }



    //Output
    printf("%d",out);


    return 0;
}
