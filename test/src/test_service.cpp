//
// Created by Chung Hoang on 9/15/20.
//

#include <iostream>
#include <cpprest/http_msg.h>
#include <cpprest/http_client.h>
#include "twain_message_handle.h"

std::string EXEC_CMD_DEMO(const char *cmd){
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

int main(int argc, char const *const *argv){

    std::cout << "Hello, Test" << std::endl;
//    web::http::client::http_client *httpClient = new web::http::client::http_client(U("https://google.com"));
//    httpClient->request(web::http::methods::GET).then([=](web::http::http_response response){
//        auto body = response.extract_string().get();
//        std::cout << "Response: " << body << std::endl;
//    }).wait();
//    char *raw_content = "{\"data\":{\"message\":\"Success\"}}";
//    web::json::value json_content = web::json::value::parse(raw_content);
//    auto data = json_content.at("data").as_object();
//    auto message = data.at("message").as_string().c_str();
//    std::cout << "Message: " << message << std::endl;

//    twain_message_handle *message_handle = new twain_message_handle("", "", "", "");
//    const char * body = "{\"command\": \"deploy_source\",\"key\": \"String\",\"node\": \"String\",\"data\": {\"url\": \"https://www.google.com\"}}";
//    message_handle->message_callback(body);
//    std::cout << "Create folder: " << EXEC_CMD_DEMO("mkdir DEMO_FOLDER") << std::endl;

    std::stringstream  demo;
    demo << "ABC" << "BDC";
    std::cout << demo.str().c_str() << std::endl;

    return 0;
}