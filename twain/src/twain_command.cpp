//
// Created by hoang on 9/15/2020.
//

#include <stdexcept>
#include "twain_command.h"
#include "string_utils.h"
#include <iostream>
#include <fstream>

std::string twain_command::exec(const char *cmd) {
    char buffer[128];
    std::string result = "";
    FILE *pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

std::string twain_command::get_device_id() {
    std::string device_id = "";
#ifdef __APPLE__
    std::string command_output = exec("diskutil info -all |grep -e \"Volume UUID\"");
    std::vector<std::string> list_device = split(command_output, "\n");
    if (list_device.empty())
        return device_id;
    const std::string device = list_device.at(0);
    std::vector<std::string> list_param = split(device, ":");
    if (list_param.empty() || list_param.size() < 2)
        return device_id;
    device_id = list_param.at(1);
    device_id.erase(std::remove(device_id.begin(), device_id.end(), ' '), device_id.end());
    return device_id;
#elif __linux__
    std::string command_output = exec("sudo blkid");
    std::vector<std::string> list_device = split(command_output, "\n");
    if (list_device.empty())
        return "";
    const std::string device = list_device.at(0);
    std::vector<std::string> list_param = split(device, " ");
    if (list_param.empty() || list_param.size() < 3)
        return "";
    const std::string uuid = list_param.at(1);
    std::vector<std::string> uuid_param = split(uuid, "=");
    if (uuid_param.empty() || uuid_param.size() < 2)
        return "";
    device_id = uuid_param.at(1);
    device_id.erase(std::remove(device_id.begin(), device_id.end(), '"'), device_id.end());
    return device_id;
#endif
}

std::string twain_command::set_up_device(const char *device_id) {
    std::cout << "Device Id: " << device_id << std::endl;
#ifdef __linux__
    std::ofstream twain_service("/lib/systemd/system/twain.service");
    twain_service << "[Unit]" << std::endl << "Description=Twain Device Service" << std::endl << "After=network.target"
                  << std::endl << "[Service]"
                  << std::endl << "Type=simple" << std::endl << "Restart=on-failure" << std::endl
                  << "ExecStart=/usr/bin/twain_service " << device_id << std::endl
                  << "Environment=PYTHONUNBUFFERED=1" << std::endl << "Restart=on-failure" << std::endl
                  << "RestartSec=2s" << std::endl
                  << "[Install]" << std::endl << "WantedBy=multi-user.target" << std::endl;
    twain_service.close();
#elif __APPLE__
#endif
    std::stringstream command;
    command << "sudo chmod 644 /lib/systemd/system/twain.service" << std::endl << "" << std::endl
            << "systemctl enable twain.service" << std::endl << "systemctl start twain.service";
    return exec(command.str().c_str());
}
