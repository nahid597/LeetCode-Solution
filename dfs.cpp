#include<iostream>
#include<queue>

using namespace std;

vector<bool>visited(100, false);

void dfs(int s, vector<int> adj[]) {

    visited[s] = true;

   cout << s << endl;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int t = adj[s][i];

        if (!visited[t])
        {
            dfs(t, adj);
        }
        
    }
     
}

int main() {

//     1
//    / \
//   2   3

// adj[1] = 2;
// adj[1] = 3;

/* [
    [],
    [2,3]
]*/

   vector<int>adj[100];
   int n, u,v,s;

   cout << "Enter number of edge " << endl;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
        cin >> u >> v;
        adj[u].push_back(v);
   }

   cout << "Enter the start node " << endl;
   cin >> s;
   
   dfs(s, adj);

   

    return 0;
}