#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int segTree[4 * MAX_N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        segTree[node] = 1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if (l > end || r < start)
    {
        return 0;
    }
    if (l <= start && r >= end)
    {
        return segTree[node];
    }
    int mid = start + (end - start) / 2;
    return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
}

void update(int node, int start, int end, int index, int value)
{
    if (start == end)
    {
        segTree[node] += (value - 1);  // adjust for 0 based indexing
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (index <= mid)
        {
            update(2 * node + 1, start, mid, index, value);
        }
        else
        {
            update(2 * node + 2, mid + 1, end, index, value);
        }
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(0, 0, n - 1);
    int q;
    cin >> q;
    
    // Performance comparison region
    auto start_time = std::chrono::high_resolution_clock::now();

    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) { // Query
            int ans = query(0, 0, n - 1, 0, x - 1);
            cout << ans << endl;
        } else { // Update
            int idx;
            cin >> idx;
            idx--;
            update(0, 0, n - 1, idx, arr[idx]);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}