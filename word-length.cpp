#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
        int cnt = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            cout << s[i] << endl;
            if(s[i] == ' ') {
                break;
            } else {
                cnt++;
            }
        }
        return cnt;
        
    }

    int main()
{

    string n = "Hello World";

    int res = lengthOfLastWord(n);

    cout << res << endl;

    return 0;
}