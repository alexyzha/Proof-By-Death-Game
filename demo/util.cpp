#include "util.h"

std::vector<std::string> split_by(const std::string& s, char c) {
    std::vector<std::string> substrings = {};
    std::string temp = "";
    for(auto& ch : s) {
        if(ch == c) {
            if(!temp.empty()) {
                substrings.push_back(temp);
            }
            temp.clear();
        } else {
            temp.push_back(ch);
        }
    }
    if(!temp.empty()) {
        substrings.push_back(temp);
    }
    return substrings;
}

std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> demo_parser(std::string file_path) {
    std::ifstream infile("levels/demo.lvl");
    if(!infile.is_open()) {
        throw std::invalid_argument("COULDN'T OPEN FILE");
    }
    std::string line;
    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> pairings;
    while(getline(infile, line)) {
        std::vector<std::string> pairing = split_by(line, ',');
        pairings[pairing[0]].push_back({pairing[1],pairing[2]});
    }
    infile.close();
    return pairings;
}