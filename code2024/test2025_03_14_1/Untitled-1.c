#include <stdio.h>

int Ackmann(int m, int n);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int num = Ackmann(m, n);
    printf("%d", num);
    return 0;
}

int Ackmann(int m, int n)
{
    if (m > 0 && n > 0)
    {
        return Ackmann(m - 1, Ackmann(m, n - 1));
    }
    else if (m > 0 && n == 0)
    {  
        return Ackmann(m - 1, 1);
    }
    else if (m == 0)
    {
        return n + 1;
    }
}
