#include "Line_Words.h"

//ф-я для поиска позиций табуляций в строке
vector<int> Tabs(const string& str) {
    vector<int> Tab_Indexes;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\t') {
            Tab_Indexes.push_back(i);
        }
    }

    return Tab_Indexes;
}


vector<string> Line_Words(string& str) {
    vector<int> Tab_indexes = Tabs(str);
    int start = 0;
    
    vector<string> Words;
    
    //вставляем в цикле подстроки с первой по предпоследнюю
    for (int i = 0; i < Tab_indexes.size(); i++) {
        string substr = str.substr(start, Tab_indexes[i] - start);
        Words.push_back(substr);
        start = Tab_indexes[i] + 1;
    }
    
    Words.push_back(str.substr(start));//вставляем последнюю подстроку
    
    return Words;
}
