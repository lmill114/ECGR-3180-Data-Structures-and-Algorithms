#include <iostream>

template <typename T>
class MyVector {
private:
    T* arr;           // Pointer to the dynamic array
    int capacity;     // Total capacity of the array
    int numElements;  // Number of elements currently in the array

public:
    // Default constructor
    MyVector() : arr(nullptr), capacity(0), numElements(0) {}

    // Constructor with size
    MyVector(int sz) : arr(new T[sz]), capacity(sz), numElements(0) {}

    // Copy constructor
    MyVector(const MyVector& vin) : arr(new T[vin.capacity]), capacity(vin.capacity), numElements(vin.numElements) {
        for (int i = 0; i < numElements; ++i) {
            arr[i] = vin.arr[i];
        }
    }

    // Destructor
    ~MyVector() {
        delete[] arr;
    }

    // Appends an element to the end of the array
    void pushBack(const T& ele) {
        if (numElements == capacity) {
            // Double the capacity if it's full
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[newCapacity];
            for (int i = 0; i < numElements; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[numElements++] = ele;
    }

    // Inserts an element at the i-th position in the array
    void insert(int i, const T& ele) {
        if (i < 0 || i > numElements) {
            std::cout << "Invalid index for insertion." << std::endl;
            return;
        }
        if (numElements == capacity) {
            // Double the capacity if it's full
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[newCapacity];
            for (int j = 0; j < numElements; ++j) {
                newArr[j] = arr[j];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        for (int j = numElements - 1; j >= i; --j) {
            arr[j + 1] = arr[j];
        }
        arr[i] = ele;
        ++numElements;
    }

    // Returns the i-th element
    T at(int i) const {
        if (i < 0 || i >= numElements) {
            std::cout << "Index out of bounds." << std::endl;
            return T();  // Default value for type T
        }
        return arr[i];
    }

    // Overloaded [] operator to access the i-th element
    T operator[](int i) const {
        return at(i);
    }

    // Deletes the i-th element
    void erase(int i) {
        if (i < 0 || i >= numElements) {
            std::cout << "Index out of bounds." << std::endl;
            return;
        }
        for (int j = i; j < numElements - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        --numElements;
    }

    // Returns the number of elements
    int size() const {
        return numElements;
    }

    // Returns true if the vector is empty, else false
    bool empty() const {
        return numElements == 0;
    }
};

int main() {
    // Create an integer vector
    MyVector<int> intVector;
    intVector.pushBack(10);
    intVector.pushBack(20);
    std::cout << "intVector[0]: " << intVector[0] << std::endl;

    // Create a string vector
    MyVector<std::string> stringVector;
    stringVector.pushBack("Hello");
    stringVector.pushBack("World");
    stringVector.pushBack("Chips");
    std::cout << "stringVector[1]: " << stringVector[1] << std::endl;

    // Create a double vector with an initial size
    MyVector<double> doubleVector(3);
    doubleVector.pushBack(3.14);
    doubleVector.pushBack(2.718);
    std::cout << "doubleVector size: " << doubleVector.size() << std::endl;

    // Testing insert, erase, and empty functions
    intVector.insert(1, 15); // Insert 15 at index 1
    intVector.erase(0);      // Erase element at index 0
    std::cout << "intVector[0] after erase: " << intVector[0] << std::endl;

    // Check if the string vector is empty
    std::cout << "Is stringVector empty? " << (stringVector.empty() ? "Yes" : "No") << std::endl;

    // Testing the copy constructor
    MyVector<std::string> copiedStringVector = stringVector; // Create a copy
    copiedStringVector.pushBack("Copied");
    std::cout << "Original stringVector[2]: " << stringVector[2] << std::endl;
    std::cout << "Copied stringVector[2]: " << copiedStringVector[2] << std::endl;
    
    return 0;
}