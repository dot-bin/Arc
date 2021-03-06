#pragma once

#ifndef __ARC_ISERIALIZABLE_H__
#define __ARC_ISERIALIZABLE_H__

#include <iostream>

using std::ostream;
using std::istream;

namespace Arc
{
	class Buffer;

	/** An interface for serializing and deserializing objects
	  */
    class ISerializable
    {
        public:

			virtual int serialize( ostream &stream ) = 0;
            virtual int deserialize( istream &stream ) = 0;

			//virtual Buffer serialize( void ) { Buffer buffer; serialize(buffer); return buffer; };
			//
			virtual int serialize( Buffer &buffer ) = 0;
			virtual int deserialize( Buffer &buffer ) = 0;

    }; // class ISerializable

} // namespace Arc

#endif // __ARC_ISERIALIZABLE_H__
