#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
ifstream fin("oferta.in");
ofstream fout("oferta.out");

int main() {
    fin >> n >> k;
    vector<double> c(n + 1, 0);
    set<double> dp1;
    set<double> dp2;
    set<double> dp3;
    set<double> dp_nou;

    for (int i = 1; i <= n; ++i) {
        fin >> c[i];
    }
    // dpi e cu i nivele in spate in piramida/casuta variantelor
    dp3.insert(0);
    dp2.insert(c[1]);
    dp1.insert(c[1] + c[2] - min(c[1], c[2]) / 2);
    dp1.insert(c[1] + c[2]);

    double unu, doi, trei, maxi_local;

    for (int i = 3; i <= n; ++i) {
        unu = c[i];
        doi = c[i - 1] + c[i] - min(c[i - 1], c[i]) / 2;
        trei = c[i] + c[i - 1] + c[i - 2] - min(c[i], min(c[i - 1], c[i - 2]));
        for (double x : dp3) {
            if (dp_nou.size() < k) {
                dp_nou.insert(x + trei);  // adaugam pentru nivelul 3
            } else {
                maxi_local = *(dp_nou.rbegin());
                if (x + trei < maxi_local) {
                    dp_nou.erase(maxi_local);
                    dp_nou.insert(x + trei);
                }
            }
        }

        for (double x : dp2) {
            if (dp_nou.size() < k) {
                dp_nou.insert(x + doi);  // adaugam pentru nivelul 2
            } else {
                maxi_local = *(dp_nou.rbegin());
                if (x + doi < maxi_local) {
                    dp_nou.erase(maxi_local);
                    dp_nou.insert(x + doi);
                }
            }
        }

        for (double x : dp1) {
            if (dp_nou.size() < k) {
                dp_nou.insert(x + unu);  // adaugam pentru nivelul 1
            } else {
                maxi_local = *(dp_nou.rbegin());
                if (x + unu < maxi_local) {
                    dp_nou.erase(maxi_local);
                    dp_nou.insert(x + unu);
                }
            }
        }

        dp3 = dp2;
        dp2 = dp1;
        dp1 = dp_nou;
        dp_nou.clear();
    }
    // if i e 1 sau 2
    int contor = 0;
    for (double x : dp1) {
        ++contor;
        if (contor == k) fout << fixed << setprecision(1) << x << '\n';
    }

    if (contor < k) {
        fout << -1;
    }

    return 0;
}
