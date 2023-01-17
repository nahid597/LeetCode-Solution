#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 vector<vector<int> > generate(int numRows) {

    vector<vector<int> > num(numRows);

    for (int i =  0; i < numRows; i++)
    {
        num[i] = vector<int>(i+1);
        for (int j = 0; j < i+1; j++)
        {
            num[i][j] = 1;
        }
            
    }

    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
           num[i][j] = num[i-1][j-1] + num[i-1][j];
        }
        
    }

    return num;
        
}

int main()
{

    vector<int> vec;

    int n, p, val;

    cin >> n;

    vector<vector<int> > result = generate(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
        
    }
    


    return 0;
}