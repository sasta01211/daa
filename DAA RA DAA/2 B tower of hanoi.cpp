#include <iostream>

using namespace std;

// Function to solve the Towers of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: if there is only one disk, move it from source to destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move top n-1 disks from source to auxiliary pole using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;  // Number of disks

    cout << "Enter the number of disks: ";
    cin >> n;

    // Calling the recursive function to solve the Towers of Hanoi problem
    cout << "The steps to solve the Towers of Hanoi are:\n";
    towerOfHanoi(n, 'A', 'B', 'C');  // A, B, C are the source, auxiliary, and destination poles

    return 0;
}
