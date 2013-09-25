#pragma once

#ifndef __ARC_UNIT_H__
#define __ARC_UNIT_H__

#include "Common.h"
#include "EventDispatcher.h"

#include "OriginLocation.h"
#include "Layer.h"
#include "Scene.h"

namespace Arc
{
	class Component;
	class PhysicsComponent;
	class ImageComponent;
	class ShapeComponent;
	class AnimatedComponent;

    class Unit :
        public EventDispatcher
    {

        friend class Layer;

    protected:

        Layer
            *_pParent;

        OriginLocation
            _originLocation;

        Point
            _origin;

        Size
            _size;

        Point
            _pos;

        float
            _depth;

        bool
            _enabled,
            _visible;

		ArrayList<Component*>
			_components;

        LinkedList<Component*>
			_componentsToAdd,
			_componentsToRemove;

        virtual void calcOriginLocation( void );

        virtual void setParentLayer( Layer* layer ) { _pParent = layer; }

		virtual void updateComponents( const FrameData* data );
		virtual void renderComponents( const RenderData* data );

    public:

        Unit( Vector2 pos, float depth = 0.0f );
        virtual ~Unit( void );

        virtual void update( const Event& event );
        virtual void render( const Event& event );

        virtual void update( const FrameData* data )  { };
        virtual void render( const RenderData* data ) { };
		
		virtual inline bool isEnabled( void ) const { return _enabled; }
		virtual inline bool isVisible( void ) const { return _visible; }
		virtual inline void setEnabled( bool enabled ) { _enabled = enabled; }
		virtual inline void setVisible( bool visible ) { _visible = visible; }
		virtual inline void toggleEnabled( void ) { _enabled = !_enabled; }
		virtual inline void toggleVisible( void ) { _visible = !_visible; }

		virtual inline Point getPos    ( void ) const { return _pos; }
		virtual inline void  setPos    ( Point pos )   { _pos = pos; }
		virtual inline void  addToPos  ( Point val ) { setPos(_pos + val); }
		virtual inline void  subFromPos( Point val ) { setPos(_pos - val); }

		virtual inline float getDepth( void ) const { return _depth; };
		virtual inline void  setDepth( float depth ) { _depth = depth; };

        virtual inline Size  getSize( void ) const { return _size; }
        virtual void         setSize( Size size );

        virtual inline Point getOrigin( void ) const { return _origin; }
        virtual void         setOrigin( Vector2 origin );

        virtual inline OriginLocation getOriginLocation( void ) const { return _originLocation; }
		virtual void                  setOriginLocation( OriginLocation originLocation );

        inline Layer* getParentLayer( void ) { return _pParent; }
		inline Scene* getParentScene( void ) { return _pParent->getParentScene(); }

		virtual bool addComponent   ( Component* component );
		virtual bool removeComponent( Component* component );
		virtual inline bool hasComponent( Component* component ) { return _components.contains(component); }

		virtual Component*         addNewComponent( void );
		virtual PhysicsComponent*  addNewPhysicsComponent( Vector2 vel = Vector2::ZERO, Vector2 acc = Vector2::ZERO );
		virtual ImageComponent*    addNewImageComponent( Texture *pTexture, Point offset = Point::ZERO, Angle rotation = Angle::ZERO, Color blendColor = Color::WHITE, Point origin = Point::ZERO );
		virtual ShapeComponent*    addNewShapeComponent( Point offset = Point::ZERO, Angle rotation = Angle::ZERO, Color blendColor = Color::WHITE, Point origin = Point::ZERO );
		virtual AnimatedComponent* addNewAnimatedComponent( void );

    }; // class Unit

    struct UnitDepthComp
        : std::binary_function<Unit*, Unit*, bool>
    {
        bool operator()( const Unit* lhs, const Unit* rhs ) const
        {
			return lhs->getDepth() < rhs->getDepth();
        }
    }; // struct UnitDepthComp

} // namespace Arc

#endif // __ARC_UNIT_H__
