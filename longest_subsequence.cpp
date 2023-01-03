#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int num_test;
	cin >> num_test;
	while(num_test > 0){
		int array_length;
		cin >> array_length;
		long long array[array_length];
		int result[array_length];
		for(int i = 0; i < array_length; i ++){
			result[i] = 1;
		}
		for(int i = 0; i < array_length; i ++){
			cin >> array[i];
		}
		for(int i = array_length - 1; i >= 0; i --){
			for(int j = i + 1; j < array_length; j ++){
				if(array[i] <= array[j]){
					if(result[j] >= result[i])
						result[i] = (1 + result[j]);
				}
			}
		}
	
		sort(result, result+array_length);
		cout << result[array_length - 1] << endl;
		num_test --;
	}
	return 0;	
}
