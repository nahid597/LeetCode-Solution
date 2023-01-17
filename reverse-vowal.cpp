#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'A')
    {
        return true;
    }
    else if (ch == 'e' || ch == 'E')
    {
        return true;
    }
    else if (ch == 'i' || ch == 'I')
    {
        return true;
    }
    else if (ch == 'o' || ch == 'O')
    {
        return true;
    }
    else if (ch == 'u' || ch == 'U')
    {
        return true;
    }

    return false;
};

string reverseVowels(string s)
{
    string result;

    int l = 0, r = s.size() - 1;
    bool p, q;

    // hello

    while (l < r)
    {
        p = isVowel(s[l]);
        q = isVowel(s[r]);

        if (!p)
        {
            l++;
        }
        if (!q)
        {
            r--;
        }

        if (p && q)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    return s;
}

int main() {
    string s;

    cin >> s;

    string res = reverseVowels(s);

     cout << res << endl;

    return 0;
}