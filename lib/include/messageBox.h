//
// Created by dev on 19/05/24.
//
#include <memory>
#include <string>

#ifndef _MESSAGEBOX_H_
#define _MESSAGEBOX_H_

namespace comm_ipc{
typedef struct {
    pid_t process_id;
    char text[100];
} message;

class messageBox final{
private:
    messageBox* _messageBox;
    messageBox(){};

public:
    ~messageBox(){};
    messageBox* getInstance();
    bool SendMessage(pid_t id, std::string value);
    std::string receiveNextMessage();
};

}

#endif //_MESSAGEBOX_H_
