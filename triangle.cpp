#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
    int sum1 = 0, sum2 = 0;
    int mn = INT_MAX;
    int ind1 = 0, ind2 = 1;
    int a = 0, b = 0;
    int result = INT_MAX;

    for (int i = 0; i < triangle.size(); i++)
    {
        if(i == 0) {
            sum1 += triangle[i][0];
            sum2 += triangle[i][0];
        } else {
            a = triangle[i][ind1];
            b = triangle[i][ind2];
            ind1 = i;
            
        }
        
        sum += mn;
    }

    return sum;
    
}
 
int main()
{

  int n, m, in;

  cout << "enter row " << endl;
  cin >> n;
   vector<vector<int> > num(n);

    for (int i =  0; i < n; i++)
    {
        cout << "enter column for row no " << i+1 << endl;
        cin >> m;  
        num[i] = vector<int>(m);
        for (int j = 0; j < i+1; j++)
        {
            cin >> in;

            num[i][j] = in;
        }
            
    }

    int total = minimumTotal(num);

    cout << total << endl;

    return 0;
}