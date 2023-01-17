#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0, k = 0,s=0;

        // 4,6,8
        // 4,5,6
        // 4,4,6,8
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                i++;
            } else {
               k = i; 
               for(int p = m; p > i; p--){
                    nums1[p] = nums1[p-1];
               }
               nums1[k] = nums2[j];
               i++;
               j++;
               m++;
            }
        }

        while(i < m) {
            nums1[i] = nums1[i];
            i++;
        }

         while(j < n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }

int main()
{

    vector<int> vec;
    vector<int> vec2;

    int n, m, p, val;

    cout << "Enter size of element of nums1" << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    cout << "Enter size of element of nums2" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec2.push_back(p);
    }

   merge(vec, m, vec2, n);

   for (int i = 0; i < vec.size(); i++)
   {
      cout << vec[i] << " ";
   }
   

   
}