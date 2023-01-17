#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

        string res = strs[0];
        string s;

        for(int i = 1; i < strs.size(); i++) {
            s = strs[i];

            for (int j = 0; j < res.size(); j++)
            {
                if (res[j] != s[j])
                {
                    res = res.substr(0,j);
                }
                
            }
            
        }

        return res;
        
    }


int main()
{

    int n, p, t;
    string s;

    cout << "Enter Num" << endl;
    cin >> n;


    vector<string>vec;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vec.push_back(s);
    }


    string res = longestCommonPrefix(vec);

    cout << res << endl;

    return 0;
}