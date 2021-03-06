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
 
#ifndef __BOTLINK_PEER_DISCOVERY_H_
#define __BOTLINK_PEER_DISCOVERY_H_

#include "botlink/PeerGroup.h"


namespace botlink
{

/**
 * Peer discovery service
 */
class PeerDiscovery
{
public:
	/**
	 * Listen and accept incoming connections asynchronously.
	 * Calling PeerDiscovery::Listen() will launch a thread that waits
	 * to hear from other Peers and adds them to the PeerGroup.
	 * @returns true, if the listener thread and socket were able to be created.
	 *          false, if there was a problem launching the listener socket.
	 */
	bool Listen();
	
	/**
	 * Connect to a specific Peer
	 */
	Peer* Connect( const char* ipAddress, uint16_t port );
	
	
protected:
	friend class PeerDiscovery;

	PeerDiscovery();
	~PeerDiscovery();
	
	std::vector<Peer*> mPeers;
}; 

}

#endif
