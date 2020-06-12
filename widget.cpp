#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //new connect syntax Qt5, no longer pass a string
    connect(
        ui->pushButton_step, &QPushButton::clicked,
        &scene, &SortScene::step
    );

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
}

Widget::~Widget()
{
    delete ui;
}

