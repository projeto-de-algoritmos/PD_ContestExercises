#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int oo{1000000010};
int dist[110][110], st[110][1 << 13];

void floyd_warshall(int N, const vector<vector<ii>> &adj) {
    for (int u = 1; u <= N; ++u)
        for (int v = 1; v <= N; ++v) 
            dist[u][v] = oo;

    for (int u = 1; u <= N; ++u) dist[u][u] = 0;

    for (int u = 1; u <= N; ++u)
        for (const auto &[v, w] : adj[u])
            dist[u][v] = w;

    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
}

int tsp(int i, int mask, int N, int B, const vector<ii> &xs){
    int ans = oo;
    if (mask == (1 << N) - 1) return dist[i][B];
    if (st[i][mask] != -1) return st[i][mask];

    for (int j = 0; j < N; ++j) {
        if (mask & (1 << j)) continue;
        auto u = xs[j].first, v = xs[j].second;
        auto cost = dist[i][u] + dist[u][v];
        ans = min(ans, tsp(v, mask | (1 << j), N, B, xs) + cost);
    }
    st[i][mask] = ans;
    return ans;
}

int solve(int N, int B, const vector<vector<ii>> &adj, const vector<ii> &xs){
    floyd_warshall(N, adj);
    memset(st, -1, sizeof st);
    return tsp(B, 0, (int)xs.size(), B, xs);
}

int main(){
    ios::sync_with_stdio(false);
    int T, Z;
    int u, v, b;

    cin >> T;
    for (int i = 0; i < T; i++){
        int N, M, B;
        cin >> N >> M >> B;

        vector<vector<ii>> adj(N + 1);

        while (M--){
            int u, v, d;
            cin >> u >> v >> d;

            adj[u].push_back(ii(v, d));
            adj[v].push_back(ii(u, d));
        }
        
        cin >> Z;
        vector<ii> xs;

        for (int i = 0; i < Z; ++i){
            cin >> u >> v >> b;
            while (b--) xs.push_back(ii(u, v));
        }
        cout << solve(N, B, adj, xs) << '\n';
    }
    return 0;
}