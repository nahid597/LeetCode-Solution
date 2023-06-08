#include<iostream>
#include<vector>

using namespace std;


int maxProfit(vector<int> wt, vector<int> p, int w, int n) {
  
    int profit[100][100];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                profit[i][j] = 0;

            } else if (wt[i-1] > j)
            {
                profit[i][j] = profit[i-1][j];

            } else {
                profit[i][j] = max(profit[i-1][j], p[i-1] + profit[i-1][w - wt[i-1]] );
            }
            
        }
        
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
           cout << i << " " << j << " " << profit[i][j] << endl;
        }
        
    }

    // cout << "w vlaue " << w << " n vlaue. " << n << endl;

    return profit[n][w];
    
}

int main() {
    vector<int>wt;
    vector<int>p;
    int n, w, wi, pi;

    cout << "Enter the weight"<< endl;
    cin >> w;

    cout << "Enter the number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> wi;
       wt.push_back(wi);

       cin >> pi;
       p.push_back(pi);
    }
    

    int res = maxProfit(wt, p, w, n);

    cout << "result " << res << endl;
    

}