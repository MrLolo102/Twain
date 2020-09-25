//
// Created by vmodev on 18/02/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_H
#define TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_H

#include <amqp.h>
#include <amqp_tcp_socket.h>
#include "twain_amqp_listen_callback.h"

class twain_amqp_listen {
private:
    const char *host_name;
    uint8_t port;
    int status;
    const char *exchange;
    const char *s_queue_name;
    amqp_socket_t *amqp_socket = NULL;
    amqp_connection_state_t amqp_connection_state;
    amqp_bytes_t queue_name;
public:
    twain_amqp_listen(const char *host_name, uint16_t port, const char *exchange, const char *s_queue_name);

    void start_listen(twain_amqp_listen_callback *callback);
};


#endif //TWAIN_RABBITMQ_CLIENT_TWAIN_AMQP_LISTEN_H
