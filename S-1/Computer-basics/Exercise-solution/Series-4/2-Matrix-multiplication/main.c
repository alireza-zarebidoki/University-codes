#include <stdio.h>

int main()
{
    //Variables
    int r1,c1,r2,c2,r,c;
    int A[100][100]; // [r1][c1]
    int B[100][100]; // [r2][c2]
    int AmB[100][100]={0}; //[r][c]

    int i,j,z;

    //Input
    scanf("%d %d",&r1,&c1);

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }


    scanf("%d %d",&r2,&c2);

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d",&B[i][j]);
        }
    }



    //Calculation

    r = r1;
    c = c2;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (z = 0; z < c1; z++)
            {
                AmB[i][j] += (A[i][z]*B[z][j]);
            }
        }
    }



    //Output
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ",AmB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
