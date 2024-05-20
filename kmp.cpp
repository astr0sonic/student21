#include "kmp.h"
#include <vector>
std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int> result;

    // ���������� ������ text
    for (int i = 0; i < text.length() - my_template.length() + 1; i++) {
        // ���������, ��������� �� ������� ��������� ������ text �� ������� �������
        if (text.substr(i, my_template.length()) == my_template) {
            // ���� ��, ��������� ��������� ������ ���������� � �������������� ������
            result.push_back(i);
        }
    }

    return result;
}