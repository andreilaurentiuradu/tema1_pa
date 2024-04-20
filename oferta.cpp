#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int n, k;
double c[10001];
vector<double> dp1, dp2, dp3, dp_nou;
double unu, doi, trei, minim_current;
int ii, jj, kk;

ifstream fin("oferta.in");
ofstream fout("oferta.out");
int main() {
    fin >> n >> k;
    for (int i = 1; i <= n; i++) {
        fin >> c[i];
    }

    // dpi e cu i nivele in spate in piramida/casuta variantelor
    // cum putem lua 0 produse
    dp3.push_back(0);
    // cum putem lua primul produs
    dp2.push_back(c[1]);
    // cum putem lua primele 2 produse
    dp1.push_back(c[1] + c[2] - min(c[1], c[2]) / 2);
    dp1.push_back(c[1] + c[2]);
    for (int i = 3; i <= n; i++) {
        // calculam cele 3 moduri in care putem lua produsul curent
        unu = c[i];
        doi = c[i - 1] + c[i] - min(c[i - 1], c[i]) / 2;
        trei = c[i] + c[i - 1] + c[i - 2] - min(c[i], min(c[i - 1], c[i - 2]));

        // facem interclasarea celor 3 vectori pastrand primele maxim k preturi
        ii = jj = kk = 0;
        while (true) {
            minim_current = -1;

            // verificam daca din vectorul cu un nivel mai sus putem adauga
            // pretul
            if (ii < dp1.size() && dp1[ii] + unu < minim_current) {
                minim_current = dp1[ii] + unu;
            }

            // verificam daca din vectorul cu 2 nivele mai sus putem adauga
            // pretul
            if (jj < dp2.size() &&
                (minim_current == -1 || dp2[jj] + doi < minim_current)) {
                minim_current = dp2[jj] + doi;
            }

            // verificam daca din vectorul cu trei nivele mai sus putem adauga
            // pretul
            if (kk < dp3.size() &&
                (minim_current == -1 || dp3[kk] + trei < minim_current)) {
                minim_current = dp3[kk] + trei;
            }

            // daca nu putem din niciun vector
            if (minim_current == -1) {
                break;
            }

            // adaugam pretul minim curent(interclasarea celor 3 vectori)
            if (dp_nou.empty() || minim_current != dp_nou.back()) {
                dp_nou.push_back(minim_current);
            }

            // daca vectorul de pe nivelul curent a ajuns sa aiba k elemente
            if (dp_nou.size() == k) {
                break;
            }

            // verificam din ce vector a fost adaugat pretul si incrementam
            // contorul
            if (ii < dp1.size() && dp1[ii] + unu == minim_current) {
                ii++;
            }
            if (jj < dp2.size() && dp2[jj] + doi == minim_current) {
                jj++;
            }
            if (kk < dp3.size() && dp3[kk] + trei == minim_current) {
                kk++;
            }
        }
        // shiftuim valorile din vectori cu un nivel mai jos
        dp3 = dp2;
        dp2 = dp1;
        dp1 = dp_nou;
        dp_nou.clear();
    }

    // afisam al k-lea pret posibil(daca exista) cu exact o zecimala
    if (dp1.size() >= k)
        fout << fixed << setprecision(1) << dp1[k - 1];
    else
        fout << -1;
    return 0;
}
