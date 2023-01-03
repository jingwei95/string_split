int g[10];  // 每個人所屬的團體編號
g[0] = 0;   // 第0人在第0團
g[1] = 0;   // 第1人在第0團
g[2] = 2;   // 第2人在第2團
…                        
g[9] = 2;   // 第9人在第2團

// 初始化
void initialize()
{
    for (int x=0; x<10; x++)
        g[x] = x;
}

// 尋找
int find(int x)
{
    return g[x];
}

// 檢查equivalance
bool equivlence(int x, int y)
{
    return g[x] == g[y];
}

// union
void union(int x, int y)
{
    // 要是x y不同團，才設成同團，以節省時間。
    if (g[x] != g[y])
    {
        int gmin = min(g[x], g[y]); // 團體編號較小者
        int gmax = max(g[x], g[y]); // 團體編號較大者
 
        // 把所有與x y同團的人，都填上同一個團體編號。
        // 設定為團體編號較小者，
        // 讓所有團體編號維持是從零0開始的連續數字。
        for (int i=0; i<10; i++)
            if (g[i] == gmax)
                g[i] = gmin;
    }
}

// union 精簡版
void union(int x, int y)
{
    // 精簡程式碼結構
    if (g[x] == g[y]) return;
 
    // 為了精簡程式碼，不管團體編號大小了。
    int gx = g[x], gy = g[y];
    for (int i=0; i<10; i++)
        if (g[i] == gx)
            g[i] = gy;
}