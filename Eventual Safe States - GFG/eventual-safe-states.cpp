//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool cycleCheck(int node,int vis[],int pathvis[],vector<int> adj[],int check[]){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycleCheck(it,vis,pathvis,adj,check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvis[it]) {
                check[node]=0;
                return true;
            }
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0},pathVis[V]={0},check[V]={0};
        vector<int> safeNodes;
        for(int i=0 ; i<V ; i++){
            if(!vis[i])
                cycleCheck(i,vis,pathVis,adj,check);
        }
        for(int i = 0 ; i < V ; i++){
            if(check[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends