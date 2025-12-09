#include <stdio.h> 
int main()
{
    char c;
    int x;
    scanf("%c",&c);
    x = (int)c;
    if (x>=65 && x<=90)
    {
        printf("Capital letter");
    }
    else if (x>=97 && x<=122)
    {
        printf("Small letter");
    }
    else
    {
        printf("Not in English alphabet");
    }

    return 0;
}
