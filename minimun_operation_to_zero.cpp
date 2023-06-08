#include<iostream>
#include<map>
#include<vector>

using namespace std;

unordered_map <string, int> mp;

int helper(vector<int>&nums, int x, int l, int r, int count) {
    if (x == 0)
    {
        return count;
    }

    if (x < 0 || l > r)
    {
        return 1e6;
    }

    string key = to_string(l) + "*" + to_string(r) + "*" + to_string(count);

    if (mp.count(key))
    {
        return mp[key];
    }

    int left = helper(nums, x - nums[l], l + 1, r, count+1);
    int right = helper(nums, x - nums[r], l, r - 1, count+1);
    
    return mp[key] = min(left, right);
    
}


int minOperations(vector<int>& nums, int x) {
   // nums = [1,1,4,2,3], x = 5

   int ans = helper(nums, x, 0, nums.size()-1, 0);

   return ans >= 1e6 ? -1 : ans;

}


int main() {
    vector<int>vec;

    int n, p, x;

    cout << "Enter target number " << endl;
    cin >> x;

    cout << "Enter number of elements " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    int res = minOperations(vec, x);

    cout << res << endl;
    
}