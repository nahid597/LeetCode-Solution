#include<iostream>
#include<vector>

using namespace std;

bool isSubset(vector<int>&nums, int sum, int n) {
    if (sum == 0)
    {
        return true;
    } else if (n == 0)
    {
        return false;
    } else if (nums[n-1] > sum)
    {
       return isSubset(nums, sum, n - 1);
    } else {
        return isSubset(nums, sum, n - 1) || isSubset(nums, sum - nums[n-1], n - 1);
    }
    
}

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += stones[i];
    }

    // for dp
    bool dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            } else if (i == 0 && j != 0)
            {
                dp[i][j] = false;
            } else if (stones[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
            }
            
        }
        
    }

    int dif = INT_MAX;
    int s1, s2;

    for (int i = 0; i <= sum/2; i++)
    {
        s1 = i;
        s2 = sum - s1;

        if (dp[n][i] && dif > abs(s1-s2))
        {
            dif = abs(s1-s2);
            cout << dif << endl;
        }

        // for recursion

        // if (isSubset(stones, s1, n) && dif > abs(s1-s2))
        // {
        //     dif = abs(s1-s2);
        // }

    }
    
    return dif;
    
}

int main() {

   vector<int>nums;
    int n,k, p;

    cout << "Enter number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        nums.push_back(p);
    }


    int res = lastStoneWeightII(nums);

    cout << "Result " << res << endl;

    return 0;
}