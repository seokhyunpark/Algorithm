#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int location(int low, int high, int x, int &cnt, vector<int> &arr);

int main() {
    int size, n, input; cin >> size; cin >> n;

    vector<int> v(size);
    for (int i = 0; i < v.size(); i++) {
        cin >> input;
        v[i] = input;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cin >> input;
        int index, cnt = 0;
        index = location(0, v.size() - 1, input, cnt, v);
        cout << cnt << " " << index << endl;
    }

    return 0;
}

int location(int low, int high, int x, int &cnt, vector<int> &arr) {
    int mid; cnt++;
    if (low > high)
        return 0;
    else {
        mid = (low + high) / 2;
        if (x == arr[mid])
            return mid + 1;
        else if (x < arr[mid])
            return location(low, mid - 1, x, cnt, arr);
        else
            return location(mid + 1, high, x, cnt, arr);
    }
}
