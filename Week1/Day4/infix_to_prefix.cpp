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
void reverse(string &k)
{

    for (int i = 0, j = k.size() - 1; i < j; i++, j--)
    {
        swap(k[i], k[j]);
    }
}
string infix_to_prefix(string s)
{
    reverse(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    string ans;
    stack<char> st;
    int i = 0;
    while (i < s.size())
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (ch == '^')
        {
            while (!st.empty() && priority(ch) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }

        else

        {
            while (!st.empty() && priority(ch) < priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }i++;
    }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
reverse(ans);

return ans;
}
int main()
{

    string s = "(A+B)*(C-D)/F-X*Y/Z";
    cout << "Infix: " << s << endl;
    cout << "Postfix: " << infix_to_prefix(s);
    return 0;
}