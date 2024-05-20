#include "kmp.h"
#include <vector>

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int> result;

    // Построение таблицы префиксов
    std::vector<int> prefix(my_template.length());
    int k = 0;
    prefix[0] = 0;
    for (int q = 1; q < my_template.length(); q++) {
        while (k > 0 && my_template[k] != my_template[q]) {
            k = prefix[k - 1];
        }
        if (my_template[k] == my_template[q]) {
            k++;
        }
        prefix[q] = k;
    }

    // Поиск вхождений подстроки
    int m = 0;
    int n = 0;
    while (m < text.length()) {
        if (my_template[n] == text[m]) {
            n++;
            m++;
        }
        if (n == my_template.length()) {
            result.push_back(m - n);
            n = prefix[n - 1];
        }
        else if (m < text.length() && my_template[n] != text[m]) {
            if (n != 0) {
                n = prefix[n - 1];
            }
            else {
                m = m + 1;
            }
        }
    }

    return result;
}