// KRUSKAL's Algorithm using Priority Queue

#include<bits/stdc++.h>
using namespace std;
  
typedef  pair<int, int> iPair;
typedef pair<int, iPair> rPair;
  

struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;
  
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
  
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};
  

struct DisjointSets
{
    int *parent, *size;
    int n;
  
    // Constructor.
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        size = new int[n+1];
  
        // Initially, all vertices are in
        // different sets and have size = 1.
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
  
            //every element is parent of itself
            parent[i] = i;
        }
    }
  
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    // Union by size of the root
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        /* Make tree with smaller height
           a subtree of the other tree  */
        if (size[x] >= size[y]){
            parent[y] = x;
            size[x] += size[y];
        }
        else // If rnk[x] <= rnk[y]
        {
            parent[x] = y;
            size[y] += size[x];
        }
  
    }
};

  
 /* Functions returns weight of the MST*/ 
  
int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result
  
    // creating heap for all the edges in the Edge List.
    priority_queue <rPair, vector<rPair>, greater<rPair>> pq;
    for(auto edge : edges) {
        pq.push(edge);
    }
  
    // Create disjoint sets
    DisjointSets ds(V);
    int i = 0;
    // Iterate through Edges on the top of the priority queue
    while (i < V - 1 && !(pq.empty()))
    {
        rPair top = pq.top();
        pq.pop();
        int u = top.second.first;
        int v = top.second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << u << " - " << v << endl;
  
            // Update MST weight
            mst_wt += top.first;
            i++;
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
    
    return (i == V - 1) ? mst_wt : INT_MIN;
}
  
int main()
{
    int V , E ;
    cout << "Enter the number of vertices and Edges : ";
    cin >> V >> E;
    Graph g(V, E);
    int u, v, w;
    cout << "Enter the Edges as vertex vertex weight : "<< endl;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << '\n';
    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();
    if(mst_wt != INT_MIN)
        cout << "\nWeight of MST is " << mst_wt;
    else
        cout << "Minimum spanning tree is not there in the graph";
  
    return 0;
}
