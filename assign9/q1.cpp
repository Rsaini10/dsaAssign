#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({v,w});
        if(undirected) adj[v].push_back({u,w});
    }

    void BFS(int s) {
        vector<bool> visited(V,false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for(auto &x: adj[u]) {
                if(!visited[x.first]) {
                    visited[x.first] = true;
                    q.push(x.first);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";
        for(auto &x: adj[u]) {
            if(!visited[x.first])
                DFSUtil(x.first, visited);
        }
    }

    void DFS(int s) {
        vector<bool> visited(V,false);
        DFSUtil(s, visited);
        cout << endl;
    }

    int findSet(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent[i], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findSet(u, parent);
        v = findSet(v, parent);
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    void KruskalMST() {
        vector<pair<int, pair<int,int>>> edges;
        for(int u=0; u<V; u++) {
            for(auto &x: adj[u]) {
                int v = x.first, w = x.second;
                if(u < v)
                    edges.push_back({w, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());
        vector<int> parent(V), rank(V,0);
        for(int i=0; i<V; i++) parent[i] = i;

        cout << "Kruskal MST: ";
        for(auto &e: edges) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;
            int set_u = findSet(u, parent);
            int set_v = findSet(v, parent);

            if (set_u != set_v) {
                cout << "(" << u << "-" << v << ":" << w << ") ";
                unionSet(set_u, set_v, parent, rank);
            }
        }
        cout << endl;
    }

    void PrimMST(int start = 0) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        pq.push({0, start});
        key[start] = 0;

        cout << "Prim MST: ";
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(inMST[u]) continue;
            inMST[u] = true;

            for(auto &x : adj[u]) {
                int v = x.first, w = x.second;
                if(!inMST[v] && key[v] > w) {
                    key[v] = w;
                    pq.push({key[v], v});
                }
            }
        }

        for(int i=0;i<V;i++) {
            cout << key[i] << " ";
        }
        cout << endl;
    }

    void Dijkstra(int s) {
        vector<int> dist(V, INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[s] = 0;
        pq.push({0,s});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(auto &x : adj[u]) {
                int v = x.first, w = x.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra Distances: ";
        for(int i=0;i<V;i++) {
            if(dist[i] == INT_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(2,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,5);
    g.addEdge(3,4,3);
    g.addEdge(4,5,8);

    cout << "BFS: ";
    g.BFS(0);

    cout << "DFS: ";
    g.DFS(0);

    g.KruskalMST();
    g.PrimMST(0);
    g.Dijkstra(0);

    return 0;
}
