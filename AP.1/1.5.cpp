void binsearch(int n, vector<int> S, int x, int& location) {
    location = 0;
    int start = 1;
    int end = n;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (S[mid] == x) {
            location = mid;
            return;
        }
        else if (S[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
}
