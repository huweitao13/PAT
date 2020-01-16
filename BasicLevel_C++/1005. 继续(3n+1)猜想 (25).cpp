#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    int n, m[101];
    cin >> n;
    memset(m, 0, sizeof(m));
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        m[idx] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        if (m[i] == 0)
            continue;
        int t = i;
        while (t != 1) {
            if (t & 1)
                t = (3 * t + 1) >> 1;
            else
                t >>= 1;
            if (t <= 100)
                m[t] = 0;
        }
    }
    vector<int> ret;
    for (int i = 100; i >= 1; i--)
        if (m[i] == 1)
            ret.push_back(i);
    for (int i = 0; i < ret.size() - 1; i++)
        cout << ret[i] << ' ';
    cout << ret[ret.size()-1];
    return 0;
}
