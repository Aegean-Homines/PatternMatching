#ifndef STATE_H
#define STATE_H
#include <vector>
#include <map>

// this is a SAMPLE - driver does not use this class directly. 
// You can change anything you want - including the name of the class.

namespace CS330 {
	template <typename Symbol>
		class State {
			public:
				////////////////////////////////////////////////////////////
				//ctor for the initial node - default transition is to self
				//name is 
				State(const std::vector<Symbol>& _name);
				//////////////////////////////////////////////////////////// 
				//ctor for non-initial nodes, 
				//default transition should be set to the initial node -
				//provided by the user.
				State(  const std::vector<Symbol>& _name, 
						bool _isTerminal, 
						const State* p_default_target);
				////////////////////////////////////////////////////////////
				//specify non-default transition. 
				void AddTransition(const Symbol & sym, const State * p_target);
				////////////////////////////////////////////////////////////
				//the main part of state. 
				const State* NextState(const Symbol & sym) const;
				////////////////////////////////////////////////////////////
				// obvious
				void PrintDebug() const;
				////////////////////////////////////////////////////////////
				// just return the name
				std::vector<Symbol> Name() const;
				////////////////////////////////////////////////////////////
				// check is we've reached the goal
				bool IsTerminal() const;
				////////////////////////////////////////////////////////////
			private:
				typedef std::map<Symbol, const State<Symbol>*> TransitionMap;
				////////////////////////////////////////////////////////////
				// used by PrintDebug
				void Print(const std::vector<Symbol> & v) const;
				State<Symbol>(const State<Symbol> &);
				State<Symbol>& operator=(const State<Symbol>&);

				std::vector<Symbol> name;   // human readable name of the state, use prefix itself
				bool isTerminal;            // is the goal state?
				TransitionMap transitions;  //transitions for all symbols in the pattern
				State<Symbol> const * p_default_state;
		};

	
}
#include "state.cpp"
#endif
