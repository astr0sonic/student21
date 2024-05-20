#include "kmp.h"
#include <vector>
using namespace std;
std::vector<int> getIndices(const std::string& my_template, const std::string& text)
{
    vector<int> T(text.size() + 1, -1);
    vector<int> matches;

    if (text.size() == 0) {
        matches.push_back(0);
        return matches;
    }

    for (int i = 1; i <= text.size(); i++) {
        int pos = T[i - 1];
        while (pos != -1 && text[pos] != text[i - 1])
            pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while (sp < my_template.size()) {
        while (kp != -1 && (kp == text.size() || text[kp] != my_template[sp]))
            kp = T[kp];
        kp++;
        sp++;
        if (kp == text.size())
            matches.push_back(sp - text.size());
    }

    return matches;
}