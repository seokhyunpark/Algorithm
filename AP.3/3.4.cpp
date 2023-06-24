#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void partition(int low, int high, int &pivotpoint, vector<int> &S);
void quicksort(int low, int high, vector<int> &S);

int main() {
    int n; cin >> n;
    
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    quicksort(1, n, S);

    int i;
    for (i = 1; i < n; i++)
        cout << S[i] << " ";
    cout << S[i] << endl << cnt;

    return 0;
}

void partition(int low, int high, int &pivotpoint, vector<int> &S) {
    int i, j, pivotitem;

    pivotitem = S[low];
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++;
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++;
}

void quicksort(int low, int high, vector<int> &S) {
    int pivotpoint;

    if (low < high) {
        partition(low, high, pivotpoint, S);
        quicksort(low, pivotpoint - 1, S);
        quicksort(pivotpoint + 1, high, S);
    }   
}
