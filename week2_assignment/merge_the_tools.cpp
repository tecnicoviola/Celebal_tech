/*
 * Program: Merge the Tools
 * Author: tecnicoviola
 * Date: 2025-06-10 14:33:45 UTC
 * Description: Splits string into equal parts and removes subsequent duplicates in each part
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class StringMerger {
private:
    string input_string;
    int k;
    
    // Helper function to process a single substring
    string process_substring(const string& s) {
        string result;
        unordered_set<char> seen;
        
        for(char c : s) {
            if(seen.find(c) == seen.end()) {
                result += c;
                seen.insert(c);
            }
        }
        
        return result;
    }
    
    // Validate input parameters
    void validate_input() {
        if(input_string.empty()) {
            throw runtime_error("Input string cannot be empty");
        }
        
        if(k <= 0) {
            throw runtime_error("K must be positive");
        }
        
        if(input_string.length() % k != 0) {
            throw runtime_error("String length must be divisible by k");
        }
    }

public:
    StringMerger(const string& s, int split_length) 
        : input_string(s), k(split_length) {
        validate_input();
    }
    
    // Process and print the results
    void merge_and_print() {
        int n = input_string.length();
        int substring_length = n / k;
        
        // Process each substring
        for(int i = 0; i < n; i += k) {
            string substring = input_string.substr(i, k);
            string processed = process_substring(substring);
            cout << processed << endl;
        }
    }
};

int main() {
    try {
        string s;
        int k;
        
        // Get input string
        cout << "Enter the string: ";
        getline(cin, s);
        
        // Get k value
        cout << "Enter k (length of substrings): ";
        cin >> k;
        
        // Create StringMerger object and process
        StringMerger merger(s, k);
        merger.merge_and_print();
        
        return 0;
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}