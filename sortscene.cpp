#include "sortscene.h"

SortScene::SortScene()
{
    for(int i = 0; i < 20; ++i) {
        createBar((i * 13) % 20 + 1);
    }

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

void SortScene::step(){

}
