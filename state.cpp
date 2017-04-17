#ifndef STATE_CPP
#define STATE_CPP

#include "state.h"

namespace CS330 {
	template < typename Symbol >
	State<Symbol>::State(const std::vector<Symbol>& _name): 
	name(_name),
	isTerminal(false),
	transitions(std::map<Symbol, const State<Symbol>*>()),
	p_default_state(this) {
		
	}

	template < typename Symbol >
	State<Symbol>::State(const std::vector<Symbol>& _name, bool _isTerminal, const State* p_default_target):
	name(_name),
	isTerminal(_isTerminal),
	transitions(std::map<Symbol, const State<Symbol>*>()),
	p_default_state(p_default_target)
	{}

	template < typename Symbol >
	void State<Symbol>::AddTransition(const Symbol& sym, const State<Symbol>* p_target) {
		transitions.insert(std::make_pair(sym, p_target));
	}

	template < typename Symbol >
	const State<Symbol>* State<Symbol>::NextState(const Symbol& sym) const {
		typename TransitionMap::const_iterator cIter;
		cIter = transitions.find(sym);
		if(cIter == transitions.end()) {
			return p_default_state;
		}else {
			return cIter->second;
		}
	}

	template < typename Symbol >
	void State<Symbol>::PrintDebug() const {
		std::cout << "Symbol for this State: " << std::endl;
		for (Symbol letter : name) {
			std::cout << letter;
		}
		std::cout << std::endl;
		std::cout << "All transitions defined for this state: " << std::endl;
		for(std::pair< Symbol, const State<Symbol>* > & entry : transitions) {
			std::cout << "Symbol: " << entry.first << " - Target: " << entry->second->Print() << std::endl;
		}

	}

	template < typename Symbol >
	std::vector<Symbol> State<Symbol>::Name() const {
		return name;
	}

	template < typename Symbol >
	bool State<Symbol>::IsTerminal() const {
		return isTerminal;
	}

	template < typename Symbol >
	void State<Symbol>::Print(const std::vector<Symbol>& v) const {
		std::string sName;
		for (Symbol letter : v) {
			sName.push_back(letter);
		}
		std::cout << sName.c_str() << std::endl;
	}

	template < typename Symbol >
	State<Symbol>::State ( const State<Symbol>& ){ }

	template < typename Symbol >
	State<Symbol>& State<Symbol>::operator= ( const State<Symbol>& ) {
		return *this;
	}
}


#endif