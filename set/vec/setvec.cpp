namespace lasd {

/* ************************************************************************** */
//SetVec
//Specific constructors
template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& container) {
    container.Traverse([this](const Data& dat) {
        Insert(dat);
    });
}

template <typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& container) {
    container.Map([this](Data& dat) {
        Insert(std::move(dat));
    });
}

//Copy constructor
template <typename Data>
SetVec<Data>::SetVec(const SetVec& set) 
    : Elements(set.Elements), head(set.head), tail(set.tail) {
    size = set.size; 
}

//Move constructor
template <typename Data>
SetVec<Data>::SetVec(SetVec&& set) noexcept 
    : Elements(std::move(set.Elements)), head(set.head), tail(set.tail) {
    size = set.size; 
    set.head = 0;
    set.tail = 0;
    set.size = 0; 
}

//Copy assignment
template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec& set) {
    if (this != &set) {
        Elements = set.Elements;
        head = set.head;
        tail = set.tail;
        size = set.size; 
    }
    return *this;
}

//Move assignment
template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec&& set) noexcept {
    if (this != &set) {
        Elements = std::move(set.Elements);
        head = set.head;
        tail = set.tail;
        size = set.size; 
        set.head = set.tail = 0;
        set.size = 0; 
    }
    return *this;
}

//Comparison operators
template <typename Data>
bool SetVec<Data>::operator==(const SetVec& set) const noexcept {
    if (Size() != set.Size()) 
        return false;
    for (unsigned long i = 0; i < Size(); ++i) {
        unsigned long thisIndex = (head + i + Elements.Size()) % Elements.Size();
        unsigned long otherIndex = (set.head + i + set.Elements.Size()) % set.Elements.Size();
        if (Elements[thisIndex] != set.Elements[otherIndex]) return false;
    }
    return true;
}

template <typename Data>
bool SetVec<Data>::operator!=(const SetVec& set) const noexcept {
    return !(*this == set);
}

//Specific member functions (inherited form OrderedDictionaryContainer)
template <typename Data>
const Data& SetVec<Data>::Min() const {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    return Elements[head];
}

template <typename Data>
Data SetVec<Data>::MinNRemove() {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    Data min = Elements[head];
    head = (head + 1 + Elements.Size()) % Elements.Size();
    size--;
    Reduce();
    return min;
}

template <typename Data>
void SetVec<Data>::RemoveMin() {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    head = (head + 1 + Elements.Size()) % Elements.Size();
    size--;
    Reduce();
}

template <typename Data>
const Data& SetVec<Data>::Max() const {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    return Elements[(tail - 1 + Elements.Size()) % Elements.Size()];
}

template <typename Data>
Data SetVec<Data>::MaxNRemove() {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    Data max = Elements[(tail - 1 + Elements.Size()) % Elements.Size()];
    tail = (tail - 1 + Elements.Size()) % Elements.Size();
    size--;
    Reduce();
    return max;
}

template <typename Data>
void SetVec<Data>::RemoveMax() {
    if(Size() == 0)
        throw std::length_error("Set is empty");
    tail = (tail - 1 + Elements.Size()) % Elements.Size();
    size--;
    Reduce();
}

template <typename Data>
const Data& SetVec<Data>::Predecessor(const Data& dat) const {
    const long capacity = Elements.Size(); // "size" è la capacità del vettore
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long predecessor_idx = -1; // Indice logico del predecessore

    // Ricerca binaria per trovare il più grande elemento < dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity; // Converti a indice fisico

        if (Elements[physical_mid] < dat) {
            predecessor_idx = mid; // Potenziale candidato
            low = mid + 1; // Cerca a destra per elementi più grandi
        } else {
            high = mid - 1; // Cerca a sinistra
        }
    }

    // Se nessun elemento è minore di dat
    if (predecessor_idx == -1) {
        throw std::length_error("No predecessor found");
    }

    // Restituisci l'elemento fisico corrispondente
    return Elements[(head + predecessor_idx + capacity) % capacity];
}

