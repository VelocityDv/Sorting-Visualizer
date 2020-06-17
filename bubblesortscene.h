#ifndef BUBBLESORTSCENE_H
#define BUBBLESORTSCENE_H

#include "sortscene.h"

class BubbleSortScene : public SortScene
{
    Q_OBJECT
public:
    BubbleSortScene();

public slots:
    void step() override;
};

#endif // BUBBLESORTSCENE_H
