#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Add all words to set for O(1) lookup
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        // If target word is not in dictionary
        if(words.find(targetWord) == words.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        words.erase(startWord); // Remove to avoid revisiting
        
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == targetWord) return steps;
            
            // Try changing each character
            for(int i = 0; i < word.length(); i++) {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(words.find(word) != words.end()) {
                        words.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};