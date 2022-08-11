
#include <iostream>
using namespace std;

int main()
{

    string s = "ab34c59dm9";
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (is_digit(s[i]))
        {
            sum += (s[i] - '0')
        }
    }
    cout << sum;
}