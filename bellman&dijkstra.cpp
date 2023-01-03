int w[9][9];    // adjacency matrix
int d[9];       // 記錄起點到各個點的最短路徑長度
int parent[9];  // 記錄各個點在最短路徑樹上的父親是誰
 
void bellman_ford(int source)
{
    for (int i=0; i<9; i++) d[i] = 1e9;
 
    d[source] = 0;              // 設定起點的最短路徑長度
    parent[source] = source;    // 設定起點是樹根（父親為自己）
 
    for (int i=0; i<9-1; i++)   // 重覆步驟V-1次
        for (int a=0; a<9; ++a) // 全部的邊都當作捷徑
            for (int b=0; b<9; ++b)
                if (d[a] != 1e9 && w[a][b] != 1e9)
                    if (d[a] + w[a][b] < d[b])
                    {
                        d[b] = d[a] + w[a][b];
                        parent[b] = a;
                    }
}

// Dijkstra Algorithm
// 要丟進Priority Queue的點
// b是點，d是可能的最短路徑長度。
// a可以提出來，不必放在Node裡。
struct Node {int b, d;};
bool operator<(Node n1, Node n2) {return n1.d > n2.d;}
 
int w[9][9];    // adjacency matrix
int d[9];
int parent[9];
bool visit[9];
 
void dijkstra_with_priority_queue(int source)
{
    for (int i=0; i<9; i++) visit[i] = false;
    for (int i=0; i<9; i++) d[i] = 1e9;
 
    // C++ STL的Priority Queue
    priority_queue<Node> pq;
 
    d[source] = 0;
    parent[source] = source;
    pq.push((Node){source, d[source]});
 
    for (int i=0; i<9; i++)
    {
        // 找出下一個要加入到最短路徑樹的點。
        int a = -1;
        while (!pq.empty() && visit[a = pq.top().b])
            pq.pop();   // 最後少pop一次，不過無妨。
 
        if (a == -1) break;
        visit[a] = true;
 
        for (int b=0; b<9; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
            {
                d[b] = d[a] + w[a][b];
                parent[b] = a;
                // 交由Priority Queue比較大小
                pq.push( (Node){b, d[b]} );
            }
    }
}

// 偵測起點是否會到達負環
bool negative_cycle()
{
    for (int a=0; a<9; ++a)
        for (int b=0; b<9; ++b)
            if (d[a] != 1e9 && w[a][b] != 1e9)
                if (d[a] + w[a][b] < d[b])
                    return true;
    return false;
}