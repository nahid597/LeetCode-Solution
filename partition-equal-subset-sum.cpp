#include <iostream>
#include <vector>

using namespace std;

bool helper(vector<int> &setItems, int sum, int n, int mem[100][100])
{

    if (sum == 0)
    {
        return true;
    }

    if (sum != 0 && n == 0)
    {
        return false;
    }

    if (mem[n][sum] != -1)
    {
        return mem[n][sum];
    }

    return mem[n][sum] = helper(setItems, sum, n - 1, mem) || helper(setItems, sum - setItems[n], n - 1, mem);
}

bool dp(vector<int> &nums, int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] = false;
            }
            else if (j - nums[i - 1] < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(vector<int> &nums)
{

    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if (sum & 1)
    {
        return false;
    }

    sum = sum / 2;

    // int mem[100][100];

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         mem[i][j] = -1;
    //     }
    // }

    // return helper(nums, sum, n - 1, mem);
       return dp(nums, n, sum);
}

int main()
{
    vector<int> wt;
    int n, w, wi, pi;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wi;
        wt.push_back(wi);
    }

    bool res = canPartition(wt);

    cout << "result " << res << endl;

    return 0;
}