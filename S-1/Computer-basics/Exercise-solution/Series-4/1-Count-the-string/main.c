#include <stdio.h>

int main()
{
    //Variables
    char string[1001];
    int length = 0;
    int i;

    //Input
    scanf("%s",string);


    //Calculation
    for (i = 0; string[i] != 0; i++)
    {
        length++;
    }





    //Output
    printf("%d",length);


    return 0;
}
