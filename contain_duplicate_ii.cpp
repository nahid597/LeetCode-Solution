#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <utility>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = k;
        int res = false;

        if (k >= nums.size())
        {
            r = nums.size() - 1;
            k = r;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            
           while (l < r)
           {
               if(nums[l] == nums[r] && l != r) {
                    res = true;
                    break;
               }

               l++;
           }

           l = i + 1;
           r = l + k; 
        }

    return res;
        
}


int main() {
    vector<int> vec;
    int m, n, k,p;

    cout << "Enter the number of row and column" << endl;
    cin >> n;

  
        for (int j = 0; j < n; j++) {
            cin >> p;
            vec.push_back(p);
        }

        cout << "Enter the target number" << endl;
        cin >> k;

    cout << "value printed " << endl;

    //  for(int i = 0 ; i < vec.size(); i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   bool res = containsNearbyDuplicate(vec,k);
   cout << res << endl;
}