//Codeforces q1, maximise number of blocks in tower 1
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
//Function to solve the problem
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long a1 = a[0]; 
    for (int i = 1; i < n; ++i) {
        if (a[i] > a1) {
            a1 += (a[i] - a1 + 1) / 2; 
        }
    }
    cout << a1 << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}