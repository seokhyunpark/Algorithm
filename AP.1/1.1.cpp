void seqsearch(int n, vector<int> S, int x, int& location) {
    location = 0;
    for (int i = 1; i < n+1; i++) {
        if (x == S[i])
            location = i;
    }
}
