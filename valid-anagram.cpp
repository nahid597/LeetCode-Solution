#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

bool isAnagram(string s, string t)
{
    int res = true;

    if (s.size() != t.size())
    {
        res = false;
        return res;
    }

    map<char, int> mp1;
    map<char, int> mp2;

    for (int i = 0; i < s.size(); i++)
    {
        mp1[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        mp2[t[i]]++;
    }
    

    for (int i = 0; i < s.size(); i++)
    {
        if (mp1[s[i]] != mp2[s[i]]) {
            res = false;
            break;
        }
        
    }

    return res;
}

int main()
{

    string s = "nahid";
    string t = "hnaid";

    bool res = isAnagram(s,t);

    cout << res << endl;

    return 0;
}