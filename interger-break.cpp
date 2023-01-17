#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int memo[100] = {0};

int integerBreak(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if(memo[n] != 0)
    return memo[n];

    int res = 0;

    for (int i = 1; i < n; i++)
    {
        int s = integerBreak(i);
        int p = integerBreak(n - i);
        res = max(res, max(i, s) * max(n - i, p));
    }

    return memo[n] = res;
}

int main()
{

    int n;

    cout << "Enter the number" << endl;

    cin >> n;

    int res = integerBreak(n);

    cout << res << endl;

    return 0;
}