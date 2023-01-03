#include <iostream>

using namespace std;

struct Node{
	long long data;
	Node *left = NULL;
	Node *right = NULL;
};

Node * createNode(long long data_input){
	Node * a = new Node;
	a->data = data_input;
	return a;
}

Node * insert(Node * a, long long data_input){
	if(a == NULL){
		a = createNode(data_input);
	}
	else if(data_input >= a->data){
		a->right = insert(a->right,data_input);
	}
	else
		a->left = insert(a->left,data_input);
	return a;
}

void search(Node * a, long long data_search){
	Node * travel = a;
	while(1){
		if(travel->data == data_search)
			break;
		else if(data_search >= travel->data){
			cout << 'R';
			travel = travel->right;
		}
		else{
			cout << 'L';
			travel = travel->left;
		}
	}
	return;
}

int main(void){
	long long target;
	while(1){
		long long num_node = 0;
		cin >> num_node;
		if(num_node == 0)
			break;
		cin >> target;
		Node * head = NULL;
		long long tmp;
		for(int i = 0; i < num_node; i ++){
			cin >> tmp;
			head = insert(head,tmp);
		}
		search(head,target);
		cout << endl;
	}
	return 0;
}
