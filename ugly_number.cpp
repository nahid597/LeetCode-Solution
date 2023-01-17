#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include<vector>
#include<math.h>

using namespace std;

vector<int> primeFactor(int n) {
    vector<int> str;

    // when number is even
    while (n % 2 == 0)
    {
        str.push_back(2);
        n = n / 2;
    }

    // when number is odd
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            str.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        str.push_back(n);
    }
    
    return str;
    
}

 bool isUgly(int n) {

    if (n < 1)
    {
        return false;
    }
    
    if (n == 1)
    {
        return true;
    }
    

    vector<int>result = primeFactor(n);
    bool res = false;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
        if(result[i] == 2 || result[i] == 3 || result[i] == 5) {
            res = true;
        } else {
            res = false;
        }
    }
    

        return res;
}

int main()
{

   int n;

    cout << "Enter number"<< endl;
    cin >> n;

    bool res = isUgly(n);

    cout << res << endl;

    return 0;
}