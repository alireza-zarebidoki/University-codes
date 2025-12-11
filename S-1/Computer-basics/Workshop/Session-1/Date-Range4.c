#include <stdio.h>

int main()
{
    int s1,e1,s2,e2,s3,e3,OUTPUT;
    printf("Enter the date range Like example : s1,e1,s2,e2,s3,e3 \n");
    scanf("%d,%d,%d,%d,%d,%d",&s1,&e1,&s2,&e2,&s3,&e3);

    s1 = s1*(s1>=s2 && s1>=s3) + s2*(s2>=s1 && s2>=s3) + s3*(s3>=s1 && s3>=s2);
    e1 = e1*(e1<=e2 && e1<=e3) + e2*(e2<=e1 && e2<=e3) + e3*(e3<=e1 && e3<=e2);
    OUTPUT = (s1<e1);
    printf("%d",OUTPUT);
}
