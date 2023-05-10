#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


 vector<int> prevPermOpt1(vector<int>& arr) {
    if (arr.size() < 2)
    {
        return arr;
    }

    // 3 1 2. -> 2 3 1
    // 1 1 5

    int mis = -1;

    int n = arr.size();

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] < arr[i-1])
        {
            mis = i - 1;
            break;
        }
        
    }

    if (mis == -1)
    {
        return arr;
    }
    

    int mx = 0, indx = 0;

    // 3 1 1 3  -> 1 3 1 3

    for (int i = mis + 1; i < n; i++)
    {
        if (arr[i] >= arr[mis])
        {
            break;
        }
        
        if (arr[i] > mx)
        {
           mx = arr[i];
           indx = i;
        }
    }
    
    swap(arr[mis], arr[indx]);

    return arr;
    
}

int main() {

    int n, p;
    vector<int>vec;

    cout << "Enter the number of elements"<< endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }
    
    vector<int> res = prevPermOpt1(vec);

    for (int i = 0; i < res.size(); i++)
    {
       cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}