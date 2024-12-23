/* 
Write a function that returns if a string of paranthesis are matched. 
You are required to use the STL stack datastructure in your code for O(n) time complexity.
See 5.17 in the book for problem description and a stack based algorithm. 
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std; 
  
// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) { 
// Your code here
    stack<char> s; // Create an empty stack to store opening parentheses

    // Iterate through each character in the input string
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            // If an opening parenthesis is encountered, push it onto the stack
            s.push(ch);
        } else {
            // If a closing parenthesis is encountered
            if (s.empty()) {
                // If the stack is empty, there is no matching opening parenthesis
                return false;
            }
            char top = s.top(); // Get the top element from the stack
            s.pop(); // Pop the top element

            // Check if the current closing parenthesis matches the top of the stack
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false; // Mismatched parentheses
            }
        }
    }

    // After processing all characters, if the stack is empty, the parentheses are balanced
    return s.empty();

} 
  
// Test - DO NOT MODIFY
int main() 
{ 
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"}; 
  	
	for(auto expr : parans) {
    	if (areParanthesisBalanced(expr)) 
        	cout << "Balanced" << endl; 
    	else
        	cout << "Not Balanced" << endl;
	} 
    return 0; 
}
