//
// Created by nyacat on 2018/6/22.
//

#ifndef KEYORDCOUNTER_SEARCHER_H
#define KEYORDCOUNTER_SEARCHER_H

#include <vector>
#include <string>

using namespace std;

class Searcher {
public:
    vector<int> bruteForce(std::string text, std::string pattern);
    vector<int> kmpSearch(std::string text, std::string pattern);

private:
    void kmpGetPMT(string target_str, int *next);
};


#endif //KEYORDCOUNTER_SEARCHER_H
