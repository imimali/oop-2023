//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_CHAT_WINDOW_H
#define SEMINAR6_CHAT_CHAT_WINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>

#include "observer.h"
#include "user.h"
#include "chat_session.h"

class ChatWindow : public QWidget, public Observer {
    User &user;
    ChatSession &session;

    QListWidget *messagesList = new QListWidget;
    QPushButton *sendButton = new QPushButton("Send");
    QTextEdit *messageEdit = new QTextEdit;

    void setup() {
        auto mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(this->messagesList);

        auto editLayout = new QHBoxLayout;
        editLayout->addWidget(this->messageEdit);
        editLayout->addWidget(this->sendButton);
        mainLayout->addLayout(editLayout);

        this->setWindowTitle(QString::fromStdString(this->user.get_username()));
        this->resize(500, 500);
        this->messageEdit->setFixedHeight(100);
    }

    void connect() {

        QObject::connect(this->sendButton, &QPushButton::clicked, [this]() {
            auto message = this->messageEdit->toPlainText().toStdString();
            this->session.add_message(this->user, message);
            this->messageEdit->clear();
        });
    }

    void populate(){
        this->messagesList->clear();
        for(auto&message:this->session.get_messages()){
            auto item = new QListWidgetItem(QString::fromStdString(message.get_user().get_username()+":"+message.get_text()));
            this->messagesList->addItem(item);
        }
    }

public:
    ChatWindow(User &user, ChatSession &session) : user{user}, session{session} {
        this->session.register_observer(this);
        this->setup();
        this->connect();
    }

    ~ChatWindow() {
        this->session.unregister_observer(this);
    }

    void update() override {
        this->populate();
    }

};

#endif //SEMINAR6_CHAT_CHAT_WINDOW_H
