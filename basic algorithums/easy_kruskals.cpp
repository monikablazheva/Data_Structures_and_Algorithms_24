int root[3000]{};

int find(int x){
    if(root[x] == x){
        return x;
    }

    return root[x] = find(root[x]);
}

void yunion(int x, int y){
    root[find(x)] = find(y);
}

struct Edge{
    int from;
    int to;
    int w;

    bool operator<(const Edge& rhs) const{
        return w < rhs.w;
    }
};

int kruskals(int n, vector<Edge>& edges) {
    int s = edges.size();
    sort(edges.begin(), edges.end());

    for(int i = 0; i < n; i++) {
        root[i] = i;
    }

    int minW = 0;
    for(int i = 0; i < s; i++){
        if(find(edges[i].from) != find(edges[i].to)){
            minW += edges[i].w;
            yunion(edges[i].from, edges[i].to);
        }
    }

    return minW;
}
