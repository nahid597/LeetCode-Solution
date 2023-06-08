#include<iostream>
#include<vector>

using namespace std;


int maxProfit(vector<int> wt, vector<int> p, int w, int n, int mem[100][100]) {
    if (n == -1 || w == 0)
    {
       return 0;
    }

    // cout << "calling " << w << " " << n << " " << wt[n]<< " " << p[n] << endl;

    if (mem[w][n] != -1)
    {
        return mem[w][n];
    }

    int result = 0;

    if (wt[n] > w)
    {
        result = maxProfit(wt, p, w, n - 1,mem);
    } else {
         result =  max(maxProfit(wt, p, w, n - 1,mem), p[n]+maxProfit(wt, p, w - wt[n], n - 1,mem));
    }

    return mem[w][n] = result;
    
}

int main() {
    vector<int>wt;
    vector<int>p;
    int n, w, wi, pi;

    cout << "Enter the weight"<< endl;
    cin >> w;

    cout << "Enter the number of elements"<< endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       cin >> wi;
       wt.push_back(wi);

       cin >> pi;
       p.push_back(pi);
    }

    int mem[100][100];

    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mem[i][j] = -1;
        }
        
    }
    

    int res = maxProfit(wt, p, w, n,mem);

    cout << "result " << res << endl;
    

}