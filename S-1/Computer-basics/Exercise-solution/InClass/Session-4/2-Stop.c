#include <stdio.h>

int main()
{
    char input[100];
    char stop[5] = {'s','t','o','p','\0'};
    int i = 0;
    while(1)
    {
        scanf("%s",&input);
        if(input[0] == stop[0] && input[1] == stop[1] && input[2] == stop[2] && input[3] == stop[3] && input[4] == stop[4]) break;
        else printf("You said %s\n",input);
        i++;
    }
}
