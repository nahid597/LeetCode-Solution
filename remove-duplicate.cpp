#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    
    int n = nums.size();
    int j = 0;
    int cnt = 0;

   
    for (int i = 0; i < n -1; i++)
    {
        if (nums[i] == nums[i+1])
        {
            nums[i] = -101;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != -101)
        {
            swap(nums[j], nums[i]);
            cnt++;
            j++;
        }
        
    }

    return cnt; 
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

    int result = removeDuplicates(vec);

    cout << result << endl;
}