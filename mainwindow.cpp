#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bubblesortscene.h"
#include "insertionsortscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new BubbleSortScene())
{
    ui->setupUi(this);

    //new connect syntax Qt5, no longer pass a string
    connect(
        ui->pushButton_step, &QPushButton::clicked,
        this, &MainWindow::step
    );

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::step()
{
    scene->step();
}



