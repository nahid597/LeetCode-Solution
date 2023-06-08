#include<iostream>
#include<vector>

using namespace std;

int lastStoneWeight(vector<int>& stones) {

       sort(stones.begin(), stones.end(), greater<int>());

       int i = 0, res = 0;

       while (i < stones.size() && (i+1) < stones.size())
       {
            res = stones[i] - stones[i+1];

            if (res == 0)
            {
                stones.erase(stones.begin(), stones.begin() + 2);
            } else {
                stones.erase(stones.begin());
                stones[0] = res;
                sort(stones.begin(), stones.end(), greater<int>());
            } 
       }

       if (stones.size())
       {
           return stones[0];
       }
       
       return 0;
}

int main() {

   vector<int>nums;
    int n,k, p;

    cout << "Enter number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        nums.push_back(p);
    }


    int res = lastStoneWeight(nums);

    cout << "Result " << res << endl;

    return 0;
}