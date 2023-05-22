//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_STATISTICS_H
#define SEMINAR6_CHAT_STATISTICS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QStaticText>
#include <map>
#include "observer.h"
#include "chat_session.h"
#include <iostream>

class Statistics : public QWidget, public Observer {
    ChatSession &session;
    std::map<std::string, int> stats;
public:
    void paintEvent(QPaintEvent *event) {
        QWidget::paintEvent(event);
        this->resize(500, 500);
        QPainter painter(this);

//        painter.fillRect(QRect(QPoint(50, 50),
//                               QPoint(150, 250)),
//                         QBrush(Qt::white));

        int index = 0;
        std::vector<Qt::GlobalColor> colors = {Qt::white, Qt::red, Qt::green};
        for (auto entry: this->stats) {
            int topLeftX = 80 + index * 120;
            int topLeftY = 400 - (20 * entry.second);
            int bottomLeftX = 180 + index * 120;
            int bottomLeftY = 400;
            index++;

            painter.fillRect(QRect(QPoint(topLeftX, topLeftY),
                                   QPoint(bottomLeftX, bottomLeftY)),
                             QBrush(colors[index % colors.size()]));

            painter.drawStaticText(bottomLeftX - 80, bottomLeftY + 20,
                                   QStaticText(QString::fromStdString(entry.first)));

        }


    }

    Statistics(ChatSession &session) : session{session} {
        this->session.register_observer(this);
    }

    ~Statistics() {
        this->session.unregister_observer(this);
    }

    void update() {
        this->stats.clear();
        for (auto &message: this->session.get_messages()) {
            this->stats[message.first.get_username()] += 1;
        }
    }

};

#endif //SEMINAR6_CHAT_STATISTICS_H
