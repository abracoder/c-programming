// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[2 * n - 1][2 * n - 1];
    a[n - 1][n - 1] = 1;
    int i = 1;
    while (i < n)
    {

        for (int j = n - i; j <= n + i; j++)
        {
            a[n - i - 1][j - 1] = i + 1;
            a[n + i - 1][j - 1] = i + 1;
            a[j - 1][n - i - 1] = i + 1;
            a[j - 1][n + i - 1] = i + 1;
        }

        i++;
    }
    // printing
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}