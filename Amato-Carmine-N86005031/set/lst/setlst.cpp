
namespace lasd {

/* ************************************************************************** */
//SetLst

//Specific constructors
template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& container) {
    container.Traverse([this](const Data& dat) {
        Insert(dat);
    });
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& container) {
    container.Map([this](Data& dat) {
        Insert(std::move(dat));
    });
}

//Copy constructor
template <typename Data>
SetLst<Data>::SetLst(const SetLst& set) : List<Data>(set) {}

//Move constructor
template <typename Data>
SetLst<Data>::SetLst(SetLst&& set) noexcept : List<Data>(std::move(set)) {}


//Copy assignment
template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& set) {
    List<Data>::operator=(set);
    return *this;
}

//Move assignment
template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& set) noexcept {
    List<Data>::operator=(std::move(set));
    return *this;
}

//Comparison operators
template <typename Data>
bool SetLst<Data>::operator==(const SetLst& set) const noexcept {
    return List<Data>::operator==(set);
    
}

template <typename Data>
bool SetLst<Data>::operator!=(const SetLst& set) const noexcept {
    return !(*this == set);
}

//Specific member functions (inherited from OrderedDictionaryContainer)
template <typename Data>
const Data& SetLst<Data>::Min() const {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    return head->element;
}

template <typename Data>
Data SetLst<Data>::MinNRemove() {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    Data min = Min();
    Remove(head->element);
    return min;
}

template <typename Data>
void SetLst<Data>::RemoveMin() {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    Data min = Min();
    Remove(min);
}

template <typename Data>
const Data& SetLst<Data>::Max() const {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    return tail->element;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove() {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    Data max = Max();
    Remove(tail->element);
    return max;
}

template <typename Data>
void SetLst<Data>::RemoveMax() {
    if(head == nullptr)
        throw std::length_error("SetLst is empty");
    Data max = Max();
    Remove(max);
}

template <typename Data>
const Data& SetLst<Data>::Predecessor(const Data& dat) const {
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr && current->element < dat) {
        prev = current;
        current = current->next;
    }

    if(prev == nullptr)
        throw std::length_error("No predecessor found");

    return prev->element;
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& dat) {
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prevPred = nullptr;

    // Trova l'ultimo nodo con elemento < dat
    while (current != nullptr && current->element < dat) {
        prevPred = prev;      // Nodo precedente al predecessore
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        throw std::length_error("No predecessor found");
    }

    // Rimuovi il nodo predNode dalla lista
    if (prevPred != nullptr) {
        prevPred->next = prev->next;  // Collega il predecessore precedente al successivo
    } else {
        head = prev->next;  // Il predecessore è la testa
    }

    // Aggiorna tail se il predecessore era la coda
    if (prev->next == nullptr) {
        tail = prevPred;
    }

    Data predecessor = prev->element;
    prev->next = nullptr;  
    delete prev;
    size--;
    return predecessor;
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& dat) {
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prevPred = nullptr;

    // Trova l'ultimo nodo con elemento < dat
    while (current != nullptr && current->element < dat) {
        prevPred = prev;      // Nodo precedente al predecessore
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        throw std::length_error("No predecessor found");
    }

    // Rimuovi il nodo predNode dalla lista
    if (prevPred != nullptr) {
        prevPred->next = prev->next;  // Collega il predecessore precedente al successivo
    } else {
        head = prev->next;  // Il predecessore è la testa
    }

    // Aggiorna tail se il predecessore era la coda
    if (prev->next == nullptr) {
        tail = prevPred;
    }

    prev->next = nullptr;  
    delete prev;
    size--;
}

