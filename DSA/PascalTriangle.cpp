#include <iostream>
using namespace std;
int main()
{
    int n;
    int number;

    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        int pascal = 1;
        for (int spacee = 1; spacee <= n - row; spacee++)
        {
            cout << " ";
        }
        for (int col = 1; col <= row; col++)
        {
            cout << pascal;
            pascal++;
        }
        number = row - 1;
        for (int triangle = 1; triangle <= row - 1; triangle++)
        {
            cout << number;
            number--;
        }
        cout << endl;
    }

}
