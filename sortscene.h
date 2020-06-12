#ifndef SORTSCENE_H
#define SORTSCENE_H

#include <QGraphicsScene>
#include <QVector>

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SortScene();

public slots:
    void step();
    void createBar(int height);

private:
    QVector<QGraphicsRectItem*> rectangles;

    int maxHeight = 20;
    float blockSize = 50.0;
    float gapSize = 10.0;

};

#endif // SORTSCENE_H
