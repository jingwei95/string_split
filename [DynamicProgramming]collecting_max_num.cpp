#include <iostream>

using namespace std;

int max(int a, int b){
	if(a >= b)
		return a;
	else
		return b;
}

int main(void){
	int area;
	cin >> area;
	int map[area + 1][area + 1];
	for(int i = 0; i < 1; i ++){
		for(int j = 0; j <= area; j ++){
			map[i][j] = 0;
		}
	}
	
	for(int i = 0; i <= area; i ++){
		for(int j = 0; j < 1; j ++){
			map[i][j] = 0;
		}
	}
	for(int i = 1; i <= area; i ++){
		for(int j = 1; j <= area; j ++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 1; i <= area; i ++){
		for(int j = 1; j <= area; j ++){
			map[i][j] += max(map[i-1][j], map[i][j-1]);
		}
	}
	cout << map[area][area];
	return 0;
}
