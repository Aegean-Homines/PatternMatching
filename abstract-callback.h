#ifndef ABSTRACTCALLBACK_H
#define ABSTRACTCALLBACK_H

// interface for callbacks to be used with FSMfind class
namespace CS330 {
	class AbstractCallback {
		public:
			virtual void OnFind(size_t pos) = 0; // called on each occurence found
			virtual void OnDone() = 0;           // called after last character is read
			virtual ~AbstractCallback() {}
	};
}
#endif
