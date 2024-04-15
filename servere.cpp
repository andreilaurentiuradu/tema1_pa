// #include <algorithm>
// #include <climits>
// #include <cmath>
// #include <fstream>
// #include <iomanip>
// #include <iostream>
// #include <vector>
// #define ull unsigned long long

// using namespace std;

// struct server {
//     ull p, c;
// };
// /*
// Vom face o cautare binara pe sirul 0, 0.1, 0.2, ... p(x)
// unde p de x este cea mai mare putere a unui server
// */

// double compute_power(ull n, vector<server> s, double source) {
//     double ans = s[0].p - fabs(s[0].c - source);
//     for (ull i = 1; i < n; ++i) {
//         if (ans > s[i].p - fabs(s[i].c - source)) {
//             ans = s[i].p - fabs(s[i].c - source);
//         }
//     }
//     return ans;
// }

// double highest_power(ull n, vector<server> s) {
//     double left = -10000, right = 10000;
//     double ans = 0;
//     while (left <= right) {
//         double mid = (left + right) / 2;
//         // cout << "mid si ans " << mid << ' ' << ans << endl;
//         double sol_1 = s[0].p - mid + s[0].c;
//         double sol_2 = s[0].c + mid - s[0].p;
//         bool is_bigger = true;
//         for (int i = 0; i < n; ++i) {
//             if (s[i].p - fabs(s[i].c - sol_1) < mid) {
//                 is_bigger = false;
//                 break;
//             }
//         }
//         if (is_bigger) {
//             ans = mid;
//             left = mid;
//         } else {
//             for (int i = 0; i < n; ++i) {
//                 if (s[i].p - fabs(s[i].c - sol_2) < mid) {
//                     is_bigger = false;
//                     break;
//                 }
//             }
//             if (is_bigger) {
//                 ans = mid;
//                 left = mid;
//             } else {
//                 right = mid;
//             }
//         }
//     }
//     return ans;
// }

// bool cmp(server a, server b) { return ((a.p - a.c) < (b.p - b.c)); }

// int main() {
//     ifstream fin("servere.in");
//     ofstream fout("servere.out");

//     ull n;
//     cin >> n;
//     server temp;
//     temp.c = 0;
//     temp.p = 0;
//     vector<server> s(n, temp);
//     for (int i = 0; i < n; ++i) {
//         cin >> s[i].p;
//     }

//     for (int i = 0; i < n; ++i) {
//         cin >> s[i].c;
//     }
//     sort(s.begin(), s.end(), cmp);

//     // for (int i = 0; i < n; ++i) {
//     //     fout << s[i].p << ' ' << s[i].c << endl;
//     // }
//     cout << highest_power(n, s);
//     return 0;
// }
#include <cmath>
#include <fstream>
#include <iomanip>
#define MAXIM 1e9
#define MINIM -1e9
using namespace std;

const double eps = 1e-2;
const int N = 100000;
int p[N], c[N];
int n;

double f(double x) {
    double mn = MAXIM;
    for (int i = 0; i < n; i++) mn = min(mn, p[i] - fabs(x - c[i]));
    return mn;
}

int main() {
    ifstream fin("servere.in");
    fin >> n;
    for (int i = 0; i < n; i++) fin >> p[i];
    for (int i = 0; i < n; i++) fin >> c[i];
    fin.close();
    double l = MINIM, r = MAXIM, m;
    while (r - l > eps) {
        m = (l + r) / 2;
        if (f(m) > f(m + eps)) {
            r = m;
        } else {
            l = m;
        }
    }
    ofstream fout("servere.out");
    fout << fixed << setprecision(1) << f(m) << '\n';
    fout.close();
    return 0;
}
