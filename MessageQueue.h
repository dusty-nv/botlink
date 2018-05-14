/*
 * Copyright (c) 2018, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
 
#ifndef __BOTLINK_MESSAGE_QUEUE_H_
#define __BOTLINK_MESSAGE_QUEUE_H_

#include "botlink/Message.h"


class Socket;


namespace botlink
{

/**
 * Synchronized queue for sending/receiving messages.
 */
class MessageQueue
{
public:
	/**
	 * Send a message
	 */
	bool Send( Message* msg );
	
	/**
	 * Retrieve the next message, or NULL if none.
	 */
	Message* Recieve( uint32_t timeout=0 );
	
protected:
	friend class Peer;
	
	MessageQueue();
	~MessageQueue();
	
	bool Connect( const char* ipAddress, uint16_t port );
	bool Connect( Socket* socket );
	
	Socket* mSocket;
}; 

}

#endif
