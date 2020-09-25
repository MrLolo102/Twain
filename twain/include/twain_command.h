//
// Created by hoang on 9/15/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_TWAIN_COMMAND_H
#define TWAIN_RABBITMQ_CLIENT_TWAIN_COMMAND_H


#include <string>

class twain_command {
public:
    static twain_command& getInstance()
    {
        static twain_command    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

private:
    twain_command(){}

private:
    std::string exec(const char *cmd);

public:
    std::string set_up_device(const char *device_id);
    std::string get_device_id();
public:
    twain_command(twain_command const &) = delete;

    void operator=(twain_command const &) = delete;
};


#endif //TWAIN_RABBITMQ_CLIENT_TWAIN_COMMAND_H
