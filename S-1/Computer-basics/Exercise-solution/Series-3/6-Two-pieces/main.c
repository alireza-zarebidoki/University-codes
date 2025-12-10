#include <stdio.h>

int main()
{
    int n, arr[1000000], sum1=0, sum2=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for (int i=0; i<n; i++) {
        sum1 = 0, sum2 = 0;
        for (int j=0; j<i; j++) {
            sum1 += arr[j];
        }
        for (int j=i; j<n; j++) {
            sum2 += arr[j];
        }
        if (sum2 == sum1) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
