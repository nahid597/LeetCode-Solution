#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {

    if (k == 0)
    {
        return;
    }

    int n = nums.size();

    k = k % n;

    reverse(nums.begin()+n-k, nums.end());

    reverse(nums.begin(), nums.end());

     reverse(nums.begin()+k, nums.end());



}

int main() {

    int n, p, k;
    vector<int> vec;

    cout << "Number of element" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> p;
       vec.push_back(p);
    }

    cout << "Number of rotate" << endl;
    cin >> k;

    rotate(vec, k);
    

    return 0;
}