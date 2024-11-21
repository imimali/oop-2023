//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR7_2_CHAT_WINDOW_H
#define SEMINAR7_2_CHAT_WINDOW_H

#include <QWidget>
#include <QListView>
#include <QAbstractItemModel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "custom_model.h"

class ChatWindow : public QWidget {

    QListView *messagesView = new QListView;
    ChatModel *itemModel;
    QPushButton *sendButton = new QPushButton("Send");
    QTextEdit *messageEdit = new QTextEdit;

    void setupUI() {
        this->itemModel = new ChatModel;
        this->messagesView->setModel(this->itemModel);
        for(int i=0;i<100000;i++){
            //this->itemModel->addMessage();
        }
        auto mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(this->messagesView);
        auto editLayout = new QHBoxLayout;
        editLayout->addWidget(this->messageEdit);
        editLayout->addWidget(this->sendButton);
        mainLayout->addLayout(editLayout);
        this->resize(500,500);
    }

    void connect(){
        QObject::connect(this->sendButton,&QPushButton::clicked,[this](){
            this->itemModel->addMessage();
        }

        );
    }
public:
    ChatWindow() {
        this->setupUI();
this->connect();
    }

};

#endif //SEMINAR7_2_CHAT_WINDOW_H
