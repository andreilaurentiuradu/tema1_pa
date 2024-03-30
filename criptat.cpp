#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// precalculam scorurile scores[i][ch] iti da scorul caracterului pentru cuv de
// pe poz i
void letter_score_per_word(char ch, string word,
                           unordered_map<char, int> &letter_score) {
    letter_score[ch] = 0;
    for (char w : word) {
        if (w == ch) {
            letter_score[ch]++;
        } else {
            letter_score[ch]--;
        }
    }
    // cout << ch_score[ch] << ' ';
}

int scor_per_length(int N, int total_length, char ch, vector<string> words,
                    vector<unordered_map<char, int> > scores, vector<int> len) {
    vector<int> dp(total_length + 1, 0);
    vector<bool> viz(total_length + 1, false);
    viz[0] = true;
    int ant = 0;
    for (int i = 0; i < N; ++i) {
        // pentru fiecare scor existent dp[i] = k,unde i e lungimea sirului si k
        // e scorul
        for (int j = ant; j >= 0; --j) {
            int future_length = j + len[i];
            // scorul nou e mai mare decat scorul curent
            if (viz[j]) {  // daca exista un cuvant cu lungimea aia
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
                }
            }
        }
    }
    // cout << endl;

    // for (int i = 0; i <= total_length; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    for (int i = ant; i > 0; --i) {
        if (dp[i] > 0) return i;
    }
    return -1;  // nu exista
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int N;
    cin >> N;
    vector<string> words(N);
    int total_length = 0;
    vector<unordered_map<char, int> > scores(0);
    vector<int> len(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        len[i] = words[i].length();
        total_length += len[i];
        scores.push_back(unordered_map<char, int>());
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            letter_score_per_word(ch, words[i], scores[i]);
        }
    }
    // cout << endl;

    int result = -1;
    int best_ch_score;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        best_ch_score =
            scor_per_length(N, total_length, ch, words, scores, len);
        if (result < best_ch_score) {
            result = best_ch_score;
        }
    }

    fout << result;

    fin.close();
    fout.close();

    return 0;
}
