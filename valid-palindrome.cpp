#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool isPalindrome(string s)
{
    if (s == "")
    {
        return true;
    }
    
    string str = "";
    string rev = "";

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            str += tolower(s[i]);
        }
    }

    for (int i = str.length() - 1; i >= 0; i--)
    {
        rev += str[i];
    }
    
    return str == rev;

}

int main()
{

    string s = "0P";

    bool res = isPalindrome(s);

    cout << res << endl;

    return 0;
}