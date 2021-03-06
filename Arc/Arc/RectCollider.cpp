#include "RectCollider.h"
#include "CircleCollider.h"

bool Arc::RectCollider::check( Point pos, Collider* pOther, Point otherPos )
{
    RectCollider*   rectOther   = dynamic_cast<RectCollider*>(pOther);
    CircleCollider* circleOther = dynamic_cast<CircleCollider*>(pOther);

    Rect newMask = RectMask;
    newMask.X += pos.X;
    newMask.Y += pos.Y;

    if (rectOther != nullptr)
    {
        Rect newOtherMask = rectOther->RectMask;
        newOtherMask.X += otherPos.X;
        newOtherMask.Y += otherPos.Y;

        return newOtherMask.intersectsRect(newMask);
    }
    else if (circleOther != nullptr)
    {
        Circle newOtherMask = circleOther->CircleMask;
        newOtherMask.X += otherPos.X;
        newOtherMask.Y += otherPos.Y;

        return newOtherMask.intersectsRect(newMask);
    }

    return false;
}

Arc::Point Arc::RectCollider::getCollisionPoint( Point pos, Collider* pOther, Point otherPos )
{
    RectCollider*   rectOther   = dynamic_cast<RectCollider*>(pOther);
    CircleCollider* circleOther = dynamic_cast<CircleCollider*>(pOther);

    Rect newMask = RectMask;
    newMask.X += pos.X;
    newMask.Y += pos.Y;

    if (rectOther != nullptr)
    {
        Rect newOtherMask = rectOther->RectMask;
        newOtherMask.X += otherPos.X;
        newOtherMask.Y += otherPos.Y;

        return newOtherMask.getIntersect(newMask).getCenter();
    }
    else if (circleOther != nullptr)
    {
        Rect newOtherMask = circleOther->CircleMask.getBounds();
        newOtherMask.X += otherPos.X;
        newOtherMask.Y += otherPos.Y;

        return newOtherMask.getIntersect(newMask).getCenter();
    }

    return Point::ZERO;
}

void Arc::RectCollider::render( const RenderTarget* renderTarget, Point pos, Vector2 origin /*= Vector2::ZERO*/ )
{
    renderTarget->drawRect(Rect(RectMask.getPos() + pos, RectMask.getSize()), Color::GREEN, 0.0f, origin);
}

