#include <stdio.h>

int main()
{
    //Variables
    int in[100000];
    int n;
    int c = 0; // c = Counting
    int t = 0; // t =Test
    int i,j;


    //Input
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&in[i]);
    }


    //Calculation
    for(i=0 ; i<n ; i++)
    {
        t = 0;
        for(j=i+1 ; j<n ; j++)
        {
            if(in[i] == in[j])
            {
                t++;
            }
        }
        if(t == 0)
        {
            c++;
        }
    }


    //Output
    printf("%d",c);


    return 0;
}
