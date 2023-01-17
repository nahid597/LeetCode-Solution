#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
        
        int res = -1;
        // 2 3 4 t=1
        // 1 3 5 6 t= 6
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
            {
                res = i;
                break;
            } else {
               if (target < nums[i])
               {
                  res = i;
                  break;
               }
                
            }
            
        }

        if(res == -1) {
            res = nums.size();
        }
        
        return res;
    }

int main()
{

    int n, p, t;

    cout << "Enter Num" << endl;
    cin >> n;

    vector<int>vec;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "Taerget " << endl;
    cin >> t;
    

    int res = searchInsert(vec,t);

    cout << res << endl;

    return 0;
}