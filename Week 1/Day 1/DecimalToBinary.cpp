
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int binary[8] = {0};
    int num = n;
    if (n < 0)
        num = -n;

    int index = 7;
    while (num != 0)
    {

        binary[index] = num % 2;

        num /= 2;
        index--;
    }

    if (n < 0)
    {
        for (int i = 0; i < 8; i++)
        {
            binary[i] = 1 - binary[i];
        }
        int carry = 1;

        for (index = 7; index >= 0; index--)
        {
            int sum = binary[index] + carry;
            binary[index] = sum % 2;
            carry = sum / 2;
         
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << binary[i];
    }
    return 0;
}
