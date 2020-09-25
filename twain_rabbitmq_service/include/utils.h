//
// Created by vmodev on 18/02/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_UTILS_H
#define TWAIN_RABBITMQ_CLIENT_UTILS_H

#include <amqp.h>
#include <iostream>
#include <string>
#include <cstdarg>

void die_on_amqp_error(amqp_rpc_reply_t x, const char *context) {
    switch (x.reply_type) {
        case AMQP_RESPONSE_NORMAL:
            return;
        case AMQP_RESPONSE_NONE:
            std::cout << stderr << context << " :missing RPC reply type!" << "\n";
            break;
        case AMQP_RESPONSE_LIBRARY_EXCEPTION:
            std::cout << stderr << context << ":" << x.library_error << "\n";
            break;
        case AMQP_RESPONSE_SERVER_EXCEPTION:
            switch (x.reply.id) {
                case AMQP_CONNECTION_CLOSE_METHOD: {
                    amqp_connection_close_t *m = (amqp_connection_close_t *) x.reply.decoded;
                    std::cout << stderr << context << ": server connection error " << m->reply_code << " message:"
                              << m->reply_text.len << " " << (char *) m->reply_text.bytes << "\n";
                    break;
                }
                case AMQP_CHANNEL_CLOSE_METHOD: {
                    amqp_channel_close_t *m = (amqp_channel_close_t *) x.reply.decoded;
                    std::cout << stderr << context << ": server channel error " << m->reply_code << " message: "
                              << m->reply_text.len << " " << (char *) m->reply_text.bytes << "\n";
                    break;
                }
                default:
                    std::cout << stderr << context << ": unknown server error, method id " << x.reply.id << "\n";
                    break;
            }
            break;

    }
    exit(1);
}

void die(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    va_end(ap);
    abort();
}

void die_on_error(int x, const char *context) {
    if (x < 0) {
        std::cout << stderr << context << " : " << amqp_error_string2(x);
        exit(1);
    }
}

#endif //TWAIN_RABBITMQ_CLIENT_UTILS_H
