#include "Caretaker.h"

void Caretaker::Save(const Memento& memento)
{
    m_mementos.push(memento);
}

Memento Caretaker::Undo()
{
    if (!m_mementos.size() == 0)
    {
        Memento memento = m_mementos.top();
        m_mementos.pop();
        return memento;
    }

    return Memento();
}