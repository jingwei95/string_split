#include <iostream>

using namespace std;

long long int hashFunc(long long int input){
   long long int hash = ((123*input + 456)%144961)%100000;
   return abs(hash);
}

struct Node{
	int exist = 0;
	long long int value = 0;
	Node *next = NULL;
};

class HashTable{
	public:
		HashTable(){
			for(int i = 0; i < 100000; i ++){
				array[i] = new Node;
			}
		};
		
		int find(long long int key_input){
			long long int index = hashFunc(key_input);
			Node *travel = array[index];
			while(travel != NULL){
				if((travel->exist > 0) && (travel->value == key_input)){
					return (travel->exist);
				}
				else if(travel->next != NULL)
					travel = travel->next;
				else
					break;
			}
			return 0;
		};
		void add(long long int key_input){
			int mark = 1;
			long long int index = hashFunc(key_input);
			if((array[index]->exist > 0) && (array[index]->value != key_input)){
				Node *space = new Node;
				space->value = key_input;
				space->exist ++;
				Node *travel = array[index];
				while(travel->next != NULL){
					travel = travel->next;
					if(travel->value == key_input){
						travel->exist ++;
						mark = 0;
						break;
					}
				}
				if(mark == 1)
					travel->next = space;
			}
			else if((array[index]->exist > 0) && (array[index]->value == key_input))
				array[index]->exist ++;
			else{
				array[index]->exist ++;
				array[index]->value = key_input;
			}
		}
	private:
		Node *array[100000];
};

int main(void){
	int num_test;
	long long int length_array;
	long long int desired_sum;
	long long int tmp;
	cin >> num_test;
	while(num_test > 0){
		long long int count = 0;
		cin >> length_array >> desired_sum;
		HashTable hasht; 
	
		for(int i = 0; i < length_array; i ++){
			cin >> tmp;
			count += hasht.find(desired_sum - tmp);
			hasht.add(tmp);		
		}
		cout << count << endl;
		num_test --;
	}
	return 0;
}
