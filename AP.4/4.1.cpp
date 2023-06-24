#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matrix_t;
int threshold;
int cnt = 0;

void strassen(int n, matrix_t A, matrix_t B, matrix_t &C);
void madd(int n, matrix_t A, matrix_t B, matrix_t &C);
void msub(int n, matrix_t A, matrix_t B, matrix_t &C);
void mmult(int n, matrix_t A, matrix_t B, matrix_t &C);
void combine(int m, matrix_t &M, matrix_t M11, matrix_t M12, matrix_t M21, matrix_t M22);
void partition(int m, matrix_t M, matrix_t &M11, matrix_t &M12, matrix_t &M21, matrix_t &M22);
void mprint(int n, matrix_t M);

int main() {
    int n; cin >> n >> threshold;
    int k = 1;
    while (k < n)
        k *= 2;
    matrix_t A(k, vector<int>(k));
    matrix_t B(k, vector<int>(k));
    matrix_t C(k, vector<int>(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    strassen(k, A, B, C);
    mprint(n, C);

    return 0;
}

void strassen(int n, matrix_t A, matrix_t B, matrix_t &C) {
    cnt++;
    if (n <= threshold)
        mmult(n, A, B, C);
    else {
        n /= 2;
        matrix_t A11(n, vector<int>(n)), A12(n, vector<int>(n)), A21(n, vector<int>(n)), A22(n, vector<int>(n));
        matrix_t B11(n, vector<int>(n)), B12(n, vector<int>(n)), B21(n, vector<int>(n)), B22(n, vector<int>(n));
        matrix_t C11(n, vector<int>(n)), C12(n, vector<int>(n)), C21(n, vector<int>(n)), C22(n, vector<int>(n));
        matrix_t M1(n, vector<int>(n)), M2(n, vector<int>(n)), M3(n, vector<int>(n)), M4(n, vector<int>(n)), M5(n, vector<int>(n)), M6(n, vector<int>(n)), M7(n, vector<int>(n));
        matrix_t L(n, vector<int>(n)), R(n, vector<int>(n));

        // partition
        partition(n, A, A11, A12, A21, A22);
        partition(n, B, B11, B12, B21, B22);

        // M1 ~ M7
        madd(n, A11, A22, L); madd(n, B11, B22, R); strassen(n, L, R, M1);
        madd(n, A21, A22, L); strassen(n, L, B11, M2);
        msub(n, B12, B22, R); strassen(n, A11, R, M3);
        msub(n, B21, B11, R); strassen(n, A22, R, M4);
        madd(n, A11, A12, L); strassen(n, L, B22, M5);
        msub(n, A21, A11, L); madd(n, B11, B12, R); strassen(n, L, R, M6);
        msub(n, A12, A22, L); madd(n, B21, B22, R); strassen(n, L, R, M7);

        // combine
        madd(n, M1, M4, L); msub(n, L, M5, R); madd(n, R, M7, C11);
        madd(n, M3, M5, C12);
        madd(n, M2, M4, C21);
        madd(n, M1, M3, L); msub(n, L, M2, R); madd(n, R, M6, C22);
        combine(n, C, C11, C12, C21, C22);
    }
}

void madd(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void msub(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void mmult(int n, matrix_t A, matrix_t B, matrix_t &C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void combine(int m, matrix_t &M, matrix_t M11, matrix_t M12, matrix_t M21, matrix_t M22) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M[i][j] = M11[i][j];
            M[i][j + m] = M12[i][j];
            M[i + m][j] = M21[i][j];
            M[i + m][j + m] = M22[i][j];
        }
 }

void partition(int m, matrix_t M, matrix_t &M11, matrix_t &M12, matrix_t &M21, matrix_t &M22) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + m];
            M21[i][j] = M[i + m][j];
            M22[i][j] = M[i + m][j + m];
        }
}

void mprint(int n, matrix_t M) {
    cout << cnt << endl;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++)
            cout << M[i][j] << " ";
        cout << M[i][j] << endl;
    }
    cout << endl;
}
