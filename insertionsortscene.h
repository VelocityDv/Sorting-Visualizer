#ifndef INSERTIONSORTSCENE_H
#define INSERTIONSORTSCENE_H

#include "sortscene.h"

class InsertionSortScene : public SortScene
{
    Q_OBJECT
public:
    InsertionSortScene();

public slots:
    void step();
};

#endif // INSERTIONSORTSCENE_H
