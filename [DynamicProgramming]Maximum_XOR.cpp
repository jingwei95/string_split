#include <iostream>

using namespace std;

int main(void){
	int num_test;
	int grp;
	cin >> num_test;
	while(num_test > 0){
		cin >> grp;
		bool array[grp][1024];
		long long tmp[grp][3];
		for(int i = 0; i < grp; i ++){
			for(int j = 0; j < 1024; j ++){
				array[i][j] = false;
			}
		}
		for(int i = 0; i < grp; i ++){
			for(int j = 0; j < 3; j ++){
				cin >> tmp[i][j];
				if(i == 0)
					array[0][tmp[i][j]] = true;
			}
		}
	
		for(int i = 1; i < grp; i ++){ 
			for(int j = 0; j < 3; j ++)
				for(int k = 0; k < 1024; k ++){
					if(array[i-1][k] == true)
						array[i][(tmp[i][j]^k)] = true;	
				}		
		}
		for(int i = 1023; i >= 0; i --){
			if(array[grp-1][i] == true){
				cout << i << endl;
				break;
			}
		}
		num_test --;
	}
	return 0;
} 

