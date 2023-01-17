#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int cntVowel(string s) {
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' || s[i] == 'a')
        {
            cnt++;
        } else if (s[i] == 'E' || s[i] == 'e')
        {
            cnt++;
        } else if (s[i] == 'I' || s[i] == 'i')
        {
            cnt++;
        } else if (s[i] == 'O' || s[i] == 'o')
        {
            cnt++;
        } else if (s[i] == 'U' || s[i] == 'u')
        {
            cnt++;
        }
    }

    return cnt;
    
}

bool halvesAreAlike(string s) {
    string a = "", b = "";
    int n = s.size();
    int s1, s2;

    for (int i = 0; i < n; i++)
    {
       if (i < n / 2)
       {
          a += s[i];
       } else {
            b += s[i];
       }
       
    }

    s1 = cntVowel(a);
    s2 = cntVowel(b);

    if (s1 == s2)
    {
        return true;
    }
    

    return false;
    
}


int main() {

    string s;
    
    cout << "Enter string" << endl;

    cin >> s;

    bool res = halvesAreAlike(s);

    cout << res << endl;

    return 0;
}