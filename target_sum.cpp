#include <iostream>
#include <vector>

using namespace std;

bool helper(vector<int> &setItems, int sum, int n, int mem[100][100])
{

    if (sum == 0)
    {
        return 1;
    }

    if (sum != 0 && n == 0)
    {
        return 0;
    }

    if (mem[n][sum] != -1)
    {
        return mem[n][sum];
    }

    return mem[n][sum] = helper(setItems, sum, n - 1, mem) + helper(setItems, sum - setItems[n], n - 1, mem);
}

int dp(vector<int> &nums, int n, int s1)
{
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        
        return t[n][s1];
}

int findTargetSumWays(vector<int> &nums, int target)
{

    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ( abs(target) > sum || (sum+target) & 1)
    {
        return 0;
    }

   int tSum = (sum + target) / 2;

    // int mem[100][100];

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         mem[i][j] = -1;
    //     }
    // }

    // return helper(nums, sum, n - 1, mem);
       return dp(nums, n, tSum);
}

int main()
{
    vector<int> wt;
    int n, w, wi, pi;

    cout << "Enter the number of target" << endl;
    cin >> w;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wi;
        wt.push_back(wi);
    }

    int res = findTargetSumWays(wt,w);

    cout << "result " << res << endl;

    return 0;
}