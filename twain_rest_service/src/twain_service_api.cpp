//
// Created by hoang on 9/11/2020.
//

#include "twain_config.h"
#include <iostream>
#include "twain_service_api.h"

void twain_service_api::login(const char *email, const char *password, web::json::value *response_body) {
    web::http::uri_builder uri_builder_(U(AUTHENTICATE));
    web::http::http_request http_request_(web::http::methods::POST);
    http_request_.set_request_uri(uri_builder_.to_string());
    http_request_.headers().add(web::http::header_names::content_type,
                                web::http::details::mime_types::application_json);
    web::json::value value = web::json::value::object();
    value[U("email")] = web::json::value::string(U(email));
    value[U("password")] = web::json::value::string(U(password));
    http_request_.set_body(value);
    this->http_client_->request(http_request_).then([=](web::http::http_response response) {

        if (response.status_code() == web::http::status_codes::OK) {
            web::json::value body = response.extract_json().get();
            *response_body = body;
        }
    }).wait();
}

twain_service_api::twain_service_api() {
    this->http_client_ = new web::http::client::http_client(U(BASE_URL));
}

void
twain_service_api::search_device(const char *access_token, const char *device_code, web::json::value *response_body) {
    web::http::uri_builder uri_builder_(U(SEARCH_DEVICE));
    web::http::http_request http_request_(web::http::methods::GET);
    uri_builder_.append_query("code", device_code);
    http_request_.set_request_uri(uri_builder_.to_string());
    http_request_.headers().add(web::http::header_names::content_type,
                                web::http::details::mime_types::application_json);
    http_request_.headers().add("x-access-token", access_token);

    this->http_client_->request(http_request_).then([=](web::http::http_response response) {
        if (response.status_code() == web::http::status_codes::OK) {
            web::json::value body = response.extract_json().get();
            *response_body = body;
        }
    }).wait();
}
