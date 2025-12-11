#include <stdio.h>

int main()
{
    // Variables
    char in[5][20];
    char h[] = {'H','A','F','E','Z','\0'};
    char m[] = {'M','O','L','A','N','A','\0'};
    int i,j,z;
    int test_h = 0 ,test_m = 0;
    int out[5] = {0};

    printf("Enter 5 strings:\n");
    // Input
    for (i = 0; i < 5; i++)
    {
        scanf("%19s", in[i]);
    }


    for (i = 0; i < 5; i++)
    {

        test_h = 1;

        for (j = 0; j < 5; j++)
        {
            if (in[i][j] != h[j])
            {
                test_h = 0;
                break;
            }
        }


        if (test_h == 1 && in[i][5] != '\0')
        {
            test_h = 0;
        }

        if (test_h == 1)
        {
            out[i] = 1;
            continue;
        }

        test_m = 1;


        for (j = 0; j < 6; j++)
        {
            if (in[i][j] != m[j])
            {
                test_m = 0;
                break;
            }
        }


        if (test_m == 1 && in[i][6] != '\0')
        {
            test_m = 0;
        }

        if (test_m == 1)
        {
            out[i] = 1;
        }
    }


    // Output
    z = 0;
    for (i = 0; i < 5; i++)
    {
        if (out[i] == 1)
        {
            z = 1;
            break;
        }
    }

    if(z == 0)
    {
        printf("NOT FOUND");
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            if(out[i] == 1)
            printf("%d ",i+1);
        }
    }

    return 0;
}
