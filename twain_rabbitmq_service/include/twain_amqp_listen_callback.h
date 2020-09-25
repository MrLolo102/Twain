//
// Created by vmodev on 18/02/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_CALLBACK_H
#define TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_CALLBACK_H

class twain_amqp_listen_callback {
public:
    virtual void message_callback(const char *body) = 0;
};

#endif //TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_CALLBACK_H
