#include <stdio.h>

int A[1000000];

int main()
{
    //Variables
    int n;
    int target;
    int answer = (-1);
    int start,middle,end;

    int i,j;

    //Input
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }

    scanf("%d",&target);


    //Calculation
    start = 0;
    end = n-1;

    for (i = start; start <= end ; i++)       /////////////
    {
        middle = ((start+end)/2);

        if (target == A[middle])
        {
            answer = middle;
            break;
        }
        else if (target < A[middle])
        {
            end = middle-1;
        }
        else
        {
            start = middle+1;
        }

    }



    //Output
    printf("%d",answer);


    return 0;
}
