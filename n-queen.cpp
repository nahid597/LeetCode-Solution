#include <iostream>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <cstring>
#include <vector>

using namespace std;

 void dfs(int i, vector<int>&row, vector<bool>&col,vector<bool>&mdia,vector<bool>&adia,vector<vector<string> >&result,vector<string>&board) {
    if (i == row.size())
    {
        result.push_back(board);
       
        return;  
    }

    for (int j = 0; j < col.size(); j++)
    {
        if(col[j] && adia[i+j] && mdia[i+col.size()-1-j])
        {
            row[i] = j;
            board[i][j] = 'Q';
            col[j] = adia[i+j] = mdia[i+col.size()-1-j] = false;
            dfs(i+1,row,col,mdia,adia,result,board);
            col[j] = adia[i+j] = mdia[i+col.size()-1-j] = true;
            board[i][j] = '.';
        }
    }
    
 }

 vector<vector<string> > solveNQueens(int n) {

    vector<bool>col(n,true);
    vector<int>row(n,0);
    vector<bool>mdia(2*n -1, true);
    vector<bool>adia(2*n -1, true);
    vector<string>board(n, string(n, '.'));
    int cnt = 0;

    vector<vector<string> > result;
    

    dfs(0,row,col,mdia,adia,result,board);

    return result;
        
}

int main() {

    int n;

    cout << "enter number" << endl;
    cin >> n;

    vector<vector<string> > res = solveNQueens(n);

    for (int i = 0; i < res.size(); i++)
    {
       for (int j = 0; j < res[i].size(); j++)
       {
          cout << res[i][j];
       }

       cout << endl;
       
    }
    

    return 0;
}