//
// Created by Mali Imre Gergely on 15.05.2023.
//

#include "chat_window.h"

#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

void ChatWindow::setup(QWidget *p) {
    auto mainLayout = new QVBoxLayout(p);
    this->messagesList = new QListWidget;
    this->messageEdit = new QTextEdit;
    this->sendButton = new QPushButton("Send");

    mainLayout->addWidget(this->messagesList);
    auto editlayout = new QHBoxLayout;
    editlayout->addWidget(this->messageEdit);
    editlayout->addWidget(this->sendButton);

    mainLayout->addLayout(editlayout);

    this->connect();

}

void ChatWindow::sendMessage() {
    auto text = this->messageEdit->toPlainText().toStdString();
    Message m{text};
    this->session.add_message(this->user, m);
    this->session.notify();
}

void ChatWindow::populateList() {
    auto messages = this->session.get_messages();
    this->messagesList->clear();
    for (auto &pair: messages) {
        auto label =
                pair.second.get_timestamp_string() + " " + pair.first.get_username() + ": " + pair.second.get_message();

        this->messagesList->addItem(QString::fromStdString(label));
    }

}

void ChatWindow::connect() {
    QObject::connect(this->sendButton, &QPushButton::clicked, [this]() {
        this->sendMessage();
        this->messageEdit->clear();
    });
}
