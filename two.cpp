
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
       
       vector<int> result;
       int n = nums.size();

      for (int i = 0; i < n; i++)
      {
         for (int j = i + 1; j < n; j++)
         {
            if(nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                break;
            }
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

