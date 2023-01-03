#include <iostream>
#include <algorithm>

using namespace std;

struct Container{
	int rank;
	char suit;
};

bool check(Container a, Container b){
	if(a.rank == b.rank)
		return true;
	else if(a.suit == b.suit)
		return true;
	else if ((a.rank == 8) || (b.rank == 8))
		return true;
	else
		return false;
}

int main(void){
	int num_test;
	cin >> num_test;
	while(num_test > 0){
		int num_card;
		cin >> num_card;
		Container memo[num_card];
		int result[num_card];
		for(int i = 0; i < num_card; i ++){
			result[i] = 1;
		}
		int input_num;
		char input_char;
		for(int i = 0; i < num_card; i ++){
			cin >> memo[i].rank  >> memo[i].suit;
		}
		for(int i = num_card - 1; i >= 0; i --){
			for(int j = i + 1; j < num_card; j ++){
				if(check(memo[i], memo[j])){
					if(result[j] >= result[i]) 
						result[i] = (1 + result[j]);
					else
						continue;
				}
			}
		}
		
		for(int i = 0; i < num_card; i ++){
			cout << result[i] << " ";
		} 
		sort(result, result+num_card);
		cout << endl;
		cout << result[num_card - 1] << endl;
		num_test --;
	}
	return 0;	
}
