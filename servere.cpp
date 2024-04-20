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

// cautam puterea minima individuala
double f(double x) {
    double mn = MAXIM;
    for (int i = 0; i < n; i++) {
        mn = min(mn, p[i] - fabs(x - c[i]));
    }
    return mn;
}

int main() {
    ifstream fin("servere.in");

    // citim datele serverelor
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        fin >> c[i];
    }
    fin.close();

    // cautam binar maximul functiei
    double l = MINIM, r = MAXIM, m;

    while (r - l > eps) {
        m = (l + r) / 2;

        // verificam daca suntem pe ramura din dreapta
        if (f(m) > f(m + eps)) {
            r = m;
        } else {
            l = m;
        }
    }

    // afisam cu exact o zecimala puterea maxima a sistemului
    ofstream fout("servere.out");
    fout << fixed << setprecision(1) << f(m) << '\n';
    fout.close();
    return 0;
}
