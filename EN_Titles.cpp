#include "EN_Titles.h"

vector<string> EN_Titles(ifstream& File, vector<string>& Episode_Ids) {
    vector<string> En_Name;
    string line;
    
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);
        
        for (int i = 0; i < Episode_Ids.size(); i++) {
            if (substrings[0] == Episode_Ids[i]) {            	
                En_Name.push_back(substrings[2]);               
                break;                
            }
        }
    }
    return En_Name;
}
