
#include <iostream>
using namespace std;
struct Item {
    int key;
    string value;
    Item(int _key, string _value): key(_key), value(_value) {}
    Item(): key(0), value("") {}
};
class HashTable {
private:
    int size;
    Item* table;
    int hashFunction(int key) {
        return key % size;
    }
public:
    HashTable(int tableSize) : size(tableSize) {
        table = new Item[tableSize];
    }
    ~HashTable() {
        delete[] table;
    }
    void insert(int key, string value) {
        int index = hashFunction(key);
        if (hashFunction(table[index].key) == index) {
            while (table[index].key != 0) {
                index++;
            }
            if (index > size) {
                cout << "Table is full" << endl;
                return;
            }
            table[index] = Item(key, value);
        }
        table[index] = Item(key, value);
    }
    void deleteByKey(int key) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (table[i].key == key) {
                index = i;
                break;
            }
        }
        if (index >= 0) {
            Item* newTable = new Item[size - 1];
            for (int i = 0; i < index; i++) {
                newTable[i] = table[i];
            }
            for (int i = index + 1; i < size; i++) {
                newTable[i - 1] = table[i];
            }
            delete[] table;
            table = newTable;
            size--;
        }
        
    }
    string findByKey(int key) {
        bool isFound = false;
        for (int i = 0; i < size; i++) {
            if (table[i].key == key) {
                isFound = true;
                return table[i].value;
            }
        }
        if (!isFound) {
            return "Item was not found";
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << table[i].value << endl;
        }
    }
};
int main()
{
    HashTable table(6);
    table.insert(6, "1");
    table.insert(7, "2");
    table.insert(8, "3");
    table.insert(9, "4");
    table.insert(10, "5");
    table.insert(16, "10");
    table.deleteByKey(16);
    cout << table.findByKey(16) << endl;
    cout << "Value of the item: " << table.findByKey(10) << endl;
    table.print();
}


