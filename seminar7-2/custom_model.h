//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR7_2_CUSTOM_MODEL_H
#define SEMINAR7_2_CUSTOM_MODEL_H

#include <QAbstractItemModel>
#include <vector>
#include <iostream>
#include "message.h"
class ChatModel:public QAbstractItemModel{
    std::vector<Message> messages;

public:
    QModelIndex index(int row,
                      int column,
                      const QModelIndex &parent = QModelIndex())
                      const override{
        return this->createIndex(row,0);
    }

    QModelIndex parent(const QModelIndex &child)
    const override{
        return {};
    }

    int rowCount(const QModelIndex &parent = QModelIndex())
    const override{
        return this->messages.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex())
    const override{
        return 1;
    }

    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole)
                  const override{
        //std::cout << "asdfsdfdsfdsfdfsdsfdsfdsff\n";
        if (role==Qt::DisplayRole){
            std::cout << "asdfsdfdsfdsfdfsdsfdsfdsff"<<index.row();
            return QString::fromStdString(this->messages.at(index.row()).get_text());
        }
        if(role==Qt::ForegroundRole){
            return QBrush(Qt::cyan);
        }
        if(role==Qt::BackgroundRole){
            //return QBrush(Qt::w);
        }
        return {};

    }

    void addMessage() {
        Message message{User{"a",1},"sdvcxvcvx"};
        this->messages.push_back(message);
        this->insertRow(this->messages.size() - 1);
        auto messageString ="message";
        //std::cout << messageString + "\n";
        auto index = this->index(this->rowCount() - 1, 0);
        this->setData(index, QString::fromStdString(messageString));
        emit dataChanged(index, index);
    }

};
#endif //SEMINAR7_2_CUSTOM_MODEL_H
