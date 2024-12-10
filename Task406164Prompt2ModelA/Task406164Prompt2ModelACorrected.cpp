#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#define MAX_N 100000

int segTree[4 * MAX_N];

void build(int node, int start, int end, vector<int> arr) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) {
        return 0;
    }
    if (l <= start && r >= end) {
        return segTree[node];
    }
    int mid = start + (end - start) / 2;
    return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
}

void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        segTree[node] = value;
    } else {
        int mid = start + (end - start) / 2;
        if (index <= mid) {
            update(2 * node + 1, start, mid, index, value);
        } else {
            update(2 * node + 2, mid + 1, end, index, value);
        }
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

int main() {
    const int N = 100000;
    vector<int> arr(N);
    
    // Fixed test input array
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    build(0, 0, N - 1, arr);

    // Performance comparison region
    auto start_time = std::chrono::high_resolution_clock::now();

    // Queries
    for (int i = 0; i < N / 10; i++) {
        int l = rand() % N;
        int r = rand() % N;
        if (l > r) swap(l, r);
        int ans = query(0, 0, N - 1, l, r);
    }

    // Updates
    for (int i = 0; i < N / 10; i++) {
        int idx = rand() % N;
        int val = rand() % 100;
        update(0, 0, N - 1, idx, val);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}