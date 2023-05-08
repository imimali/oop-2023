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
    mainVBoxLayout->addLayout(hLayout);

    this->populateList(this->service.get_all());
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

