
namespace lasd {

/* ************************************************************************** */

//Specific constructors
template <typename Data>
HeapVec<Data>::HeapVec(const TraversableContainer<Data>& container) : SortableVector<Data>::SortableVector(container) {
    Heapify();
}

template <typename Data>
HeapVec<Data>::HeapVec(MappableContainer<Data>&& container) : SortableVector<Data>::SortableVector(std::move(container)) {
    Heapify();
}

//Copy constructor
template <typename Data>
HeapVec<Data>::HeapVec(const HeapVec<Data>& heap) : SortableVector<Data>::SortableVector(heap) {}

//Move constructor
template <typename Data>
HeapVec<Data>::HeapVec(HeapVec<Data>&& heap) noexcept : SortableVector<Data>::SortableVector(std::move(heap)) {}

//Copy assignment
template <typename Data>
HeapVec<Data>& HeapVec<Data>::operator=(const HeapVec<Data>& heap) {
    SortableVector<Data>::operator=(heap);
    return *this;
}

//Move assignment
template <typename Data>
HeapVec<Data>& HeapVec<Data>::operator=(HeapVec<Data>&& heap) noexcept {
    SortableVector<Data>::operator=(std::move(heap));
    return *this;
}

//Comparison operators
template <typename Data>
bool HeapVec<Data>::operator==(const HeapVec<Data>& heap) const noexcept {
    return SortableVector<Data>::operator==(heap);
}

template <typename Data>
bool HeapVec<Data>::operator!=(const HeapVec<Data>& heap) const noexcept {
    return !(*this == heap);
}

//Specific member functions (inherited from Heap)
template <typename Data>
bool HeapVec<Data>::IsHeap() const {
    // if (size <= 1) 
    //     return true;
    
    // Parte dalla radice e controlla se ogni nodo padre è maggiore dei suoi figli
    for (unsigned long i = 0; i < (size / 2); ++i) {      //size / 2 è indice della prima foglia
        const unsigned long left = LeftChild(i);
        if (left < size && Elements[left] > Elements[i]) 
            return false;
            
        const unsigned long right = RightChild(i);
        if (right < size && Elements[right] > Elements[i]) 
            return false;
    }
    return true;
}

template <typename Data>
void HeapVec<Data>::Heapify() {   
    for (long i = (size / 2) - 1; i >= 0; --i) {
        HeapifyDown(i, size);
    }
}

//Specific member function (inherited from SortableLinearContainer)
template <typename Data>
void HeapVec<Data>::Sort() noexcept {
    if(size > 1)
        HeapSort();
}

//Auxiliary functions
template <typename Data>
void HeapVec<Data>::HeapSort() {   
    if(!IsHeap()) {
        Heapify();
    }

    //Scambia la radice(massimo) con l'ultimo elemento e chiama heapify per riportare in radice il massimo dell'albero di size - 1
    unsigned long heapSize = size;
    for (unsigned long i = heapSize - 1; i > 0; --i) {
        std::swap(Elements[0], Elements[i]);
        --heapSize;
        HeapifyDown(0, heapSize);
    }
}

template <typename Data>
void HeapVec<Data>::HeapifyDown(unsigned long index, unsigned long heapSize) {
    unsigned long Sx = LeftChild(index);
    unsigned long Dx = RightChild(index);
    unsigned long maxIndex;
    // Controlla se l'indice sinistro è valido e se il valore è maggiore del nodo padre
    if(Sx < heapSize && Elements[index] < Elements[Sx]) {
        maxIndex = Sx;
    } else {
        maxIndex = index;
    }
    // Controlla se l'indice destro è valido e se il valore è maggiore del nodo padre
    if(Dx < heapSize && Elements[maxIndex] < Elements[Dx]) {
        maxIndex = Dx;
    }
    // Se il nodo padre non è il nodo massimo, scambia i nodi e continua a chiamare Heapify
    if(maxIndex != index) {
        std::swap(Elements[index], Elements[maxIndex]);
        HeapifyDown(maxIndex, heapSize);
    }
}

template <typename Data>
inline unsigned long HeapVec<Data>::Parent(unsigned long index) const {
    return (index - 1) / 2;
}

template <typename Data>
inline unsigned long HeapVec<Data>::LeftChild(unsigned long index) const {
    return (2 * index) + 1;
}

template <typename Data>
inline unsigned long HeapVec<Data>::RightChild(unsigned long index) const {
    return (2 * index) + 2;
}

/* ************************************************************************** */

}
