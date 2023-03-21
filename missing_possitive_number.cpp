#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;


int findKthPositive(vector<int>& arr, int k) {
    vector<int>st;
    int r = 0,p;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            p = 1;
            while (p < arr[i])
            {
                st.push_back(p);
                p++;
            }
           
        } else {
            // 2 3 4 7 11
            //7-6 < 5
            r = i;
            p = arr[i-1];
            while (p < arr[r] && p + 1 != arr[r])
            {
               p++;
               st.push_back(p);
            }
        }
        
    }

    if (st.size() < k)
    {
        p = arr[arr.size() - 1];
        int n = st.size();

        for (int i = 0; i < k - n; i++)
        {
            p++;
            st.push_back(p);
        }  
    }


    return st[k-1];
        
}

int main() {
  
    vector<int>vec;
    int n,p, k;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> p;
       vec.push_back(p);
    }

   cout << "Enter the kth of elements" << endl;
    cin >> k;
    

    int res = findKthPositive(vec, k);

    cout <<res << endl;
    
}
