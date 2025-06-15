#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

/**
 * Calculates the average of unique elements
 */
double calculateAverage(const vector<int>& numbers) {
    set<int> unique(numbers.begin(), numbers.end());

    if (unique.empty()) {
        throw runtime_error("No unique elements to calculate average.");
    }

    double sum = 0;
    for (int num : unique) {
        sum += num;
    }

    return sum / unique.size();
}

int main() {
    try {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        if (n <= 0) {
            throw runtime_error("Number of elements must be positive.");
        }

        vector<int> nums(n);
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        double avg = calculateAverage(nums);
        cout << fixed << setprecision(3) << "Average of unique numbers: " << avg << endl;

        return 0;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
