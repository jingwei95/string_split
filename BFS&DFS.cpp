// BFS
bool adj[9][9]; // 一張圖，資料結構為adjacency matrix。
bool visit[9];  // 記錄圖上的點是否遍歷過，有遍歷過為true。
 
void BFS()
{
    // 建立一個queue。
    queue<int> q;
 
    // 全部的點都初始化為尚未遍歷
    for (int i=0; i<9; i++)
        visit[i] = false;
 
    for (int k=0; k<9; k++)
        if (!visit[k])
        {
            // 一、把起點放入queue。
            q.push(k);
            visit[k] = true;
 
            // 二、重複下述兩點，直到queue裡面沒有東西為止：
            while (!q.empty())
            {
                // 甲、從queue當中取出一點。
                int i = q.front(); q.pop();
 
                // 乙、找出跟此點相鄰的點，並且尚未遍歷的點，
                //     依照編號順序通通放入queue。
                for (int j=0; j<9; j++)
                    if (adj[i][j] && !visit[j])
                    {
                        q.push(j);
                        visit[j] = true;
                    }
            }
        }
}

// DFS
bool adj[9][9]; // 一張圖，資料結構為adjacency matrix。
bool visit[9];  // 記錄圖上的點是否遍歷過，有遍歷過為true。
 
void DFS(int i)
{
    for (int j=0; j<9; j++)
        if (adj[i][j] && !visit[j])
        {
            visit[j] = true;    // 標記為已遍歷
            DFS(j);
        }
}
 
void traversal()
{
    // 全部的點都初始化為尚未遍歷
    for (int i=0; i<9; i++)
        visit[i] = false;
 
    for (int i=0; i<9; i++)
        if (!visit[i])
        {
            visit[i] = true;
            DFS(i);
        }
}