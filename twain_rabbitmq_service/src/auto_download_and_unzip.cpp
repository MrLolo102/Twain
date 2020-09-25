//
// Created by vmodev on 18/02/2020.
//

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include "auto_download_and_unzip.h"

auto_download_and_unzip::auto_download_and_unzip() {
}

void auto_download_and_unzip::run_script(const char *url, const char *time) {
    char *tmpURL = strdup(url);
    char *subURL = std::strtok(tmpURL, "&");

    std::vector<char *> v;
    while (subURL != NULL) {
        v.push_back(subURL);
        subURL = strtok(NULL, "&");
    }
    char desURL[strlen(url) + v.size()];
    strcpy(desURL, v[0]);
    strcat(desURL, "\\&");
    for (int i = 1; i < v.size() - 1; ++i) {
        strcat(desURL, v[i]);
        strcat(desURL, "\\&");
    }
    strcat(desURL, v[v.size() - 1]);
    std::stringstream command;
    command << "DIR=\"~/tmp/\"\n"
               "if [ ! -d \"$DIR\" ]; then\n"
               "  mkdir ~/tmp\n"
               "fi\n"
               "\n"
               "mkdir ~/tmp/" << time << "\n"
                                         "if ! [ -x \"$(command -v wget)\" ]; then\n"
                                         "  sudo apt install wget\n"
                                         "fi\n"
                                         "wget "
            << "\"" << url << "\"" << " -O ~/tmp/" << time << "/" << time << ".zip ";
    std::cout << EXEC(command.str().c_str()) << std::endl;
    delete (tmpURL);
    delete (subURL);
}

void auto_download_and_unzip::unzip_source_code(const char *fileName, const char *fileMapName) {
    std::stringstream command;
    command << "if ! [ -x \"$(command -v unzip)\" ]; then\n"
               "  sudo apt install unzip\n"
               "fi\n"
               "\n"
               "if [ ! -d ~/source_code/ ]; then\n"
               "    mkdir ~/source_code\n"
               "fi\n"
               "\n"
               "unzip -o ~/tmp/" << fileName << "/" << fileName << ".zip -d ~/source_code/" << fileMapName;

    std::cout << EXEC(command.str().c_str()) << std::endl;
}

void auto_download_and_unzip::unzip_model(const char *fileName, const char *fileMapName) {
    std::stringstream command;
    command << "if ! [ -x \"$(command -v unzip)\" ]; then\n"
               "  sudo apt install unzip\n"
               "fi\n"
               "\n"
               "if [ ! -d ~/model/ ]; then\n"
               "    mkdir ~/model\n"
               "fi\n"
               "\n"
               "unzip -o ~/tmp/" << fileName << "/" << fileName << ".zip -d ~/model/" << fileMapName;
    std::cout << EXEC(command.str().c_str()) << std::endl;
}

void auto_download_and_unzip::run_service(const char *nodeName) {
    std::stringstream command;
    command << "bash ~/source_code/" << nodeName << "/run.sh";
    std::cout << EXEC(command.str().c_str()) << std::endl;
}

std::string auto_download_and_unzip::EXEC(const char *cmd) {
    char buffer[128];
    std::string result = "";
    FILE *pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}