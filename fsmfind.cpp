#ifndef FSMFIND_CPP
#define FSMFIND_CPP

#include "fsmfind.h"

namespace CS330 {
	template < typename Symbol >
	FSMFind<Symbol>::FSMFind(const std::vector<Symbol>& _pattern) {

	}

	template < typename Symbol >
	FSMFind<Symbol>::~FSMFind() {}

	template < typename Symbol >
	void FSMFind<Symbol>::RegisterOnFind(AbstractCallback* p_cb) {}

	template < typename Symbol >
	void FSMFind<Symbol>::RegisterOnDone(AbstractCallback* p_cb) {}

	template < typename Symbol >
	void FSMFind<Symbol>::Find(const std::vector<Symbol>& text) {}

	template < typename Symbol >
	FSMFind<Symbol>::FSMFind(const FSMFind&) {

	}

	template < typename Symbol >
	FSMFind<Symbol>& FSMFind<Symbol>::operator= (const FSMFind&) {

		return FSMFind<Symbol>();

	}

	template < typename Symbol >
	std::vector<Symbol> FSMFind<Symbol>::substring(const std::vector<Symbol>& str, size_t pos, size_t length) const {

		return std::vector<Symbol>();

	}

	template < typename Symbol >
	void FSMFind<Symbol>::CreateTransitions(size_t i, size_t j0) {}
}


#endif
