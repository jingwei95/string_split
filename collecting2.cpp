#include <iostream>

using namespace std;

struct map_new{
	int num2 = 0;
	int num5 = 0;
}; 

int count2(long long num){
	int count = 0;
	while((num % 2) == 0){
		count ++;
		num /= 2;
	} 
	return count;
}

int count5(long long num){
	int count = 0;
	while((num % 5) == 0){
		count ++;
		num /= 5;
	} 
	return count;
}

int main(void){
	int area;
	cin >> area;
	int map[area + 1][area + 1];
	map_new record[area + 1][area + 1];
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
			record[i][j].num2 = count2(map[i][j]);
			record[i][j].num5 = count5(map[i][j]);
		}
	}
	for(int i = 1; i <= area; i ++){
		for(int j = 1; j <= area; j ++){
			if((i - 1) == 0){
				record[i][j].num2 += record[i][j-1].num2;
				record[i][j].num5 += record[i][j-1].num5;
			}
			else if((j - 1) == 0){
				record[i][j].num2 += record[i-1][j].num2;
				record[i][j].num5 += record[i-1][j].num5;
			}
			else if(((i - 1) == 0) && ((j - 1) == 0))
				continue;
			else{
				record[i][j].num2 += min(record[i-1][j].num2, record[i][j-1].num2);
				record[i][j].num5 += min(record[i-1][j].num5, record[i][j-1].num5);
			}
		}
	}
	
		
	
	cout << min(record[area][area].num2, record[area][area].num5);
	return 0;
}
