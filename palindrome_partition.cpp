#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include<string.h>

using namespace std;

bool isPlaindrome(string s)
{
    int l = 0, r = s.size() - 1;
    bool res = true;

    while (l < r)
    {
        if (s[l] != s[r])
        {
            res = false;
            break;
        }
        l++;
        r--;
    }

    return res;
}

void helper(string s, vector<vector<string> >&result, vector<string> temp) {

    if (s.size() == 0) {
        result.push_back(temp);
    }

    // aab
  
    for (int i = 0; i < s.size(); i++)
    {
       string left = s.substr(0,i+1);
       
       if (isPlaindrome(left))
       {
            temp.push_back(left);
            helper(s.substr(i+1),result,temp);
            temp.pop_back();
       }
       
    }  
    
}

vector<vector<string> > partition(string s)
{

    vector<vector<string> > result;
    vector<string>temp;

    helper(s, result, temp);

    return result;
   
}

int main()
{
    string s;

    cin >> s;

    vector<vector<string> > res = partition(s);

    // cout << res << endl;

    return 0;
}