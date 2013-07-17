#include "Rect.h"
#include "Circle.h"

Rect Rect::ZERO = Rect(0, 0, 0, 0);
Rect Rect::ONE  = Rect(0, 0, 1, 1);

Rect::Rect( float x, float y, float width, float height )
{
    X = x;
    Y = y;
    Width = width;
    Height = height;
}

Rect::Rect( void )
{
    X = 0;
    Y = 0;
    Width = 0;
    Height = 0;
}

Rect::Rect( Vector2 pos, Vector2 size )
{
    X = pos.X;
    Y = pos.Y;
    Width = size.X;
    Height = size.Y;
}

Rect::~Rect( void )
{
}

string Rect::toString( void ) const
{
    stringstream ss;
    ss << "Rect [X: " << X << ", Y: " << Y << ", W: " << Width << ", H: " << Height << "]";
    return ss.str();
}

void Rect::setPos( Vector2 pos )
{ 
    X = pos.X;
    Y = pos.Y;
}

void Rect::setSize( Vector2 size )
{
    Width = size.X;
    Height = size.Y;
}

bool Rect::containsRect( Rect other ) const
{
    if ( left() > other.right()  ||
         top()  > other.bottom() ||
         other.left() > right()  ||
         other.top()  > bottom() )
    {
        return false;
    }

    return true;
}

bool Rect::containsCircle( Circle other ) const
{
    return other.containsRect(*this);
}

bool Rect::containsPoint( Vector2 point ) const
{
    if( point.X < left()   ||
        point.X > right()  ||
        point.Y < top()    ||
        point.Y > bottom() )
    {
        return false;
    }

    return true;
}

const Rect Rect::operator+( const Rect &rhs ) const
{
    Rect result = *this;
    result += rhs;
    return result;
}

const Rect Rect::operator-( const Rect &rhs ) const
{
    Rect result = *this;
    result -= rhs;
    return result;
}

Rect & Rect::operator+=( const Rect &rhs )
{
    X      += rhs.X;
    Y      += rhs.Y;
    Width  += rhs.Width;
    Height += rhs.Height;
    return *this;
}

Rect & Rect::operator-=( const Rect &rhs )
{
    X      -= rhs.X;
    Y      -= rhs.Y;
    Width  -= rhs.Width;
    Height -= rhs.Height;
    return *this;
}

bool Rect::operator==( const Rect &rhs ) const
{
    return (X == rhs.X && Y == rhs.Y && Width == rhs.Width && Height == rhs.Height);
}

bool Rect::operator!=( const Rect &rhs ) const
{
    return !(*this == rhs);
}


