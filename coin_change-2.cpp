#include<iostream>
#include<vector>

using namespace std;

int mem[302][5002];

int helper(vector<int>&coin, int amount, int i, int &ans) {

    if (amount == 0)
    {
        cout << "calling amount" << endl;
        ans++;
        return 0;
    }
    

    if (amount > 0 && i == coin.size())
    {
        return 1e9;
    }

    if (mem[i][amount] != -1)
    {
        cout << "call inside" << endl; 
        ans++;
        return mem[i][amount];
    }
    

    if (coin[i] > amount)
    {
        return mem[i][amount] = helper(coin, amount, i + 1, ans);
    } else {
        return mem[i][amount] = 1 + helper(coin, amount - coin[i], i, ans) && helper(coin, amount, i + 1, ans);
    }
    
}

int dp(vector<int>&coin, int amount) {

    int n = coin.size();
    int dp[n + 1][amount + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (coin[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            
            else {
                dp[i][j] =  dp[i-1][j] + dp[i][j-coin[i-1]];
            }
        }
        
    }

    return dp[n][amount];
    
}


int coinChange(vector<int>&coin, int amount) {
  
//     int ans = 0;
//     int res = helper(coin, amount, 0, ans);

//    if (res == 1e9)
//    {
//       return 0;
//    } 

//    cout << "result ans " << ans << endl;

    int res = dp(coin, amount);

    return res;
    
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

    cout << "Before calling" << endl;


    for (int i = 0; i <= 301; i++)
    {
         for (int j = 0; j <= 5001; j++)
         {
            mem[i][j] = -1;
         }
         
    }
    

    int res = coinChange(wt, w);

    cout << "result " << res << endl;
    

}