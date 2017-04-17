#ifndef FSMFIND_CPP
#define FSMFIND_CPP

#include "fsmfind.h"

namespace CS330 {
	template < typename Symbol >
	FSMFind<Symbol>::FSMFind(const std::vector<Symbol>& _pattern): 
	pattern(_pattern),
	states(std::vector<State<Symbol>*>()),
	vecOnFind(std::vector<AbstractCallback*>()),
	vecOnDone(std::vector<AbstractCallback*>()),
	possibleInput(std::set<Symbol>())
	{
		for (unsigned int i = 0; i < pattern.size(); ++i) {
			possibleInput.insert(pattern[i]);
		}
		CreateTransitions();
	}

	template < typename Symbol >
	FSMFind<Symbol>::~FSMFind() {
		for(State<Symbol> * state: states) {
			delete state;
		}
	}

	template < typename Symbol >
	void FSMFind<Symbol>::RegisterOnFind(AbstractCallback* p_cb) {
		vecOnFind.push_back(p_cb);
	}

	template < typename Symbol >
	void FSMFind<Symbol>::RegisterOnDone(AbstractCallback* p_cb) {
		vecOnDone.push_back(p_cb);
	}

	template < typename Symbol >
	void FSMFind<Symbol>::Find(const std::vector<Symbol>& text) {
		State<Symbol> const * state = states[0];
		// Go through the text
		for (unsigned i = 0; i < text.size(); ++i) {
			// Get the next state
			Symbol input = text[i];
			state = state->NextState(input);
			// If terminal state
			if(state->IsTerminal()) {
				// Call "OnFind" functions
				for (unsigned j = 0; j < vecOnFind.size(); ++j) {
					vecOnFind[j]->OnFind(i);
				}
			}
		}

		// Call "OnDone" functions when done
		for (unsigned i = 0; i < vecOnDone.size(); ++i) {
			vecOnDone[i]->OnDone();
		}
	}

	template < typename Symbol >
	FSMFind<Symbol>::FSMFind(const FSMFind&) {

	}

	template < typename Symbol >
	FSMFind<Symbol>& FSMFind<Symbol>::operator= (const FSMFind&) {

		return *this;

	}

	template < typename Symbol >
	std::vector<Symbol> FSMFind<Symbol>::substring(const std::vector<Symbol>& str, size_t pos, size_t length) const {
		return std::vector<Symbol>(str.begin() + pos, str.begin() + pos + length);
	}

	template < typename Symbol >
	void FSMFind<Symbol>::CreateTransitions() {
		State<Symbol>* initialState = new State<Symbol>(std::vector<Symbol>());
		states.push_back(initialState);
		std::vector<Symbol> name;
		// Regular transitions
		for (unsigned i = 0; i < pattern.size(); ++i) {
			name.push_back(pattern[i]);
			State<Symbol>* state = new State<Symbol>(name, i == pattern.size()-1, initialState);
			states.push_back(state);
			State<Symbol>* prevState = states[i];
			prevState->AddTransition(pattern[i], state);
		}

		// Rest of transitions
		// Go through all the states
		for (unsigned i = 1; i < states.size(); ++i) {
			State<Symbol>* currentState = states[i];
			name = currentState->Name();

			// Go through all possible symbols that can be added to the state
			for(Symbol symbol : possibleInput) {
				// add the symbol
				name.push_back(symbol);
				// Go through all possible matchings with the resulting name
				for (unsigned int k = 1; k < name.size(); ++k) {
					std::vector<Symbol> possibleName = substring(name, k, name.size() - k);
					// Create transition if the substring is equal to the state with the same size
					if (possibleName == states[possibleName.size()]->Name()) {
						currentState->AddTransition(symbol, states[possibleName.size()]);
					}
				}
				name.pop_back();
			}
		}
	}
}


#endif
