struct Edge{
    int from;
    int to;
    int w;
    
    bool operator<(const Edge& rhs) const{
        return w > rhs.w;
    }
};

long long prims(int n, vector<vector<int>> edges, int start) {
    int s = edges.size();
    
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < s; i++) {
        graph[edges[i][0]].push_back({edges[i][0], edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][1], edges[i][0], edges[i][2]});
    }
    
    unordered_set<int> visited;
    priority_queue<Edge> pq;
    
    pq.push({ start, start, 0 });
    long long w = 0;
    
    while(!pq.empty() && (int)visited.size() < n) {
        auto curr = pq.top();
        pq.pop();
        
        if(visited.count(curr.to)) {
            continue;
        }
        visited.insert(curr.to);
        w += curr.w;
        
        for(auto& edge: graph[curr.to]){
            if(visited.count(edge.to)){
                continue;
            }
            pq.push(edge);
        }
    }
    
    return w;
}
