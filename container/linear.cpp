
namespace lasd {

/* ************************************************************************** */

//LinearContainer

//comparison operators
template <typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& container) const noexcept {
    if(size != container.size)
    return false;
    for(unsigned long i = 0; i<size; ++i) {
        if((*this)[i] != container[i])
        return false;
    }
    return true;
}

template <typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& container) const noexcept {
    return !(*this == container);
}

//Specific member functions
template <typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(size == 0)
        throw std::length_error("Empty Linear Container");
    return (*this)[0];
}

template <typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(size == 0)
        throw std::length_error("Empty Linear Container");
    return (*this)[size - 1];
}

//Specific member function (inherited from TraversableContainer)
template <typename Data>
void LinearContainer<Data>::Traverse(TraverseFun function) const {
    PreOrderTraverse(function);
}

//specific member function (inherited from PreOrderTraversableContainer)
template <typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun function) const {
    for(unsigned long i = 0; i<size; ++i) {
        function((*this)[i]);
    }
}

//specific member function (inherited from PostOrderTraversableContainer)
template <typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun function) const {
    for(unsigned long i = size; i > 0; ) {
        function((*this)[--i]);
    }
}

/* ************************************************************************** */

//MutableLinearContainer

//Specific member functions
template <typename Data>
Data& MutableLinearContainer<Data>::Front() {
    return const_cast<Data&>(static_cast<const MutableLinearContainer<Data>&>(*this).Front());
}

template <typename Data>
Data& MutableLinearContainer<Data>::Back() {
    return const_cast<Data&>(static_cast<const MutableLinearContainer<Data>&>(*this).Back());
}

//Specific member function (inherited from MappableContainer)
template <typename Data>
void MutableLinearContainer<Data>::Map(MapFun function) {
    PreOrderMap(function);
}

//Specific member function (inherited from PreOrderMappableContainer)
template <typename Data>
void MutableLinearContainer<Data>::PreOrderMap(MapFun function) {
    for(unsigned long i = 0; i < size; ++i) {
        function((*this)[i]);
    }
}

//Specific member function (inherited from PostOrderMappableContainer)
template <typename Data>
void MutableLinearContainer<Data>::PostOrderMap(MapFun function) {
    for(unsigned long i = size; i > 0; ) {
        function((*this)[--i]);
    }
}

/* ************************************************************************** */

//SortableLinearContainer

//Specific member functions

template <typename Data>
void SortableLinearContainer<Data>::insertionSort() {
    for (unsigned long i = 1; i < size; ++i) {
        Data key = (*this)[i];
        long long j = i - 1;
        while (j >= 0 && (*this)[j] > key) {
            (*this)[j+1] = (*this)[j];
            --j;
        }
        (*this)[j + 1] = key;
    }
}

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    insertionSort();
}


}
