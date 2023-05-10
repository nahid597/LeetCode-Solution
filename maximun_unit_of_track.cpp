#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maximumUnits(vector<vector<int> >& boxTypes, int truckSize) {

    vector<pair<int,int> >mp;
    int ans = 0;

     for(int i = 0;i < boxTypes.size();i++)
        mp.push_back(make_pair(boxTypes[i][1],boxTypes[i][0]));

    sort(mp.begin(), mp.end(), greater<pair<int,int> >());

    for (int i = 0; i < mp.size(); i++)
    {
        if (truckSize >= mp[i].second)
        {
            ans += mp[i].first * mp[i].second;
            truckSize -= mp[i].second;
        } else {
            ans += mp[i].first * truckSize;
            break;
        }
        
    }

    return ans;
}

int main() {

    vector<vector<int> > vec;
    vector<int>temp;

    int m,n, p;

    cout << "Enter the number of truck" << endl;

    cin >> n;

    cout << "Enter the number of row" << endl;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        vector<int>temp;
        for (int j = 0; j < 2; j++)
        {
           cin >> p;
           temp.push_back(p);
        }

        vec.push_back(temp);
        
    }


   int res = maximumUnits(vec,n);

   cout << "result " << res << endl;
   
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //        cout << vec[i][j] << " ";
    //     }

    //     cout << endl;
        
    // }
    
    return 0;
}