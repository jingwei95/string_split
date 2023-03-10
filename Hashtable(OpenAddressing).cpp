/*範例程式碼簡單地以Quadratic Probing(c1=c2=0.5c1=c2=0.5，m=2Pm=2P)實作出Open Addressing的Hash Table。
關於Rehashing、調整Table大小的議題與Hash Table：Chaining的方法大同小異，不過load factor可能要限制得更嚴謹(請看下一小節的挑論)，這裡就不再贅述。*/

// C++ code
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct dict{
    int key;
    string value;
    dict():key(0),value(""){};
    dict(int k, string s):key(k),value(s){};
};

class HashOpenAddress{
private:
    int size, count;
    dict *table;

    int QuadraticProbing(int key, int i);

    // TableDoubling()
    // TableShrinking()
    // Rehashing()

public:
    HashOpenAddress():size(0),count(0),table(0){};
    HashOpenAddress(int m):size(m),count(0){
        table = new dict[size];
    }
    void Insert(int key, string value);
    void Delete(int key);
    string Search(int key);
    void Display();
};

string HashOpenAddress::Search(int key){

    int i = 0;
    while (i != size) {
        int j = QuadraticProbing(key, i);
        if (table[j].key == key) {
            return table[j].value;
        }
        else {
            i++;
        }
    }
    return "...data not found\n";
}

void HashOpenAddress::Delete(int key){

    int i = 0;
    while (i != size) {
        int j = QuadraticProbing(key, i);
        if (table[j].key == key) {
            table[j].key = 0;
            table[j].value = "";
            count--;
            return;
        }
        else {
            i++;
        }
    }
    cout << "...data not found\n";
}

void HashOpenAddress::Insert(int key, string value){

    int i = 0;
    while (i != size) {
        int j = QuadraticProbing(key, i);
        if (table[j].value == "") {
            table[j].key = key;
            table[j].value = value;
            count++;
            return;
        }
        else {
            i++;
        }
    }
    cout << "Hash Table Overflow\n";
}

int HashOpenAddress::QuadraticProbing(int key, int i){
    // c1 = c2 = 0.5
    return ((int)( (key % size) + 0.5*i + 0.5*i*i ) % size);
}

void HashOpenAddress::Display(){

    for (int i = 0; i < size; i++) {
        cout << "slot#" << i << ": (" << table[i].key
             << "," << table[i].value << ")" << endl;
    }
    cout << endl;
}
int main(){

    HashOpenAddress hash(8);          // probing sequence:
    hash.Insert(33, "blue");          // 1,2,4,7,3,0,6,5 -> 1
    hash.Insert(10, "yellow");        // 2,3,5,0,4,1,7,6 -> 2
    hash.Insert(77, "red");           // 5,6,0,3,7,4,2,1 -> 5
    hash.Insert(2, "white");          // 2,3,5,0,4,1,7,6 -> 3
    hash.Display();
    hash.Insert(8, "black");          // 0,1,3,6,2,7,5,4 -> 0
    hash.Insert(47, "gray");          // 7,0,2,5,1,6,4,3 -> 7
    hash.Insert(90, "purple");        // 2,3,5,0,4,1,7,6 -> 4
    hash.Insert(1, "deep purple");    // 4,5,7,2,6,3,1,0 -> 6
    hash.Display();
    hash.Insert(15, "green");         // hash table overflow

    cout << "number#90 is " << hash.Search(90) << "\n\n";

    hash.Delete(90);
    cout << "after deleting (90,purple):\n";
    cout << "number#90 is " << hash.Search(90) << "\n";

    hash.Insert(12, "orange");        // 4,5,7,2,6,3,1,0 -> 4
    hash.Display();

    return 0;
}