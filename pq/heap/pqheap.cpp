namespace lasd {

/* ************************************************************************** */

//Specific constructor
template <typename Data>
PQHeap<Data>::PQHeap(const TraversableContainer<Data>& container) : HeapVec<Data>::HeapVec(container) {
    capacity = size;
}

template <typename Data>
PQHeap<Data>::PQHeap(MappableContainer<Data>&& container) : HeapVec<Data>::HeapVec(std::move(container)) {
    capacity = size;
}

//Copy constructor
template <typename Data>
PQHeap<Data>::PQHeap(const PQHeap<Data>& heap) : HeapVec<Data>::HeapVec(heap) {
    capacity = size;
}

//Move constructor
template <typename Data>
PQHeap<Data>::PQHeap(PQHeap<Data>&& heap) noexcept : HeapVec<Data>::HeapVec(std::move(heap)) {
    capacity = size;
}

//Copy assignment
template <typename Data>
PQHeap<Data>& PQHeap<Data>::operator=(const PQHeap<Data>& heap) {
    HeapVec<Data>::operator=(heap);
    capacity = size;
    return *this;
}

//Move assignment
template <typename Data>
PQHeap<Data>& PQHeap<Data>::operator=(PQHeap<Data>&& heap) noexcept {
    HeapVec<Data>::operator=(std::move(heap));
    capacity = size;
    return *this;
}

//Specific member functions (inherited from PQ)
template <typename Data>
const Data& PQHeap<Data>::Tip() const {
    if (size == 0) {
        throw std::length_error("PQHeap is empty");
    }
    return Elements[0];
}

template <typename Data>
void PQHeap<Data>::RemoveTip() {
    if (size == 0) {
        throw std::length_error("PQHeap is empty");
    }
    std::swap(Elements[0], Elements[size - 1]);
    --size;
    HeapifyDown(0, size);

    Reduce();
}

template <typename Data>
Data PQHeap<Data>::TipNRemove() {
    if (size == 0) {
        throw std::length_error("PQHeap is empty");
    }
    Data tip = Elements[0];
    Elements[0] = Elements[size - 1];
    --size;
    HeapifyDown(0, size);

    Reduce();
    return tip;
}

template <typename Data>
void PQHeap<Data>::Insert(const Data& dat) {
    Reduce();
    Expand();
    Elements[size] = dat;
    unsigned long index = size;
    ++size;
    HeapifyUp(index);
}

template <typename Data>
void PQHeap<Data>::Insert(Data&& dat) {
    Reduce();
    Expand();
    Elements[size] = std::move(dat);
    unsigned long index = size;
    ++size;
    HeapifyUp(index);
}

template <typename Data>
void PQHeap<Data>::Change(unsigned long index, const Data& value) {
    
    Data oldValue = Elements[index];
    Elements[index] = value;
    
    if (value > oldValue) {
         // Il valore è aumentato, quindi dobbiamo "risalire" l'albero
        HeapifyUp(index);
    } else if (value < oldValue) {
        // Il valore è diminuito, quindi dobbiamo "scendere" l'albero
        HeapifyDown(index, size);
    }
}

template <typename Data>
void PQHeap<Data>::Change(unsigned long index, Data&& value) {
    
    Data oldValue = Elements[index];
    Elements[index] = std::move(value);
    
    if (Elements[index] > oldValue) {
        // Il valore è aumentato, quindi dobbiamo "risalire" l'albero
        HeapifyUp(index);
    } else if (Elements[index] < oldValue) {
        // Il valore è diminuito, quindi dobbiamo "scendere" l'albero
        HeapifyDown(index, size);
    }
}

//Auxiliary functions
template <typename Data>
void PQHeap<Data>::Resize(const unsigned long newSize) {
    
    Data* newElements = new Data[newSize]; 
    for (unsigned long i = 0; i < size; ++i) {
        newElements[i] = std::move(Elements[i]);
    }
    delete[] Elements; 
    Elements = newElements; 
    capacity = newSize;
}

template <typename Data>
void PQHeap<Data>::Expand() {
    if (size >= capacity) {
        unsigned long new_capacity = (capacity == 0) ? 8 : capacity * 2;
        Resize(new_capacity);
    }
}

template <typename Data>
void PQHeap<Data>::Reduce() {
    if (size * 5 <= capacity) {
        unsigned long new_capacity = capacity / 2;
        const unsigned long MIN_CAPACITY = 8;
        if (new_capacity < MIN_CAPACITY) {
            new_capacity = MIN_CAPACITY;
        }
        Resize(new_capacity);
    }
}

template <typename Data>
void PQHeap<Data>::HeapifyUp(unsigned long index) {
    // Se l'elemento è alla radice (indice 0), non c'è più nulla da fare.
    if (index == 0) {
        return;
    }

    unsigned long parentIndex = Parent(index);

    // Se l'elemento corrente è maggiore del suo genitore,
    // scambiali e continua a salire con il genitore.
    if (Elements[index] > Elements[parentIndex]) {
        std::swap(Elements[index], Elements[parentIndex]);
        HeapifyUp(parentIndex); 
    }
}

template <typename Data>
inline const Data& PQHeap<Data>::operator[](const unsigned long index) const {
    return HeapVec<Data>::operator[](index);
}


/* ************************************************************************** */

}
