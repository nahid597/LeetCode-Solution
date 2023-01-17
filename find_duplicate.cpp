#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
    vector<int>flag(nums.size() + 1, 0);

    int a = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if(flag[nums[i]] == 0) {
            flag[nums[i]] = 1;
        } else {
            a = nums[i];
            break;
        }
    }

    return a;
}

int main() {

    vector<int> vec;

    int p, n;

    cout << "Enter the number of elements" << endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }
    
    int res = findDuplicate(vec);

    cout << res << endl;

    return 0;
}