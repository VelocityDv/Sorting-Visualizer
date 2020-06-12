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
    void createBar(int height);
    void shuffle();
    virtual void step();
    void swap(int first, int second);

protected:
    void updatePosition(int index);

    QVector<QGraphicsRectItem*> rectangles;

    int maxHeight = 19;
    float blockSize = 50.0;
    float gapSize = 10.0;

    int pos = 0;
    int sortedCount = 0;
};

#endif // SORTSCENE_H
