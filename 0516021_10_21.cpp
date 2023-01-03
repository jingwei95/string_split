#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t, top;
int how_many_scc = 0;
void DFS(int i, vector<int> map[], int visit[], int low[], int stack[], bool instack[], int contract[], int NumVertice, vector<int> & scc){
	visit[i] = low[i] = ++t;
	stack[top++] = i;
	instack[i] = true;
	for(int t = 0;t < map[i].size();t++){
		int j = map[i][t];
		if(!visit[j]){
			DFS(j, map, visit, low, stack, instack, contract, NumVertice, scc);
		}
		if(instack[j]){
			low[i] = min(low[i], low[j]);
		}
	}
	//cout << visit[i] <<" "<<low[i]<<endl; 
	if(visit[i] == low[i]){
		cout <<"找到scc了"<<endl;
		int j;
		do{
			j = stack[--top];
			instack[j] = false;
			contract[j] = i;
		}while(j != i);
		scc.push_back(i);
		how_many_scc ++;
	}
	
}
int main(void){
	int test_case;
	cin >> test_case;
	for(int tc = 0;tc < test_case;tc++){
		how_many_scc = 0;
		int NumVertice, NumEdge;
		cin >> NumVertice >> NumEdge;
		vector<int> map[NumVertice];
		vector<int> scc;
		int visit[NumVertice], low[NumVertice];
		for(int i = 0;i < NumVertice;i++)
			visit[i] = 0;
		t = 0;
		top = 0;
		int stack[NumVertice];
		int ans = 0, boss;
		bool instack[NumVertice];
		int contract[NumVertice];
		int count = 0;
		for(int m = 0;m < NumEdge;m++){
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			map[a].push_back(b);
		}
		for(int i = 0;i < NumVertice;i++){
			//cout <<"分隔線"<<endl;
			if(!visit[i]){ 
				DFS(i, map, visit, low, stack, instack, contract, NumVertice, scc);
			}
		}
		bool scc_inside[how_many_scc];
		for(int i = 0;i < how_many_scc;i++)
			scc_inside[i] = false;
		for(int i = 0;i < how_many_scc;i++)
			cout << "scc[i]"<<scc[i]<<endl;
		//	cout << "contract[i]"<<contract[i]<<endl;
		for(int i = 0;i < NumVertice;i++){
			for(int j = 0;j < map[i].size();j++){
				for(int k = 0;k < how_many_scc;k++){
					if(scc[k] == contract[map[i][j]] && contract[i] != scc[k]){
						//cout << i <<" " <<j <<" "<<k<<endl; 
						scc_inside[k] = true;
					}
				}
			}
		}
		for(int i = 0;i < how_many_scc;i++){
			if(scc_inside[i] == false){
				boss = scc[i];
				count++;
			}
		}
		if(count == 1){
			for(int i = 0;i < NumVertice;i++){
				if(contract[i] == boss)
					ans++;
			}
			cout << ans << endl;
		}
		else
			cout << 0 << endl;
		for(int i = 0;i < NumVertice;i++)
			map[i].clear();
		scc.clear();
		//cout <<"how many scc:"<<how_many_scc<<endl;
	}
	return 0;
}
