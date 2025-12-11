#include <stdio.h>

int main()
{
    //Variables
    char in[5][20];
    char h[] = {'H','A','F','E','Z','\0'};
    char m[] = {'M','O','L','A','N','A','\0'};
    int i,j,z;
    int test_h = 0 ,test_m = 0;
    int out[5] = {0};
    //Input
    for (i = 0; i < 5; i++)
    {
        scanf("%19s", in[i]);
    }

    //Calculation
    for (j = 0; j < 5; j++) // i = shomare radif
    {
        for (i = 0; in[j][i] != 0; i++) // j = shoroe string
        {
            if (in[j][i] == h[0] || in[j][i] == h[1] || in[j][i] == h[2] || in[j][i] == h[3] || in[j][i] == h[4])
            {
                test_h;
                out[i] = 1;
            }
            if (in[j][i] == m[0] || in[j][i] == m[1] || in[j][i] == m[2] || in[j][i] == m[3] || in[j][i] == m[4] || in[j][i] == m[5])
            {
                test_m;
                out[i] = 1;
            }
        }
    }



    //Output
    if(out[0] == 0 && out[1] == 0 && out[2] == 0 && out[3] == 0 && out[4] == 0)
    {
        printf("NOT FOUND");
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            printf("%d",out[i]);
        }

    }



    return 0;
}
