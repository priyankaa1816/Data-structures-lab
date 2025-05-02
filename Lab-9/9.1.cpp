#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int y;
        cin >> y;

        vector<int> players(y);
        for (int i = 0; i < y; i++) {
            players[i] = i + 1; // Initialize players
        }

        while (true) {
            vector<int> toRemove;
            for (int ai : a) {
                if (ai <= players.size()) {
                    toRemove.push_back(players[ai - 1]); // Mark players to remove
                }
            }

            if (toRemove.empty()) {
                break; // No more players to remove
            }

            vector<int> newPlayers;
            for (int player : players) {
                if (find(toRemove.begin(), toRemove.end(), player) == toRemove.end()) {
                    newPlayers.push_back(player); // Keep players not marked for removal
                }
            }

            players = newPlayers; // Update the list of players
        }

        cout << players.size() << ' '; // Output the number of remaining players
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _test;
    cin >> _test;
    while (_test--) {
        solve();
    }

    return 0;
}