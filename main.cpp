#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <zconf.h>
#include "Searcher.h"

#if defined __GNUC__
char *clear = "clear";
#elif defined _MSC_VER
char *clear = "cls";
#endif

using namespace std;

void mysleep(int sleepTime) {
#if defined __GNUC__
    sleep(sleepTime);
#elif defined _MSC_VER
#include <windows.h>
    Sleep(sleepTime);
#endif
}

void BFsearch(const string &fileName, const string &keyWord) {
    Searcher strFinder;
    ifstream inputStream(fileName);
    string lineStr;

    int lineNum = 1;
    cout << "BruteForce: " << endl;
    while (getline(inputStream, lineStr)) {
        std::vector<int> c = strFinder.bruteForce(lineStr, keyWord);
        if (c.size() != 0) {
            cout << "Line-" << lineNum << " Count: " << c.size();
            for (int i = 0; i < c.size(); i++) {
                cout << " - No." << i + 1 << " at: " << c[i];
            }
            cout << endl;
            lineNum++;
        }
    }
}


void KMPsearch(const string &fileName, const string &keyWord) {
    Searcher strFinder;
    ifstream inputStream(fileName);
    string lineStr;

    int lineNum = 1;
    cout << "KMP: " << endl;
    while (getline(inputStream, lineStr)) {
        std::vector<int> c = strFinder.kmpSearch(lineStr, keyWord);
        if (c.size() != 0) {
            cout << "Line-" << lineNum << " Count: " << c.size();
            for (int i = 0; i < c.size(); i++) {
                cout << " - No." << i + 1 << " at: " << c[i];
            }
            cout << endl;
            lineNum++;
        }
    }
}

bool checkFile(const string &fileName) {
    ifstream inputStream(fileName);
    if (inputStream) {
        return true;
    } else {
        return false;
    }
}

int main() {
//    std::vector<int> a = strFinder.bruteForce("tmp tab tmp abc tmp", "tmp");
//
//    cout << "BruteForce: " << a.size() << endl;
//    for (int i = 0; i < a.size(); i++) {
//        cout << "No." << i + 1 << " at: " << a[i] << endl;
//    }
//
//    vector<int> b = strFinder.kmpSearch("tmptt tab tmptt atmptc ttmp", "ttmp");
//    cout << "KMP: " << b.size() << endl;
//
//    for (int i = 0; i < b.size(); i++) {
//        cout << "No." << i + 1 << " at: " << b[i] << endl;
//    }

    string fileName;
    string keyWord;
    cout << "Input file name:" << endl;
    while (true) {
        cin >> fileName;
//        fileName = "./data/" + fileName;
        fileName = "/Users/nyacat/Projects/CLionProjects/searcher/data/test.txt";
        if (!checkFile(fileName)) {
            cout << "File not found!" << endl;
            mysleep(1);
            system(clear);
        } else {
            cout << "File: " << fileName << " Opened" << endl;
            cout << "Input keyword to search!" << endl;
            cin >> keyWord;
            BFsearch(fileName, keyWord);
            KMPsearch(fileName, keyWord);
            break;
        }
    }

    return 0;
}