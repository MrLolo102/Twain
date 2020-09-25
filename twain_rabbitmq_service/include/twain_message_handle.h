//
// Created by vmodev on 18/02/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_TWAIN_MESSAGE_HANDLE_H
#define TWAIN_RABBITMQ_CLIENT_TWAIN_MESSAGE_HANDLE_H

#include "twain_amqp_listen_callback.h"
#include "auto_download_and_unzip.h"
class twain_message_handle : public twain_amqp_listen_callback {
private:
    auto_download_and_unzip * auto_download_and_unzip_;
public:
    twain_message_handle();
    void message_callback(const char *body) override ;
};


#endif //TWAIN_RABBITMQ_CLIENT_TWAIN_MESSAGE_HANDLE_H
