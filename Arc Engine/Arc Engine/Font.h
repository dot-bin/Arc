#pragma once

#ifndef __ARC_FONT_H__
#define __ARC_FONT_H__

#include "Common.h"
#include "GameObject.h"

#include <SDL/SDL_ttf.h>

namespace Arc
{
    class RenderTarget;
    class CachedText;

    class Font :
        public GameObject
    {

        friend class RenderTarget;
        friend class CachedText;

    private:

        string
            _filename;

        TTF_Font
            *_pFont;

        int
            _size;

        virtual TTF_Font* SDLFont( void ) const { return _pFont; }

    public:

        Font( string filename, int size );
        virtual ~Font( void );

        virtual string toString( void ) const;

        virtual int size( void ) const { return _size; }

        virtual Size measureString( string text );

    };
}

#endif
