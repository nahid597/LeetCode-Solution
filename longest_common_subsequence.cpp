#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int lcs(string s1, string s2, int m, int n, vector<vector<int> >&dp) {
    // abcd
    // befg

    if (m == 0 || n == 0)
    {
        return 0;
    }

    if(s1[m-1] == s2[n-1]) {
        return dp[m][n] = 1 + max(lcs(s1,s2,m-1,n-1, dp));
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    

   
    return dp[m][n] = max(lcs(s1,s2,m,n-1, dp), lcs(s1,s2,m-1,n,dp));
    
}

int longestCommonSubsequence(string text1, string text2) {

    int m = text1.size();
    int n = text2.size();

    vector<vector<int> > dp(m+1, vector<int>(n+1, -1));

    return lcs(s1,s2,m,n-1, dp);
        
}

int main()
{

    string s1,s2;

    cout << "Enter 2 string" << endl;

    cin >> s1;
    cin >> s2;

  
    int res = longestCommonSubsequence(s1,s2);

    cout << res << endl;

    return 0;
}