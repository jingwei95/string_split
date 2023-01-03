#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

class SCC{
	public:
		SCC(int num);
		void DFS(int i);
		void tarjan();
		void insert(int front, int end);
		void print();
		void scan();
	private:
		vector <int> adj[10000];
		int visit[10000];
		vector <int> low;
		int t = 0;
		stack <int> mystack;
		vector <bool> instack;        
		vector <int> contract;   
		vector <int> record;
		int n;
};

SCC::SCC(int num){
	low.resize(num);
	instack.resize(num);
	contract.resize(num);
	n = num;
}    
 
void SCC::DFS(int i){
    visit[i] = low[i] = ++t;
    mystack.push(i);
    instack[i] = true;
    for(auto z = 0; z < adj[i].size(); z ++){
        int j = adj[i][z];
        if(!visit[j])
        	DFS(j);      
        if(instack[j])
        	low[i] = min(low[i], low[j]);
    }
 
    
    if (visit[i] == low[i]){	
        int j;
        do{
        	j = mystack.top();
        	mystack.pop();
        	instack[j] = false;
            contract[j] = i;
        }while (j != i);
        record.push_back(i);
    }
}
 
void SCC::tarjan(){
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < n; i ++){
    	if(!visit[i])
        	DFS(i);
    }
}

void SCC::insert(int front, int end)
{
    adj[front].push_back(end);
}

void SCC::scan(){
	vector <bool> record_inside(record.size(), false);
	for(auto i = 0; i < n; i ++){
		for(auto j = 0; j < adj[i].size(); j ++){
			for(auto k = 0; k < record.size(); k ++){
				if(record[k] == contract[adj[i][j]] && contract[i] != record[k]){
					record_inside[k] = true;
				}
			}
		}
	}
	int represenation;
	int count = 0;
	for(auto i = 0; i < record.size(); i ++){
		if(!record_inside[i]){
			represenation = record[i];
			count ++;
		}
	}
	int ans = 0;
	if(count == 1){
		for(auto i = 0; i < n; i ++){
			if(contract[i] == represenation)
				ans ++;
		}
		cout << ans << endl;
	}
	else
		cout << 0 << endl;
}

int main(void){
	int num_test; 
	int num_verticle;
	int num_edge;
	int front;
	int end;
	cin >> num_test; 
	while(num_test > 0){
		cin >> num_verticle >> num_edge;
		SCC graph(num_verticle); 
		for(auto i = 0; i < num_edge; i ++){
			cin >> front >> end;
			graph.insert((front-1), (end-1));
		}
		graph.tarjan();
		graph.scan();
		num_test --;
	}
	return 0;
}
