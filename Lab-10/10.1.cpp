//Codeforces 10.1q
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_set<int> seen;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (seen.find(a[i]) != seen.end()) {
                break;
            }
            seen.insert(a[i]);
            ans++;
        }
        cout << n - ans << endl;
    }
    return 0;
}
