//
// Created by vmodev on 18/02/2020.
//

#include <iostream>
#include "twain_message_handle.h"
#include <chrono>
#include <string>
#include <cpprest/http_client.h>

void twain_message_handle::message_callback(const char *body) {
    web::json::value json_data = web::json::value::parse(body);

    std::string data_string = json_data.to_string();

    long start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const char *time = std::to_string(start).c_str();

    std::cout << "Command: " << json_data.at("command").as_string().c_str() << std::endl;

    const std::string command = json_data.at("command").as_string().c_str();
    if (std::strcmp(command.c_str(), "deploy_source") == 0) {
        auto json_data_child = json_data.at("data").as_object();
        std::string url = json_data_child.at("url").as_string().c_str();
        auto_download_and_unzip_->run_script(url.c_str(), time);
        auto_download_and_unzip_->unzip_source_code(time, json_data.at("node").as_string().c_str());
    } else if (std::strcmp(command.c_str(), "deploy_model") == 0) {
        auto json_data_child = json_data.at("data").as_object();
        std::string url = json_data_child.at("url").as_string();
        auto_download_and_unzip_->run_script(url.c_str(), time);
        auto_download_and_unzip_->unzip_model(time, json_data.at("node").as_string().c_str());
    } else if (std::strcmp(command.c_str(), "run_code") == 0) {
        auto_download_and_unzip_->run_service(json_data.at("node").as_string().c_str());
    }

}

twain_message_handle::twain_message_handle() {
    auto_download_and_unzip_ = new auto_download_and_unzip();
}