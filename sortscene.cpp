#include "sortscene.h"

#include <QGraphicsRectItem>

#include <random>
#include <algorithm>

SortScene::SortScene()
{
    for(int i = 0; i < 20; ++i) {
        createBar(i % 20 + 1);
    }

    shuffle();
}

void SortScene::createBar(int height)
{
    //add rect (x, y, width, height)
    //0 0
    //--------- x+
    //|y+
    //|
    //|
    //do not add this to git.
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

}
