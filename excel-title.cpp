#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>

using namespace std;

int titleToNumber(string columnTitle)
{
    int res = 0;
    int temp;

    // AA. AB BA
    //  1*26+1
    for (int i = 0; i < columnTitle.size(); i++)
    {
        temp = columnTitle[i] - 64;
        res = res*26 + temp;
    }

    return res;
}

int main()
{

    string s1 = "ABC";

    int res = titleToNumber(s1);

    cout << res << endl;

    return 0;
}