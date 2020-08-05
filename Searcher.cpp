//
// Created by nyacat on 2018/6/22.
//

#include "Searcher.h"

vector<int> Searcher::bruteForce(std::string text, std::string pattern) {
    int text_index = 0;
    int pattern_index = 0;
    vector<int> position;
    while (text_index < text.size()) {
        if (text[text_index] == pattern[pattern_index]) {
            text_index++;
            pattern_index++;
        } else {
            text_index = text_index - pattern_index + 1;
            pattern_index = 0;
        }
        if (pattern_index >= pattern.size()) {
            position.push_back(text_index - pattern_index);
            pattern_index = 0;
        }
    }

    return position;
}

// 部分匹配表
void Searcher::kmpGetPMT(std::string pattern, int partialMatchTable[]) {
    //q 模版字符串下标  k 最大前后缀长度
    int q;
    int k = 0;
    // 模版字符串的第一个字符的最大前后缀长度为0
    partialMatchTable[0] = 0;

    //for循环，从第二个字符开始，依次计算每一个字符对应的next值
    for (q = 1; q < pattern.length(); q++) {
        //递归的求出P[0]···P[q]的最大的相同的前后缀长度k
        while (k > 0 && pattern[q] != pattern[k]) {
            k = partialMatchTable[k - 1];
        }
        //如果相等，那么最大相同前后缀长度加1
        if (pattern[k] == pattern[q]) {
            k++;
        }
        partialMatchTable[q] = k;
    }
}

vector<int> Searcher::kmpSearch(std::string text, std::string pattern) {
    vector<int> position;

    int partialMatchTable[pattern.length()];
    kmpGetPMT(pattern, partialMatchTable);

    for (int text_index = 0, pattern_index = 0; text_index < text.length(); text_index++) {
        while (pattern_index > 0 && pattern[pattern_index] != text[text_index]) {
            pattern_index = partialMatchTable[pattern_index];
        }
        if (pattern[pattern_index] == text[text_index]) {
            pattern_index++;
        }
        if (pattern_index == pattern.length()) {
            position.push_back(text_index - pattern_index + 1);
            pattern_index = 0;
        }
    }

    return position;
}