#include <fstream>
#include <iostream>
#define ull unsigned long long
#define MOD (ull)(1e9 + 7)
using namespace std;

// calculam modulul ridicarii la putere in timp logaritmic
ull fast_exp(ull base, ull exp) {
    ull ans = 1;

    while (exp) {
        if (exp & 1) {
            ans *= base;
            ans %= MOD;
        }
        exp >>= 1;
        base *= base;
        base %= MOD;
    }

    return ans;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    ull types, nr, twos, threes;
    char T, ant;
    fin >> types;

    fin >> nr;
    fin.get();
    fin >> ant;

    // daca seventa incepe cu H
    if (ant == 'H') {
        twos = 1;
        threes = nr;
    } else {
        twos = nr - 1;
        threes = 1;
    }

    for (ull i = 1; i < types; ++i) {
        fin >> nr;
        fin.get();
        fin >> T;

        if (ant == 'H') {
            // daca piesa anterioara a fost orizontala
            if (T == 'H') {
                // daca urmatoarele nr piese vor fi orizontale
                threes += nr;
            } else {
                // daca urmatoarele nr piese vor fi verticale
                twos += nr - 1;
            }
        } else {
            // daca piesa anterioara a fost verticala
            if (T == 'H') {
                // daca urmatoarele nr piese vor fi orizontale
                twos++;
                threes += nr - 1;
            } else {
                // daca urmatoarele nr piese vor fi verticale
                twos += nr;
            }
        }
        // actualizam piesa anterioara
        ant = T;
    }

    // calculam nr de posibilitati de colorare
    fout << fast_exp(2, twos) * fast_exp(3, threes) % MOD;

    return 0;
}
