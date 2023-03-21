#include <iostream>
#include <vector>
#include <iterator>
#include<map>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());

       // -4 -1 -1 0 1 2

       int l, m, r, sum, mx = INT_MIN;
       int n =  nums.size();
      
       for (int i = 0; i < n -1; i++)
       {
           // 0 0 0 0
           // -1 1 2 4  t = 1
            
            l = i;
            m = l + 1;
            r = n - 1;
            sum = 0;
           // mx = INT_MIN;

            while (m < r)
            {
                sum = nums[l] + nums[m] + nums[r];
                mx = max(sum, mx);
                if (sum == target)
                {
                    mx = sum;
                }
                
               else if (sum > target)
                {
                    r--;
                } else {
                    m++;
                } 
            }
       }
       
       return mx;
}

int main()
{
    vector<int> vec;
    int n, p, t;

    cout << "Enter the Number of element" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "Enter the target Number" << endl;
    cin >> t;

   int res = threeSumClosest(vec, t);
   
    cout << res<< endl;

    return 0;
}