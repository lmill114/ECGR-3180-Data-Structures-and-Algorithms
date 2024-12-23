// From Goodrich, Tamassia, and Mount 
// Homework

/*
 Write a short C++ program that takes two arguments of type STL vec-
tor<double>, a and b, and returns the element-by-element product of a
and b. That is, it returns a vector c of the same length such that c[i] =
a[i] · b[i].
*/
#include <iostream>
#include <vector>


std::vector<double> vecProduct(const std::vector<double>& v1, const std::vector<double>& v2) {
	// Return empty vector if v1 and v2 are of different sizes;
	std::vector<double> c;				//Declare product vector
	int sizeV1 = v1.size();				//To make comparing size of the vectors easier
	int sizeV2 = v2.size();
	double temp = 0.0;					//Placeholder for push_back function

	if (sizeV1 != sizeV2){				//Returns empty vector if vector sizes are unequal
		return c;
	}
	

	for (int j = 0; j < sizeV1; j++){	//Multiplies each element together and adds it to vector c
		temp = v1.at(j) * v2.at(j);
		c.push_back(temp);
	}
	
	return c;
}

// Overload << operator to print std::vector
std::ostream& operator <<(std::ostream& os, const std::vector<double>& v) {
	for (int i = 0; i < v.size(); i++) {
		os << v.at(i) << " ";
	}
	os << std::endl;
	return os;
}

// Test 
int main() {
	// Test 1
	std::vector<double> v1{1.0, 2.0, 3.0};
	std::vector<double> v2{4.0, 5.0, 6.0};
	std::vector<double> v3 = vecProduct(v1, v2);
	std::cout << v3; // Should print 4, 10, 18

	// Test 2
	std::vector<double> v4{42.0};
	std::cout << vecProduct(v1, v4); // Should print empty vector

}