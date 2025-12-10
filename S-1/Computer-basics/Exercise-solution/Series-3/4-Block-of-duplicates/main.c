#include <stdio.h>

int main()
{
    //Variables
    int in[100000];
    int n;
    int i,j;

    int n_out1 = 1,n_out2 = 1;
    int a;

    //Input
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&in[i]);
    }

    a = in[0];

    //Calculation // eslah shod v2

    for(i=0 ; i<n ; i++)
    {
        if(in[i] == in[i+1])
        {
            n_out2++;
        }
        else
        {
            if(n_out2 > n_out1)
            {
                n_out1 = n_out2;
                a = in[i-1];
            }
            n_out2 = 1;
        }
    }

    if(n_out2 > n_out1) // bray bolan tarin zanjiri ke dar akhar hast
    {
        n_out1 = n_out2;
        a = in[n-1];
    }

    //Output
    printf("%d %d",a,n_out1);


    return 0;
}
