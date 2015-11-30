//
//  DisplayView.h
//  PixelSpaceOdyssey
//
//  Created by Alex Lementuev on 11/29/15.
//  Copyright © 2015 Space Madness. All rights reserved.
//

#ifndef DisplayView_h
#define DisplayView_h

#include <stdio.h>

#include "View.h"

struct RectList;
typedef struct RectList RectList;

RectList* RectListCreate(int capacity);
void RectListRender(SDL_Renderer* renderer, const RectList* list, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void RectListDestroy(RectList* list);

class DisplayView : public View
{
private:
    RectList* _pixelRects;
    RectList* _gridRects;
    bool     _gridVisible;
    
public:
    DisplayView(int width, int height);
    ~DisplayView();
    
public:
    void copyScreenBuffer(unsigned const char* screenBuffer, int bufferWidth, int bufferHeight);
    void render(SDL_Renderer* renderer);
    
public:
    inline bool gridVisible() { return _gridVisible; }
    inline void setGridVisible(bool visible) { _gridVisible = visible; }
    inline void toggleGrid() { _gridVisible = !_gridVisible; }
};

#endif /* DisplayView_h */
