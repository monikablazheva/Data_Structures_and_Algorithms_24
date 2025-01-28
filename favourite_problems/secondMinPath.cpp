class Solution {
    struct Node{
        int id;
        int distance;

        bool operator<(const Node& rhs) const{
            return distance > rhs.distance;
        }
    };
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        vector<int> visited(n + 1, 0);

        dist1[1] = 0;

        priority_queue<Node> pq;
        pq.push({1, 0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int timeTaken = curr.distance;
            visited[curr.id]++;

            if(visited[curr.id] > 2) continue;

            if (visited[curr.id] == 2 && curr.id == n) return timeTaken;
            // If the current light is red, wait till the path turns green.
            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }

            for(auto& adj: graph[curr.id]){
                
                if(dist1[adj] > timeTaken){
                    dist2[adj] = dist1[adj];
                    dist1[adj] = timeTaken;
                    pq.push({adj, timeTaken});
                }
                else if(dist2[adj] > timeTaken &&
                dist1[adj] != timeTaken){
                    dist2[adj] = timeTaken;
                    pq.push({adj, timeTaken});
                }
            }
        }
        
        return 0;
    }
};
