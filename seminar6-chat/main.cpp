#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "chat_session.h"
#include "chat_window.h"
#include "statistics.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Verdana",18));
    User u1{"user1", 1};
    User u2{"picasso", 2};
    User u3{"picasso2", 2};
    ChatSession session;


    ChatWindow window {u1,session};
    ChatWindow window1 {u2,session};
    ChatWindow window2 {u3,session};
    Statistics stats{session};
    window.show();
    window1.show();
    window2.show();
    stats.show();
    return QApplication::exec();
}
