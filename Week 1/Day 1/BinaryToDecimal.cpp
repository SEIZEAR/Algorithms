#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int last_digit, ans = 0, i = 0;
    while (n != 0)
    {
        last_digit = n % 10;
        if (last_digit == 1)
        {
            ans += pow(2, i);
        }
        i++;
        n /= 10;
    }
    cout << ans;
}