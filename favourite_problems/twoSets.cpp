//shortest path from q to whatever element from a component
struct Edge{
    int to;
    int w;
};

struct Node{
    int index;
    int distance;
    bool operator<(const Node rhs) const{
        return distance > rhs.distance;
    }
};

vector<int> shortestPaths(int n, unordered_map<int, vector<Edge>>& graph, unordered_set<int>& tStarts){
    vector<int> distances(n, INT_MAX);
    priority_queue<Node> pq;
    
    for(int el: tStarts){
        pq.push({el, 0});
        distances[el] = 0;
    }
    
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        
        if(curr.distance > distances[curr.index]){
            continue;
        }
        
        for(auto& edge: graph[curr.index]){
            int newW = curr.distance + edge.w;
            if(newW < distances[edge.to]){
                distances[edge.to] = newW;
                pq.push({edge.to, newW});
            }
        }
    }
    
    return distances;
}

int main() {
    int N, M, K, Q, t, q, from, to, w;
    unordered_map<int, vector<Edge>> graph;
    unordered_set<int> T;
    unordered_set<int> S;
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }
    for(int i = 0; i < N; i++){
        S.insert(i);
    }
    
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> t;
        T.insert(t);
        S.erase(t);
    }
    
    vector<int> distances = shortestPaths(N, graph, T);
    
    cin>> Q;
    for(int i = 0; i < Q; i++){
        cin >> q;
        cout << distances[q] << endl;
    }
    
    return 0;
}
