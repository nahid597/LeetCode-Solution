#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <utility>

using namespace std;

 double findMaxAverage(vector<int>& nums, int k) {
        int mx = INT_MIN;
        double temp = -10001;
        int cSum = 0;

        // 1 k = 1

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k)
            {
                cSum -= (double) nums[i-k];
            }

            cSum += (double) nums[i];

            if(i >= k - 1) {
               mx = max(mx, cSum);
            }
            
        }

        temp = mx*1.0 / k;
       

    return temp;
        
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

   double res = findMaxAverage(vec,k);
   cout << res << endl;
}