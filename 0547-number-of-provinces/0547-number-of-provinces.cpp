class Solution {
public:
    
    void dfs(vector<int> &list,vector<int>& visit, int i,vector<vector<int>>& isConnected){
        for(int j=0;j<list.size();j++){
                if(!visit[j] && i!=j && list[j]==1){
                    visit[j]=1;
                    dfs(isConnected[j],visit,j,isConnected);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<int> visited;
            for(int i=0;i<isConnected.size();i++)
                    visited.push_back(0);
            int count=0;
        
            
            for(int i=0;i<isConnected.size();i++){
                if(!visited[i]){
                    visited[i]=1;
                    count++;
                    dfs(isConnected[i],visited,i,isConnected);
                }
            }
        return count;
    }
};