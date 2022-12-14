/*
 *	BBTimeSimulator class implementation
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2006-18, IRIT UPS.
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

#include <otawa/prog/Process.h>
#include <otawa/tsim/BBTimeSimulator.h>
#include <otawa/ipet/IPET.h>
#include <otawa/sim.h>
#include <otawa/sim/BasicBlockDriver.h>
#include <otawa/prog/WorkSpace.h>
#include <otawa/proc/ProcessorException.h>

using namespace otawa::sim;

namespace otawa { namespace tsim {

/**
 */
p::declare BBTimeSimulator::reg = p::init("otawa::tsim::BBTimeSimulator", Version(2, 0, 0))
	.extend<BBProcessor>()
	.make<BBTimeSimulator>()
	.provide(ipet::BB_TIME_FEATURE)
	.require(REGISTER_USAGE_FEATURE);


/**
 * This processor compute the execution time of each basic block using the
 * provided simulator.
 *
 * @par Provided Features
 * @li @ref otawa::ipet::BB_TIME_FEATURE
 *
 * @par Required Feature
 * @li @ref otawa::REGISTER_USAGE_FEATURE
 */
BBTimeSimulator::BBTimeSimulator(p::declare& r): BBProcessor(r), state(nullptr) {
}


/**
 */
void BBTimeSimulator::processBB(WorkSpace *fw, CFG *cfg, Block *b) {
	if(!b->isBasic())
		return;
	BasicBlock *bb = b->toBasic();
	sim::BasicBlockDriver driver(bb);
	state->reset();
	state->run(driver);
	ipet::TIME(bb) = state->cycle();
}


/**
 */
void BBTimeSimulator::setup(WorkSpace *ws) {
	sim::Simulator *simulator = ws->process()->simulator();
	if(!simulator)
		throw ProcessorException(*this, "no simulator available");
	PropList props;
	USE_MEMORY(props) = false;
	state = simulator->instantiate(ws, props);
}


/**
 */
void BBTimeSimulator::cleanup(WorkSpace *ws) {
	// TODO delete state;
	state = 0;
}

} }		// otawa::tsim
