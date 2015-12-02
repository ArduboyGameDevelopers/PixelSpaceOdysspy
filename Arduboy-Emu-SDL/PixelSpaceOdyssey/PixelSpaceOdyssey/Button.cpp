//
//  Button.c
//  PixelSpaceOdyssey
//
//  Created by Alex Lementuev on 12/1/15.
//  Copyright © 2015 Space Madness. All rights reserved.
//

#include <string>
#include <assert.h>

#include "Button.h"

Button::Button(int width, int height, ButtonClickHandler handler) :
    View(width, height),
    _clickHandler(handler),
    _selected(false),
    _mousePressed(false),
    _toggle(false)
{
    bzero(_stateImages, sizeof(_stateImages));
}

Button::~Button()
{
    for (int i = 0; i < kButtonStateCount; ++i)
    {
        if (_stateImages[i])
        {
            _stateImages[i]->release();
        }
    }
}

void Button::render(SDL_Renderer* render) const
{
    ButtonState state;
    if (_selected || _mousePressed)
    {
        state = ButtonStateSelected;
    }
    else if (hasMouse())
    {
        state = ButtonStateHighlighted;
    }
    else
    {
        state = ButtonStateNormal;
    }
    
    Image* image = getStateImage(state);
    if (image != NULL)
    {
        image->draw(render, left(), top());
    }
}

void Button::mouseDown(int x, int y)
{
    _mousePressed = true;
}

void Button::mouseMove(int x, int y)
{
}

void Button::mouseUp(int x, int y)
{
    if (_mousePressed)
    {
        _mousePressed = false;
        if (_toggle)
        {
            _selected = !_selected;
        }

        if (_clickHandler)
            _clickHandler(this);
    }
}

void Button::mouseEnter(int x, int y)
{
}

void Button::mouseExit(int x, int y)
{
    _mousePressed = false;
}

void Button::setStateImage(ButtonState state, Image* image)
{
    assert(state >= 0 && state < kButtonStateCount);
    _stateImages[state] = image->retain();
}

Image* Button::getStateImage(ButtonState state) const
{
    assert(state >= 0 && state < kButtonStateCount);
    return _stateImages[state];
}