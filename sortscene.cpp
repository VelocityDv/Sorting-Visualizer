#include "sortscene.h"

#include <QGraphicsRectItem>

#include <random>
#include <algorithm>

SortScene::SortScene()
{
    for(int i = 0; i < 19; ++i) {
        createBar(i % 19 + 1);
    }

    shuffle();

    underline = addRect(
        0, maxHeight * blockSize + 5, (blockSize * 2) + gapSize, 5,
        //add custom bar
        QPen(QColor(255, 0 , 0)), QBrush(QColor(255, 0, 0))
    );
}

void SortScene::createBar(int height)
{
    rectangles.push_back(addRect(
        (blockSize + gapSize) * rectangles.size(),
        (maxHeight - height) * blockSize,
        blockSize,
        blockSize * height
    ));
}

void SortScene::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rectangles.begin(), rectangles.end(), g);

    for(int i = 0; i < rectangles.size(); ++i){
        updatePosition(i);
    }
}

void SortScene::updatePosition(int index)
{
    auto rectangle = rectangles[index]->rect();
    rectangle.moveLeft((blockSize + gapSize) * index);
    rectangles[index]->setRect(rectangle);
}

void SortScene::step()
{
    if(rectangles[pos]->rect().height() > rectangles[pos + 1]->rect().height()){
        swap(pos, pos+1);
    }

    pos = (pos + 1) % (rectangles.size() - 1);

    auto rectangle = underline->rect();
    rectangle.moveLeft((blockSize + gapSize) * pos);
    underline->setRect(rectangle);
}

void SortScene::swap(int first, int second)
{
    std::swap(rectangles[first], rectangles[second]);

    updatePosition(first);
    updatePosition(second);
}
