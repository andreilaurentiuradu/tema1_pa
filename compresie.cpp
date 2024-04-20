#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int max_length(int n, vector<int> a, int m, vector<int> b) {
    int i = 0, j = 0, cop_n = n, cop_m = m;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            if (i >= n) {
                // daca nu sunt egale si nu mai putem face operatii
                return -1;
            }

            // adaugam la urmatorul element
            a[i + 1] += a[i];
            --cop_n;

            // crestem indicele din primul vector
            ++i;
        } else if (a[i] > b[j]) {
            if (j >= m) {
                // daca nu sunt egale si nu mai putem face operatii
                return -1;
            }

            // adaugam la urmatorul element
            b[j + 1] += b[j];
            --cop_m;
            ++j;
        } else {
            // crestem ambii indici care retin pozitiile din vectori
            ++i;
            ++j;
        }
    }

    if (cop_n != cop_m) {
        // daca nu sunt egale si nu mai putem face operatii
        return -1;
    }

    return cop_n;
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
    fout << max_length(n, a, m, b) << endl;
    fin.close();
    fout.close();
    return 0;
}
