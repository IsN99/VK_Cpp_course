#include "RU_Titles.h"

vector<string> RU_Titles(ifstream& File, vector<string>& Episode_Ids) {
    vector<string> Ru_Name;
    string line;
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);        
        if (substrings[3] == "RU" || substrings[4] == "ru") {
            for (int i = 0; i < Episode_Ids.size(); i++) {
                if (substrings[0] == Episode_Ids[i]) {
                    Ru_Name.push_back(substrings[2]);
                    break;
                }
            }
        }
    }
    return Ru_Name;
}
