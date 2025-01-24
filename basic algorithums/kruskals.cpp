//Disjoint Set with rank and size
class UnionFind{
    private:
    vector<int> root, rank, size;
    
    public:
    UnionFind(int n){
        root.resize(n);
        rank.resize(n, 1);
        size.resize(n, 1);
        
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

    bool yunion(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY) return false;
        
        if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else if(rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        else{
            root[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
        
        return true;
    }
    
    int getRank(int x){
        return rank[find(x)];
    }
    
    int getSize(int x){
        return size[find(x)];
    }
};

struct Edge{
    int from;
    int to;
    int w;
    
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

int kruskals(int n, vector<Edge>& edges) {
    int s = edges.size();
    UnionFind uf(n);
    int minW = 0;
    int counter = 0;

    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < s; i++) {
        if (counter == n - 1){
            break;
        }
      
        if (uf.yunion(edges[i].from, edges[i].to)) {
            minW += edges[i].w;
            counter++;
        }
    }

    return minW;
}
