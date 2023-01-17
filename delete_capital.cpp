#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

bool detectCapitalUse(string word)
{
    if (word.size() == 1)
    {
        return true;
    }

    bool res = false;

    // USA
    // Leetcode
    // google

    bool st1 = false;
    bool st2 = false;

    if (word[0] >= 65 && word[0] <= 90 && word[1] >= 65 && word[1] <= 90)
    {
        st1 = true;
    }

    if (word[0] >= 65 && word[0] <= 90 && word[1] >= 97 && word[1] <= 122)
    {
        st2 = true;
    }

    for (int i = 1; i < word.size(); i++)
    {
        if (st1)
        {
            if (word[i] >= 65 && word[i] <= 90)
            {
                res = true;
            }
            else
            {
                res = false;
                break;
            }
        }
        else if (st2)
        {
            if (word[i] >= 97 && word[i] <= 122)
            {
                res = true;
            }
            else
            {
                res = false;
                break;
            }
        }
        else
        {
            if (word[i] >= 97 && word[i] <= 122)
            {
                res = true;
            }
            else
            {
                res = false;
                break;
            }
        }
    }

    return res;
}

int main()
{
    string s;

    cout << "Enter the word" << endl;
    cin >> s;

    bool res = detectCapitalUse(s);

    cout << res << endl;

    return 0;
}