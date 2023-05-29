#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "chat_window.h"
#include "chat_session.h"
#include "statistics.h"
#include "chart_stats.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Verdana",18));
    ChatSession s;

    User user1{1,"electro"};
    User user2{2,"vulture"};
    Statistics statistics{s};
    //ChartStats chart_stats{s};

    ChatWindow w1{user1,s};
    ChatWindow w2{user2,s};
    w1.show();
    w2.show();
    statistics.show();
    //chart_stats.show();
    return QApplication::exec();
}
