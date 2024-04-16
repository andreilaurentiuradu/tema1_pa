#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// precalculam scorurile scores[i][ch] iti da scorul caracterului pentru cuv de
// pe poz i
void letter_score_per_word(char ch, string word,
                           unordered_map<char, int> &letter_score,
                           bitset<26> &letters) {
    // letter_score[ch] = 0;
    for (char w : word) {
        if (w == ch) {
            letters[w - 'a'] = 1;
            letter_score[ch]++;
        } else {
            letter_score[ch]--;
        }
    }
    // cout << ch_score[ch] << ' ';
}

int scor_per_length(int N, int total_length, char ch, vector<string> words,
                    vector<unordered_map<char, int> > scores, vector<int> len) {
    int dp[10001] = {0};   // scorurile cele mai bune pentru cuv de lungimea aia
    int viz[10001] = {0};  // daca exista un cuv cu lungimea aia
    viz[0] = true;
    int ant = 0, result = -1;
    for (int i = 0; i < N; ++i) {
        // pentru fiecare scor existent dp[i] = k,unde i e lungimea sirului si k
        // e scorul
        for (int j = ant; j >= 0; --j) {
            // scorul nou e mai mare decat scorul curent
            if (viz[j]) {  // daca exista un cuvant cu lungimea aia
                int future_length = j + len[i];
                if (!viz[future_length] ||
                    dp[j] + scores[i][ch] >
                        dp[future_length]) {  // daca nu exista sau avem unu cu
                                              // scor mai bun
                    viz[future_length] = true;
                    dp[future_length] =
                        dp[j] + scores[i][ch];  // noul scor e actualizat
                    if (ant < future_length) {
                        ant = future_length;  // noul ant e actualizat
                    }
                    if (dp[future_length] > 0 &&
                        result < future_length) {  // daca am gasit un raspuns
                                                   // mai bun
                        result = future_length;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int N;
    fin >> N;
    vector<string> words(N);
    int total_length = 0;
    vector<unordered_map<char, int> > scores(N, unordered_map<char, int>());
    // vector care retine cate un map pentru fiecare cuvant reprezentand
    // scorul fiecarei litere pentru acel cuvant
    // scores[i] retine fiecare litera impreuna cu scorul ei
    vector<int> len(N + 1);  // lungimea fiecarui cuvant
    bitset<26> letters(0);
    int counter = 0;
    for (int i = 0; i < N; ++i) {
        fin >> words[i];
        len[i] = words[i].length();
        total_length += len[i];
        for (char ch = 'a'; counter < 8 && ch <= 'z'; ++ch) {
            letter_score_per_word(ch, words[i], scores[i], letters);
            if (scores[i][ch] > -len[i]) {
                counter++;
            }
        }
        counter = 0;
    }
    fin.close();
    // cout << endl;

    int result = -1;
    int best_ch_score;
    for (char ch = 'a'; counter < 8 && ch <= 'z'; ++ch) {
        if (letters[ch - 'a']) {
            counter++;
            best_ch_score =
                scor_per_length(N, total_length, ch, words, scores, len);
            if (result < best_ch_score) {
                result = best_ch_score;
            }
        }
    }

    fout << result;

    fout.close();

    return 0;
}
