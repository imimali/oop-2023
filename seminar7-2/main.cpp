#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "chat_window.h"
#include "custom_model.h"
#include <algorithm>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Times New Roman", 24));
    ChatWindow w;
    w.show();
    return QApplication::exec();
}
