#include <stack>
#include <iostream>
using namespace std;

string prefix_to_infix(string s)
{
    stack<string> st;
    string temp;
    for (int i = s.size()-1; i>=0; i--)
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
        {
            st.push(string(1,ch));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            temp = "(" + t1 + ch + t2 + ')';
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{

    string s = "+-6^2*379";
    cout << "Prefix: " << s << endl;
    cout << "Infix: " << prefix_to_infix(s);
    return 0;
}