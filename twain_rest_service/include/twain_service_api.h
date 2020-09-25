//
// Created by hoang on 9/11/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_TWAIN_SERVICE_API_H
#define TWAIN_RABBITMQ_CLIENT_TWAIN_SERVICE_API_H

#include <string>
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"

class twain_service_api {
public:
    void login(const char *email, const char *password, web::json::value *response_body);
    void search_device(const char *access_token, const char *device_code,web::json::value *response_body);

    static twain_service_api& getInstance()
    {
        static twain_service_api    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

private:
    twain_service_api();

    web::http::client::http_client *http_client_;
public:
    twain_service_api(twain_service_api const &) = delete;

    void operator=(twain_service_api const &) = delete;
};


#endif //TWAIN_RABBITMQ_CLIENT_TWAIN_SERVICE_API_H
