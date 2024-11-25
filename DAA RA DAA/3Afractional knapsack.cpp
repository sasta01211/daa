#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items based on value/weight ratio in descending order
bool compare(Item& a, Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare); // Sort items based on value/weight ratio

    double totalValue = 0.0;
    for (auto& item : items) {
        if (capacity == 0) {
            break;
        }

        // If the item can be completely taken
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else { 
            // Take the fraction of the item
            totalValue += item.value * ((double)capacity / item.weight);
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    // Number of test cases
    int t = 2;

    // Test case 1
    cout << "Test case 1:" << endl;
    int n1 = 3;
    vector<Item> items1 = {{60, 10}, {100, 20}, {120, 30}};
    int capacity1 = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity1, items1) << endl;

    // Test case 2
    cout << "Test case 2:" << endl;
    int n2 = 4;
    vector<Item> items2 = {{60, 10}, {40, 40}, {100, 20}, {120, 30}};
    int capacity2 = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity2, items2) << endl;

    return 0;
}
