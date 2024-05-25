#include "lzw.h"

vector<int> compress(const string& text) {
    map<string, int> dict;
    for (int i = 0; i < 256; i++) {
        dict[string(1, char(i))] = i;
    }
    string curr = "";
    vector<int> compress;
    for (char c : text) {
        string comb = curr + c;
        if (dict.find(comb) != dict.end()) {
            curr = comb;
        }
        else {
            compress.push_back(dict[curr]);
            dict[comb] = dict.size();
            curr = string(1, c);
        }
    }
    if (!curr.empty()) {
        compress.push_back(dict[curr]);
    }
    return compress;
}

string decompress(const vector<int>& compressed) {
    map<int, string> dict;
    for (int i = 0; i < 256; i++) {
        dict[i] = string(1, char(i));
    }
    if (dict.find(compressed[0]) != dict.end()) {
        string prev = dict[compressed[0]];
    }
    else {
        throw runtime_error("Invalid compressed data.");
    }
    string decompress = prev;
    for (int i = 1; i < compressed.size(); i++) {
        string curr;
        if (dict.find(compressed[i]) != dict.end()) {
            curr = dict[compressed[i]];
        }
        else {
            curr = prev + prev[0];
        }
        decompress += curr;
        dict[dict.size()] = prev + curr[0];
        prev = curr;
    }
    return decompress;
}
