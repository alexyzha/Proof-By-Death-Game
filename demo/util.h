#pragma once
#include <algorithm>
#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <locale>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#ifndef ANSI_ESC_COMMON
#define ANSI_ESC_COMMON
#define BLACK "\x1B[30m"
#define LBLACK "\x1B[90m"
#define RED "\x1B[31m"
#define LRED "\x1B[91m"
#define GREEN "\x1B[32m"
#define LGREEN "\x1B[92m"
#define YELLOW "\x1B[33m"
#define LYELLOW "\x1B[93m"
#define BLUE "\x1B[34m"
#define LBLUE "\x1B[94m"
#define MAGENTA "\x1B[35m"
#define LMAGENTA "\x1B[95m"
#define CYAN "\x1B[36m"
#define LCYAN "\x1B[96m"
#define WHITE "\x1B[37m"
#define LWHITE "\x1B[97m"
#define RESET "\x1B[0m"
#endif

#ifndef DEMO_UTIL
#define DEMO_UTIL

const std::string DEMO_OPTIONS[3][4] {
    {"Alice", "Bob", "Charlie", "Dave"},
    {"Red", "Orange", "Yellow", "White"},
    {"Green", "Blue", "Purple", "Black"}
};

const std::unordered_map<std::string, int> COLOR_TO_INT {
    {"Red", 0},
    {"Orange", 1},
    {"Yellow", 2},
    {"White", 3},
    {"Green", 4},
    {"Blue", 5},
    {"Purple", 6},
    {"Black", 7}
};

const std::unordered_map<int, std::string> INT_TO_COLOR {
    {0, "Red"},
    {1, "Orange"},
    {2, "Yellow"},
    {3, "White"},
    {4, "Green"},
    {5, "Blue"},
    {6, "Purple"},
    {7, "Black"}
};

std::vector<std::string> split_by(const std::string& s, char c);

/*
 *  Returns umap<str, vector<pair<str, str>>>
 */
std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> demo_parser(std::string file_path);

#endif