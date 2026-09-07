#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() {return this-> c.begin(); }
		iterator end() {return this->c.end(); }
		void push(T obj) {this->c.push_back(obj); }
		void pop() {this->c.pop_back(); }
		void emplace(T obj) {this->c.emplace(obj); }
		size_t size() {return this->c.size(); }
		void empty() {this->c.empty(); }
		T top() {return this->c.back(); }
		void swap(MutantStack _stack) {this->c.swap(_stack); }
};

#endif