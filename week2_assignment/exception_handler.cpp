/*
 * Program: Exception Handler
 * Author: tecnicoviola
 * Date: 2025-06-10 15:18:52 UTC
 * Description: Implements division with exception handling
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

class Calculator {
private:
    // Helper function to validate if string contains only digits
    bool is_numeric(const string& str) {
        for(char c : str) {
            if(!isdigit(c) && c != '-') {
                return false;
            }
        }
        return true;
    }

public:
    // Main function to perform division with exception handling
    void divide(const string& a_str, const string& b_str) {
        try {
            // Check if inputs are numeric
            if(!is_numeric(a_str) || !is_numeric(b_str)) {
                throw invalid_argument("Invalid input");
            }
            
            // Convert strings to integers
            int a = stoi(a_str);
            int b = stoi(b_str);
            
            // Check for division by zero
            if(b == 0) {
                throw runtime_error("Division by zero");
            }
            
            // Perform division and print result
            cout << a / b << endl;
            
        } catch(const invalid_argument&) {
            cout << "Error Code: invalid input" << endl;
        } catch(const runtime_error&) {
            cout << "Error Code: division by zero" << endl;
        } catch(...) {
            cout << "Error Code: unknown error" << endl;
        }
    }
};

int main() {
    int t;
    Calculator calc;
    
    try {
        cout << "Enter number of test cases: ";
        cin >> t;
        
        if(t <= 0) {
            throw runtime_error("Number of test cases must be positive");
        }
        
        cin.ignore(); // Clear the newline
        
        cout << "Enter pairs of numbers (one pair per line):" << endl;
        for(int i = 0; i < t; i++) {
            string line;
            getline(cin, line);
            
            // Parse input line
            stringstream ss(line);
            string a, b;
            ss >> a >> b;
            
            calc.divide(a, b);
        }
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}