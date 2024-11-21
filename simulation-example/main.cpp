#include <QApplication>
#include <QPushButton>
#include "tests.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    test_all();
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Verdana",40));
    Repository r{"/Users/maliimregergely/mig/oop-2023/simulation-example/cars_prod.txt"};
    Service s{r};
    UI ui{s};
    ui.show();

    return QApplication::exec();
}
