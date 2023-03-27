#include "Line_Words.h"


std::vector<std::string> Line_Words(std::string& str) {
    int start = 0;
    
    std::vector<std::string> Words;

    //вставляем в цикле подстроки с первой по предпоследнюю
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\t') {
            std::string substr = str.substr(start, i - start);
            Words.push_back(substr);
            start = i + 1;
        }
    }

    Words.push_back(str.substr(start));//вставляем последнюю подстроку
    
    return Words;
}
