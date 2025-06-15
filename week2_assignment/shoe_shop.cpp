#include <iostream>
#include <map>

using namespace std;

int main() {
    int num_shoes;
    cout << "Enter number of shoes available: ";
    cin >> num_shoes;

    map<int, int> inventory;

    cout << "Enter the shoe sizes available (space separated): ";
    for (int i = 0; i < num_shoes; ++i) {
        int size;
        cin >> size;
        inventory[size]++;
    }

    int num_customers;
    cout << "Enter number of customers: ";
    cin >> num_customers;

    int total_earnings = 0;

    cout << "Enter desired size and price for each customer (e.g., 8 100):\n";
    for (int i = 0; i < num_customers; ++i) {
        int desired_size, price;
        cin >> desired_size >> price;

        if (inventory[desired_size] > 0) {
            total_earnings += price;
            inventory[desired_size]--;
        }
    }

    cout << "\nTotal earnings: " << total_earnings << endl;

    return 0;
}
