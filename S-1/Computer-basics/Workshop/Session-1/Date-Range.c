#include <stdio.h>

int main()
{
    int s1,e1,s2,e2,s3,e3;
    int s,e;
    printf("Enter the date range Like example : s1,e1,s2,e2,s3,e3 \n");
    scanf("%d,%d,%d,%d,%d,%d",&s1,&e1,&s2,&e2,&s3,&e3);
    s = s1;
    if(s2>=s1)
    {
        s = s2;
        if(s3>=s2)
        {
            s = s3;
        }
        else
        {
            s = s2;
        }
    }
    else
    {
        s = s1;
    }

    e = e1;
    if(e2<=e1)
    {
        e = e2;
        if(e3<=e2)
        {
            e = e3;
        }
        else
        {
            e = e2;
        }
    }
    else
    {
        e = e1;
    }

    if(e>s)
    {
        printf("possible");
    }
    else
    {
        printf("impossible");
    }
}
