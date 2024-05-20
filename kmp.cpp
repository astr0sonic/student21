#include "kmp.h"
#include <vector>
std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int> result;

    // ѕеребираем строку text
    for (int i = 0; i < text.length() - my_template.length() + 1; i++) {
        // ѕровер€ем, совпадает ли текуща€ подстрока строки text со строкой шаблона
        if (text.substr(i, my_template.length()) == my_template) {
            // ≈сли да, добавл€ем начальный индекс совпадени€ в результирующий вектор
            result.push_back(i);
        }
    }

    return result;
}