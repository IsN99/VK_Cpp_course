#include "Episode_Search.h"

vector<string> Episode_Search(ifstream& File, string& Ser_Id) {
    vector<string> Episode_Id;
    string line;
    
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);

        //ищем совпадение Id сериала с Родительским Id для эпизода
        if (substrings[1] == Ser_Id) {
            Episode_Id.push_back(substrings[0]);
        }
    }
    return Episode_Id;
}
