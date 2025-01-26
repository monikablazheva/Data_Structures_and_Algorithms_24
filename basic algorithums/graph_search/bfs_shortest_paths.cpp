vector<int> bfsShortestPaths(int n, int m, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<int>> graph;
    for(auto& edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    vector<int> distances(n, -1);
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    int distance = 0;
    
    while(!q.empty()){
        int qSize = q.size();
        
        for(int i = 0; i < qSize; i++){
            auto curr = q.front();
            q.pop();
            distances[curr] = distance;
        
            for(int& neib: graph[curr]){
                if(!visited[neib]){
                    visited[neib] = true;
                    q.push(neib);
                }
            }
        }
        
        distance++;
    }
    
    //distances.erase(distances.begin() + s - 1);
    return distances;
}
