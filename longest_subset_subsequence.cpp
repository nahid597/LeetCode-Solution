#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s)
{

    int ch[256] = {0};

    int i = 0, j = 0, ans = 0;

    // abcadab

    while (j < s.size())
    {
        ch[s[j]]++;

        while (ch[s[j]] > 1)
        {
            ch[s[i]]--;
            i++;
        }
        
        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main()
{

    string s;

    cout << "Enter string" << endl;

    cin >> s;

   
       // makeSubString(s, 0, 0);
    
    

    int res = lengthOfLongestSubstring(s);

    cout << res << endl;

    return 0;
}