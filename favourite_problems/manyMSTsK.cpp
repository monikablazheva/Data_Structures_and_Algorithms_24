#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    vector<int> root, rank, size;
    vector<long long> weight;
    
public:
    
    UnionFind(int n){
        root.resize(n);
        size.resize(n,1);
        rank.resize(n,1);
        weight.resize(n,0);
        
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
    }
    
    int find(int x){
        if(root[x] == x){
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void yunion(int x, int y, long long w){
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY) return;
        
        if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            size[rootX] += size[rootY];
            weight[rootX] += weight[rootY] + w;
        }
        else if(rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
            size[rootY] += size[rootX];
            weight[rootY] += weight[rootX] + w;
        }
        else {
            root[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
            weight[rootX] += weight[rootY] + w;
        }
    }
    
    int getSize(int x){
        return size[find(x)];
    }
    
    long long getWeight(int x){
        return weight[find(x)];
    }
};

struct Edge{
    int from;
    int to;
    long long w;
    
    bool operator<(const Edge& rhs) const{
        return w < rhs.w;
    }
};

long long kruskal(vector<Edge>& edges, int n, int K){
    sort(edges.begin(), edges.end()); 
    UnionFind uf(n);
    
    for(auto& edge: edges){
        uf.yunion(edge.from, edge.to, edge.w);
    }
    
    long long weight = 0;
    for(int i = 0; i < n; i++){
        if(uf.find(i) == i){
            if(uf.getSize(i) % K == 0){
                weight += uf.getWeight(i);
            }
        }
    }
    
    return weight;
}

void solve(){
    int V, E, K, from, to;
    long long w;
    cin >> V >> E >> K;
    vector<Edge> edges;
    
    for(int i = 0; i < E; i++){
        cin>> from >> to >> w;
        edges.push_back({from, to, w});
    }
    
    cout << kruskal(edges, V, K) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        solve();
    }

    return 0;
}
