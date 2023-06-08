#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int> &nums) {
    int mx = INT_MIN;
    int l = 0;
    int dp[nums.size() + 1];

     if(nums.size() < 2) {
        return nums[0];
    }

    if(nums.size() < 3) {
        return max(nums[0], nums[1]);
    }

    dp[0] = nums[0];
    dp[1] = nums[1];

    for (int i = 2; i < nums.size(); i++)
    {
        l = i - 2;
        mx = INT_MIN;

        while (l >= 0)
        {
            mx = max(mx, dp[l]); 
            l--;
        }

        dp[i] = nums[i] + mx;
          
    }

    int res = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        res = max(res, dp[i]);
    }
    
    return res;   
}

int rob(vector<int>& nums) {

    vector<int> st1 = nums;
    vector<int> st2 = nums;

    st1.erase(st1.begin());

    int s1 = helper(st1);

    st2.pop_back();

    int s2 = helper(st2);

    return max(s1,s2);    
}

int main() {

    vector<int>vec;
    int n, p;

    cout << "Enter the number of elements" << endl;

    cin >> n;

    cout << "Enter the number" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    int res = rob(vec);

    cout << "result " << res << endl;
    

    return 0;
}