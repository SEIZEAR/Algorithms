#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp;
    int left_arr = start;
    int right_arr = mid + 1;

    // merge both halves
    while (left_arr <= mid && right_arr <= end)
    {
        if (arr[left_arr] < arr[right_arr])
        {
            temp.push_back(arr[left_arr++]);
        }
        else
        {
            temp.push_back(arr[right_arr++]);
        }
    }

    // copy remaining elements
    while (left_arr <= mid)
    {
        temp.push_back(arr[left_arr++]);
    }
    while (right_arr <= end)
    {
        temp.push_back(arr[right_arr++]);
    }

    // put back sorted elements into original array
    for (int i = 0; i < temp.size(); i++)
    {
        arr[start + i] = temp[i];
    }
}

void merge_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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
    merge_sort(array, 0, size - 1);
    print_array(array, size);
}