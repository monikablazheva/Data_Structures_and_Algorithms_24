int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        
        for(int i = 0; i < k+1; i++){
            vector<int> newRow(distances);
            for(auto& edge: flights){
                int from = edge[0];
                int to = edge[1];
                int w = edge[2];
                if(distances[from] != INT_MAX && distances[from] + w < newRow[to]){
                    newRow[to] = distances[from] + w;
                }
            }

            distances = std::move(newRow);
        }

        if(distances[dst] == INT_MAX){
            return -1;
        }
        return distances[dst];
    }
