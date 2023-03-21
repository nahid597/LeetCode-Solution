#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <utility>

using namespace std;

bool checkBoundary (int row, int col, vector<vector<int> >& grid) {
    int r = grid.size();
    int c = grid[0].size();

    if(row < r  && col < c && col > -1 && row > -1) {
        return true;
    } else {
        return false;
    }
}

int numIslands(vector<vector<int> >& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int cnt = 0;

    bool visited[row + 1] [col+1];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            visited[i][j] = false;
        }
    }


    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                cnt++;
                visited[i][j] = true;

                queue<pair<int,int> > q;
                pair<int,int> p;
                
                p.first = i;
                p.second = j;

                q.push(p);

                while(!q.empty()) {
                    pair<int,int> tempP;
                    pair<int,int> p1;
                    tempP = q.front();
                    q.pop();

                    if(checkBoundary(tempP.first + 1, tempP.second, grid)) {
                        if(!visited[tempP.first + 1][tempP.second] && grid[tempP.first + 1][tempP.second] == 1) {
                            visited[tempP.first + 1][tempP.second] = true;
                            p1.first = tempP.first + 1;
                            p1.second = tempP.second;
                            q.push(p1);
                        }
                    }

                     if(checkBoundary(tempP.first - 1, tempP.second, grid)) {
                        if(!visited[tempP.first - 1][tempP.second] && grid[tempP.first - 1][tempP.second] == 1) {
                            visited[tempP.first - 1][tempP.second] = true;
                            p1.first = tempP.first - 1;
                            p1.second = tempP.second;
                            q.push(p1);
                        }
                    }

                     if(checkBoundary(tempP.first, tempP.second -1, grid)) {
                        if(!visited[tempP.first][tempP.second - 1] && grid[tempP.first][tempP.second - 1] == 1) {
                            visited[tempP.first][tempP.second - 1] = true;
                            p1.first = tempP.first;
                            p1.second = tempP.second - 1;
                            q.push(p1);
                        }
                    }

                     if(checkBoundary(tempP.first, tempP.second + 1, grid)) {
                        if( !visited[tempP.first][tempP.second + 1] && grid[tempP.first][tempP.second + 1] == 1) {
                            visited[tempP.first][tempP.second + 1] = true;
                            p1.first = tempP.first;
                            p1.second = tempP.second + 1;
                            q.push(p1);
                        }
                    }
                }
            }
        }
    }


    return cnt;


}

int main() {
    vector<vector<int> > vec;
    int m, n,p;

    cout << "Enter the number of row and column" << endl;
    cin >> m;
    cin >> n;

    for(int i = 0 ; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            cin >> p;
            v.push_back(p);
        }

        vec.push_back(v);
    }

    cout << "value printed " << endl;

    //  for(int i = 0 ; i < vec.size(); i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   int res = numIslands(vec);
   cout << res << endl;
}