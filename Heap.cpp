#include <iostream>
using namespace std;
struct Heap {
	int* arr;
	int max_capacity;
	int current_size;
     Heap(int capacity) {
		this->max_capacity = capacity;
		arr = new int[capacity + 1];
		current_size = 0;
	}
	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	int Parent(int i) {
		return (i - 1) / 2;
	}
	void insert(int value) {
		if (current_size == max_capacity) {
			cout << "Overflow!" << endl;
			return;
		}
		current_size++;
		int i = current_size - 1;
		arr[i] = value;
          // Min
		while (i != 0 && arr[Parent(i)] > arr[i]) {
			swap(arr[Parent(i)], arr[i]);
			i = Parent(i);
		}
         //Max
      while (i != 0 && arr[Parent(i)] < arr[i]) {
			swap(arr[Parent(i)], arr[i]);
			i = Parent(i);
		}

	}
};
int main() {
	Heap hp(19);
	hp.insert(12);
	hp.insert(5);
	hp.insert(1);
	hp.insert(7);
	hp.insert(2);
    cout << "This is Min Heap: " << endl;
	for (int i = 0; i < hp.current_size; i++) {
		cout << hp.arr[i] << " ";
	}
      cout <<endl;
    cout << "This is Max Heap: " << endl;
	for (int i = 0; i > hp.current_size; i++) {
		cout << hp.arr[i] << " ";
	}
	
	return 0;
}