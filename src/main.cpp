#include <QApplication>
#include <QVBoxLayout>
#include "ui/BookMarket.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BookMarket bookMarket;
    bookMarket.show();
    return QApplication::exec();
}
