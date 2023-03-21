#include<iostream>
#include<queue>

using namespace std;

void bfs(int s, vector<int> adj[]) {
    vector<bool>visited(100, false);

    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
       int t = q.front();
       q.pop();
       cout << t << endl;

       for (int i = 0; i < adj[t].size(); i++)
       {
          if (!visited[adj[t][i]])
          {
             q.push(adj[t][i]);
             visited[adj[t][i]] = true;
          }
       }
       
    }
     
}

int main() {

//     1
//    / \
//   2   3

// adj[1] = 2;
// adj[1] = 3;

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
   
   bfs(s, adj);

   

    return 0;
}