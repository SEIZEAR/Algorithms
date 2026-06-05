
#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int array[] = {5, 6, 78, 66, 12, 0, 78, 2, 0, 1, 99};
    int size = sizeof(array) / sizeof(int);
    selection_sort(array, size);
    print_array(array, size);

    return 0;
}