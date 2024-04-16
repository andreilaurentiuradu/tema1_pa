#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
ifstream fin("oferta.in");
ofstream fout("oferta.out");

int main() {
    fin >> n >> k;
    vector<double> c(n + 1, 0);
    vector<double> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        fin >> c[i];
    }
    // SA TESTEZI DOAR k = 1
    if (k != 1) {
        fout << -1;
        return 0;
    }
    dp[1] = c[1];
    dp[2] = c[1] + c[2] - min(c[1], c[2]) / 2;

    double unu, doi, trei;
    for (int i = 3; i <= n; ++i) {
        unu = dp[i - 1] + c[i];
        doi = dp[i - 2] + c[i - 1] + c[i] - min(c[i - 1], c[i]) / 2;
        trei = dp[i - 3] + c[i] + c[i - 1] + c[i - 2] -
               min(c[i], min(c[i - 1], c[i - 2]));
        dp[i] = min(unu, min(doi, trei));
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    fout << fixed << setprecision(1) << dp[n] << "\n";
    return 0;
}
