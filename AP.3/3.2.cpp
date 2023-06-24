#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void mergesort(int n, vector<int> &S);
void merge(int h, int m, vector<int> &U, vector<int> &V, vector<int> &S);

int main() {
    int n, input; cin >> n;

    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> input;
        S[i] = input;
    }
    mergesort(n, S);

    int i;
    for (i = 1; i < n; i++)
        cout << S[i] << " ";
    cout << S[i];
    cout << endl << cnt;

    return 0;
}

void mergesort(int n, vector<int> &S) {
    if (n > 1) {
        int h = n / 2;
        int m = n - h;

        vector<int> U(h + 1), V(m + 1);
        cnt += h + m;
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h + 1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

void merge(int h, int m, vector<int> &U, vector<int> &V, vector<int> &S) {
    int i = 1, j = 1, k = 1;
    while (i <= h && j <= m) {
        if (U[i] < V[j])
            S[k++] = U[i++];
        else
            S[k++] = V[j++];
    }

    if (i > h) {
        while (j <= m)
            S[k++] = V[j++];
    }
    else {
        while (i <= h)
            S[k++] = U[i++];
    }
}
