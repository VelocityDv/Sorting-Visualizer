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

}

void SortScene::play(){
    timer.start(delay);
}

void SortScene::pause(){
    timer.stop();
}

bool SortScene::isPlaying(){
    return timer.isActive();
}

void SortScene::swap(int first, int second)
{
    std::swap(rectangles[first], rectangles[second]);

    updatePosition(first);
    updatePosition(second);
}
