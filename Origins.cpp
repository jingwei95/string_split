/*
a vertex is called origin if it is able to reach every other vertex
find how many origins are in the given directed graph(no loops but may have two edges connecting the same pair of vertices)
*/

#include <iostream>
#include <vector>
#include <stack>

void DFS(int vertex, std::vector<int>*adjList, std::stack<int>&finish, bool *visited);
void DFS_t(int vertex, std::vector<int>*adjList_t, std::stack<int>&finish, bool *visited, std::vector<int>&set);


int main(){
    int t{};        //1 <= t <= 100, t: number of test case
    std::cin >> t;
    for (int i = 0; i < t; ++i){
        int n{}, m{};           //n: number of vertices, m: number of edges
        std::cin >> n >> m;     //2 <= n <= 10^4, 1 <= m <= 10^4

        /*initialize*/
        std::vector<int>*adjList = new std::vector<int>[n + 1];
        std::vector<int>*adjList_t = new std::vector<int>[n + 1];
        bool *visited = new bool[n + 1];
        for (int j = 0; j <= n; ++j){
            visited[j] = false;
        }

        /*insert edges*/
        for (int j = 0; j < m; ++j){
            int a{}, b{};
            std::cin >> a >> b;
            adjList[a].push_back(b);
            adjList_t[b].push_back(a);
        }

        /*do DFS and find strongly connected component*/
        std::stack<int>finish;
        for (int j = 1; j <= n; ++j){
            if (!visited[j])
                DFS(j, adjList, finish, visited);
        }

        /*find the first strongly connected component*/
        int vertex = finish.top();
        std::vector<int>set;
        DFS_t(vertex, adjList_t, finish, visited, set);  //DFS after transpose

        /*set all nodes be not visited before*/
        for (int j = 0; j <= n; ++j){
            visited[j] = false;
        }

        /*find origins*/
        if (set.size() == n){   //if the size of the first set I found equals to the number of vertices
            std::cout << n << "\n";     //only one strongly connected component
        }
        else{
            std::stack<int>time;
            DFS(set[0], adjList, time, visited);
            if (time.size() != n){  //if the size of the node visited is not equal to the number of vertices
                std::cout << 0 << "\n";
            }
            else {
                std::cout << set.size() << "\n";
            }
        }

        /*deallocation*/
        delete[] adjList;
        delete[] adjList_t;
        delete[] visited;
    }
    return 0;
}

void DFS(int vertex, std::vector<int>*adjList, std::stack<int>&finish, bool *visited){
    visited[vertex] = true;
    for (int i = 0; i < adjList[vertex].size(); ++i){
        if (!visited[adjList[vertex][i]])
            DFS(adjList[vertex][i], adjList, finish, visited);
    }
    finish.push(vertex);
}

void DFS_t(int vertex, std::vector<int>*adjList_t, std::stack<int>&finish, bool *visited, std::vector<int>&set){
    visited[vertex] = false;    //true after DFS, so let false be visited here
    set.push_back(vertex);
    for (int i = 0; i < adjList_t[vertex].size(); ++i){
        if (visited[adjList_t[vertex][i]]){
            DFS_t(adjList_t[vertex][i], adjList_t, finish, visited, set);
        }
    }
}
