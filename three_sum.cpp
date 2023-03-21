#include <iostream>
#include <vector>
#include <iterator>
#include<map>
#include<algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());

       // -4 -1 -1 0 1 2

       int l, m, r, sum;
       int n =  nums.size();

      vector<vector<int> >res;
      
       for (int i = 0; i < n -1; i++)
       {
           // 0 0 0 0
           // -4 -1 -1 -1 0 1 2 
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            
            l = i;
            m = l + 1;
            r = n - 1;
            sum = 0;

            while (m < r)
            {
                sum = nums[l] + nums[m] + nums[r];
                if (sum == 0)
                {
                    vector<int>st;

                    st.push_back(nums[l]);
                    st.push_back(nums[m]);
                    st.push_back(nums[r]);
                    res.push_back(st);
                    m++;
                    while (nums[m] == nums[m-1] && m < r)
                    {
                        m++;
                    }

                } else if (sum > 0)
                {
                    r--;
                } else {
                    m++;
                }
                
            }
       }
       
       return res;
        
}

int main()
{
    vector<int> vec;
    int n, p;

    cout << "Enter the Number of element" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

   vector<vector<int> >res = threeSum(vec);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
        
    }

    cout << endl;

    return 0;
}