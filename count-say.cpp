#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

string countDigit(string s){
    int cnt = 1;
    int d;

    string res = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i+1])
        {
            cnt ++;
        } else {
            res += cnt + 48;
            res += s[i];
            cnt = 1;
        }
        
    }
    
    return res;
    
}

string countAndSay(int n) {
     
     if (n == 1)
     {
        return "1";
     }

     return countDigit(countAndSay(n-1));
}

int main()
{

    int n = 5;

    string res = countAndSay(n);

    cout << res << endl;

    return 0;
}