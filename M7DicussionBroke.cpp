#include <iostream>

int main()
{
    int multiplicationTable[5][5];

    for (int i = 1;i <= 5; i++)
    {
        for (int j = 0;j < 5; j++)
        {
            multiplicationTable[i][j] = i * j;
        }
    }

    return 0;
}