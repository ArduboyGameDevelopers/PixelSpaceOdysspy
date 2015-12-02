//
//  Button.h
//  PixelSpaceOdyssey
//
//  Created by Alex Lementuev on 12/1/15.
//  Copyright © 2015 Space Madness. All rights reserved.
//

#ifndef Button_h
#define Button_h

#include "View.h"
#include "Image.h"

class Button;

typedef void (*ButtonClickHandler)(Button* button);

enum ButtonState { ButtonStateNormal, ButtonStateHighlighted, ButtonStateSelected };
const int kButtonStateCount = 3;

class Button : public View
{
private:
    ButtonClickHandler _clickHandler;
    ButtonState _state;
    bool _mousePressed;
    Image* _stateImages[kButtonStateCount];
    
public:
    Button(int width, int height, ButtonClickHandler handler = NULL);
    virtual ~Button();
    
public:
    virtual void render(SDL_Renderer* render) const;
    
    virtual void mouseDown(int x, int y);
    virtual void mouseMove(int x, int y);
    virtual void mouseUp(int x, int y);
    virtual void mouseEnter(int x, int y);
    virtual void mouseExit(int x, int y);
    
public:
    void setStateImage(ButtonState state, Image* image);
    Image* getStateImage(ButtonState state) const;
    
public:
    inline ButtonClickHandler clickHandler() const { return _clickHandler; }
    inline void setClickHandler(ButtonClickHandler clickHandler) { _clickHandler = clickHandler; }
};

#endif /* Button_h */