#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) { 
    int once = 0;
    int twice = 0;

   
    // 2 2 3 2
    // 00 00 10
    // 10 10 10
    // 10 10 00
    // 11 01 11
    // 10 00 00
    for (int i = 0; i < nums.size(); i++)
    {
        once = (~twice) & (once ^ nums[i]);
        twice = (~once) & (twice^nums[i]);
    }

    return once;
}


int main() {

    int n,p;
    vector<int>vec;
    
    cout << "Enter number of elements" << endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    int res = singleNumber(vec);

    cout << res << endl;
    

    return 0;
}