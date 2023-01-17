#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include<vector>

using namespace std;

 vector<string> findWords(vector<string>& words) {
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl";
    string s3 = "zxcvbnm";

    string stor = "", st;
    char ch;
    vector<string>result;
    int p = 1;

    for (int i = 0; i < words.size(); i++)
    {
        ch = tolower(words[i][0]);
        p = 1;

        for (int j  = 0; j < s1.size(); j++)
        {
            if (ch == s1[j])
            {
                stor = s1;
                break;
            }
            
        }

        for (int j  = 0; j < s3.size(); j++)
        {
            if (ch == s3[j])
            {
                stor = s3;
                break;
            }
            
        }
        for (int j  = 0; j < s2.size(); j++)
        {
            if (ch == s2[j])
            {
                stor = s2;
                break;
            }
            
        }

        for (int j = 0; j < words[i].size(); j++)
        {
            
           int pp = stor.find(tolower(words[i][j]));

            if(pp < 0) {
                p = 0;
                break;
            }
        }

        if (p)
        {
            result.push_back(words[i]);
        }
        
    }

    return result;
        
}

int main()
{
    string s;
    vector<string>vec;

    int n;

    cout << "Number of elements" <<endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vec.push_back(s);
    }
    

   vector<string> res = findWords(vec);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    

    return 0;
}