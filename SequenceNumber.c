#include <stdio.h>
void printSums(int N)
{
    int n;
    for(n = 1; n <= N / 2; n++)
    {
        int sum = 0;
        int i;
        for(i = n; i <= N; i++)
        {
            sum = sum + i;
            if(sum == N)
            {
                int j;
                for(j = n; j <= i; j++)
                {
                    printf("%d ", j);
                }
                printf("\n");
                break;
            }
            if(sum > N)
            {
                break;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    printSums(N);
    return 0;
}