#include <iostream>
#include <algorithm>

using namespace std;

// New struct for all attributes
struct Job{
	int id;
	int job;
	int fines;
	double ratio_fine;
};

// Mod- QuickSort for float
bool myfunction (Job a,Job b){
	return (a.ratio_fine < b.ratio_fine); 
}

int main(void){
	int num_test;
	cin >> num_test;
	int num_job;
	while(num_test > 0){
		// Start - Reading data
		cin >> num_job;
		Job ratio[num_job];
		for(int i = 0; i < num_job; i ++){
			cin >> ratio[i].job;
		}
		for(int i = 0; i < num_job; i ++){
			cin >> ratio[i].fines;
		}
		// End - Reading Data
		
		// Count ratio of T/S
		for(int i = 0; i < num_job; i ++){
			ratio[i].ratio_fine = ((double) ratio[i].job/ ratio[i].fines);
			ratio[i].id = (i + 1);
		}
		sort(&ratio[0],ratio + num_job,myfunction); // Sort ratio of T/S
		
		// Add total days required for each job
		long long num_days = 0; // Day count which increase everyday
		for(int i = 0; i < num_job; i ++){
			num_days += ratio[i].job;
			ratio[i].job = num_days - ratio[i].job;
		}
		
		// Count total MIN fines 
		long long total_fines = 0;
		for(int i = 1; i < num_job; i ++){
			total_fines += (long long)ratio[i].fines * ratio[i].job;
		}
		cout << total_fines << endl;
		
		// Print schedule of jobs
		for(int i = 0; i < num_job; i ++){
			cout << ratio[i].id << " ";
		}
		cout << endl;
		num_test --;
	}
	return 0;
}
