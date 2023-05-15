//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_CHAT_WINDOW_H
#define CHAT_APP_CHAT_WINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include "user.h"
#include "message.h"
#include "observer.h"
#include "chat_session.h"


class ChatWindow : public QWidget, public Observer {
Q_OBJECT
    User &user;
    ChatSession &session;
    QListWidget *messagesList;
    QPushButton *sendButton;
    QTextEdit *messageEdit;

    void setup(QWidget *p);

    void populateList();

    void connect();

public:
    ChatWindow(User &user1, ChatSession &session) : session{session}, user{user1} {
        session.register_observer(this);
        this->setup(this);
    }

    void sendMessage();

    void update() override {
        this->populateList();
    }


};


#endif //CHAT_APP_CHAT_WINDOW_H
