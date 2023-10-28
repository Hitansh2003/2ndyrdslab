#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << target << std::endl;
        return;
    }

    towerOfHanoi(n - 1, source, target, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are the names of the pegs

    return 0;
}
