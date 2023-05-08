//
// Created by Mali Imre Gergely on 08.05.2023.
//
#include "posts_ui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <algorithm>
#include <iostream>
#include <QMessageBox>
#include <QGroupBox>

void PostUI::setupUI(QWidget *widget) {
    widget->resize(800, 700);
    auto mainVBoxLayout = new QVBoxLayout(widget);

    this->postsList = new QListWidget;


    this->filterEdit = new QLineEdit;
    this->filterEdit->setPlaceholderText("Filter by author");
    this->filterEdit->setFixedHeight(36);
    mainVBoxLayout->addWidget(this->filterEdit);
    mainVBoxLayout->addWidget(this->postsList);

    auto hLayout = new QHBoxLayout;
    auto formLayout = new QFormLayout;

    this->authorEdit = new QLineEdit;
    this->titleEdit = new QLineEdit;
    this->contentEdit = new QTextEdit;

    this->authorEdit->setFixedHeight(36);
    this->titleEdit->setFixedHeight(36);

    this->authorEdit->setFixedWidth(256);
    this->titleEdit->setFixedWidth(256);


    formLayout->addRow(QString("Title"), this->titleEdit);
    formLayout->addRow(QString("Author"), this->authorEdit);
    formLayout->addRow(QString("Content"), this->contentEdit);

    hLayout->addLayout(formLayout);

    this->addButton = new QPushButton("Add");
    this->updateButton = new QPushButton("Update");
    hLayout->addWidget(this->addButton);
    hLayout->addWidget(this->updateButton);

    this->authorsLayout = new QHBoxLayout;
    auto authorsContainer = new QGroupBox("Authors");
    authorsContainer->setLayout(this->authorsLayout);
    mainVBoxLayout->addLayout(hLayout);
    mainVBoxLayout->addWidget(authorsContainer);

    this->populateList(this->service.get_all());
    this->addAuthors();
    this->connect();
}

void PostUI::populateList(vector<Post> elements) {
    this->currentElements = elements;
    this->postsList->clear();
    QStringList result;
    std::transform(elements.begin(), elements.end(), std::back_inserter(result),
                   [](const Post &p) {
                       return QString::fromStdString(
                               std::to_string(p.get_id()) + " - " + p.get_author() + ": " + p.get_title() + " " +
                               p.get_content().substr(0, 10) + "...");//only display the first ten characters
                   });

    this->postsList->addItems(result);
}

void PostUI::connect() {
    QObject::connect(this->postsList,
                     &QListWidget::itemSelectionChanged,
                     [this]() {
                         int index = this->selectedIndex();
                         auto element = this->currentElements.at(index);
                         this->titleEdit->setText(QString::fromStdString(element.get_title()));
                         this->authorEdit->setText(QString::fromStdString(element.get_author()));
                         this->contentEdit->setText(QString::fromStdString(element.get_content()));
                     });

    QObject::connect(this->addButton,
                     &QPushButton::clicked,
                     [this]() {
                         auto title = this->titleEdit->text().toStdString();
                         auto author = this->authorEdit->text().toStdString();
                         auto content = this->contentEdit->toPlainText().toStdString();

                         if (title.empty() || author.empty() || content.empty()) {
                             QMessageBox::information(this, "Something went wrong", "Something went wrong");
                             return;
                         }

                         this->service.add(title, author, content);

                         this->populateList(this->service.get_all());
                         this->addAuthors();
                         this->titleEdit->clear();
                         this->authorEdit->clear();
                         this->contentEdit->clear();
                     });
    QObject::connect(this->updateButton,
                     &QPushButton::clicked, [this]() {
                int index = this->selectedIndex();
                if (index == -1) {
                    QMessageBox::information(this, "Nothing selected", "Nothing selected");
                    return;
                }
                auto element = this->currentElements.at(index);

                auto title = this->titleEdit->text().toStdString();
                auto author = this->authorEdit->text().toStdString();
                auto content = this->contentEdit->toPlainText().toStdString();

                if (title.empty() || author.empty() || content.empty()) {
                    QMessageBox::information(this, "Something went wrong", "Something went wrong");
                    return;
                }

                this->service.update(element.get_id(), title, author, content);
                this->populateList(this->service.get_all());
                this->addAuthors();

                this->titleEdit->clear();
                this->authorEdit->clear();
                this->contentEdit->clear();
            });

    QObject::connect(this->filterEdit,
                     &QLineEdit::textChanged,
                     [this](const QString &text) {
                         auto stringText = text.toStdString();
                         auto filtered = this->service.filter_by_author(stringText);
                         this->populateList(filtered);
                     });
}


int PostUI::selectedIndex() {
    auto index = this->postsList->selectionModel()->currentIndex();
    return index.row();
}

void PostUI::addAuthors() {
    auto authors = this->service.get_authors();
    for (const auto &author: authors) {
        // skip existing authors
        if (this->authorButtons.find(author) != this->authorButtons.end()) {
            continue;
        }
        auto authorButton = new QPushButton(QString::fromStdString(author));
        this->authorsLayout->addWidget(authorButton);
        this->authorButtons[author] = authorButton;
        //!!!!!!! try what happens if you capture author by reference
        QObject::connect(authorButton, &QPushButton::clicked, this, [author, this]() {

            int nrPosts = this->service.filter_by_author(author).size();
            std::cout << "authorrr" << author << std::endl;
            auto text = "Author '" + author + "' has " + std::to_string(nrPosts) + " post(s).";
            QMessageBox::information(this, QString::fromStdString(text), QString::fromStdString(text));
        });
    }
    vector<string> authorsToRemove;
    for (const auto &pair: this->authorButtons) {
        //author in button map but not in authors returned from the service, so it should be reomved
        if (authors.find(pair.first) == authors.end()) {
            authorsToRemove.push_back(pair.first);
        }
    }
    for (const auto &author: authorsToRemove) {
        delete this->authorButtons[author];
        this->authorButtons.erase(author);
    }
}

