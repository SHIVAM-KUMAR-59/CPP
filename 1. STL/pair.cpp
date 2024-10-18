#include <iostream>
#include <utility> // Needed for std::pair
using namespace std;

void explainPairs() {
    // Correctly initializing pairs using the constructor
    pair<int, int> p1(1, 2);
    cout << p1.first << " " << p1.second << endl;

    // Nested pair initialization with space between right angle brackets
    pair<int, pair<int, int> > p2(1, pair<int, int>(2, 3));
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    // Correctly initializing an array of pairs
    pair<int, int> arr[] = {pair<int, int>(1, 2), pair<int, int>(3, 4), pair<int, int>(5, 6)};
    for (int i = 0; i < 3; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}

int main() {
    cout << "Hello, this is about pairs" << endl;
    explainPairs();
    return 0;
}
