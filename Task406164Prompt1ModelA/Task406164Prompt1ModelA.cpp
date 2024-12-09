
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

class SegTree {
public:
    vector<int> count;

    SegTree() : count(N * 4, 0) { }

    void build(int start, int end, int node) {
        if (start == end) return;
        int mid = start + (end - start) / 2;
        build(start, mid, node * 2);
        build(mid + 1, end, node * 2 + 1);
        count[node] = count[node * 2] + count[node * 2 + 1];
    }

    void update(int l, int r, int val, int start, int end, int node) {
        if (l > end || r < start) return;
        if (l <= start && r >= end) {
            count[node] = (end - start + 1) < val ? 0 : end - start + 1;
            return;
        }
        int mid = start + (end - start) / 2;
        update(l, r, val, start, mid, node * 2);
        update(l, r, val, mid + 1, end, node * 2 + 1);
        count[node] = count[node * 2] + count[node * 2 + 1];
    }

    int query(int val, int start, int end, int node) {
        if (val <= start) return 0;
        if (val >= end + 1) return count[node];
        int mid = start + (end - start) / 2;
        return query(val, start, mid, node * 2) + query(val, mid + 1, end, node * 2 + 1);
    }
};

void testSegTree() {
    vector<int> arr{1, 3, 5, 7, 2, 4, 6, 8};
    SegTree st;
    st.build(0, static_cast<int>(arr.size()) - 1, 1);

    // Perform some updates
    st.update(2, 4, 6, 0, static_cast<int>(arr.size()) - 1, 1);
    st.update(5, 5, 10, 0, static_cast<int>(arr.size()) - 1, 1);
    
    // Perform some queries
    int queries[] = {2, 3, 4, 10};
    for (int q: queries) {
        int ans = st.query(q, 0, static_cast<int>(arr.size()) - 1, 1);
        cout << "Query for " << q << ": " << ans << endl;
    }
}
 
 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testSegTree();

    return 0;
}
