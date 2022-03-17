// Floyd Warshall algorithm to get all source shortest paths and print all the paths
//also it detects negative cycle.
#include<bits/stdc++.h>
using namespace std;

void Floyd_Warshall(vector<vector<int>> G) {
    int n = G.size();
    int inf = 1e9;
    vector<vector<int>>apsp = G;
    vector<vector<int>> next(n, vector<int>(n, -1));
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 0)
                apsp[i][j] = inf;
            if(G[i][j] != 0)
                next[i][j] = j;
        }
    }

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                apsp[i][j] = 0;
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if(apsp[i][k] == inf || apsp[k][j] == inf)
                    continue;
                if (apsp[i][k] + apsp[k][j] < apsp[i][j]) {
                    apsp[i][j] = apsp[i][k] + apsp[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    //for detecting negative cycles
    for (int k = 0; k < n; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if(apsp[i][k] == inf || apsp[k][j] == inf)
                    continue;
                if (apsp[i][k] + apsp[k][j] < apsp[i][j]) {
                    apsp[i][j] = -inf;
                    next[i][j] = -2;
                }
            }
        }
    }  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(apsp[i][j] == -inf) {
                    cout<<"path from "<<i<< " to "<< j << " is contaminated by negative cycle"<<endl;
                    continue;
                }

            else if (apsp[i][j] != inf && i != j) {
                
                cout << "path from " << i << " to " << j << "is  " ;
                int start = i;
                while (start != j) {
                    cout << start <<"->";
                    start = next[start][j];
                }
                cout << j;
                cout<<'\n';
            }
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>>G(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = w;
    }
    Floyd_Warshall(G);
}
