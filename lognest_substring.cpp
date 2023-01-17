#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int lenOfUniqueSubString(string s)
{
    int cnt = 0;
    int ch[127] = {0};
    // pwwkew

    cout << s << endl;

    for (int i = 0; i < s.size(); i++)
    {
        if (ch[s[i]] == 0)
        {
            cnt++;
            ch[s[i]] = 1;
        }
        else
        {
            return cnt;
        }
    }

    return cnt;
}

void makeSubString(string s, int pos, int l)
{
    // abcabc
    //  a
    //  ab
    //  abc
    if (s.size() == l)
    {
        cout << s << endl;
        return;
    }

    for (int i = pos; i < s.size(); i++)
    {
        // cout << "pos " << pos << " i " << i << endl;
        makeSubString(s.substr(pos, i + 1), pos , i + 1);
        makeSubString(s.substr(i+1), pos, s.size() - i + 1);
    }
}

int lengthOfLongestSubstring(string s)
{

    string st = "";
    int res;
    int mx = INT_MIN;

    // pwwkew
    for (int i = 0; i < s.size(); i++)
    {
        st = "";
        for (int j = i; j < s.size(); j++)
        {
            st += s[j];
            res = lenOfUniqueSubString(st);
            mx = max(mx, res);
        }
    }

    return mx;
}

int main()
{

    string s;

    cout << "Enter string" << endl;

    cin >> s;

   
        makeSubString(s, 0, 0);
    
    

    // int res = lengthOfLongestSubstring(s);

    // cout << res << endl;

    return 0;
}