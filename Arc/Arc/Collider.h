#pragma once

#ifndef __ARC_COLLIDER_H__
#define __ARC_COLLIDER_H__

#include "Common.h"
#include "ManagedObject.h"

#include "RenderTarget.h"

namespace Arc
{
    class Collider
        : public ManagedObject
    {
    protected:

        bool 
            _debugOutlines;

    public:

        virtual ~Collider( void ) { _debugOutlines = false; }

        virtual bool check( Point pos, Collider* pOther, Point otherPos ) = 0;
        virtual Point getCollisionPoint( Point pos, Collider* pOther, Point otherPos ) = 0;
        virtual Point center( void ) = 0;

        virtual void render( const RenderTarget* renderTarget, Point pos, Vector2 origin = Vector2::ZERO ) { }

        virtual inline void setDebugOutlines( bool enabled ) { _debugOutlines = enabled; }
        virtual inline bool isDebugOutlines( void ) { return _debugOutlines; }
        virtual inline void toggleDebugOutlines( void ) { _debugOutlines = !_debugOutlines; }

    }; // class Collider

} // namespace Arc

#endif // __ARC_COLLIDER_H__
