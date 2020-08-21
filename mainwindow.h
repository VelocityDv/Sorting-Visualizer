#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sortscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    template<class T>
    void setupScene();

public slots:
    void step();
    void togglePlay();
    void selectAlgorithm(int index);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<SortScene> scene;
};

#endif // MAINWINDOW_H
