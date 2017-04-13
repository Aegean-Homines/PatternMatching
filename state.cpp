#ifndef STATE_CPP
#define STATE_CPP

#include "state.h"

namespace CS330 {
	template < typename Symbol >
	State<Symbol>::State(const std::vector<Symbol>& _name) {}

	template < typename Symbol >
	State<Symbol>::State(const std::vector<Symbol>& _name, bool _isTerminal, const State* p_default_target) {}

	template < typename Symbol >
	void State<Symbol>::AddTransition(const Symbol& sym, const State<Symbol>* p_target) {}

	template < typename Symbol >
	const State<Symbol>* State<Symbol>::NextState(const Symbol& sym) const {
		return nullptr;
	}

	template < typename Symbol >
	void State<Symbol>::PrintDebug() const {}

	template < typename Symbol >
	std::vector<Symbol> State<Symbol>::Name() const {
		return std::vector<Symbol>();
	}

	template < typename Symbol >
	bool State<Symbol>::IsTerminal() const {
		return false;
	}

	template < typename Symbol >
	void State<Symbol>::Print(const std::vector<Symbol>& v) const {}
}


#endif