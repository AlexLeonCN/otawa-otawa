/*
 *	$Id$
 *	BCG class interface
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2008, IRIT UPS.
 * 
 *	OTAWA is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	OTAWA is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OTAWA; if not, write to the Free Software 
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef BCG_H_
#define BCG_H_

#include <otawa/otawa.h>
#include <otawa/dfa/BitSet.h>
#include <otawa/graph/DiGraph.h>

namespace otawa { namespace bpred {

class BCGNode;
class BCGEdge;




class BCG: public otawa::graph::GenDiGraph<BCGNode, BCGEdge> {
public:
	BCG(int _class);
	BCG(const otawa::dfa::BitSet& _hist);
	~BCG();
	int getClass();
	otawa::dfa::BitSet& getHistory(); 
private:
	int m_class;
	otawa::dfa::BitSet *m_history;
};




class BCGEdge: public otawa::graph::GenEdge<BCGNode, BCGEdge> {
public:
	BCGEdge(bool taken);
	~BCGEdge();
	bool isTaken();
private:
	bool m_edge_taken;
};




class BCGNode: public otawa::graph::GenVertex<BCGNode, BCGEdge> {
public:
	BCGNode(int cfg_bb, bool entry, bool exit, bool exit_T=false, bool exit_NT=false);
	BCGNode(int cfg_bb, bool entry, bool exit,const otawa::dfa::BitSet *history, bool exit_T=false, bool exit_NT=false);
	~BCGNode();
	
	int getCorrespondingBBNumber();
	bool isEntry();
	bool isExit();
	bool exitsWithT();
	bool exitsWithNT();
	bool isSuccessor(BCGNode* succ,bool& withT, bool& withNT);
	otawa::dfa::BitSet& getHistory(); 

private:
	bool m_entry;
	bool m_exit;
	bool m_exit_T; // exits with Taken
	bool m_exit_NT; // exits with NotTaken
	otawa::dfa::BitSet *m_history;
	int m_bb;
};

} }		// otawa::bpred

#endif /*BCG_H_*/