template <typename Data>
const Data& SetLst<Data>::Successor(const Data& dat) const {
    typename List<Data>::Node* current = head;
    while(current != nullptr && current->element <= dat) {
        current = current->next;
    }

    if(current == nullptr)
        throw std::length_error("No successor found");

    return current->element;
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& dat) {
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* current = head;

    // Trova il primo nodo con elemento > dat
    while (current != nullptr && current->element <= dat) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        throw std::length_error("No successor found");
    }

    // Rimuovi il nodo successorNode dalla lista
    if (prev != nullptr) {
        prev->next = current->next; // Aggiorna il next del predecessore
    } else {
        head = current->next; // Il successore è la testa
    }

    // Aggiorna tail se il successore era la coda
    if (current->next == nullptr) {
        tail = prev;
    }

    Data successor = current->element;
    current->next = nullptr; 
    delete current; 
    size--; 
    return successor;
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& dat) {
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* current = head;

    // Trova il primo nodo con elemento > dat
    while (current != nullptr && current->element <= dat) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        throw std::length_error("No successor found");
    }

    // Rimuovi il nodo successorNode dalla lista
    if (prev != nullptr) {
        prev->next = current->next; // Aggiorna il next del predecessore
    } else {
        head = current->next; // Il successore è la testa
    }

    // Aggiorna tail se il successore era la coda
    if (current->next == nullptr) {
        tail = prev;
    }

    current->next = nullptr; 
    delete current; 
    size--;
}

//Specific member functions (inherited from DictionaryContainer)
template <typename Data>
bool SetLst<Data>::Insert(const Data& dat) {
    if(Exists(dat))
        return false;

    typename List<Data>::Node* newNode = new typename List<Data>::Node(dat);

    if(head == nullptr) {
        head = tail = newNode;
        size++;
        return true;
    }

    if(newNode->element < head->element) {
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr && current->element < newNode->element) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    newNode->next = current;

    if(current == nullptr) {
        tail = newNode;
    }
    size++;
    return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data&& dat) {
    if(Exists(dat))
        return false;

    typename List<Data>::Node* newNode = new typename List<Data>::Node(std::move(dat));

    if(head == nullptr) {
        head = tail = newNode;
        size++;
        return true;
    }

    if(newNode->element < head->element) {
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr && current->element < newNode->element) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    newNode->next = current;

    if(current == nullptr) {
        tail = newNode;
    }
    size++;
    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& dat) {
    if(!Exists(dat))
        return false;
    
    if(head == nullptr)
        return false;

    if(head->element == dat) {
        typename List<Data>::Node* temp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        temp->next = nullptr;
        delete temp;
        size--;
        return true;
    }

    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->element == dat) {
            if(prev != nullptr) {
                prev->next = current->next;
            }
            if(current == tail) {
                tail = prev;
            }
            current->next = nullptr;
            delete current;
            size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

//Specific member function (inherited from LinearContainer)
template <typename Data>
const Data& SetLst<Data>::operator[](const unsigned long i) const {
    return List<Data>::operator[](i);
}

//Specific member function (inherited from TestableContainer)
template <typename Data>
bool SetLst<Data>::Exists(const Data& dat) const noexcept {
    unsigned long left = 0;
    unsigned long right = (size == 0) ? 0 : size - 1;
    while (left <= right) {
        unsigned long mid = (left + right) / 2;
        typename List<Data>::Node* midNode = GetAt(mid); 
        if (midNode == nullptr) 
            return false;
        if (midNode->element == dat) {
            return true;
        } else if (midNode->element < dat) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
// template <typename Data>
// bool SetLst<Data>::Exists(const Data& dat) const noexcept {
//     typename List<Data>::Node* current = head;
//     while(current != nullptr) {
//         if(current->element == dat)
//             return true;
//         if(current->element > dat)
//             break;
//         current = current->next;
//     }
//     return false;
// }

//Specific member function (inherited from ClearableContainer)
template <typename Data>
void SetLst<Data>::Clear() {
    List<Data>::Clear();
}

//Auxiliary function
template <typename Data>
typename List<Data>::Node* SetLst<Data>::GetAt(const unsigned long i) const {
    typename List<Data>::Node* current = head;
    
    for (unsigned long pos = 0; pos < i; ++pos) {
        if (current == nullptr) 
            return nullptr;
        current = current->next;
    }
    return current;
}

/* ************************************************************************** */

}
