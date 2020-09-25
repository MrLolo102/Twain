//
// Created by hoang on 9/15/2020.
//

#include <iostream>
#include "twain_amqp_listen.h"
#include "twain_message_handle.h"
#include "twain_service_config.h"

int main(int argc, char const *const *argv){
    std::cout << "Starting listen twain rabbitmq" << std::endl;
    const char *queueName = argv[1];
    auto *amqpListen = new twain_amqp_listen(RABBIT_MQ_URL, PORT, EXCHANGE, queueName);
    twain_amqp_listen_callback *twainMessageCallback = new twain_message_handle();

    amqpListen->start_listen(twainMessageCallback);
    return 0;
}