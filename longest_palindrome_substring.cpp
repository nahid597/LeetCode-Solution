#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

vector<string>vec;
vector<string>::iterator itr;


string longestPalindrome(string s) {
    string result = "";
    int len = 0;
    int l,r;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        // odd length
        // ababa
        l = r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r-l+1 > len)
            {
                len = r - l + 1;
                result = s.substr(l,len);
            }

            l -= 1;
            r += 1;
        }

        // even length
        // abbc
        l = i;
        r = i+1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r-l+1 > len)
            {
                len = r - l + 1;
                result = s.substr(l,len);
            }

            l -= 1;
            r += 1;
        }

    }

    return result;
}

int main()
{

    string s;

    cin >> s;

    string res = longestPalindrome(s);

    cout << res << endl;

    return 0;
}