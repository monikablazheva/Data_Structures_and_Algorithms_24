struct Edge{
    int to;
    int w;
};

struct Node{
    int index;
    int distance;
    
    bool operator<(const Node& rhs) const{
        return distance > rhs.distance;
    }
};

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> distances(n, INT_MAX);
    priority_queue<Node> next;
    
    distances[s - 1] = 0;
    next.push({s,0});
    
    while(!next.empty()){
        auto curr = next.top();
        next.pop();
        
        if(curr.distance > distances[curr.index - 1]){
            continue;
        }
        
        for(auto& edge: graph[curr.index]){
            int newW = curr.distance + edge.w;
            if(newW < distances[edge.to - 1]){
                distances[edge.to - 1] = newW;
                next.push({edge.to, newW});
            }
        }
    }
    
    return distances;
}
