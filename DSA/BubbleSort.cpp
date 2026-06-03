
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])

            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
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
    bubble_sort(array, size);
    print_array(array, size);

    return 0;
}