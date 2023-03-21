#include "Tabs.h"

vector<int> Tabs(const string& str) {
    vector<int> Tab_Indexes;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\t') {
            Tab_Indexes.push_back(i);
        }
    }
    
    return Tab_Indexes;
}
