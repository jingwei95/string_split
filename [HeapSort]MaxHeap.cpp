#include <iostream>
#include <vector>

using namespace std;

void exchange(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void maxHeapify(vector<int> &A, int i, int len){
      int l = (i*2);	// root 's left child 
      int r = (i*2 + 1); // root's right child
      int largest = i;
      if((l <= len) && (A[l] > A[i]))
           largest = l;
      if((r <= len) && (A[r] > A[largest]))
           largest = r;
      if(largest != i){
           exchange(A[i], A[largest]);
           maxHeapify(A, largest, len);
      }
      
}

void buildMaxHeap(vector<int> &A){
      for(int i = ((int)(A.size())/2); i >=1; i--){
      	  maxHeapify(A, i, (int)A.size());
	  }
}


void HeapSort(vector<int> &A){
      buildMaxHeap(A);
      for(int i = 1; i <= A.size(); i ++){
		cout << A[i] << " ";
	  }	
	  cout << endl;
      int heapSize = (int)A.size();
      for(int i = A.size(); i >= 2; i --){
           exchange(A[1], A[i]);
           heapSize --;
           maxHeapify(A, 1, heapSize);
      }
}

int main(void){
	int size_array;
	cin >> size_array;
	vector<int> array;
	array.resize(size_array);
	for(int i = 1; i <= size_array; i ++){
		cin >> array[i];
	}
	HeapSort(array);
	for(int i = 1; i <= size_array; i ++){
		cout << array[i] << " ";
	}	
	cout << endl;
	return 0; 
}
