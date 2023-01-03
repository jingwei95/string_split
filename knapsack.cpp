// 以背包問題為例，我們使用兩個陣列value與item，value表示目前的最佳解所得之總價，item表示最後一個放至背包的水果，假設有負重量 1～8的背包8個，並對每個背包求其最佳解
#include <stdio.h> 
#include <stdlib.h> 

#define LIMIT 8   // 重量限制 

typedef struct { 
    char name[20]; 
    int weight; 
    int price; 
} Fruit; 

void knapsack(Fruit*, int*, int*, int, int);
int min(Fruit*, int);


int main(void) { 
    Fruit fruits[] = {{"李子", 4, 4500}, 
                      {"蘋果", 5, 5700}, 
                      {"橘子", 2, 2250}, 
                      {"草莓", 1, 1100}, 
                      {"甜瓜", 6, 6700}};
    int items[LIMIT + 1] = {0}; 
    int values[LIMIT + 1] = {0};  
    
    int length = sizeof(fruits) / sizeof(fruits[0]);
    knapsack(fruits, values, items, length, LIMIT);

    printf("物品\t價格\n"); 
    int i;
    for(i = LIMIT; i >= min(fruits, length); i -= fruits[items[i]].weight) {
        printf("%s\t%d\n", fruits[items[i]].name, fruits[items[i]].price); 
    } 
    printf("合計\t%d\n", values[LIMIT]); 

    return 0; 
}  

void knapsack(Fruit* fruits, int* values, int* items, 
              int length, int limit) {
    int i, w;
    for(i = 0; i < length; i++) { 
        for(w = fruits[i].weight; w <= limit; w++) {
            int p = w - fruits[i].weight;
            int newValue = values[p] + fruits[i].price; 
            if(newValue > values[w]) {   // 找到階段最佳解 
                values[w] = newValue; 
                items[w] = i; 
            }
        } 
    }
}

int min(Fruit* fruits, int length) {
    int i, m;
    for(i = 0, m = fruits[0].weight; i < length; i++) {
        if(fruits[i].weight < m) {
            m = fruits[i].weight;
        }
    }
    return m;
} 