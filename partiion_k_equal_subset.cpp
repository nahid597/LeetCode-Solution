#include<iostream>
#include<vector>

using namespace std;

bool visited[10001] = {false};

bool helper(vector<int>&nums, int pos, int target, int targetSum, int k) {
   
   if (k == 0)
   {
      return true;
   }


   if (target == targetSum)
   {
        return helper(nums,0,target,0,k-1);
   }

   for (int i = pos; i < nums.size(); i++)
   {
        if (visited[i] || targetSum + nums[i] > target)
        {
            continue;
        }

        visited[i] = true;

       if (helper(nums,i+1,target,targetSum + nums[i], k))
       {
          return true;
       }

        visited[i] = false;    
   }

   return false;
    
}

 bool canPartitionKSubsets(vector<int>& nums, int k) {
    
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if (sum % k == 1)
    {
        return false;
    }

    sum = sum / k;

     return helper(nums, 0, sum, 0, k);
    
}

int main() {

    vector<int>nums;
    int n,k, p;

    cout << "Enter number of k"<< endl;
    cin >> k;

    cout << "Enter number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        nums.push_back(p);
    }


    bool res = canPartitionKSubsets(nums, k);

    cout << "Result " << res << endl;



    return 0;
}
