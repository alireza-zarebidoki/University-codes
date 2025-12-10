#include <stdio.h>

int main()
{
    //Variables
    int in[100000];
    int n;
    int size1 = 1,size2 = 1;
    int i,j;


    // Input
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&in[i]);
    }


    //Calculation
    for (i=1 ; i<n ; i++)
    {
        if(in[i]>in[i-1])
        {
            size2++;
        }
        else
        {
            if(size2 > size1)
            {
                size1 = size2;
            }
            size2 = 1;
        }
    }

    if(size2 > size1) // برای چک کردن مجدد آرایه هایی که تا آخر صعودی هستن
        {
            size1 = size2;
        }


    //Output
    printf("%d",size1);


    return 0;
}
