#pragma once

#ifndef __ARC_SOUND_H__
#define __ARC_SOUND_H__

#include "Common.h"
#include "ManagedObject.h"
#include "IFrameListener.h"

#include <SDL/SDL_mixer.h>

namespace Arc
{
    class Sound :
        public ManagedObject
    {
    protected:

        Mix_Chunk* _pChunk;

        int _channel;

    public:

        Sound( string filename );
        virtual ~Sound( void );

        virtual inline string toString( void ) const { return "Sound"; }

        virtual void update( const Event& event );

        virtual void play( bool loop = false );
        virtual void stop( void );

        virtual bool isPlaying( void );

        virtual float getVolume( void );
        virtual void  setVolume( float vol );

        virtual void fadeIn  ( double duration );
        virtual void fadeOut ( double duration );
        virtual void stopFade( void );

    }; // class Sound

} // namespace Arc

#endif //__ARC_SOUND_H__
