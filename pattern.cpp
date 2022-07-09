#include <iostream>
#include <vector>
using namespace std;

int main()

{
    int n;
    cin >> n;
    int size = 2 * n - 1;
    int l = 0, r = 2 * n - 2;
    vector<vector<int>> res(size, vector<int>(size));
    while (n != 0)
    {
        for (int i = l; i <= r; ++i)
        {
            for (int j = l; j <= r; ++j)
            {
                if (i == l || i == r || j == l || j == r)
                    res[i][j] = n;
            }
        }
        ++l;
        --r;
        --n;
    }
    for (auto it : res)
    {
        cout << endl;
        for (auto a : it)
            cout << a << " ";
    }
}