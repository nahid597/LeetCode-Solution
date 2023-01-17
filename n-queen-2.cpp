#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

 void dfs(int i, vector<int>&row, vector<bool>&col,vector<bool>&mdia,vector<bool>&adia,int &cnt) {
    if (i == row.size())
    {
       cnt++;
       return;  
    }

    for (int j = 0; j < col.size(); j++)
    {
        if(col[j] && adia[i+j] && mdia[i+col.size()-1-j])
        {
            row[i] = j;
            col[j] = adia[i+j] = mdia[i+col.size()-1-j] = false;
            dfs(i+1,row,col,mdia,adia,cnt);
            col[j] = adia[i+j] = mdia[i+col.size()-1-j] = true;
        }
    }
    
 }

 int totalNQueens(int n) {

    vector<bool>col(n,true);
    vector<int>row(n,0);
    vector<bool>mdia(2*n -1, true);
    vector<bool>adia(2*n -1, true);
    int cnt = 0;

    dfs(0,row,col,mdia,adia,cnt);

    return cnt;
        
}

int main() {

    int n;

    cout << "enter number" << endl;
    cin >> n;

    int res = totalNQueens(n);

   cout << res << endl;
    

    return 0;
}