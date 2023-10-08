#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define CMAX 505

struct lineInTable {
    string before = "", word = "", after = "";
    int poz;
} lines[CMAX / 2];

vector<string> words, uninportantWords;
int startingRow, endingRow, nrLines;
int maxBefore, maxWord, maxAfter;
/*void transformStringIntoChar(string s, char c[CMAX]) {
 int nrl = s.length();
 for (int i = 0; i < nrl; i++)
 c[i] = s[i];
 c[nrl] = '\n';
}*/
void transformUnused(string unused) {
    int nrl = unused.length();
    string s = "";
    for (int i = 0; i < nrl; i++)
        if (unused[i] == ' ') {
            uninportantWords.push_back(s);
            s = "";
        } else
            s += unused[i];
    if (nrl) uninportantWords.push_back(s);
}

void transformRows(string rows) {
    int nrl = rows.length();
    bool space = false;
    for (int i = 0; i < nrl; i++) {
        if (rows[i] == ' ')
            space = true;
        else if (!space)
            startingRow = startingRow * 10 + (rows[i] - '0');
        else
            endingRow = endingRow * 10 + (rows[i] - '0');
    }
}

bool verifyPunctuation(char c) { return strchr(".?!,;:", c); }

void insertPoint() {
    string s = ".";
    words.push_back(s);
}

bool verifyIdentic(string a, string b) {
    if (a.length() != b.length()) return false;
    int nrl = a.length();
    for (int i = 0; i < nrl; i++)
        if (tolower(a[i]) != tolower(b[i])) return false;
    return true;
}
bool verifyUninportant(string s) {
    for (auto &str : uninportantWords)
        if (verifyIdentic(str, s)) return true;
    return false;
}
void insertWord(string s) {
    if (s.empty()) return;
    if (verifyUninportant(s))
        insertPoint();
    else
        words.push_back(s);
}
void separateWords(string original) {
    int nrl = original.length();
    insertPoint();
    string s;
    for (int i = 0; i < nrl; i++) {
        if (verifyPunctuation(original[i])) {
            insertWord(s);
            s.erase();
            insertPoint();
        } else if (original[i] == ' ') {
            insertWord(s);
            s.erase();
        } else
            s += original[i];
    }
    insertWord(s);
    insertPoint();
}
void addBefore(int curLine, int pozWord) {
    if (words[pozWord - 1][0] != '.') {
        if (words[pozWord - 2][0] != '.') {
            if (words[pozWord - 3][0] != '.') {
                lines[curLine].before += words[pozWord - 3];
                lines[curLine].before += " ";
            }
            lines[curLine].before += words[pozWord - 2];
            lines[curLine].before += " ";
        }
        lines[curLine].before += words[pozWord - 1];
    }
}
void addAfter(int curLine, int pozWord) {
    if (words[pozWord + 1][0] == '.') return;
    lines[curLine].after += words[pozWord + 1];
    if (words[pozWord + 2][0] == '.') return;
    lines[curLine].after += " ";
    lines[curLine].after += words[pozWord + 2];
    if (words[pozWord + 3][0] == '.') return;
    lines[curLine].after += " ";
    lines[curLine].after += words[pozWord + 3];
}
void createLines() {
    for (int i = 0; i < words.size(); i++)
        if (words[i][0] != '.') {
            lines[nrLines].word = words[i];
            lines[nrLines].poz = nrLines;
            addBefore(nrLines, i);
            addAfter(nrLines, i);
            nrLines++;
        }
}
int compareStrings(string a, string b) {
    int nrla = a.length(), nrlb = b.length();
    for (int i = 0; i < min(nrla, nrlb); i++)
        if (tolower(a[i]) < tolower(b[i]))
            return 1;
        else if (tolower(a[i]) > tolower(b[i]))
            return -1;
    if (nrla > nrlb) return -1;
    if (nrla < nrlb) return 1;
    return 0;
}
bool cmp(lineInTable a, lineInTable b) {
    int rez = compareStrings(a.word, b.word);
    if (rez == 0) return a.poz < b.poz;
    return rez == 1;
}
void makeMaximums() {
    for (int i = 0; i < nrLines; i++) {
        maxBefore = max(maxBefore, (int)lines[i].before.length());
        maxWord = max(maxWord, (int)lines[i].word.length());
        maxAfter = max(maxAfter, (int)lines[i].after.length());
    }
}
int findLineToPrint() {
    int nrLine;
    int mini = 999999999;
    for (int i = startingRow - 1; i < endingRow; i++) {
        int nr = 0;
        nr += maxBefore - (int)lines[i].before.length();
        nr += maxWord - (int)lines[i].word.length();
        nr += maxAfter - (int)lines[i].after.length();
        if (nr < mini) {
            nrLine = i;
            mini = nr;
        }
    }
    return nrLine;
}
string printLine(int nrLine) {
    string s;
    int nrDashes = maxBefore - (int)lines[nrLine].before.length();
    for (int i = 0; i < nrDashes; i++) s += '-';
    s += lines[nrLine].before;
    s += " <";
    s += lines[nrLine].word;
    nrDashes = maxWord - (int)lines[nrLine].word.length();
    for (int i = 0; i < nrDashes; i++) s += '-';
    s += "> ";
    s += lines[nrLine].after;
    nrDashes = maxAfter - (int)lines[nrLine].after.length();
    for (int i = 0; i < nrDashes; i++) s += '-';
    return s;
}
string findARow(string original, string unused, string rows) {
    transformUnused(unused);
    transformRows(rows);
    separateWords(original);
    createLines();
    sort(lines, lines + nrLines, cmp);
    makeMaximums();
    int nrLine = findLineToPrint();
    return printLine(nrLine);
}
