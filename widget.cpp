#include "widget.h"
#include "ui_widget.h"

#include "insertionsortscene.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , scene(new InsertionSortScene())
{
    ui->setupUi(this);
    //new connect syntax Qt5, no longer pass a string
    connect(
        ui->pushButton_step, &QPushButton::clicked,
        this, &Widget::step
    );

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::step()
{
    scene->step();
}
