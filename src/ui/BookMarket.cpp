#include <QWebChannel>
#include <QVBoxLayout>
#include <QWebEngineView>
#include "BookMarket.h"
#include "ui_BookMarket.h"

BookMarket::BookMarket(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    QVBoxLayout layout;
    layout.setContentsMargins(0, 0, 0, 0); // 设置布局的边距为零
    layout.setSpacing(0); // 设置布局的间距为零
    this->setLayout(&layout);
    QWebEngineView webEngineView;
    layout.addWidget(&webEngineView);
    QWebChannel webChannel;
    webEngineView.page()->setWebChannel(&webChannel);
    webEngineView.setUrl(QUrl("F:/Code/WebStorm/bookmarket/dist/index.html"));
}

BookMarket::~BookMarket() {

}
