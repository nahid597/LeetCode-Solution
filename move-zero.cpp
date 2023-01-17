#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int j = 0;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if(nums[i] != 0 && flag) {
                swap(nums[i], nums[j]);
                j++;
            }
        }  

         for (int i = 0; i < n; i++)
        {
           cout << nums[i] << " ";
        }
}

int main()
{

    int n, p;
    cout << "Enter num of element" << endl;
    cin >> n;

    vector<int>str;

   for (int i = 0; i < n; i++)
   {
    cin >> p;
      str.push_back(p);
   }
   
   moveZeroes(str);


    return 0;
}