#include <QApplication>
#include <QPushButton>
#include <iostream>

#include "repository.h"
#include "service.h"
#include "posts_ui.h"

int main(int argc, char *argv[]) {
    Repository<Post> repository;
    Service service{repository};
    service.add("title","author","lorem ipsum dolor sit amet");
    service.add("title1","author","exordfdfgcizamus te omnis iumundus spiritus");
    service.add("title2","a","exorceratewizamus te omnis iumundus spiritus");
    service.add("title3","aa","exorczxcvxizamus te omnis iumundus spiritus");
    service.add("title4","aaa","zxcv te omnis iumundus spiritus");
    service.add("titl5","aaa","exorxcbdfghdgfcizamus te omnis iumundus spiritus");
    //service.update(1,"aa","a","a");
    QApplication a(argc, argv);

    PostUI ui{service};
    ui.show();
    return QApplication::exec();
}
