/*
 * Program: Regular Expression Validator
 * Author: tecnicoviola
 * Date: 2025-06-10 15:20:24 UTC
 * Description: Validates whether a given string is a valid regular expression
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class RegexValidator {
private:
    // Helper function to trim whitespace
    string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        size_t last = str.find_last_not_of(" \t\n\r");
        return (first != string::npos) ? str.substr(first, last - first + 1) : str;
    }

public:
    bool validate_regex(const string& pattern) {
        try {
            // Attempt to construct regex from pattern
            regex r(pattern);
            return true;
        } catch(const regex_error&) {
            return false;
        }
    }
    
    void process_test_cases() {
        int t;
        cout << "Enter number of test cases: ";
        cin >> t;
        
        if(t <= 0) {
            throw runtime_error("Number of test cases must be positive");
        }
        
        cin.ignore(); // Clear the newline
        
        cout << "Enter regex patterns (one per line):" << endl;
        for(int i = 0; i < t; i++) {
            string pattern;
            getline(cin, pattern);
            
            pattern = trim(pattern);
            bool is_valid = validate_regex(pattern);
            
            cout << (is_valid ? "True" : "False") << endl;
        }
    }
};

int main() {
    try {
        RegexValidator validator;
        validator.process_test_cases();
        return 0;
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}