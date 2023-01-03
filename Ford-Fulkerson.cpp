// 有一條涓流經過邊ij（adjacency matrix）
typedef int Graph[10][10];      // adjacency matrix
Graph C, F, R;                  // 容量上限、流量、剩餘容量
 
void one_stream_pass_ij()
{
    memcpy(R, C, sizeof(C));    // 最初每一條邊的剩餘容量等於容量上限
    memset(F, 0, sizeof(F));    // 最初的流量為零
 
    F[i][j] = F[i][j] + 流量;
    F[j][i] = -F[i][j];
    R[i][j] = C[i][j] - F[i][j];
    R[j][i] = C[j][i] - F[j][i];
}

// 有一條涓流經過邊ij（adjacency matrix）
typedef int Graph[10][10];  // adjacency matrix
Graph C, F, R;              // 容量上限、流量、剩餘容量
 
void one_stream_pass_ij()
{
    memcpy(R, C, sizeof(C));    // 最初每一條邊的剩餘容量等於容量上限
    memset(F, 0, sizeof(F));    // 最初的流量為零
 
    F[i][j] = F[i][j] + 流量;
    R[i][j] = C[i][j] - F[i][j] + F[j][i];
    R[j][i] = C[j][i] - F[j][i] + F[i][j];
}

// 有一條涓流經過邊ij（adjacency matrix）
typedef int Graph[10][10];  // adjacency matrix
Graph C, F, R;              // 容量上限、流量、剩餘容量
 
void one_stream_pass_ij()
{
    memset(F, 0, sizeof(F));    // 最初的流量為零
    memcpy(R, C, sizeof(C));    // 最初每一條邊的剩餘容量等於容量上限
 
    R[i][j] -= 流量;
    R[j][i] += 流量;
    F[i][j] = max(C[i][j] - R[i][j], 0);
    F[j][i] = max(C[j][i] - R[j][i], 0);
}

// 找出一個最大流＋計算最大流的流量
typedef int Graph[10][10];  // adjacency matrix
Graph C, F, R;              // 容量上限、流量、剩餘容量
 
int Ford_Fulkerson(int s, int t)    // 源點、匯點
{
    memset(F, 0, sizeof(F));    // 最初的流量為零
 
    while (存在一條擴充路徑：C[i][j] - F[i][j] > 0)
        for (這條擴充路徑的每一條邊ij)
        {
            F[i][j] += 擴充路徑流量;
            F[j][i] = -F[i][j];
        }
}
 
void Ford_Fulkerson(int s, int t)
{
    memset(F, 0, sizeof(F));    // 最初的流量為零
 
    while (存在一條擴充路徑：C[i][j] - F[i][j] + F[j][i] > 0)
        for (這條擴充路徑的每一條邊ij)
            F[i][j] += 擴充路徑流量;
}
 
void Ford_Fulkerson(int s, int t)
{
    memcpy(R, C, sizeof(C));    // 最初每一條邊的剩餘容量等於容量上限
 
    while (存在一條擴充路徑：R[i][j] > 0)
        for (這條擴充路徑的每一條邊ij)
        {
            R[i][j] -= 擴充路徑流量;
            R[j][i] += 擴充路徑流量;
        }
}