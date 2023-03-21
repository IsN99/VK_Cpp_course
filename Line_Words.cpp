#include "Line_Words.h"

vector<string> Line_Words(string& str) {
    vector<int> Tab_indexes = Tabs(str);
    int start = 0;
    
    vector<string> Words;
    
    for (int i = 0; i < Tab_indexes.size(); i++) {
        string substr = str.substr(start, Tab_indexes[i] - start);
        Words.push_back(substr);
        start = Tab_indexes[i] + 1;
    }
    
    Words.push_back(str.substr(start));
    
    return Words;
}
