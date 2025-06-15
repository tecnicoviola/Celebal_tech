/*
 * Program: Alphabet Rangoli Pattern
 * Author: tecnicoviola
 * Date: 2025-06-10 14:32:18 UTC
 * Description: Prints a rangoli pattern using alphabets based on given size
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class RangoliPattern {
private:
    int size;
    
    // Helper function to create a single line of the pattern
    string create_line(int line_number) {
        string result;
        
        // Calculate the alphabets needed for this line
        int alpha_count = 2 * abs(size - 1 - line_number) + 1;
        char start_char = 'a' + size - 1;
        
        // Add characters from start to middle
        for(int i = 0; i < alpha_count/2; i++) {
            result += start_char - i;
            result += "-";
        }
        
        // Add middle character
        result += (start_char - alpha_count/2);
        
        // Add characters from middle to end
        for(int i = alpha_count/2 - 1; i >= 0; i--) {
            result += "-";
            result += start_char - i;
        }
        
        return result;
    }
    
    // Calculate the width of the pattern
    int calculate_width() {
        return 4 * size - 3;
    }

public:
    RangoliPattern(int n) : size(n) {
        if(n < 1 || n > 26) {
            throw runtime_error("Size must be between 1 and 26");
        }
    }
    
    // Print the complete rangoli pattern
    void print() {
        int width = calculate_width();
        vector<string> lines;
        
        // Generate all lines
        for(int i = 0; i < size; i++) {
            string line = create_line(i);
            lines.push_back(line);
        }
        
        // Print upper half
        for(int i = size-1; i > 0; i--) {
            cout << setw((width - lines[i].length())/2 + lines[i].length()) 
                 << lines[i] << endl;
        }
        
        // Print middle line
        cout << lines[0] << endl;
        
        // Print lower half
        for(int i = 1; i < size; i++) {
            cout << setw((width - lines[i].length())/2 + lines[i].length()) 
                 << lines[i] << endl;
        }
    }
};

int main() {
    try {
        int n;
        cout << "Enter the size (1-26): ";
        cin >> n;
        
        RangoliPattern rangoli(n);
        rangoli.print();
        
        return 0;
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}