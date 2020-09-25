//
// Created by hoang on 9/15/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_STRING_UTILS_H
#define TWAIN_RABBITMQ_CLIENT_STRING_UTILS_H

#include <string>
#include <vector>
#include <regex>

std::vector<std::string> split(const std::string& input, const std::string& regex) {
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
    return {first, last};
}

#endif //TWAIN_RABBITMQ_CLIENT_STRING_UTILS_H
