//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_PRACTICE_UI_H
#define SIMULATION_PRACTICE_UI_H

#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QBrush>
#include <iostream>
#include <utility>
#include <map>
#include "service.h"

class UI : public QWidget {
Q_OBJECT

    Service &service;
    QListWidget *carsList = new QListWidget;
    QLineEdit *registrationNrEdit = new QLineEdit;
    std::vector<Car> currentItems;
    QPushButton* sortByModelButton=new QPushButton("Sort by Model");
    QPushButton* sortByRegistrationNR=new QPushButton("Sort by Registration Nr");
    QPushButton* unsortedButton=new QPushButton("Unsorted");
public:
    UI(Service &s) : service{s} {
        this->setupUI();
    }

    void setupUI() {
        this->resize(500, 500);
        auto mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(this->carsList);
        mainLayout->addWidget(this->registrationNrEdit);

        auto buttonsLayout = new QHBoxLayout;
        buttonsLayout->addWidget(this->sortByModelButton);
        buttonsLayout->addWidget(this->sortByRegistrationNR);
        buttonsLayout->addWidget(this->unsortedButton);
        mainLayout->addLayout(buttonsLayout);
        this->populate(this->service.get_all());
        this->connect();
    }

    void populate(std::vector<Car> cars) {
        std::map<std::string, QColor> colorMap;
        colorMap["red"]=Qt::red;
        colorMap["green"]=Qt::green;
        colorMap["white"]=Qt::white;
        this->currentItems=std::move(cars);
        this->carsList->clear();
        for (const auto &car: this->currentItems) {
            auto item = new QListWidgetItem(
                    QString::fromStdString(car.get_model() + "(" + std::to_string(car.get_mileage()) + ")"));

            item->setBackground(colorMap[car.get_color()]);
            this->carsList->addItem(item);
        }
    }

    int getSelectedIndex() {
        auto index = this->carsList->selectionModel()->selectedRows();
        if (index.empty()) {
            return -1;
        }
        return index.at(0).row();
    }

    void connect() {
        QObject::connect(this->carsList, &QListWidget::itemSelectionChanged, [this]() {
            auto index = this->getSelectedIndex();
            if (index==-1){
                return;
            }
            auto element = this->currentItems.at(index);
            this->registrationNrEdit->setText(QString::fromStdString(element.get_registration_nr()));
        });

        QObject::connect(this->sortByModelButton,&QPushButton::clicked,[this](){
            auto sorted = this->service.get_sorted_by_model();
            this->populate(sorted);
        });

        QObject::connect(this->sortByRegistrationNR,&QPushButton::clicked,[this](){
            auto sorted = this->service.get_sorted_by_registration_nr();
            this->populate(sorted);
        });

        QObject::connect(this->unsortedButton,&QPushButton::clicked,[this](){
            auto all = this->service.get_all();
            this->populate(all);
        });

    }

};

#endif //SIMULATION_PRACTICE_UI_H
