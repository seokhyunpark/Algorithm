int sum(int n, vector<int> S) {
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += S[i];
    return total;
}
