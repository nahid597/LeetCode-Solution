
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
       
       vector<int> nums2;
       vector<int> result;

       nums2 = nums;

        sort(nums2.begin(), nums2.end());

        int i = 0, sum = 0, p =0, q = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            sum = nums2[i] + nums2[j];

            if (target == sum)
            {
                break;
            }

            if(sum < target) {
                i++;
            } else {
                j++;
            } 
        }

        p = nums2[i];
        q = nums2[j];

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == p || nums[i] == q)
            {
               result.push_back(i);
            }
            
        } 

        return result;   
}

int main() {

    int n, target, p;

    cin >> n;

    vector<int>nums;

    for (int i = 0; i < n; i++) {
        cin >> p;
        nums.push_back(p);
    }

    cout << "Enter target " << endl;

    cin >> target;

   vector<int> result = twoSum(nums, target);

   for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << ",";
        } 

    return 0;
}
