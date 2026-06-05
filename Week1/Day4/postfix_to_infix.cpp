#include <stack>
#include <iostream>
using namespace std;
int priority(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '-' || ch == '+')
        return 1;
    else
        return 0;
}

string postfix_to_infix(string s)
{
    stack<string> st;
    string temp;
    for (int i = 0; i < s.size(); i++)
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
            temp = "(" + t2 + ch + t1 + ')';
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{

    string s = "2532^*+9+";
    cout << "Postfix: " << s << endl;
    cout << "Infix: " << postfix_to_infix(s);
    return 0;
}