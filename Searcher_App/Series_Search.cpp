#include "Series_Search.h"

vector<string> Series_Search(ifstream& File, string& Ser_Name) {
    vector<string> result;
    string line;
    
    while (getline(File, line)) {
        vector<string> substrings = Line_Words(line);//разбиваем каждую перебираемую строку на слова        
        if (substrings[1] == "tvSeries" && substrings[3] == Ser_Name) {
            result = substrings;
            break; 
        }
    }
    
    return result;
}
