#include "bubblesortscene.h"

#include <QGraphicsRectItem>

BubbleSortScene::BubbleSortScene()
{

    connect(
        &timer, &QTimer::timeout,
        this, &BubbleSortScene::step
    );

    addText("Bubble Sort");
}

void BubbleSortScene::step()
{
    if(rectangles[pos]->rect().height() > rectangles[pos + 1]->rect().height()){
        swap(pos, pos+1);
    }

    rectangles[pos]->setBrush(QColor(255, 255, 255));
    rectangles[pos + 1]->setBrush(QColor(255, 255, 255));

    pos = (pos + 1) % (rectangles.size() - 1 - sortedCount);
    if(pos == 0 && sortedCount < rectangles.size() - 2){
        ++sortedCount;
    }

    rectangles[pos]->setBrush(QColor(255, 0, 0));
    rectangles[pos + 1]->setBrush(QColor(255, 0, 0));
}
