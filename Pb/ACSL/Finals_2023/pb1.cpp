#include <algorithm>
#include <cstring>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
ofstream cout("ctc.out");

struct Row {
    string word, before, after;
    int poz;
};

vector<string> words;
set<string> bannedWords;
int iRow1, iRow2;
vector<Row> table;
int maxBefore, maxWord, MaxAfter;

bool cmp(Row aRow, Row bRow) {
    string a = aRow.word, b = bRow.word;
    transform(a.begin(), a.end(), a.begin(), [](char c) { return tolower(c); });
    transform(b.begin(), b.end(), b.begin(), [](char c) { return tolower(c); });
    if (a == b) return aRow.poz < bRow.poz;
    return a < b;
}

inline bool isOk(string s) {
    transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });
    if (bannedWords.find(s) != bannedWords.end()) {
        return 0;
    }
    return isalpha(s[0]);
}

inline void separateUnused(string unused) {
    for (char *word = strtok(&unused[0], " "); word; word = strtok(0, " ")) {
        bannedWords.insert(word);
    }
}

inline void separateRows(string rows) {
    int iSpace = rows.find(" ");
    iRow1 = stoi(rows.substr(0, iSpace)) - 1;
    iRow1 = stoi(rows.substr(iSpace + 1)) - 1;
}

inline void separateWords(string original) {
    for (char *word = strtok(&original[0], " "); word; word = strtok(0, " ")) {
        string x = string(word);
        auto c = x[x.size() - 1];
        if (!isalpha(c)) {
            x.pop_back();
            words.push_back(x);
            words.push_back(string(1, c));
            continue;
        }
        words.push_back(x);
    }
}

inline void makeTable() {
    Row row;
    for (int i = 0; i < words.size(); i++) {
        if (!isOk(words[i])) continue;
        row.word = words[i];
        row.before = row.after = "";
        for (int j = 1; j <= 3; j++) {
            if (i - j < 0 || !isOk(words[i - j])) break;
            row.before = words[i - j] + ' ' + row.before;
        }
        if (row.before.size() > 0) row.before.pop_back();
        for (int j = 1; j <= 3; j++) {
            if (i + j > words.size() - 1 || !isOk(words[i + j])) break;
            row.after += words[i + j] + ' ';
        }
        if (row.after.size() > 0) row.after.pop_back();
        row.poz = i;
        table.push_back(row);
    }
}

inline void findMaxes() {
    for (auto x : table) {
        maxBefore = max(maxBefore, (int)x.before.size());
        maxWord = max(maxWord, (int)x.word.size());
        MaxAfter = max(MaxAfter, (int)x.after.size());
    }
}

inline string findLine() {
    int nrMin = 1000, iLine, nr;
    for (int i = 0; i < table.size(); i++) {
        auto x = table[i];
        nr = -x.before.size() - x.word.size() - x.after.size();
        if (nr < nrMin) nrMin = nr, iLine = i;
    }
    auto x = table[iLine];
    while (x.before.size() < maxBefore) x.before = '-' + x.before;
    while (x.word.size() < maxWord) x.word += '-';
    while (x.after.size() < MaxAfter) x.after += '-';
    return x.before + " <" + x.word + "> " + x.after;
}

string findARow(string original, string unused, string rows) {
    separateWords(original);
    separateUnused(unused);
    separateRows(rows);
    makeTable();
    sort(table.begin(), table.end(), cmp);
    findMaxes();
    // for (auto x : table) {
    //     cout << '|' << x.before << '|' << x.word << '|' << x.after << "|\n";
    // }
    return findLine();
}

int main() {
    cout << findARow(
        "KWIC is an acronym for Key Word In Context, the most common format "
        "for concordance lines which is used for indexing in context.",
        "for in the", "7 15");
    return 0;
}