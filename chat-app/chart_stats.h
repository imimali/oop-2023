//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_CHART_STATS_H
#define CHAT_APP_CHART_STATS_H
#include "observer.h"
#include "chat_session.h"
#include <QPainter>
#include <QStaticText>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <map>
#include <QHBoxLayout>
#include <iostream>
class ChartStats: public QWidget, public Observer {
    Q_OBJECT
            ChatSession &session;
    QHBoxLayout*mainLayout;
    QChartView* chart;
public:
    ChartStats(ChatSession &s) : session{s} {
        this->session.register_observer(this);
        this->mainLayout=new QHBoxLayout(this);
    }

    ~ChartStats() override {
        this->session.unregister_observer(this);
    }

    void paintEvent(QPaintEvent *event)override{
        QWidget::paintEvent(event);

        auto series = new QBarSeries();
//
        std::map<std::string, int> stats;

        for (auto &pair: this->session.get_messages()) {
            stats[pair.first.get_username()] += 1;
        }
//
        for(auto&pair:stats){
            std::string label = pair.first;
            auto *set0 = new QBarSet(QString::fromStdString(label));
            *set0 << pair.second;
            series->append(set0);
        }
//
        auto *qchart = new QChart();
        qchart->addSeries(series);
        qchart->setTitle("Simple barchart example");
        qchart->setAnimationOptions(QChart::SeriesAnimations);
//
        auto *chartView = new QChartView(qchart);
        //delete this->chart;
        this->chart=chartView;
        chartView->setRenderHint(QPainter::Antialiasing);
        this->mainLayout->addWidget(chartView);
        this->resize(500,500);
    }
    void update()override{

    }
};
#endif //CHAT_APP_CHART_STATS_H
