#include <iostream>
#include <queue>

using namespace std;

bool checkBoundary(int r, int c, vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (r >= 0 && r < m && c >= 0 && c < n)
    {
        return true;
    }

    return false;
}

int numEnclaves(vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    bool visited[m + 1][n + 1];
    int mx = 0;
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                visited[i][j] = true;
                queue<pair<int, int> > q;
                pair<int, int> p;
                int cnt = 0;
                bool flag = false;

                p.first = i;
                p.second = j;

                q.push(p);

                while (!q.empty())
                {
                    cnt++;
                    pair<int, int> tempP;
                    pair<int, int> p1;

                    tempP = q.front();
                    q.pop();

                    if (checkBoundary(tempP.first, tempP.second - 1, grid))
                    {
                        if (!visited[tempP.first][tempP.second - 1] && grid[tempP.first][tempP.second - 1] == 1)
                        {
                            visited[tempP.first][tempP.second - 1] = true;
                            p1.first = tempP.first;
                            p1.second = tempP.second - 1;
                            q.push(p1);
                        }
                    }
                    else
                    {
                        flag = true;
                    }

                    if (checkBoundary(tempP.first - 1, tempP.second, grid))
                    {
                        if (!visited[tempP.first - 1][tempP.second] && grid[tempP.first - 1][tempP.second] == 1)
                        {
                            visited[tempP.first - 1][tempP.second] = true;
                            p1.first = tempP.first - 1;
                            p1.second = tempP.second;
                            q.push(p1);
                        }
                    }
                    else
                    {
                        flag = true;
                    }

                    if (checkBoundary(tempP.first + 1, tempP.second, grid))
                    {
                        if (!visited[tempP.first + 1][tempP.second] && grid[tempP.first + 1][tempP.second] == 1)
                        {
                            visited[tempP.first + 1][tempP.second] = true;
                            p1.first = tempP.first + 1;
                            p1.second = tempP.second;
                            q.push(p1);
                        }
                    }
                    else
                    {
                        flag = true;
                    }

                    if (checkBoundary(tempP.first, tempP.second + 1, grid))
                    {
                        if (!visited[tempP.first][tempP.second + 1] && grid[tempP.first][tempP.second + 1] == 1)
                        {
                            visited[tempP.first][tempP.second + 1] = true;
                            p1.first = tempP.first;
                            p1.second = tempP.second + 1;
                            q.push(p1);
                        }
                    }
                    else
                    {
                        flag = true;
                    }
                }

                if(!flag) {
                    ans += cnt;
                }
            }
        }
    }

    return ans;
}

int main()
{

    vector<vector<int> > vec;
    int m, n, p;

    cout << "Enter the number of row and column" << endl;
    cin >> m;
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            cin >> p;
            v.push_back(p);
        }

        vec.push_back(v);
    }

    cout << "Final Result printed " << endl;

    int res = numEnclaves(vec);
    cout << res << endl;

    return 0;
}