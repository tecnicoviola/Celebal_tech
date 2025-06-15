/*
 * Program: Set Operations Implementation
 * Author: tecnicoviola
 * Date: 2025-06-10 15:21:46 UTC
 * Description: Implements set operations: discard, remove, and pop
 */

#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class SetOperations {
private:
    set<int> numbers;

public:
    // Add numbers to set
    void add_numbers() {
        int n;
        cout << "Enter size of set: ";
        cin >> n;
        
        if(n <= 0) {
            throw runtime_error("Set size must be positive");
        }
        
        cout << "Enter space-separated numbers: ";
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            numbers.insert(num);
        }
    }
    
    // Execute commands on the set
    void execute_command(const string& command) {
        stringstream ss(command);
        string operation;
        ss >> operation;
        
        if(operation == "pop") {
            if(!numbers.empty()) {
                numbers.erase(numbers.begin());
            }
        }
        else if(operation == "remove") {
            int element;
            ss >> element;
            numbers.erase(element);
        }
        else if(operation == "discard") {
            int element;
            ss >> element;
            numbers.erase(element);
        }
    }
    
    // Get sum of remaining elements
    int get_sum() const {
        int sum = 0;
        for(int num : numbers) {
            sum += num;
        }
        return sum;
    }
    
    // Print current set
    void print_set() const {
        cout << "Current set: ";
        for(int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        SetOperations set_ops;
        set_ops.add_numbers();
        
        int m;
        cout << "Enter number of commands: ";
        cin >> m;
        
        if(m <= 0) {
            throw runtime_error("Number of commands must be positive");
        }
        
        cin.ignore(); // Clear the newline
        
        cout << "Enter commands (one per line):" << endl;
        for(int i = 0; i < m; i++) {
            string command;
            getline(cin, command);
            set_ops.execute_command(command);
        }
        
        cout << set_ops.get_sum() << endl;
        
        return 0;
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}