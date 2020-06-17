#include "insertionsortscene.h"
#include "sortscene.h"

#include <QGraphicsRectItem>
#include <algorithm>

InsertionSortScene::InsertionSortScene()
{
    addText("Insertion Sort");
}

bool InsertionSortScene::SortedSublist(){
    return std::is_sorted(rectangles.begin(), pos+1+rectangles.begin(), [](const auto &first, const auto &second) {
                return (first->rect().height() < second->rect().height());
           });
}

void InsertionSortScene::step()
{

    if (sortedCount == rectangles.size() - 1){
        return;
    }

    rectangles[pos]->setBrush(QColor(255, 255, 255));
    rectangles[pos + 1]->setBrush(QColor(255, 255, 255));

    if(rectangles[pos]->rect().height() > rectangles[pos + 1]->rect().height()){
        swap(pos, pos+1);
        --pos;

        pos = std::max(0, pos);
    }
    else {
        ++sortedCount;
        pos = sortedCount;
    }

    //well it works -_-
    if (sortedCount == rectangles.size() - 1){
        return;
    }

    rectangles[pos]->setBrush(QColor(255, 0, 0));
    rectangles[pos + 1]->setBrush(QColor(255, 0, 0));
}
