#include <bits/stdc++.h>
using namespace std;

string stateAt(long long t, const vector<pair<string,long long>>& phases) {
    long long T = 0;
    for (auto &p : phases) T += p.second;        // total siklus
    long long x = ((t % T) + T) % T;              // pos dalam siklus (aman utk t negatif)
    for (auto &p : phases) {
        if (x < p.second) return p.first;         // 1 if saja, bukan chain panjang
        x -= p.second;
    }
    return phases.back().first; // fallback
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long G, Y, R;
    // Input: durasi Hijau, Kuning, Merah
    if (!(cin >> G >> Y >> R)) return 0;

    int q; 
    cin >> q; // jumlah pertanyaan
    vector<pair<string,long long>> phases = {
        {"Green", G},
        {"Yellow", Y},
        {"Red", R}
    };

    while (q--) {
        long long t; 
        cin >> t; // detik ke-?
        cout << stateAt(t, phases) << "\\n";
    }
    return 0;
}
