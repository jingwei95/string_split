#include <iostream>
#include <vector>

using namespace std; 

struct Node{
	long long data;
	long long rank = 0;
	Node *parent = NULL;
	long long num_child = 1; 
}; 

class Set{
	public:
		// DEFAULT CONSTRUCTOR
		Set(long long num){
			array.resize(num+1);
			num_ppl = num;
			for(long long i = 1; i <= num; i ++){
				array[i] = makeSet(i);
			}
		};
		// CREATE NEW NODE
		Node * makeSet(long long input){
			Node * a = new Node;
			a->data = input;
			return a;
		};
		// FIND REPRESENTATIVE OF A SET
		Node * findSet(Node * node){
			if(node->parent == NULL)
				return node;
	        node->parent = findSet(node->parent);
	        return node->parent;
		};
		// LINK A & B TO FORM NEW SET
		void union_new(long long a, long long b){
			Node * node1 = array[a];
	        Node * node2 = array[b];
	        Node * parent1 = findSet(node1);
	        Node * parent2 = findSet(node2);
	        if(parent1->data == parent2->data) {
	            return;
	        }
	        if (parent1->rank >= parent2->rank) {
	            if(parent1->rank == parent2->rank) 
			 		parent1->rank ++;
	            parent2->parent = parent1;
	            parent1->num_child += parent2->num_child;
	        } else {
	            parent1->parent = parent2;
	            parent2->num_child += parent1->num_child;
	        }
		};
		// FIND LARGEST FRIEND GROUP
		void print_ans(){
			long long ans = 0;
			for(long long i = 1; i <= num_ppl; i ++){
				if(array[i]->num_child > ans)
					ans = array[i]->num_child;
			}
			cout << ans << endl;
		}
	private:
		vector <Node *> array;
		long long num_ppl;
};

int main(void){
	long long num_ppl; // num of people
	long long fren_pair;
	cin >> num_ppl >> fren_pair;
	Set a(num_ppl);
	long long front;
	long long back;
	for(long long i = 0; i < fren_pair; i ++){
		cin >> front >> back;
		a.union_new(front, back);
	}
	a.print_ans();
	return 0;
}
