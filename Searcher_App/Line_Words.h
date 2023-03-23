#pragma once

#ifndef LINEWORDS_H
#define LINEWORDS_H

//подключаем библиотеки используемые в проекте здесь, т.к. функция является крайней по подключению
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "fstream"

using namespace std;


//функция возвращает вектор подстрок, на которые строка делится табуляциями
vector<string> Line_Words(string& str);

#endif
