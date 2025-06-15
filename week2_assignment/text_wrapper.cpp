/*
 * Program: Text Wrapper
 * Author: tecnicoviola
 * Date: 2025-06-10 14:30:52 UTC
 * Description: Wraps text into paragraphs of specified width
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Wraps text into paragraphs of specified width
 * @param str Input string to be wrapped
 * @param width Maximum width of each line
 * @return String with line breaks at specified width
 */
string wrap_text(string str, int width) {
    if (width <= 0) {
        throw runtime_error("Width must be positive");
    }
    
    stringstream wrapped;
    size_t current_pos = 0;
    
    while (current_pos < str.length()) {
        // Extract substring of specified width
        string segment = str.substr(current_pos, width);
        
        // Add the segment to result
        wrapped << segment;
        
        // Add newline if not at the end of string
        if (current_pos + width < str.length()) {
            wrapped << "\n";
        }
        
        // Move to next segment
        current_pos += width;
    }
    
    return wrapped.str();
}

int main() {
    try {
        string text;
        int width;
        
        // Read input string
        cout << "Enter the string: ";
        getline(cin, text);
        
        // Read width
        cout << "Enter the width: ";
        cin >> width;
        
        // Input validation
        if (text.empty()) {
            throw runtime_error("Input string cannot be empty");
        }
        
        // Process and display wrapped text
        string wrapped_text = wrap_text(text, width);
        cout << "Wrapped text:\n" << wrapped_text << endl;
        
        return 0;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}