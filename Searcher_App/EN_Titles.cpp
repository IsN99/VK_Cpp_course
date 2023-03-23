#include "EN_Titles.h"

vector<string> EN_Titles(ifstream& File, vector<string>& Episode_Ids) {
    vector<string> En_Name;
    string line;
    
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);
        
        //Ищем для каждой строки совпадения Id с идендификаторами нужных эпизодов
        auto it = find(Episode_Ids.begin(), Episode_Ids.end(), substrings[0]);
        if (it != Episode_Ids.end()) {
            En_Name.push_back(substrings[2]);
        }

    }
    return En_Name;
}
