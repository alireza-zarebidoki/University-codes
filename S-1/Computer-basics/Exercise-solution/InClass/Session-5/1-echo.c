#include <stdio.h>

int main()
{
    //Variables
    char s[100];
    int i,j;


    //Input
    printf("Enter the word : \n");
    scanf("%s",s);


    //Calculation & Output
    for (i = 0; s[i] != 0 ; i++)
    {
        for (j = 0; j != i; j++)
        {
            s[j] = s[i];
        }
        printf("%s\n",s);
    }



    return 0;
}
