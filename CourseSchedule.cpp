#include<iostream>
#include<queue>
#include<vector>

using namespace std;


// bool dfs(int s, int par, vector<int> adj[], vector<bool>visited) {

//     visited[s] = true;
//     bool res = false;


//     for (int i = 0; i < adj[s].size(); i++)
//     {
//         int t = adj[s][i];

//         if (!visited[t])
//         {
//             return dfs(t, s, adj, visited);
//         } else {
//             if (par != t)
//             {
//                 return true;
//             } 
//         }
        
//     }

//     return res;
// }

// bool isCycle(vector<int> adj[], int v) {

//     bool res;
//    // vector<bool>visited(100, false);

//     for (int i = 0; i < v; i++)
//     {
//         vector<bool>visited(100, false);

//         res = dfs(i, -1, adj, visited);

//         if(res) {
//             cout << "nahid" << endl;
//             return true;
//         }
//     }
    

//     return false;
// }




 bool helperDfs(int s, vector<int>adj[], vector<bool>&visited,vector<bool> &resStack, vector<int>&travesNodes) {

    if (!visited[s])
    {
        visited[s] = true;
        resStack[s] = true;
        
        if (travesNodes[s] == -1)
        {
           travesNodes[s] = 1;
        }

        for (int i = 0; i < adj[s].size(); i++)
        {
            int temp = adj[s][i];


            if(!visited[temp] && helperDfs(temp,adj,visited,resStack,travesNodes)) {
            return true;
            } else  if (resStack[temp])
                {
                    return true;
                }

        }
    }
    
    resStack[s] = false;
    return false;
    
 }

  bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {

    // [[1,0],[1,2],[2,1]]
    vector<int>adj[numCourses + 1];
    int u, v;
    bool res = false;
    int cnt = 0;

    for (int  i = 0; i < prerequisites.size(); i++)
    {
        u = prerequisites[i][0];
        v = prerequisites[i][1];
        adj[u].push_back(v);
    }

     vector<bool>visited(numCourses, false);
     vector<bool> resStack(numCourses,false);
     vector<int>travesNodes(numCourses, -1);
    

    for (int  i = 0; i < numCourses; i++)
    {
       
       if(!visited[i]) {
            res = helperDfs(i, adj, visited,resStack, travesNodes);
            if (res)
            {
                cout << "circle found" << endl;
                break;
            }
       }
        
    }

    if (res) {
        return false;
    } else {
        for (int i = 0; i < travesNodes.size(); i++)
        {
            if(travesNodes[i] == 1) {
                cnt++;
            }
        }
    }

    if (cnt == numCourses)
    {
        return true;
    }
    
    return false;
        
    }

int main() {


   vector<vector<int> > prerequisites;
   vector<int>vec;

   int numCourses, u, v;

   cout << "Enter number of course " << endl;
   cin >> numCourses;

   // vertex must be (0 to n - 1) range;

   // [[1,0],[1,2],[3,1]]

   for (int i = 0; i < numCourses; i++)
   {
        vector<int>vec;
        cin >> u >> v;
        vec.push_back(u);
        vec.push_back(v);
        prerequisites.push_back(vec);
   }


   bool res = canFinish(numCourses, prerequisites);

   cout << "final result " << res << endl;

   

    return 0;
}