#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int newSize = 0;
    int unique[n];  

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            unique[newSize] = arr[i];
            newSize++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) cout << unique[i] << " ";
    cout << endl;

    return 0;
}