template <typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& dat) {
    const long capacity = Elements.Size();
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long predecessor_idx = -1;
    // Ricerca binaria per trovare il più grande elemento < dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity;

        if (Elements[physical_mid] < dat) {
            predecessor_idx = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Se nessun elemento è minore di dat
    if (predecessor_idx == -1) {
        throw std::length_error("No predecessor found");
    }

    // Restituisci l'elemento fisico corrispondente
    Data pred = Elements[(head + predecessor_idx + capacity) % capacity];

    // Determina se è più conveniente spostare gli elementi da sinistra o da destra
    const long elementsFromHead = predecessor_idx;
    const long elementsFromTail = Size() - predecessor_idx - 1;
    
    if (elementsFromHead <= elementsFromTail) {
        ShiftRight(0, predecessor_idx);
        head = (head + 1 + Elements.Size()) % Elements.Size();
    } else {
        ShiftLeft(predecessor_idx, Size() - 1);
        tail = (tail - 1 + Elements.Size()) % Elements.Size();
    }
    
    size--;
    Reduce();
    return pred;
}

template <typename Data>
void SetVec<Data>::RemovePredecessor(const Data& dat) {
    const long capacity = Elements.Size();    
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long predecessor_idx = -1;
    // Ricerca binaria per trovare il più grande elemento < dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity;

        if (Elements[physical_mid] < dat) {
            predecessor_idx = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Se nessun elemento è minore di dat
    if (predecessor_idx == -1) {
        throw std::length_error("No predecessor found");
    }

    // Determina se è più conveniente spostare gli elementi da sinistra o da destra
    const long elementsFromHead = predecessor_idx;
    const long elementsFromTail = Size() - predecessor_idx - 1;
    
    if (elementsFromHead <= elementsFromTail) {
        ShiftRight(0, predecessor_idx);
        head = (head + 1 + Elements.Size()) % Elements.Size();
    } else {
        ShiftLeft(predecessor_idx, Size() - 1);
        tail = (tail - 1 + Elements.Size()) % Elements.Size();
    }
    
    size--;
    Reduce();
}

template <typename Data>
const Data& SetVec<Data>::Successor(const Data& dat) const {
    const long capacity = Elements.Size(); 
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long successor_idx = -1; // Indice logico del successore

    // Ricerca binaria per trovare il più piccolo elemento > dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity; // Converti a indice fisico

        if (Elements[physical_mid] > dat) {
            successor_idx = mid; // Potenziale candidato
            high = mid - 1; // Cerca a sinistra per elementi più piccoli
        } else {
            low = mid + 1; // Cerca a destra
        }
    }

    // Se nessun elemento è maggiore di dat
    if (successor_idx == -1) {
        throw std::length_error("No successor found");
    }

    // Restituisci l'elemento fisico corrispondente
    return Elements[(head + successor_idx + capacity) % capacity];
}

template <typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& dat) {
    const long capacity = Elements.Size();
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long successor_idx = -1;

    // Ricerca binaria per trovare il più piccolo elemento > dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity;

        if (Elements[physical_mid] > dat) {
            successor_idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Se nessun elemento è maggiore di dat
    if (successor_idx == -1) {
        throw std::length_error("No successor found");
    }

    // Restituisci l'elemento fisico corrispondente
    Data succ = Elements[(head + successor_idx + capacity) % capacity];
    
    const long elementsFromHead = successor_idx;
    const long elementsFromTail = Size() - successor_idx - 1;
    
    if (elementsFromHead <= elementsFromTail) {
        ShiftRight(0, successor_idx);
        head = (head + 1 + Elements.Size()) % Elements.Size();
    } else {
        ShiftLeft(successor_idx, Size() - 1);
        tail = (tail - 1 + Elements.Size()) % Elements.Size();
    }

    size--;
    Reduce();
    return succ;
}

template <typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& dat) {
    const long capacity = Elements.Size();
    const long numElements = Size();

    // Controlla se il vettore è vuoto
    if (numElements == 0) {
        throw std::length_error("SetVec is empty");
    }

    long low = 0;
    long high = numElements - 1;
    long successor_idx = -1;

    // Ricerca binaria per trovare il più piccolo elemento > dat
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long physical_mid = (head + mid + capacity) % capacity;

        if (Elements[physical_mid] > dat) {
            successor_idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Se nessun elemento è maggiore di dat
    if (successor_idx == -1) {
        throw std::length_error("No successor found");
    }

    const long elementsFromHead = successor_idx;
    const long elementsFromTail = Size() - successor_idx - 1;
    
    if (elementsFromHead <= elementsFromTail) {
        ShiftRight(0, successor_idx);
        head = (head + 1 + Elements.Size()) % Elements.Size();
    } else {
        ShiftLeft(successor_idx, Size() - 1);
        tail = (tail - 1 + Elements.Size()) % Elements.Size();
    }
    
    size--;
    Reduce();
}

//Specific member functions (inherited from DictionaryContainer)
template <typename Data>
bool SetVec<Data>::Insert(const Data& dat) {
    // Ridimensiona se necessario
    Expand();
    
    unsigned long pos = FindIndex(dat);

    // Verifica se l'elemento esiste già
    // Non uso Exists per evitare di riattraversare l'array
    if (pos < Size()) {
        unsigned long physicalPos = (head + pos) % Elements.Size();
        if (Elements[physicalPos] == dat) {
            return false;
        }
    }

    // Sposta gli elementi per fare spazio
    ShiftRight(pos, Size());
    
    // Inserisci il nuovo elemento
    unsigned long insertPos = (head + pos) % Elements.Size();
    Elements[insertPos] = dat;

    // Aggiorna tail e size
    tail = (tail + 1) % Elements.Size();
    size++;
    return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data&& dat) {
    // Ridimensiona se necessario
    Expand();
    
    unsigned long pos = FindIndex(dat);

    // Verifica se l'elemento esiste già
    // Non uso Exists per evitare di riattraversare l'array
    if (pos < Size()) {
        unsigned long physicalPos = (head + pos) % Elements.Size();
        if (Elements[physicalPos] == dat) {
            return false;
        }
    }

    // Sposta gli elementi per fare spazio
    ShiftRight(pos, Size());

    // Inserisci il nuovo elemento
    unsigned long insertPos = (head + pos) % Elements.Size();
    Elements[insertPos] = std::move(dat);

    // Aggiorna tail e size
    tail = (tail + 1) % Elements.Size();
    size++;
    return true;
}

template <typename Data>
bool SetVec<Data>::Remove(const Data& dat) {
    if(Size() == 0)
        return false;

    // Trova la posizione logica dell'elemento
    long pos = FindExactIndex(dat);

    // Se l'elemento non esiste, restituisci false
    if(pos == -1)
        return false;
    
    // Determina se è più conveniente spostare gli elementi da sinistra o da destra
    const long elementsFromHead = pos;
    const long elementsFromTail = Size() - pos - 1;
    
    if (elementsFromHead <= elementsFromTail) {
        ShiftRight(0, pos);
        head = (head + 1 + Elements.Size()) % Elements.Size();
    } else {
        ShiftLeft(pos, Size() - 1);
        tail = (tail - 1 + Elements.Size()) % Elements.Size();
    }
    
    // Aggiorna size
    size--;

    // Controlla se la size è <= 20% della capacità e ridimensiona se necessario
    Reduce();

    return true;
}

//Specific member function (inherited from LinearContainer)
template <typename Data>
const Data& SetVec<Data>::operator[](const unsigned long i) const {
    if(i >= Size())
        throw std::out_of_range("Index out of range");
    return Elements[(head + i + Elements.Size()) % Elements.Size()];
}

//Specific member function (inherited from TestableContainer)
template <typename Data>
bool SetVec<Data>::Exists(const Data& dat) const noexcept {
    if(Size() == 0) 
        return false;

    long left = 0;
    long right = Size() - 1;
    long capacity = Elements.Size();

    while(left <= right) {
        long mid = left + (right - left) / 2;
        //Converto indici logici in indici fisici
        long physical_mid = (head + mid) % capacity;
        if(Elements[physical_mid] == dat) {
            return true;
        } else if(Elements[physical_mid] < dat) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
// template <typename Data>
// bool SetVec<Data>::Exists(const Data& dat) const noexcept {
//     for (unsigned long i = 0; i < Size(); ++i) {
//         unsigned long physicalIdx = (head + i + Elements.Size()) % Elements.Size();
//         if (Elements[physicalIdx] == dat) {
//             return true;
//         }
//     }
//     return false;
// }

//Specific member function (inherited from ClearableContainer)
template <typename Data>
void SetVec<Data>::Clear() {
    head = 0;
    tail = 0;
    size = 0;
}

//Auxiliary functions
template <typename Data>
unsigned long SetVec<Data>::FindIndex(const Data& dat) const {
    long long left = 0;
    long long right = Size();
    
    while (left < right) {
        unsigned long mid = (left + right) / 2;
        unsigned long physicalMid = (head + mid) % Elements.Size();
        if (Elements[physicalMid] < dat) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

template <typename Data>
long SetVec<Data>::FindExactIndex(const Data& dat) const {
    long left = 0;
    long right = Size() - 1;
    unsigned long capacity = Elements.Size();
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long physical_mid = (head + mid + capacity) % capacity;
        
        if (Elements[physical_mid] == dat) {
            return mid; 
        } else if (Elements[physical_mid] < dat) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename Data>
void SetVec<Data>::Resize(unsigned long newCapacity) {
    if (newCapacity < Size()) {
        newCapacity = Size();
    }

    Vector<Data> newElements(newCapacity);
    unsigned long numElements = Size();

    // Copia gli elementi esistenti nel nuovo array
    for (unsigned long i = 0; i < numElements; ++i) {
        newElements[i] = std::move(Elements[(head + i + Elements.Size()) % Elements.Size()]);
    }

    Elements = std::move(newElements);
    head = 0;
    tail = numElements;
}

// Funzioni ausiliarie per lo spostamento degli elementi
template <typename Data>
void SetVec<Data>::ShiftRight(unsigned long startIdx, unsigned long endIdx) {
    // Sposta gli elementi dalla posizione startIdx a endIdx verso destra
    for (unsigned long i = endIdx; i > startIdx; --i) {
        unsigned long current = (head + i + Elements.Size()) % Elements.Size();
        unsigned long prev = (head + i - 1 + Elements.Size()) % Elements.Size();
        Elements[current] = Elements[prev];
    }
}

template <typename Data>
void SetVec<Data>::ShiftLeft(unsigned long startIdx, unsigned long endIdx) {
    // Sposta gli elementi dalla posizione startIdx a endIdx verso sinistra
    for (unsigned long i = startIdx; i < endIdx; ++i) {
        unsigned long current = (head + i + Elements.Size()) % Elements.Size();
        unsigned long next = (head + i + 1 + Elements.Size()) % Elements.Size();
        Elements[current] = Elements[next];
    }
}

template <typename Data>
void SetVec<Data>::Expand() {
    if (Size() == Elements.Size()) {
        Resize(Elements.Size() == 0 ? 5 : Elements.Size() * 2);
    }
}

template <typename Data>
void SetVec<Data>::Reduce() {
    if (size * 5 <= Elements.Size()) {
        unsigned long new_capacity = Elements.Size() / 2;
        const unsigned long MIN_CAPACITY = 8;
        if (new_capacity < MIN_CAPACITY) {
            new_capacity = MIN_CAPACITY;
        }
        Resize(new_capacity);
    }
}

/* ************************************************************************** */

}
