#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>
#include <vector>

struct MessageInfo {
    std::string cmd;
    std::vector<std::string> params;
};

class Client{
    private:
        int fd;
        bool valid;
        bool invite;
        std::string nickname;
        std::string realname;
        std::string username;
        std::string currentChannel;
        time_t signonTime;
        time_t idleTime;

    public:
        Client(int fd);
        ~Client();
        int getSocket();
        void setValid(bool value);
        bool getValid();
        void setNickname(std::string nickname);      
        std::string getNickname();
        std::string &getRealname();
        void setUsername(std::string username, std::string realname);
        std::string &getUsername();
        std::string getCurrentchannel(); //
        void setCurrentchannel(std:: string channelname);
        bool getInvite();
        void setInvite(bool value);

        /* debug */
        void showInfo();

        /* time */
        void updateSignonTime();
        void updateIdleTime();
        time_t getIdleTime();
        time_t getSignonTime();

};

#endif
