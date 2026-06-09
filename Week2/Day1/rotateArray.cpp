#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

vector<int> rotate_array(vector<int> v, int k)
{
    vector<int> temp(v.size()); // allocate same size
    for (int i = 0; i < v.size(); i++)
    {
        temp[(i + k) % v.size()] = v[i];
    }
    return temp;
}

int main()
{
    vector<int> v = {-0, 35, 6, -10, 3230, 0, 7, 0};
    int k = 4;
    vector<int> ans = rotate_array(v, k);
    print_array(ans);
    return 0;
}
