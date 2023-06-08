#include<iostream>
#include<vector>

using namespace std;


int helper(vector<int>&coin, int amount, int i) {

    if (amount == 0)
    {
        return 0;
    }

    if (amount >= 0 && i == coin.size())
    {
        return 1e5;
    }

    if (coin[i] > amount)
    {
        return helper(coin, amount, i + 1);
    } else {
        return min(1 + helper(coin, amount - coin[i], i), helper(coin, amount, i + 1));
    }
    
}


int coinChange(vector<int>&coin, int amount) {
  
  // this is for recursive
//     res = helper(coin, amount, 0);

//    if (res == 1e5)
//    {
//       return -1;
//    } 

    // this is for dp

    int c = coin.size();

    int dp[c + 1][amount + 1];

    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            } 
            
            else if (i == 0)
            {
                dp[i][j] = 1e5;
            }
            
            else if (coin[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(1 + dp[i][j - coin[i-1]], dp[i-1][j]);
            }
            
        }
        
    }
    
    return dp[c][amount] > 1e4 ? -1 : dp[c][amount];
    
}

int main() {
    vector<int>wt;
    int n, w, wi, pi;

    cout << "Enter the amount"<< endl;
    cin >> w;

    cout << "Enter the number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> wi;
       wt.push_back(wi);
    }
    

    int res = coinChange(wt, w);

    cout << "result " << res << endl;
    

}