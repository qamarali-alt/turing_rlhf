#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100005

int segTree[4 * MAX_N];

void build(int node, int start, int end)
{
    if (start == end) {
        segTree[node] = arr[start];
    } 
    else {
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if (l > end || r < start) {
        return 0;
    }

    if (l <= start && r >= end) {
        return segTree[node];
    }

    int mid = start + (end - start) / 2;
    return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
}

void update(int node, int start, int end, int index, int diff)
{
    if (start == end) {
        segTree[node] += diff;
    } else {
        int mid = start + (end - start) / 2;
        if (index <= mid) {
            update(2 * node + 1, start, mid, index, diff);
        } else {
            update(2 * node + 2, mid + 1, end, index, diff);
        }
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

 
int main() {
    const int N = 1e5;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1; // Initialize the array from 1 to N for testing
    }

    build(0, 0, N - 1);
    int q = 1e5;
 
    // Performance comparison region
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < q; i++)
    {
	    int type;
	    int l, r, x;
	    do{
		    type = rand() % 3;
	    }while(type == 0 && i == 0);
	    
	    if(type == 0) // Update
	    {
		    l = rand() % N;
		    x = rand() % 100 + 1;
		    update(0, 0, N - 1, l, x - arr[l]);
		    arr[l] = x;
	    }
	    else
	    {
		    l = rand() % N;
		    r = min(N - 1, rand() % (N - l) + l);
		    int ans = query(0, 0, N - 1, l, r);
            //cout << ans << endl; // uncomment this if you want to verify the queries
	    }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    

    return 0;
}
