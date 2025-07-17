// 01 Recursive solution for 10 Edit Distance DP 33
#include <bits/stdc++.h>
using namespace std;

int edit(int i, int j, string &s1, string &s2) {
    if (i < 0) return j + 1;  // Insert remaining characters of s2
    if (j < 0) return i + 1;  // Delete remaining characters of s1

    if (s1[i] == s2[j])
        return edit(i - 1, j - 1, s1, s2);
    else
        return 1 + min({
            edit(i - 1, j, s1, s2),     // delete
            edit(i, j - 1, s1, s2),     // insert
            edit(i - 1, j - 1, s1, s2)  // replace
        });
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << "Edit Distance: " << edit(word1.size() - 1, word2.size() - 1, word1, word2) << endl;
    return 0;
}

