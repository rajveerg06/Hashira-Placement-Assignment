#include <bits/stdc++.h>
using namespace std;

// Convert string in base b to decimal (supports bases > 10 with letters)
long long baseToDecimal(const string &value, int base) {
    long long num = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else digit = 10 + (tolower(c) - 'a');
        num = num * base + digit;
    }
    return num;
}

int main() {
    // Example test case (Sample JSON parsed manually)
    int n = 4, k = 3;
    vector<pair<int,string>> inputs = {
        {10, "4"},
        {2, "111"},
        {10, "12"},
        {4, "213"}
    };

    vector<long long> roots;
    for (auto &p : inputs) {
        roots.push_back(baseToDecimal(p.second, p.first));
    }

    // Degree of polynomial = k - 1
    int degree = k - 1;
    vector<long long> coeffs = {1}; // Start with constant 1

    // Multiply (x - root) for first (k-1) roots
    for (int r = 0; r < degree; r++) {
        vector<long long> newCoeff(coeffs.size() + 1, 0);
        for (int i = 0; i < coeffs.size(); i++) {
            newCoeff[i] += coeffs[i];
            newCoeff[i+1] -= coeffs[i] * roots[r];
        }
        coeffs = newCoeff;
    }

    // Print coefficients
    cout << "Polynomial coefficients: ";
    for (long long c : coeffs) cout << c << " ";
    cout << endl;

    return 0;
}
