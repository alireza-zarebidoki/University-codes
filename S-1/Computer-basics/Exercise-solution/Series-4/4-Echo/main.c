#include <stdio.h>

char s[100000001];

int main()
{
    //Variables
    int test = 0;
    int n=0;

    int i;

    //Input
    scanf("%s",s);


    //Calculation
    for (i = 0; s[i] != 0; i++)
    {
        if (test != s[i] && n!=0)
        {
            test = s[i];
            printf("%d",n);
            printf("%c",s[i]);
            n = 1;
        }
        else if (test != s[i] && n==0)
        {
            test = s[i];
            printf("%c",s[i]);
            n = 1;
        }

        else
        {
            n++;
        }
    }
    printf("%d",n);

    return 0;
}
