//
// Created by vmodev on 18/02/2020.
//

#include <cstdint>
#include "twain_amqp_listen.h"
#include "utils.h"
#include "twain_amqp_listen_callback.h"

twain_amqp_listen::twain_amqp_listen(const char *host_name, uint16_t port, const char *exchange,
                                     const char *s_queue_name) {
    this->host_name = host_name;
    this->port = port;
    this->exchange = exchange;
    this->s_queue_name = s_queue_name;

    amqp_connection_state = amqp_new_connection();
    amqp_socket = amqp_tcp_socket_new(amqp_connection_state);
    if (!amqp_socket) {
        die("Creating TCP Socket");
    }
    status = amqp_socket_open(amqp_socket, host_name, port);
    if (status) {
        die("Opening TCP Socket");
    }
    die_on_amqp_error(amqp_login(amqp_connection_state, "/", 0, 131072, 0, AMQP_SASL_METHOD_PLAIN, "guest", "guest"),
                      "Logging in");
    amqp_channel_open(amqp_connection_state, 1);
    die_on_amqp_error(amqp_get_rpc_reply(amqp_connection_state), "Opening channel");
}

void twain_amqp_listen::start_listen(twain_amqp_listen_callback *callback) {
    amqp_queue_declare_ok_t *amqpQueueDeclareOk = amqp_queue_declare(amqp_connection_state, 1,
                                                                     amqp_empty_bytes, 0, 0, 0,
                                                                     1, amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(amqp_connection_state), "Declaring queue");
    queue_name = amqp_bytes_malloc_dup(amqpQueueDeclareOk->queue);
    if (queue_name.bytes == NULL) {
        std::cout << stderr << " Out of memory while copy queue name" << "\n";
        return;
    }

    die_on_amqp_error(amqp_get_rpc_reply(amqp_connection_state), "Binding queue");
    amqp_basic_consume(amqp_connection_state, 1, amqp_cstring_bytes(this->s_queue_name), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);
    die_on_amqp_error(amqp_get_rpc_reply(amqp_connection_state), "Consuming");

    for (;;) {
        amqp_rpc_reply_t res;
        amqp_envelope_t amqpEnvelope;

        amqp_maybe_release_buffers(amqp_connection_state);
        res = amqp_consume_message(amqp_connection_state, &amqpEnvelope, NULL, 0);
        if (AMQP_RESPONSE_NORMAL != res.reply_type) {
            break;
        }
        std::cout << (char *) amqpEnvelope.message.body.bytes << "\n";
        char *body = (char *) amqpEnvelope.message.body.bytes;
        callback->message_callback(body);
        amqp_destroy_envelope(&amqpEnvelope);
    }
    amqp_bytes_free(queue_name);
    die_on_amqp_error(amqp_channel_close(amqp_connection_state, 0, AMQP_REPLY_SUCCESS), "Closing channel");
    die_on_amqp_error(amqp_connection_close(amqp_connection_state, AMQP_REPLY_SUCCESS), "Closing connection");
    die_on_error(amqp_destroy_connection(amqp_connection_state), "Ending connection");
}
