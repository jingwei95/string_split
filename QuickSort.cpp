#include <iostream>

using namespace std;

int mark = 0;

void exchange(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int *array, int p, int r){
	int i = p-1;
	for(int j = p; j < r; j ++){
		if(array[j] < array[r]){		/* comparison of elements of A*/
		 	i ++;
			exchange(&array[i], &array[j]);
		}
	}
	i ++;
	exchange(&array[i], &array[r]);
	return i;
}

void Quicksort(int *array, int p, int r){
	if(p < r){
		int q = Partition(array, p, r);		/* divide */
		if((q == r) || (q == p)){
			mark ++;
		} 
		Quicksort(array, p, q-1);		/* conquer */
		Quicksort(array, q+1, r);		/* conquer */	
	}
}

int main(void){
	int num_test;
	int num_case;
	cin >> num_test;
	for(int i = 0; i < num_test; i ++){	
		cin >> num_case;	
		int array[num_case] = {};
		for(int j = 0; j < num_case; j ++){
			cin >> array[j];
		}
		int tmp = array[num_case - 1];
		Quicksort(array, 0, num_case - 1);
		if(mark >= (num_case - 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		for(int j = 0; j < num_case; j ++){
			cout << array[j] << " ";
		}	
		mark = 0;
	}	
	return 0; 
}
