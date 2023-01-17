#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRow(int rowIndex)
{

    vector<vector<int> > num(rowIndex + 1);

    vector<int> result;

    for (int i = 0; i < rowIndex + 1; i++)
    {
        num[i] = vector<int>(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            num[i][j] = 1;
        }
    }

    for (int i = 2; i < rowIndex + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
        }
    }

    for (int i = rowIndex; i < rowIndex + 1; i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            result.push_back(num[i][j]);
        }
    }

    return result;
}

int main()
{

    vector<int> vec;

    int n, p, val;

    cin >> n;

    vector<int> result = getRow(n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<< " ";
    }

    return 0;
}