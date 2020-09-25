//
// Created by vmodev on 18/02/2020.
//

#ifndef TWAIN_RABBITMQ_CLIENT_AUTO_DOWNLOAD_AND_UNZIP_H
#define TWAIN_RABBITMQ_CLIENT_AUTO_DOWNLOAD_AND_UNZIP_H


class auto_download_and_unzip {
private:
public:
    auto_download_and_unzip();

    void run_script(const char *url, const char *time);

    void unzip_source_code(const char *fileName, const char *fileMapName);

    void unzip_model(const char *fileName, const char *fileMapName);

    void run_service(const char *nodeName);

    std::string EXEC(const char *cmd);
};


#endif //TWAIN_RABBITMQ_CLIENT_AUTO_DOWNLOAD_AND_UNZIP_H
