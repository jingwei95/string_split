#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long parent[100000];

struct Edges{
	long long front;
	long long end;
	long long index;
	long long weight;
};

bool myfunc(const Edges &a, const Edges &b)
{
    return a.weight < b.weight;
}

long long find(long long x){
	if(parent[x] == x){
		return x;
	}
	return find(parent[x]);
}

void union_new(long long x, long long y){
    long long fx = find(x);
    long long fy = find(y);
    parent[fx] = fy;
}

int main(void){
	long long num_vertex, num_edge;
	cin >> num_vertex >> num_edge;
	vector <bool> included(num_edge, false);
	for(auto i = 0; i < 100000; i ++){
		parent[i] = i;
	}
	vector <Edges> container(num_edge);

	for(auto i = 0; i < num_edge; i ++){
		cin >> container[i].front >> container[i].end >> container[i].weight;
		container[i].index = i;
	}
	sort(container.begin(), container.end(), myfunc);
	long long counter_edge = 0;
	long long counter2;
	long long front;
	long long end;
	while(counter_edge < num_edge){
		counter2 = counter_edge;
			while(container[counter_edge].weight == container[counter2].weight){
				front = container[counter2].front; 
				end = container[counter2].end;
				if(find(front) != find(end)) {	
					included[container[counter2].index] = true;
				}
				counter2 ++;
			}
		while(counter_edge < counter2){
			front = container[counter_edge].front; 
			end = container[counter_edge].end;
			union_new(front, end);			
			counter_edge ++;
		}
	}
	for(auto i = 0; i < num_edge; i ++){
		if(included[i])
			cout << "at least one" << endl;
		else
			cout << "none" << endl;
	}
	return 0;
}
