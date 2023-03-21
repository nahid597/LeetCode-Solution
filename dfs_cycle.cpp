#include<iostream>
#include<queue>

using namespace std;


bool dfs(int s, int par, vector<int> adj[], vector<bool>visited) {

    visited[s] = true;
    bool res = false;

//     0
//    / \
//   1-> 2

    for (int i = 0; i < adj[s].size(); i++)
    {
        int t = adj[s][i];

        if (!visited[t])
        {
            return dfs(t, s, adj, visited);
        } else {
            if (par != t)
            {
                return true;
            } 
        }
        
    }

    return res;
}

bool isCycle(vector<int> adj[], int v) {

    bool res;
   // vector<bool>visited(100, false);

    for (int i = 0; i < v; i++)
    {
        vector<bool>visited(100, false);

        res = dfs(i, -1, adj, visited);

        if(res) {
            cout << "nahid" << endl;
            return true;
        }
    }
    

    return false;
}

int main() {

//     1
//    / \
//   2 ->3

// adj[1] = 2;
// adj[1] = 3;

/* [
    [],
    [2,3]
]*/

   vector<int>adj[100];
   int n, u,v,s,v1;

   cout << "Enter number of edge " << endl;
   cin >> n;

   // vertex must be (0 to n - 1) range;

   for (int i = 0; i < n; i++)
   {
        cin >> u >> v;
        adj[u].push_back(v);
   }

   cout << "Enter number of vertex " << endl;
   cin >> v1;

   
   bool res = isCycle(adj,v1);

   cout << res << endl;
   

    return 0;
}