#include<iostream>
#include<vector>

using namespace std;

bool helper(vector<int>&setItems, int sum, int n) {
  
    if (sum == 0) 
    {
        return true;
    }

    if (sum != 0 && n == 0) 
    {
        return false;
    }

    return helper(setItems, sum, n - 1) || helper(setItems, sum - setItems[n], n - 1);
    
}

bool dp(vector<int>&items, int sum, int n) {
    bool dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (j != 0 && i == 0)
            {
                dp[i][j] = false;
            }

            else if (j - items[i-1] < 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-items[i-1]];
            }  
        }
    }

    return dp[n][sum];
}

bool isSubSetSum(vector<int>&setItems, int sum, int n) {
  
  // bool res = helper(setItems, sum, n);
  return dp(setItems, sum, n+1);
   
}

int main() {
    vector<int>wt;
    int n, w, wi, pi;

    cout << "Enter the sum"<< endl;
    cin >> w;

    cout << "Enter the number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> wi;
       wt.push_back(wi);
    }
    

    bool res = isSubSetSum(wt, w, n -1);

    cout << "result " << res << endl;
    

}