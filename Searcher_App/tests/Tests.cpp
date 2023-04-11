#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <assert.h>
#include "Line_Words.h"
#include "Searchers.h"

// Тестирование функции на пустой строке
void TestEmptyString() {
    std::string str = "";
    std::vector<std::string> words = Line_Words(str);
    assert(words.size() == 1);
    assert(words[0].empty());
}

// Тестирование функции на строке без пробелов
void TestStringWithoutTabs() {
    std::string str = "1";
    std::vector<std::string> words = Line_Words(str);
    assert(words.size() == 1);
    assert(words[0] == "1");
}

// Тестирование функции на строке с одним табом
void TestStringWithOneTab() {
    std::string str = "1\t2";
    std::vector<std::string> words = Line_Words(str);
    assert(words.size() == 2);
    assert(words[0] == "1");
    assert(words[1] == "2");
}

// Тестирование функции на строке с несколькими табами
void TestStringWithMultipleTabs() {
    std::string str = "1\t234\t567\t89\t10\t1112";
    std::vector<std::string> words = Line_Words(str);
    assert(words.size() == 6);
    assert(words[0] == "1");
    assert(words[1] == "234");
    assert(words[2] == "567");
    assert(words[3] == "89");
    assert(words[4] == "10");
    assert(words[5] == "1112");
}

// Тестирование функции на строке, содержащей только табы
void TestStringWithOnlyTabs() {
    std::string str = "\t\t\t";
    std::vector<std::string> words = Line_Words(str);
    assert(words.size() == 4);
    assert(words[0].empty());
    assert(words[1].empty());
    assert(words[2].empty());
    assert(words[3].empty());
}

void TestEnTitles() {
    std::ifstream file("basics_test.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }
    std::vector<std::string> episodeIds = {"tt4", "tt5"};
    std::vector<std::string> enTitles = EN_Titles(file, episodeIds);
    if (enTitles.empty()) {
        std::cerr << "Failed to extract titles" << std::endl;
        return;
    }
    assert(enTitles.size() == 2);
    assert(enTitles[0] == "S1E1");
    assert(enTitles[1] == "S1E2");
}

void TestEpisodeSearch() {
    std::ifstream file("episode_test.txt");
    std::vector<std::string> episodeIds = Episode_Search(file, "tt1");
    assert(episodeIds.size() == 2);
    assert(episodeIds[0] == "tt4");
    assert(episodeIds[1] == "tt5");
}

void TestSeriesSearch() {
    std::ifstream file("basics_test.txt");
    std::vector<std::string> series = Series_Search(file, "Series1");
    assert(series.size() == 9);
    assert(series[0] == "tt1");
    assert(series[1] == "tvSeries");
    assert(series[2] == "Series1");
    assert(series[3] == "Series1");
}

void TestRuTitles() {
    std::ifstream file("akas_test.txt");
    std::vector<std::string> episodeIds = {"tt4", "tt5"};
    std::vector<std::string> ruTitles = RU_Titles(file, episodeIds);
    assert(ruTitles.size() == 2);
    assert(ruTitles[0] == "Эпизод1С1");
    assert(ruTitles[1] == "Эпизод1С2");
}

int main() {
    TestEmptyString();
    std::cout << "TestEmptyString passed" << std::endl;
    TestStringWithoutTabs();
    std::cout << "TestStringWithoutTabs passed" << std::endl;
    TestStringWithOneTab();
    std::cout << "TestStringWithOneTab passed" << std::endl;
    TestStringWithMultipleTabs();
    std::cout << "TestStringWithMultipleTabs passed" << std::endl;
    TestStringWithOnlyTabs();
    std::cout << "TestStringWithOnlyTabs passed" << std::endl;
    TestEnTitles();
    std::cout << "TestEnTitles passed" << std::endl;
    TestEpisodeSearch();
    std::cout << "TestEpisodeSearch passed" << std::endl;    
    TestSeriesSearch();
    std::cout << "TestSeriesSearch passed" << std::endl;
    TestRuTitles();
    std::cout << "TestRuTitles passed" << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
