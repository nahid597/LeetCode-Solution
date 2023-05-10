#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

 bool cycleUtil(vector<int> adj[], int s, vector<int>&visited) {
    if (visited[s] == 1)
    {
        return true;
    }

    if (visited[s] == 2)
    {
        return false;
    }

    visited[s] = 1;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (cycleUtil(adj, adj[s][i], visited))
        {
            return true;
        }
    }
    
    visited[s] = 2;
    return false;
 }

 bool detectCycle(vector<int>adj[], int n) {
    vector<int>visited(n , 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cycleUtil(adj, i, visited))
            {
                return true;
            }
            
        }
        
    }

    return false;
    
 }

 void helperDfs(int s, vector<int>adj[], vector<bool>&visited,stack<int>&myStack) {
    visited[s]= true;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!visited[adj[s][i]])
        {
            helperDfs(adj[s][i], adj, visited, myStack);
        }
        
    }

    myStack.push(s);
 }

  vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {

    // [[1,0],[1,2],[2,1]]
    vector<int>adj[numCourses + 1];
    int u, v;
    bool res = false;
    int cnt = 0;
    

    for (int  i = 0; i < prerequisites.size(); i++)
    {
        u = prerequisites[i][1];
        v = prerequisites[i][0];
        adj[u].push_back(v);
    }

     vector<int>answer;

     if (detectCycle(adj, numCourses))
     {
        return answer;
     }
     
     vector<bool>visited(numCourses, false);
     stack<int>myStack;

    for (int  i = 0; i < numCourses ; i++)
    {
       if(!visited[i]) {
            helperDfs(i, adj, visited,myStack);
       }  
    }

    while (!myStack.empty())
    {
        answer.push_back(myStack.top());
        myStack.pop();
    }
    
    return answer;
        
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


    vector<int> res = findOrder(numCourses, prerequisites);

   cout << "final result "<< endl;

   for (int i = 0; i < res.size(); i++)
   {
        cout << res[i] << " ";
   }

   cout << endl;

    return 0;
}