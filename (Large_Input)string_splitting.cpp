#include <iostream>

using namespace std;

int main(void){
	int num_test;
	cin >> num_test;
	while(num_test > 0){
		int length;
		int m;
		cin >> length >> m;
		char tmp;
		int a;
		int ans = 0;
		int count = 0;
		for(int i = 0; i < length; i ++){
			cin >> tmp;
			a = tmp - '0';
			ans = (((ans%m)*10 + a) % m);
			if(ans == 0){	
				count ++;
				ans = 0;
			}			
		}
		cout << count << endl;
		num_test --;
	}
	return 0;
}
