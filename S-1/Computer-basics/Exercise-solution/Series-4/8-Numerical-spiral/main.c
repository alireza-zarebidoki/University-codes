#include <stdio.h>

int M[100][100]; // [y][x]


int main()
{
    //Variables
    int n;
    int x,y;
    int a = 1; //Amount

    int i,j;

    //Input
    scanf("%d",&n);


    //Calculation
    y = (n/2);
    x = (n/2);

    M[y][x] = a; //mid

    for (i = 1 ; i <= n ; i++)
    {
        if (i%2 != 0) // i = 1,3,5
        {
            for (j = 0; j < i; j++)
            {
                if (a >= n * n) break; // FIX: اگر ماتریس پر شد، خارج شو
                a++;
                x++;
                M[y][x] = a;
            }
            for (j = 0; j < i; j++)
            {
                if (a >= n * n) break; // FIX: اگر ماتریس پر شد، خارج شو
                a++;
                y++;
                M[y][x] = a;
            }
        }
        else // i = 2,4,6
        {
            for (j = 0; j < i; j++)
            {
                if (a >= n * n) break; // FIX: اگر ماتریس پر شد، خارج شو
                a++;
                x--;
                M[y][x] = a;
            }
            for (j = 0; j < i; j++)
            {
                if (a >= n * n) break; // FIX: اگر ماتریس پر شد، خارج شو
                a++;
                y--;
                M[y][x] = a;
            }
        }
    }



    //Output
    int width = 1;
    if (n * n >= 100) {
        width = 2;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%*d", width, M[i][j]);

            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }




    return 0;
}
