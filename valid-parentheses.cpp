#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s) {
     bool result = false;
     char top;
     int open = 0, close = 0;
     
     stack<char>st;

     for (int i = 0; i < s.size(); i++)
     {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            open++;
        } else {
            if (!st.empty())
            {
                top = st.top();
                st.pop();
            }
            close++;
        }

        if (s[i] == ')')
        {
            if (top == '(')
            {
                result = true;
            } else {
                result = false;
                break;
            } 
        } else if (s[i] == '}')
        {
            if (top == '{')
            {
                result = true;
            } else {
                result = false;
                break;
            } 
        } else if (s[i] == ']')
        {
            if (top == '[')
            {
                result = true;
            } else {
                result = false;
                break;
            } 
        }
        
     }

     if (!st.empty() || open != close)
     {
        result = false;
     }
     

     return result;   
}

int main() {

    string x;

    cin >> x;

    bool res = isValid(x);

    cout << res << endl;

    return 0;
}