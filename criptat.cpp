#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#define SMAX 10001
#define NMAX 1001
#define LITMAX 26

using namespace std;

// lungimea fiecarui cuvant
int len[NMAX];
// nr de cuvinte
int N;
// fiecare linie reprezinta de cate ori apare fiecare litera in fiecare
// cuvant incepand cu pozitia 0
int mapare[NMAX][LITMAX];
// marcam literele existente
int existing_letter[LITMAX];

// lungimea maxima cu litera dominanta pe pozitia ch in alfabet
int scor_per_length(int ch) {
    // scorurile cele mai bune pentru cuv de lungimea
    int dp[SMAX] = {0};
    // daca exista un cuv cu lungimea aia
    int viz[SMAX] = {0};
    viz[0] = 1;
    int ant = 0, result = -1;
    for (int i = 0; i < N; ++i) {
        // pentru fiecare scor existent dp[i] = k,unde i e lungimea sirului si k
        // e scorul
        for (int j = ant; j >= 0; --j) {
            if (viz[j]) {  // daca exista un cuvant cu lungimea aia
                // noua lungime
                int future_length = j + len[i];
                // scorul literei ch pentru cuvantul i
                int letter_score = mapare[i][ch] - (len[i] - mapare[i][ch]);

                // daca nu exista o parola valida cu lungimea noua
                // sau daca gasim o parola cu un scor mai bun
                if (!viz[future_length] ||
                    dp[j] + letter_score > dp[future_length]) {
                    // noul scor e actualizat
                    viz[future_length] = true;
                    dp[future_length] = dp[j] + letter_score;

                    if (ant < future_length) {
                        // noul ant e actualizat
                        ant = future_length;
                    }
                    if (dp[future_length] > 0 && result < future_length) {
                        // daca am gasit un raspuns mai bun
                        result = future_length;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    fin >> N;

    // counter pentru a vedea daca s-a ajuns la 8 litere diferite
    // (limita de la restrictii)
    int counter = 0;
    string word;
    for (int i = 0; i < N; ++i) {
        fin >> word;
        for (char w : word) {
            // actualizam in matricea caracteristica
            // mapare[i][j] retine de cate ori apare litera j in cuvantul i
            ++mapare[i][w - 'a'];
            // creste nr de litere din cuvant
            ++len[i];
            // marcam litera daca exista in vreun cuvant
            existing_letter[w - 'a'] = 1;
        }
    }
    fin.close();
    int result = -1;
    int best_ch_score;

    // luam fiecare litera din alfabet
    for (int i = 0; counter < 8 && i < LITMAX; ++i) {
        // verificam daca exista in vreun cuvant
        if (existing_letter[i]) {
            counter++;
            // calculam parola de lungime maxima cu litera dominanta (i + 'a')
            best_ch_score = scor_per_length(i);
            // daca am gasit o lungime mai buna
            if (result < best_ch_score) {
                result = best_ch_score;
            }
        }
    }

    // afisam lungimea maxima
    fout << result;
    fout.close();

    return 0;
}
