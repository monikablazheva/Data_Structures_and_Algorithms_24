bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr){
    visited[curr] = 1; //in progress
    
    for(int& neib: graph[curr]){
        if(visited[neib] == 1){
            return true;
        }
        if(visited[neib] == 0){
            if(dfs(graph, visited, neib)){
                return true;
            }
        }
    }
    
    visited[curr] = 2; //checked
    
    return false;
}

bool isCyclic(vector<vector<int>>& graph, int n){
    vector<int> visited(n,0);
    
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
           if(dfs(graph, visited, i)){
                return true;
            }
        }
    }
    
    return false;
}
