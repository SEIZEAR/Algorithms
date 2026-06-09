#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int, int> search_element(vector<vector<int>> arr, int rows, int cols, int target)
{
    int row = 0, col = cols - 1;
    while (row < rows && col >=0)
    {

        int mid_value = arr[row][col];
        if (mid_value == target)
            return {row, col};
        else if (mid_value < target)
            row++;
        else
            col--;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> arr = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
    };

    int rows = arr.size(), cols = arr[0].size(), target = 11;

    pair<int, int> element = search_element(arr, rows, cols, target);

    if (element.first != -1)
        cout << "Element " << target << " found at position ("
             << element.first << "," << element.second << ")\n";
    else
        cout << "Element " << target << " not found in matrix.\n";

    return 0;
}
