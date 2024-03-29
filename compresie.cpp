#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;

void afisare(int n, vector<int> a) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int max_length(int n, vector<int> a, int m, vector<int> b) {
    int i = 0, j = 0, nou;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            nou = a[i];
            if (i >= n) {
                return -1;
            }
            a[i + 1] += a[i];        // adaugam la urmatorul element
            a.erase(a.begin() + i);  // il stergem
            --n;
            // afisare(n, a);
        } else if (a[i] > b[j]) {
            nou = b[i];
            if (j >= m) {
                return -1;
            }
            b[j + 1] += b[j];
            b.erase(b.begin() + j);  // il stergem
            --m;
            // afisare(m, b);
        } else {
            ++i;
            ++j;
        }
    }
    return n;
}

int main() {
    int n, m;
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    fin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    fin >> m;
    vector<int> b(m, 0);
    for (int i = 0; i < m; ++i) {
        fin >> b[i];
    }
    fout << max_length(n, a, m, b);
    return 0;
}
