#include <iostream>
#include <vector> 

using namespace std; 

struct Node{
	int coin;
	int num;
	Node * next = NULL;
};

class collectCoin{
	public:
		collectCoin(int num){
			num_coin = num;
			array.resize(num+1);	
		};
		void createNode(int index,int input){
			Node * a = new Node;
			a->coin = input;
			a->num = index;
			array[index] = a;
		};
		Node * createNode2(int index,int input){
			Node * a = new Node;
			a->coin = input;
			a->num = index;
			return a;
		};
		void connectVertex(int front,int back){
			Node * tmp = createNode2(back,array[back]->coin);
			if(array[front]->next != NULL){
				Node * travel = array[front];
				while(travel->next != NULL){
					travel = travel->next;
				}
				travel->next = tmp;
			}
			else
				array[front]->next = tmp;
			tmp = createNode2(front,array[front]->coin);	
			if(array[back]->next != NULL){
				Node * travel = array[back];
				while(travel->next != NULL){
					travel = travel->next;
				}	
				
				travel->next = tmp;
			}
			else
				array[back]->next = tmp;
		};
		void run(){
			vector<bool> visited(num_coin+1,false);
			long long ans = DFS(1,visited);
			cout << ans << endl; 
		}
		long long DFS(int v, vector<bool> visited){
			long long collected = array[v]->coin;
			long long tmp = 0;
		    if(visited[v] == true)
		    	return 0;
		    visited[v] = true;
		    Node * travel = array[v];
		    while(travel->next != NULL){
		    	travel = travel->next;
		        if (!visited[travel->num])
		            tmp = max(tmp,DFS(travel->num, visited));
		    }
		    return (collected + tmp);
		}; 
	private:
		vector<Node *> array;
		int num_coin;
};

int main(void){
	int num_vertex;
	cin >> num_vertex;
	collectCoin wallet(num_vertex);
	int tmp1;
	for(int i = 1; i <= num_vertex; i ++){
		cin >> tmp1;
		wallet.createNode(i,tmp1);
	}
	int tmp2;
	for(int i = 1; i < num_vertex; i ++){
		cin >> tmp1 >> tmp2;
		wallet.connectVertex(tmp1, tmp2);
	}
	wallet.run();
	return 0;
}
