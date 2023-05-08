//
// Created by Mali Imre Gergely on 08.05.2023.
//

#ifndef SEMINAR5_212_POSTS_UI_H
#define SEMINAR5_212_POSTS_UI_H
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "service.h"
class PostUI:public QWidget{
    Q_OBJECT
    Service& service;
    QListWidget* postsList;

    QLineEdit* titleEdit;
    QLineEdit* authorEdit;
    QTextEdit* contentEdit;

    QPushButton* addButton;
    QPushButton* updateButton;
    QLineEdit* filterEdit;
    void populateList(vector<Post> elements);
    void connect();
    int selectedIndex();

    void setupUI(QWidget* widget);
public:
    PostUI(Service& service):service{service}{
        this->setupUI(this);
    }



};

#endif //SEMINAR5_212_POSTS_UI_H
