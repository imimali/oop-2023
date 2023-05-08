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
    widget->resize(700, 700);
    auto mainVBoxLayout = new QVBoxLayout(widget);

    this->postsList = new QListWidget;
    QFont f{"Verdana", 20};
    this->postsList->setFont(f);


    this->filterEdit = new QLineEdit;
    mainVBoxLayout->addWidget(this->filterEdit);
    mainVBoxLayout->addWidget(this->postsList);

    auto hLayout = new QHBoxLayout;
    auto formLayout = new QFormLayout;

    this->authorEdit = new QLineEdit;
    this->titleEdit = new QLineEdit;
    this->contentEdit = new QTextEdit;

    this->authorEdit->setFont(f);
    this->titleEdit->setFont(f);
    this->contentEdit->setFont(f);

    formLayout->addRow(QString("Title"), this->titleEdit);
    formLayout->addRow(QString("Author"), this->authorEdit);
    formLayout->addRow(QString("Content"), this->contentEdit);

    hLayout->addLayout(formLayout);

    this->addButton = new QPushButton("Add");
    this->updateButton = new QPushButton("Update");
    this->addButton->setFont(f);
    this->updateButton->setFont(f);
    hLayout->addWidget(this->addButton);
    hLayout->addWidget(this->updateButton);
    mainVBoxLayout->addLayout(hLayout);

    this->populateList(this->service.get_all());
    this->connect();
}

void PostUI::populateList(vector<Post> elements) {
    this->postsList->clear();
    QStringList result;
    std::transform(elements.begin(), elements.end(), std::back_inserter(result),
                   [](const Post &p) {
                       return QString::fromStdString(
                               std::to_string(p.get_id()) + " - " + p.get_title() + " " + p.get_author() + " " +
                               p.get_content().substr(0, 10) + "...");
                   });

    this->postsList->addItems(result);
}

void PostUI::connect() {
    QObject::connect(this->postsList,
                     &QListWidget::itemSelectionChanged,
                     [this]() {
                         int index = this->selectedIndex();
                         auto elements = this->service.get_all();
                         auto element = elements.at(index);
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
                             //QMessageBox::warning(this,"Something went wrong","Something went wrong");
                             QMessageBox::information(this, "Something went wrong", "Something went wrong");
                             return;
                         }

                         this->service.add(title, author, content);

                         this->populateList(this->service.get_all());
                     });
    QObject::connect(this->updateButton,
                     &QPushButton::clicked, [this]() {
                int index = this->selectedIndex();
                if (index == -1) {
                    QMessageBox::information(this, "Nothing selected", "Nothing selected");
                    return;
                }
                auto elements = this->service.get_all();
                auto element = elements.at(index);

                auto title = this->titleEdit->text().toStdString();
                auto author = this->authorEdit->text().toStdString();
                auto content = this->contentEdit->toPlainText().toStdString();

                if (title.empty() || author.empty() || content.empty()) {
                    //QMessageBox::warning(this,"Something went wrong","Something went wrong");
                    QMessageBox::information(this, "Something went wrong", "Something went wrong");
                    return;
                }

                this->service.update(element.get_id(), title, author, content);
                this->populateList(this->service.get_all());
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

