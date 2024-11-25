#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store Name and Score
struct Student {
    string name;
    int score;
};

// Function to perform partitioning for Quick Sort
int partition(vector<Student>& arr, int low, int high) {
    int pivot = arr[high].score;  // Taking the score of the last element as pivot
    int i = low - 1;  // Pointer for the smaller element

    for (int j = low; j < high; ++j) {
        // If current element's score is less than the pivot
        if (arr[j].score < pivot) {
            ++i;
            swap(arr[i], arr[j]);  // Swap if smaller element is found
        }
    }
    swap(arr[i + 1], arr[high]);  // Move pivot to correct position
    return i + 1;  // Return the pivot index
}

// Quick Sort function to sort the array of structures
void quickSort(vector<Student>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array of structures
void printArray(const vector<Student>& arr) {
    for (const auto& student : arr) {
        cout << "Name: " << student.name << ", Score: " << student.score << endl;
    }
}

int main() {
    // Initialize array of structures
    vector<Student> students = {
        {"Alice", 50},
        {"Bob", 80},
        {"Charlie", 70},
        {"David", 90}
    };

    cout << "Before Sorting:" << endl;
    printArray(students);

    // Perform Quick Sort on the array
    quickSort(students, 0, students.size() - 1);

    cout << "\nAfter Sorting by Score:" << endl;
    printArray(students);

    return 0;
}
