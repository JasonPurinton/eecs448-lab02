/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList()
{
	m_front= nullptr;
	m_size= 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
		// Checks if list is empty
	if(m_front == nullptr) return true;
	return(false);
}

template <typename T>
int LinkedList<T>::size() const
{
	// Returns the size of the list
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
Node<T>* tempPtr = m_front;
bool isFound = false;
	// Flag to tell if the method is exit.
	bool exit = false;
	if(tempPtr != nullptr && !isFound)
	{
		while(tempPtr != nullptr && !exit)
		{
			// If the position we're looking at is the same as the input position,
			if(value == tempPtr->getValue())
			{
				isFound= true;
				exit = true;
			}
			// Make the temporary pointer look at the next node in the list.
			tempPtr = tempPtr->getNext();
		}
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
/*	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
//	bool isRemoved = false;

	/** TODO
		Fix this method
	*/

		// Create a node pointer to look at the front of the array.
	Node<T>* tempPtr = m_front;
	if(!isEmpty())
	{
		// If this is not the last node in list
		if(tempPtr->getNext() != nullptr)
		{
			//Next pointer isn't null
			while(tempPtr->getNext()->getNext()!= nullptr)
			{
				tempPtr= tempPtr->getNext();
			}
			// Delete the last pointe
			delete tempPtr->getNext();
			tempPtr->setNext(nullptr);
			m_size--;
			//Return that we just deleted a node.
			return true;
		}
		// If this is the last node in the list
		else
		{
			//Make m_front point at null
			m_front = nullptr;
			// Delete this node that we're pointing at,
			delete tempPtr;
			m_size--;
			// Return that we deleted a node.
			return true;
		}
	}
	// Return false since you can't delete a node if there are no nodes.
	else return false;
//	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
