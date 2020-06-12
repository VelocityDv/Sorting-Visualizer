#include "insertionsortscene.h"
#include "sortscene.h"

#include <QGraphicsRectItem>

InsertionSortScene::InsertionSortScene()
{
    addText("Insertion Sort");
}

void InsertionSortScene::step()
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

    rectangles[pos]->setBrush(QColor(0, 255, 0));
    rectangles[pos + 1]->setBrush(QColor(0, 255, 0));
}
