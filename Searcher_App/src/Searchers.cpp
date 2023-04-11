#include "Searchers.h"

std::vector<std::string> Episode_Search(std::ifstream& File, const std::string& Ser_Id) {
    std::vector<std::string> Episode_Id;
    std::string line;
    
    while (std::getline(File, line)) {
        std::vector<std::string> substrings = Line_Words(line);

        //ищем совпадение Id сериала с Родительским Id для эпизода
        if (substrings.at(1) == Ser_Id) {
            Episode_Id.push_back(substrings.at(0));
        }
    }
    return Episode_Id;
}

std::vector<std::string> EN_Titles(std::ifstream& File, const std::vector<std::string>& Episode_Ids){
    std::vector<std::string> En_Name;
    std::string line;
    
    //сортируем эпизоды
    std::vector<std::string> sorted_Episode_Ids = Episode_Ids;
    std::sort(sorted_Episode_Ids.begin(), sorted_Episode_Ids.end());

    while (std::getline(File, line)) {
        std::vector<std::string> substrings = Line_Words(line);
        
        //Ищем для каждой строки совпадения Id с идендификаторами нужных эпизодов
        if (std::binary_search(sorted_Episode_Ids.begin(), sorted_Episode_Ids.end(), substrings.at(0))) {
            En_Name.push_back(substrings.at(2));
        } 

    }
    return En_Name;
}

std::vector<std::string> Series_Search(std::ifstream& File, const std::string& Ser_Name) {
    std::vector<std::string> result;
    std::string line;
    
    while (std::getline(File, line)) {
        std::vector<std::string> substrings = Line_Words(line);//разбиваем каждую перебираемую строку на слова
        if (substrings.at(1) == "tvSeries" && substrings.at(3) == Ser_Name) {
            result = substrings;
            break; 
        }
    }
    
    return result;
}

std::vector<std::string> RU_Titles(std::ifstream& File, const std::vector<std::string>& Episode_Ids) {
    std::vector<std::string> Ru_Name;
    std::string line;
    
    //сортируем эпизоды
    std::vector<std::string> sorted_Episode_Ids = Episode_Ids;
    std::sort(sorted_Episode_Ids.begin(), sorted_Episode_Ids.end());
    
    while (std::getline(File, line)) {
        std::vector<std::string> substrings = Line_Words(line);
        if (substrings.at(3) == "RU" || substrings.at(4) == "ru") {
            //Ищем для каждой строки совпадения Id с идендификаторами нужных эпизодов
            if (std::binary_search(sorted_Episode_Ids.begin(), sorted_Episode_Ids.end(), substrings.at(0))) {
                Ru_Name.push_back(substrings.at(2));
            } 

        }
    }
    return Ru_Name;
}


