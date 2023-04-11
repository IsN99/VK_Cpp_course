#pragma once
#include "Line_Words.h"

std::vector<std::string> Episode_Search(std::ifstream& File, const std::string& Ser_Id);

std::vector<std::string> Series_Search(std::ifstream& File, const std::string& Ser_Name);

std::vector<std::string> RU_Titles(std::ifstream& File, const std::vector<std::string>& Episode_Ids);

std::vector<std::string> EN_Titles(std::ifstream& File, const std::vector<std::string>& Episode_Ids);
