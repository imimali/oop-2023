//
// Created by Mali Imre Gergely on 22.05.2023.
//

#ifndef SIMULATION_EXAMPLE_UI_H
#define SIMULATION_EXAMPLE_UI_H

#include <QWidget>
#include <QSlider>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QBrush>
#include <QSlider>
#include <map>
#include <iostream>
#include "service.h"

class UI : public QWidget {
Q_OBJECT

    Service &service;
    QListWidget *carsList = new QListWidget;
    QLineEdit *registrationEdit = new QLineEdit;
    QPushButton *sortByModelButton = new QPushButton{"Sort By Model"};
    QPushButton *sortByRegistrationNrButton = new QPushButton{"Sort By Registration Nr"};
    QPushButton *unsortedButton = new QPushButton{"Unsorted"};
    QSlider* mileageSlider;
    std::vector<Car> currentElements;

    void setupUI() {
        this->resize(500, 500);
        auto mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(this->carsList);
        mainLayout->addWidget(this->registrationEdit);
        auto buttonsLayout = new QHBoxLayout;
        buttonsLayout->addWidget(this->sortByModelButton);
        buttonsLayout->addWidget(this->sortByRegistrationNrButton);
        buttonsLayout->addWidget(this->unsortedButton);
        mainLayout->addLayout(buttonsLayout);

        this->mileageSlider = new QSlider(Qt::Horizontal);
        this->mileageSlider->setTickInterval(200);
        this->mileageSlider->setMaximum(10000);
        this->mileageSlider->setMinimum(0);
        //this->mileageSlider->setTickPosition();
        mainLayout->addWidget(this->mileageSlider);
        this->populate(this->service.get_all());
        this->connect();

    }

    void populate(std::vector<Car> elements) {
        this->carsList->clear();
        std::map<std::string ,QColor> colorMap;
        colorMap["red"]=Qt::red;
        colorMap["blue"]=Qt::blue;
        colorMap["negru"]=Qt::black;
        colorMap["yellow"]=Qt::yellow;
        this->currentElements=std::move(elements);
        for (const auto &car: this->currentElements) {
            auto item = new QListWidgetItem(
                    QString::fromStdString(car.get_model() +
                                           "(" +
                                           std::to_string(car.get_mileage())
                                           + ")"));

            item->setBackground(colorMap[car.get_color()]);
            this->carsList->addItem(item);
        }
    }

    int selectedIndex() {
        auto index = this->carsList->selectionModel()->selectedIndexes();
        if (index.empty()) {
            return -1;
        }
        return index.at(0).row();
    }

    void connect() {
        QObject::connect(
                this->carsList, &QListWidget::itemSelectionChanged,
                [this]() {
                    int index = this->selectedIndex();
                    if (index == -1) {
                        return;
                    }
                    Car element = this->currentElements.at(index);
                    this->registrationEdit->setText(
                            QString::fromStdString(
                                    element.get_registration_nr()
                            ));
                });
        QObject::connect(this->sortByModelButton,
                         &QPushButton::clicked,
                         [this](){
            auto sortedByModel = this->service.get_sorted_by_model();
            this->populate(sortedByModel);
        });

        QObject::connect(this->sortByRegistrationNrButton,
                         &QPushButton::clicked,
                         [this](){
                             auto sortedByModel = this->service.get_sorted_by_registration_nr();
                             this->populate(sortedByModel);
                         });

        QObject::connect(this->unsortedButton,
                         &QPushButton::clicked,
                         [this](){
                             auto sortedByModel = this->service.get_all();
                             this->populate(sortedByModel);
                         });

        QObject::connect(this->mileageSlider,
                         &QSlider::sliderMoved,
                         [this](int value){
            auto elements = this->service.get_filtered_by_mileage(value);
            this->populate(elements);
        });
    }

public:

    UI(Service &s) : service{s} {
        this->setupUI();
    }
};

#endif //SIMULATION_EXAMPLE_UI_H
