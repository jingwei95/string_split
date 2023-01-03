#include <iostream>
 

using namespace std;

int main(void){
	int num_test;
	long long int p, q, r;
	long long int x, y, z;
	long long int size;
	long long int tmp;
	cin >> num_test;
	for(int i = 0; i < num_test; i ++){
		cin >> p >> q >> r;
		cin >> x >> y >> z;
		cin >> tmp;
		const int size = tmp;
		long long int min = 0, max = size;
		long long int cut1, cut2;
		while(min <= max){
			cut1 = (max+min)/2, cut2 = (size - cut1);
			if(((cut1*cut1*p + q*cut1 + r) < ((cut2-1)*(cut2-1)*x + y*(cut2-1) + z)) && (cut1 < size))
				min = cut1 + 1;
			else if((((cut1-1)*(cut1-1)*p + q*(cut1-1) + r) > (cut2*cut2*x + y*cut2 + z)) && (cut1 > 0))
				max = cut1 - 1;
			else{
				if(cut1 == 0)
					cout << ((cut2-1)*(cut2-1)*x + y*(cut2-1) + z) << endl;
				else if(cut2 == 0)
					cout << ((cut1-1)*(cut1-1)*p + q*(cut1-1) + r) << endl;
				else
					if(((cut1-1)*(cut1-1)*p + q*(cut1-1) + r) > ((cut2-1)*(cut2-1)*x + y*(cut2-1) + z))
						cout << ((cut1-1)*(cut1-1)*p + q*(cut1-1) + r) << endl;
					else
						cout << ((cut2-1)*(cut2-1)*x + y*(cut2-1) + z) << endl;
				break;
			}
		}
	}
	return 0;
}
