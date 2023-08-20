#include <iostream>


class smart_array : public std::exception {
private:
	int* arr = 0;
	int count = 0;
	int size = 0;
public:
	//smart_array(const smart_array&) = delete;
	//smart_array& operator=(const smart_array&) = delete;

	smart_array(const int size1) {
		size = size1;

		arr = new int[size];
	}


	void add_element(int val) {
		if (count >= size) {
			throw std::runtime_error("the number of elements is greater than the number of elements for which memory is allocated.");
		}
		else {
			arr[count] = val;
			++count;
		}
	}


	int get_element(int index) {
		if ((index >= size) || (index < 0)) {
			throw exception("Error getting an element by index! index out of range");
		}
		else {
			return arr[index];
		}
	}


	~smart_array() {
		delete[] arr;
	}


	smart_array(const smart_array& NewArr) {
		this->size = NewArr.size;
		arr = new int[NewArr.size];

		for (int i = 0; i < NewArr.size; i++) {
			this->arr[i] = NewArr.arr[i];
		}
		
		for (int i = 0; i < NewArr.size; i++) {
			this->count = count;
		}
	};

	smart_array& operator=(const smart_array& NewArr) {
		if (this != &NewArr) {
			this->size = NewArr.size;
			delete[] arr;

			arr = new int[NewArr.size];

			for (int i = 0; i < NewArr.size; i++) {
				this->arr[i] = NewArr.arr[i];
			}

			for (int i = 0; i < NewArr.size; i++) {
				this->count = count;
			}

			return *this;
		}
		return *this;
	}
};


int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

	arr = new_array;
}