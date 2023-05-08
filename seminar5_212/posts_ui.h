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
#include <QHBoxLayout>
#include "service.h"
#include <map>

using std::map;

class PostUI : public QWidget {
Q_OBJECT
    Service &service;
    QListWidget *postsList;
    vector<Post> currentElements;

    QLineEdit *titleEdit;
    QLineEdit *authorEdit;
    QTextEdit *contentEdit;

    QPushButton *addButton;
    QPushButton *updateButton;
    QLineEdit *filterEdit;
    QHBoxLayout *authorsLayout;
    std::map<string, QPushButton *> authorButtons;


    void populateList(vector<Post> elements);

    void connect();

    int selectedIndex();

    void setupUI(QWidget *widget);

    /*
     * Add a button for each existing author. When you push a button, a dialog box will tell you how many posts that author has.
     */
    void addAuthors();

public:
    PostUI(Service &service) : service{service} {
        this->setupUI(this);
    }


};

#endif //SEMINAR5_212_POSTS_UI_H
