#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i * i <= n; i++);
    printf("%d", i - 1);
}