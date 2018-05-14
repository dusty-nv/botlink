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
 
#ifndef __BOTLINK_PEER_GROUP_H_
#define __BOTLINK_PEER_GROUP_H_

#include "botlink/Peer.h"


namespace botlink
{


/**
 * Peer Group
 */
class PeerGroup
{
public:
	/**
	 * Function pointer typedef called when events in the
	 * PeerGroup occur, like a Peer being connected/added
	 * or disconnected/removed from the group.
	 */
	typedef void (*PeerEventCallback)( Peer* peer );

	/**
	 * Set the callback used when a new Peer is discovered,
	 * connected, or added to the group.
	 */
	inline void OnPeerConnected( PeerEventCallback fnc )		{ mOnConnected = fnc; }
	
	/**
	 * Set the callback used when a new Peer is disconnected
	 * or removed from the group.
	 */
	inline void OnPeerDisconnected( PeerEventCallback fnc )		{ mOnDisconnected = fnc; }
	
	/**
	 * Retrieve the number of peers in the group.
	 */
	inline uint32_t GetNumPeers() const							{ return mPeers.size(); }
	
	/**
	 * Retrieve a message queue.
	 */
	inline Peer* GetPeer( uint32_t index )						{ return mPeers[index]; }
	
	
protected:
	friend class PeerDiscovery;

	PeerGroup();
	~PeerGroup();
	
	std::vector<Peer*> mPeers;
	
	PeerEventCallback mOnConnected;
	PeerEventCallback mOnDisconnected;
}; 

}

#endif
