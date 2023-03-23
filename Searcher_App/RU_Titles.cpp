#include "RU_Titles.h"

vector<string> RU_Titles(ifstream& File, vector<string>& Episode_Ids) {
    vector<string> Ru_Name;
    string line;
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);        
        if (substrings[3] == "RU" || substrings[4] == "ru") {

            //Ищем для каждой строки совпадения Id с идендификаторами нужных эпизодов
            auto it = find(Episode_Ids.begin(), Episode_Ids.end(), substrings[0]);
            if (it != Episode_Ids.end()) {
                Ru_Name.push_back(substrings[2]);
            }

        }
    }
    return Ru_Name;
}
