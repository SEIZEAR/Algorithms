#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivot_index = start + count;
    swap(arr[pivot_index], arr[start]);

    int i = start, j = end;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= pivot  && i < pivot_index)
            i++;
        while (arr[j] > pivot && j > pivot_index)
            j--;
        if (i < pivot_index && j > pivot_index)
            swap(arr[i++], arr[j--]);
 
     }
        return pivot_index;
}
void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {5, 6, 78, -66, 12, 0, 78, -2, 0, 1, 99};
    int size = sizeof(array) / sizeof(int);
    quick_sort(array, 0, size - 1);
    print_array(array, size);
}