void exchange(int n, vector<int>& S) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (S[j] > S[j + 1]) {
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}
