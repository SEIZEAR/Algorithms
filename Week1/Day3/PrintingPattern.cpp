#include <iostream>
using namespace std;
int main()
{
    char ch;
    int row = 1;
    while (row <= 3)
    {
        int col = 1;
        while (col <= row)
        {
            ch = 'A' + row - 1;
            cout << ch;
            col++;
        }
        cout << endl;
        row++;
    }
}

