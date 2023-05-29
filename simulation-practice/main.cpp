#include <QApplication>
#include <QPushButton>
#include "tests.h"
#include "ui.h"
int main(int argc, char *argv[]) {
    test_all();
    QApplication a(argc, argv);
    Repository r("/Users/maliimregergely/mig/oop-2023/simulation-practice/test_cars.txt");
    Service s{r};
    UI ui{s};
    ui.show();
    return QApplication::exec();
}
