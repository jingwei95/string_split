#include <iostream>
#include <vector>
#define z 1000000

using namespace std;

/***********************
	COUNTING SORT
***********************/

int main(void){
	int num_test;
	long long int n;
	long long int k, p, q, r;
	cin >> num_test;
	for(int i = 0; i < num_test; i ++){
		cin >> n >> k >> p >> q >> r;
	
	    vector<int> count(z), array(n+1), place(n+1);
	    
		for(int j = 0; j <= z; j ++){
			count[j] = 0;
		} 
		for(int j = 1; j <= n; j ++){
			array[j] = (((((((((p)%z*j)%z)%z*j)%z)%z + ((q%z)*j)%z)%z)%z + r)%z);		
			count[array[j]] ++;
		}
		int tmp = 0;
		for(int j = 1; j < z; j ++){
			count[j] = count[j] + count[j-1];
			if(count[j] >= k){
				cout << j << endl;
				break;
			}
		}
	}
	
	return 0;
}
