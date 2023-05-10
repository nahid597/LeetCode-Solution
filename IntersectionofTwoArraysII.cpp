#include<iostream>
#include<vector>

using namespace std;


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int>ans;
        int flag[1001] = {0};

        for (int i = 0; i < nums1.size(); i++)
        {
            flag[nums1[i]] += 1;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (flag[nums2[i]] > 0)
            {
               ans.push_back(nums2[i]);
               flag[nums2[i]] -= 1;
            }
            
        }
        

        return ans;
        
}


int main() {

    vector<int> nums1;
    vector<int> nums2;

    int n1, n2, p;

    cout << "Enter the nums1 elements" << endl;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        cin >> p;
        nums1.push_back(p);
    }

    cout << endl;

    cout << "Enter the nums2 elements" << endl;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        cin >> p;
        nums2.push_back(p);
    }
    
    vector<int> res = intersect(nums1, nums2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
    

    return 0;
}