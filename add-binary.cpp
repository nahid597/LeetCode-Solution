#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>

using namespace std;

string addBinary(string a, string b)
{
    int aa, bb, rem = 0;
    string res = "";
    int n = max(a.size(), b.size());

   // 100
   // 00100
   // 00100
    if (a.size() != n)
    {
        reverse(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '\0')
            {
                a += '0';
            }
        }

        reverse(a.begin(), a.end());
    }

    if (b.size() != n)
    {
        reverse(b.begin(), b.end());

        for (int i = 0; i < n; i++)
        {
            if (b[i] == '\0')
            {
                b += '0';
            }
        }

        reverse(b.begin(), b.end());
    }

    cout << a << " " << b << endl;

    for (int i = n-1; i >= 0; i--)
    {
        aa = a[i] - 48;
        bb = b[i] - 48;

        res += ((aa + bb + rem) % 2) + 48;
        rem = (aa + bb + rem) / 2;
    }

    if (rem != 0)
    {
        res += rem + 48;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{

    string s1 = "1";
    string s2 = "11";

    string res = addBinary(s1, s2);

    cout << res << endl;

    return 0;
}