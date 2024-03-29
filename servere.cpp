#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;

/*
Vom face o cautare binara pe sirul 0, 0.1, 0.2, ... p(x)
unde p de x este cea mai mare putere a unui server
*/

double compute_power(ull n, vector<ull> p, vector<ull> c, double source) {
    double ans = p[0] - fabs(c[0] - source);
    for (ull i = 1; i < n; ++i) {
        if (ans > p[i] - fabs(c[i] - source)) {
            ans = p[i] - fabs(c[i] - source);
        }
    }
    return ans;
}

double highest_power(ull n, vector<ull> p, vector<ull> c) {
    double left = 0, right;
    // puterea de calcul maxima este puterea maxima a unui server
    right = p[0];
    for (int i = 0; i < n; ++i) {
        if (right < p[i]) {
            right = p[i];
        }
    }

    double ans = compute_power(n, p, c, 0);
    while (left <= right) {
        double mid = (left + right) / 2;
        double current_power = compute_power(n, p, c, mid);
        double current_power_lower = compute_power(n, p, c, mid - 0.1);
        if (current_power >= ans) {
            ans = current_power;
        }
        if (current_power >= current_power_lower) {
            left = mid + 0.1;
        } else {
            right = mid - 0.1;
        }
    }

    // for (double i = left; i <= right; i += 0.1) {
    //     ans = max(ans, compute_power(n, p, c, i));
    // }
    return ans;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    ull n;
    cin >> n;
    vector<ull> p(n, 0);
    vector<ull> c(n, 0);

    for (ull i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (ull i = 0; i < n; ++i) {
        cin >> c[i];
    }

    fout << highest_power(n, p, c);
    return 0;
}
