#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string word1, string word2) 
{
    if (word1.length() < 1 || word2.length() < 1) return false;
    int hash[256];
    for (int i = 0; i < 256; i++)
        hash[i] = 0;
    for (int i = 0; i < word1.length(); i++) {
        hash[word1[i]]++;
    }
    for (int i = 0; i < word2.length(); i++) {
        hash[word2[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (hash[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isAnagram("silent", "listen") << endl;
    return 0;
}

