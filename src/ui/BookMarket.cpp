#include <QWebChannel>
#include <QVBoxLayout>
#include <QWebEngineView>
#include "BookMarket.h"
#include "ui_BookMarket.h"
#include "../service/BookService.h"
#include "../Test.h"
#include "../service/ProxyService.h"
#include "../model/Address.h"
#include "../service/OrderService.h"

BookMarket::BookMarket(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);//设置布局的边距为零
    layout->setSpacing(0);//设置布局的间距为零
    this->setLayout(layout);

    QWebEngineView *webEngineView = new QWebEngineView(this);//创建WebEngineView
    QWebChannel* webChannel=new QWebChannel(this);//创建webChannel
    layout->addWidget(webEngineView);

    webChannel->registerObject("bookService",new BookService());//将自定义对象注册到QWebChannel中
    webChannel->registerObject("proxyService",new ProxyService());//将自定义对象注册到QWebChannel中

    webEngineView->page()->setWebChannel(webChannel);;//给WebEngineView添加WebChannel
    webEngineView->setUrl(QUrl("F:/Code/WebStorm/bookmarket/dist/index.html"));

    qRegisterMetaType<BookService>("BookService");
    qRegisterMetaType<OrderService>("OrderService");
    qRegisterMetaType<Address>("Address");
}

BookMarket::~BookMarket() {

}