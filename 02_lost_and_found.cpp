#include <bits/stdc++.h>
using namespace std;

// User-defined reverse (tanpa std::reverse)
void myReverse(string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
        ++i; --j;
    }
}

// Konversi int ke "triplet" 3 digit (000..999)
string toTriplet(int v) {
    ostringstream oss;
    oss << setw(3) << setfill('0') << v;
    return oss.str();
}

// Encode: plaintext -> digit-string (dibalik)
string encodeToReversedDigits(const string &plain) {
    // 1) simpan ASCII yang sudah di-offset ke vector<int>
    vector<int> codes;
    codes.reserve(plain.size());
    for (size_t i = 0; i < plain.size(); ++i) {
        int code = (unsigned char)plain[i];
        int shifted = code + (int)(i % 7);
        codes.push_back(shifted);
    }
    // 2) gabung jadi triplet
    string digits;
    digits.reserve(codes.size() * 3);
    for (int x : codes) digits += toTriplet(x);
    // 3) balikan seluruh digit → jadi sandi
    myReverse(digits);
    return digits;
}

// Decode penuh dari digit-string yang sudah dibalik
string decodeFromReversedDigits(const string &reversedDigits) {
    string d = reversedDigits;
    myReverse(d); // kembalikan ke urutan triplet asli
    // pecah per 3 digit
    vector<int> codes;
    for (size_t i = 0; i + 2 < d.size(); i += 3) {
        int val = (d[i]-'0')*100 + (d[i+1]-'0')*10 + (d[i+2]-'0');
        codes.push_back(val);
    }
    // pulihkan char
    string plain;
    plain.reserve(codes.size());
    for (size_t i = 0; i < codes.size(); ++i) {
        int code = codes[i] - (int)(i % 7);
        plain.push_back((char)code);
    }
    return plain;
}

// Partial: ambil hanya k karakter pertama dari sandi digit
string partialDecode(const string &reversedDigits, int k) {
    string d = reversedDigits;
    myReverse(d); // balik dulu
    int needDigits = max(0, k) * 3;
    if ((int)d.size() < needDigits) needDigits = (int)d.size() - ( (int)d.size() % 3 );
    string slice = d.substr(0, needDigits);

    vector<int> codes;
    for (size_t i = 0; i + 2 < slice.size(); i += 3) {
        int val = (slice[i]-'0')*100 + (slice[i+1]-'0')*10 + (slice[i+2]-'0');
        codes.push_back(val);
    }
    string part;
    part.reserve(codes.size());
    for (size_t i = 0; i < codes.size(); ++i) {
        int code = codes[i] - (int)(i % 7);
        part.push_back((char)code);
    }
    return part;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
      Menu sederhana:
      1 -> Encode plaintext → keluaran digit-string (dibalik)
      2 -> Decode full dari digit-string (dibalik)
      3 -> Partial decode: k karakter pertama dari sandi digit (dibalik)
    */
    int mode;
    if (!(cin >> mode)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\\n');

    if (mode == 1) {
        string plaintext;
        getline(cin, plaintext);
        string cipher = encodeToReversedDigits(plaintext);
        cout << cipher << "\\n";
    } else if (mode == 2) {
        string rd;
        getline(cin, rd);
        cout << decodeFromReversedDigits(rd) << "\\n";
    } else if (mode == 3) {
        string rd;
        int k;
        getline(cin, rd);
        cin >> k;
        cout << partialDecode(rd, k) << "\\n";
    }
    return 0;
}
