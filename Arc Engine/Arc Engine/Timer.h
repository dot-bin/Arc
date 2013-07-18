#pragma once

namespace Arc
{

#ifndef __ARC_TIMER_H__
#define __ARC_TIMER_H__

#include "Common.h"
#include "GameObject.h"

#include <ctime>

#ifdef WINDOWS

#include <Windows.h>

#else

#include <sys/time.h>
#include <unistd.h>

#endif

class Timer :
    public GameObject
{
private:

    static double
        MICRO;

    double
        _startTimeMicro,
        _endTimeMicro;

    bool
        _stopped;

#ifdef WINDOWS

    LARGE_INTEGER
        _freq,
        _startCount,
        _endCount;

    double calcDiffMillis( LARGE_INTEGER from, LARGE_INTEGER to ) const;

#else

    timeval
        _startCount,
        _endCount;

    double calcDiffMillis( timeval from, timeval to ) const;

#endif

public:

    Timer( void );
    virtual ~Timer( void );

    virtual string toString( void ) const;

    void start( void );
    void stop ( void );

    double getElapsedMicro( void );
    double getElapsedMilli( void );
    double getElapsed( void );

    void sleepUntilElapsed( double millis );

};

#endif

}
