#include "lzw.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

std::vector<unsigned char> compress(const std::string& text) {
    std::map<std::string, unsigned char> dict;
    for (int i = 0; i < 256; i++) {
        dict[std::string(1, char(i))] = i;
    }
    std::string curr = "";
    std::vector<unsigned char> compressed;
    for (char c : text) {
        std::string comb = curr + c;
        if (dict.find(comb) != dict.end()) {
            curr = comb;
        }
        else {
            compressed.push_back(dict[curr]);
            dict[comb] = dict.size();
            curr = std::string(1, c);
        }
    }
    if (!curr.empty()) {
        compressed.push_back(dict[curr]);
    }
    return compressed;
}

std::string decompress(const std::vector<unsigned char>& compressed) {
    std::map<unsigned char, std::string> dict;
    for (int i = 0; i < 256; i++) {
        dict[i] = std::string(1, char(i));
    }
    std::string prev = dict[compressed[0]];
    std::string decompress = prev;
    for (int i = 1; i < compressed.size(); i++) {
        std::string curr;
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
