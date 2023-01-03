#include <iostream>
#include <cstdio> 

using namespace std;

int initial[2][2] = {{1,1},{1,0}};

void multiply(int ans[2][2], int initial[2][2]){
	int p1,p2,p3,p4;
	p1 = (ans[0][0] * initial[0][0] + ans[0][1] * initial[1][0]);
	p2 = (ans[0][0] * initial[0][1] + ans[0][1] * initial[1][1]);
	p3 = (ans[1][0] * initial[0][0] + ans[1][1] * initial[1][0]);
	p4 = (ans[1][0] * initial[0][1] + ans[1][1] * initial[1][1]);
	ans[0][0] = p1 % 29989;
	ans[0][1] = p2 % 29989;
	ans[1][0] = p3 % 29989;
	ans[1][1] = p4 % 29989;
}

void square(int ans[2][2], int num){
	if(num < 2)
		return;	
	square(ans, num / 2);	
	multiply(ans, ans);
	if((num % 2) != 0){
		multiply(ans, initial);
	}		
}

int fibo(int num){
	int ans[2][2] = {{1,1},{1,0}};
	if(num == 0)
		return 0;
	square(ans, num-1);
	return ans[0][0];
}

int main(void){
	int num_test;
		cin >> num_test;
		int input_num; 
		for(int i = 0; i < num_test; i ++){
			cin >> input_num;	
			cout << fibo(input_num) << endl;
		}
	return 0;
}
