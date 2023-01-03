// Tarjan Algorithm
int adj[9][9];          // 記錄邊數，支援多重邊
int visit[9], low[9], t = 0;
int stack[9], top = 0;  // 堆疊
int contract[9];        // 每個點收縮到的點
 
void DFS(int i, int p)
{
    visit[i] = low[i] = ++t;
    stack[top++] = i;   // push i
 
    for (int j=0; j<9; ++j)
        if (adj[i][j])
        {
            // tree edge
            if (!visit[j])
                DFS(j, i);
 
            // tree/back edge
            if (!(j == p && adj[i][j] == 1))
                low[i] = min(low[i], low[j]);
        }
 
    // 形成BCC。
    // i點會是BCC裡面，最早拜訪的點。
    if (visit[i] == low[i])
    {
//      cout << "block:";
        int j;
        do {
            j = stack[--top];   // pop j
//          cout << j;
            contract[j] = i;
        } while (i != j);
    }
}
 
void tarjan()
{
    memset(visit, 0, sizeof(visit));
    t = 0;
 
    for (int i=0; i<9; ++i)
        if (!visit[i])
            DFS(i, i);
}

// Kosaraju's Algorithm
int adj[9][9];          // adjacency matrix
bool visit[9];          // DFS visit record
vector<int> finish[9];  // DFS離開點的順序
int scc[9];             // 每個點的強連通分量編號
 
void DFS1(int i)
{
    visit[i] = true;
    for (int j=0; j<9; ++j)
        if (adj[i][j] && !visit[j])
            DFS1(j);
 
    finish.push_back(i);
}
 
void DFS2(int i, int c)
{
    cout << "第" << c << "個強連通分量";
    cout << "包含第" << i << "點";
    scc[i] = c; // 設定第i點屬於第c個強連通分量
 
    visit[i] = true;
    for (int j=0; j<9; ++j)
        if (adj[j][i] && !visit[j]) // 顛倒所有邊的方向
            DFS2(j, c);
}
 
void kosaraju()
{
    finish.clear();
    memset(visit, false, sizeof(visit));
    for (int i=0; i<9; ++i)
        if (!visit[i])
            DFS1(i);
 
    memset(visit, false, sizeof(visit));
    for (int i=9-1; i>=0; --i)
        if (!visit[finish[i]])      // 原圖的偽拓撲順序
            DFS2(finish[i], c++);   // 找到一個強連通分量
}