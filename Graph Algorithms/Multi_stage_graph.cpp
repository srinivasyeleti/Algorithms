//Multi Stage Graph problem using DP to find the minimum path from source vertex
//to sink vertex using Forward approach.
// Graph is taken in adjacancy List representation.

#include<bits/stdc++.h>
using namespace std;

void Multi_stage_graph(vector<pair<int, int>> G[], int v, int e) {
    vector<int> cost(v + 1, INT_MAX);
    cost[v] = 0;
    for (int i = v - 1; i > 0; i--) {
        for (auto x : G[i]) {
            int j = x.first;
            int w = x.second;
            cost[i] = min(cost[i], w + cost[j]);
        }
    }
    cout << cost[1];
    return;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>>G[v + 1];
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
    }
    Multi_stage_graph(G, v, e);

    return 0;
}
