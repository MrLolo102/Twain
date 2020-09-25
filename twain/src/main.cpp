//
// Created by vmodev on 18/02/2020.
//

#include <iostream>
#include <cpprest/http_client.h>
#include "twain_service_api.h"
#include "twain_command.h"


int main(int argc, char const *const *argv) {

    const char *start_type = argv[1];

    if (std::strcmp(start_type, "get_device_id") == 0) {
        std::cout << twain_command::getInstance().get_device_id() << std::endl;
    } else if (std::strcmp(start_type, "set_up") == 0) {
        std::string email;
        std::string password;

        std::cout << "Enter your email:";
        std::cin >> email;
        std::cout << "Enter your password:";
        std::cin >> password;
        web::json::value *response_login = new web::json::value;
        twain_service_api::getInstance().login(email.c_str(), password.c_str(), response_login);
        const char *access_token = response_login->at("data").as_object().at("access_token").as_string().c_str();
        std::string device_id = twain_command::getInstance().get_device_id();
        std::cout << "Device Id: " << device_id << std::endl;
        twain_service_api::getInstance().search_device(access_token, device_id.c_str(), response_login);
        const char *message = response_login->at("message").as_string().c_str();
        std::cout << "Message: " << message << std::endl;

        int size_device = response_login->at("data").as_object().at("items").as_array().size();
        if (size_device > 0){
            std::cout << "Setup device: " << twain_command::getInstance().set_up_device(device_id.c_str());
        }
    }

    return 0;
}
