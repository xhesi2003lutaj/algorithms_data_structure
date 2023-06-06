#include <iostream>

using namespace std;

int count(int coins[], int n, int sum)
{
    int table[n][sum+1];

    for (int i = 0; i < n; i++) {
        table[i][0] = 1;
    }

    for (int i = 0; i <= sum; i++) {
        if (i % coins[0] == 0) {
            table[0][i] = 1;
        } else {
            table[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i] > j) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = table[i-1][j] + table[i][j-coins[i]];
            }
        }
    }

    return table[n-1][sum];
}

int main()
{
    int coins[] = { 1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;
    cout << count(coins, n, sum) << endl;

    return 0;
}
