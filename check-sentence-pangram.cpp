#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

bool checkIfPangram(string sentence)
{
    int res = true;

    string abc = "abcdefghijklmnopqrstuvwxyz";

    map<char, int> mp;

    for (int i = 0; i < sentence.size(); i++)
    {
        mp[sentence[i]]++;
    }
    

    for (int i = 0; i < abc.size(); i++)
    {
        if (mp[abc[i]] <= 0) {
            res = false;
            break;
        }
        
    }

    return res;
}

int main()
{

    string s = "thequickbrownfoxjumpsoverthelazydog";

    bool res = checkIfPangram(s);

    cout << res << endl;

    return 0;
}