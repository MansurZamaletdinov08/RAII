#include <iostream>
#include <string>


class smart_array : public std::exception {
	private:
		int* arr = 0;
		int count = 0;
		int size = 0;
public:
	smart_array(const int size1) {
		size = size1;

		arr = new int[size];

		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}
	}


	void add_element(int val) {
		if (count > size) {
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
};


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
