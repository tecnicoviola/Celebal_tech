#include <iostream>
#include <string>
using namespace std;

string capitalizeName(const string& name) {
    string result = name;
    bool capitalizeNext = true;
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == ' ') {
            capitalizeNext = true;
        } else if (capitalizeNext && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            capitalizeNext = false;
        } else {
            capitalizeNext = false;
        }
    }
    return result;
}

int main() {
    string fullName;
    getline(cin, fullName);
    cout << capitalizeName(fullName) << endl;
    return 0;
}