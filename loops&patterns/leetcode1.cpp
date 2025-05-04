#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Trie Node Structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> sentences;  // stores sentences that have the current prefix
};

class AutoCompleteSystem {
public:
    // Constructor
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        current_input = "";
        
        // Initialize frequency map and build the Trie
        for (int i = 0; i < sentences.size(); i++) {
            addSentence(sentences[i], times[i]);
        }
    }
    
    // Input method: handles user input character by character
    vector<string> input(char c) {
        if (c == '#') {
            // Add current input sentence to the system
            addSentence(current_input, 1);
            current_input = "";  // Reset the input
            return {};
        }
        
        current_input += c;
        TrieNode* node = root;
        
        // Traverse the Trie based on the current input prefix
        for (char ch : current_input) {
            if (node->children.find(ch) == node->children.end()) {
                return {};  // No prefix match found
            }
            node = node->children[ch];
        }
        
        // Get all matching sentences for the current prefix
        vector<string> matched_sentences = node->sentences;
        
        // Sort sentences based on frequency, then lexicographically
        sort(matched_sentences.begin(), matched_sentences.end(), [this](const string& a, const string& b) {
            if (frequency[a] != frequency[b])
                return frequency[a] > frequency[b];
            return a < b;
        });
        
        // Return top 3 sentences
        vector<string> result;
        for (int i = 0; i < min(3, (int)matched_sentences.size()); i++) {
            result.push_back(matched_sentences[i]);
        }
        return result;
    }

private:
    TrieNode* root;  // Root of the Trie
    unordered_map<string, int> frequency;  // Frequency map to store sentence frequencies
    string current_input;  // Stores current input string
    
    // Helper function to add a sentence to the Trie and update frequency
    void addSentence(const string& sentence, int count) {
        frequency[sentence] += count;
        TrieNode* node = root;
        
        for (char ch : sentence) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            if (find(node->sentences.begin(), node->sentences.end(), sentence) == node->sentences.end()) {
                node->sentences.push_back(sentence);
            }
        }
    }
};

// Example usage
int main() {
    vector<string> sentences = {"i love you", "island", "ironman", "i love geeksforgeeks"};
    vector<int> times = {5, 3, 2, 2};
    
    AutoCompleteSystem* system = new AutoCompleteSystem(sentences, times);
    
    // Simulate typing inputs
    vector<string> result = system->input('i');
    for (string s : result) cout << s << endl;
    result = system->input(' ');
    for (string s : result) cout << s << endl;
    result = system->input('a');
    for (string s : result) cout << s << endl;
    result = system->input('#');  // Finalize input
    for (string s : result) cout << s << endl;
    
    return 0;
}
