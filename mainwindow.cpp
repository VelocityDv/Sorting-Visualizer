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

    connect(
        ui->pushButton_togglePlay, &QPushButton::clicked,
        this, &MainWindow::togglePlay
    );

    connect(
        ui->dropBox_algorithmSelector, QOverload<int>::of(&QComboBox::activated),
        this, &MainWindow::selectAlgorithm
    );

    setupScene<BubbleSortScene> ();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::step()
{
    scene->step();
}

void MainWindow::togglePlay()
{
    if(!scene->isPlaying()){
        scene->play();
        ui->pushButton_togglePlay->setText("Pause");
    }else{
        scene->pause();
        ui->pushButton_togglePlay->setText("Play");
    }
}

void MainWindow::selectAlgorithm(int index)
{
    if(index == 0)
        setupScene<BubbleSortScene> ();
    else if(index == 1)
        setupScene<InsertionSortScene> ();
}

template<class T>
void MainWindow::setupScene()
{
    scene.reset();
    scene = std::make_unique<T> ();
    ui->graphicsView->setScene(scene.get());
}
