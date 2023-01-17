#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

 char findTheDifference(string s, string t) {
     
        char c;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());


        for (int i = 0; i < t.size(); i++)
        {
            if(t[i] != s[i]) {
                c = t[i];
                break;
            }
        }
       
        
        return c;
        
    }

int main() {
    string s1,s2;

    cout << "Enter the string" << endl;

    cin >> s1;
    cin >> s2;

    char c = findTheDifference(s1,s2);

    cout << c << endl;

    return 0;
}