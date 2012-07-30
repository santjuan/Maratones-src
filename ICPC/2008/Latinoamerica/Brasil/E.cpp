#include <vector>
#include <iostream>
using namespace std;

// In this implementation, the tree is represented by a vector<int>.
// Elements are numbered by 0, 1, ..., n-1.
// tree[i] is sum of elements with indexes i&(i+1)..i, inclusive.
// (Note: this is a bit different from what is proposed in Fenwick's article.
// To see why it makes sense, think about the trailing 1's in binary
// representation of indexes.)

// Creates a zero-initialized Fenwick tree for n elements.
vector<int> create(int n) { return vector<int>(n, 0); }

// Returns sum of elements with indexes a..b, inclusive
int query(const vector<int> &tree, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
          sum += tree[b];
        return sum;
    } else {
        return query(tree, 0, b) - query(tree, 0, a-1);
    }
}

// Increases value of k-th element by inc.
void increase(vector<int> &tree, int k, int inc) {
    for (; k < (int)tree.size(); k |= k + 1)
        tree[k] += inc;
}

int main()
{
    vector<int> a = create(100001);
    while(true)
    {
        int n;
        for(int i = 0; i < 100001; i++)
        {
            a[i] = 0;
        }
        cin >> n;
        if(n == 0)
            return 0;
        int cuenta = 0;
        for(int i = 0; i < n; i++)
        {
            int este;
            cin >> este;
            increase(a, este, 1);
            cuenta += query(a, este + 1, n);
        }
        if(cuenta % 2 == 0)
            cout << "Carlos" << endl;
        else
            cout << "Marcelo" << endl;
    }
}
