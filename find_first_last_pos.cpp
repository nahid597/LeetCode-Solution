#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchFirst(int l, int r, vector<int>nums, int target) {
    while (l <= r)
    {
        int mid = l + (r-l) / 2;

        if (nums[mid] == target && (mid == 0 || nums[mid-1] < target))
        {
            return mid;
        }

        if(nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid -1;
        }
    }

    return -1; 
}

int searchLast(int l, int r, vector<int>nums, int target) {
    while (l <= r)
    {
        int mid = l + (r-l) / 2;

        cout << l << " " << r << endl;

        if (nums[mid] == target && (mid == nums.size() -1 || nums[mid+1] > target))
        {
            return mid;
        }

        if(nums[mid] > target) {
            r = mid -1;
        } else {
            l = mid + 1;
        }
    }

    return -1; 
}

vector<int> searchRange(vector<int>& nums, int target) {
    
    vector<int> result;
    int s = searchFirst(0,nums.size()-1, nums, target);
    int p = searchLast(0,nums.size()-1, nums, target);
    result.push_back(s);
    result.push_back(p);

    return result;

}

int main()
{

    vector<int> vec;

    int n, p, val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "enter target " << endl;
    cin >> val;

    vector<int> result = searchRange(vec, val);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
}