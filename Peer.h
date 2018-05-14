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
 
#ifndef __BOTLINK_PEER_H_
#define __BOTLINK_PEER_H_

#include "botlink/MessageQueue.h"

#include <string>
#include <vector>


namespace botlink
{

/**
 * Peer node instance
 */
class Peer
{
public:
	/**
	 * Connect
	 * TODO:  PeerDiscovery service should create
	 */
	//static Peer* Connect( const char* ipAddress, uint16_t port );
	
	/**
	 * Retrieve the number of message queues connected to the Peer.
	 */
	inline uint32_t GetNumQueues() const					{ return mQueues.size(); }
	
	/**
	 * Retrieve a message queue.
	 */
	inline MessageQueue* GetQueue( uint32_t index )			{ return mQueues[index]; }
	
	
	// TODO:  add Peer state dictionary
	
protected:
	friend class PeerDiscovery;
	friend class PeerGroup;
	
	Peer();
	~Peer();
	
	std::vector<MessageQueue*> mQueues;
}; 

}

#endif
