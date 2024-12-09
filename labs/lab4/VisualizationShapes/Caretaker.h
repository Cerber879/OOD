#pragma once

#include "Memento.h"
#include <stack>

class Caretaker 
{
public:
	static Caretaker& GetInstance()
	{
		static Caretaker instance;
		return instance;
	}

    void Save(const Memento& memento);
    Memento Undo();

private:
	Caretaker() : m_mementos(std::stack<Memento>()) {}

	Caretaker(const Caretaker&) = delete;
	Caretaker& operator=(const Caretaker&) = delete;

    std::stack<Memento> m_mementos;
};
