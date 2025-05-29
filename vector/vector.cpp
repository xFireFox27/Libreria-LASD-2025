
namespace lasd {

/* ************************************************************************** */

//Vector

//Specific constructors
template<typename Data>
Vector<Data>::Vector(const unsigned long newSize) {
    size = newSize;
    Elements = new Data[size] {};
}

//A vector obtained from a TraversableContainer
template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& container) : Vector(container.Size()) {
    unsigned long i = 0;
    container.Traverse([this, &i](const Data& dat) {
        Elements[i++] = dat;
    });
}

//A vector obtained from a MappableContainer
template <typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& container) : Vector(container.Size()) {
    unsigned long i = 0;
    container.Map([this, &i](Data& dat) {
        Elements[i++] = std::move(dat);
    });
}

//Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vector) {
    size = vector.size;
    Elements = new Data[size];
    std::copy(vector.Elements, vector.Elements + size, Elements);
}

//Move constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& vector) noexcept {
    std::swap(size, vector.size);
    std::swap(Elements, vector.Elements);
}

//Destructor
template <typename Data>
Vector<Data>::~Vector() {
    delete[] Elements;
}

//Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vector) {
    Vector<Data> *tmpvec = new Vector<Data>(vector);
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

//Move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vector) noexcept {
    std::swap(size, vector.size);
    std::swap(Elements, vector.Elements);
    return *this;
}

//Comparison operators
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vector) const noexcept {
    if (size != vector.size)
        return false;
    for(unsigned long i = 0; i < size; ++i) {
        if(Elements[i] != vector[i])
            return false;
    }
    return true;
}

template <typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vector) const noexcept {
    return !(*this ==  vector);
}

//Specfic mebmer funcrions (inherited from MutableLinearContainer)
template <typename Data>
Data& Vector<Data>::operator[](const unsigned long i) {
    return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->operator[](i));
}

template <typename Data>
Data& Vector<Data>::Front() {
    return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->Front());
}

template <typename Data>
Data& Vector<Data>::Back() {
    return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->Back());
}

//Specfic member functions (inherited from LinearContainer)
template <typename Data>
const Data& Vector<Data>::operator[](const unsigned long i) const {
    if(i >= size)
        throw std::out_of_range("Out of range Vector");
    return Elements[i];
}

template <typename Data>
const Data& Vector<Data>::Front() const {
    if(size == 0)
        throw std::length_error("Empty Vector");
    return Elements[0];
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size == 0)
        throw std::length_error("Empty Vector");
    return Elements[size - 1];
}

//Specfic member function (inherited from ClearableContainer)
template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    size = 0;
    Elements = nullptr;
}

//Specfic member function (inherited from ResizableContainer)
template <typename Data>
void Vector<Data>::Resize(const unsigned long newSize) {
    if(newSize == 0) {
        Clear();
        return;
    }
    if(newSize == size)
        return;
    Data* newElements = new Data[newSize] {};
    unsigned long minSize = std::min(size, newSize);
    for(unsigned long i = 0; i < minSize; ++i) 
        std::swap(Elements[i], newElements[i]);
    std::swap(Elements, newElements);
    delete[] newElements;
    newElements = nullptr;
    size = newSize;
}
/* ************************************************************************** */

//SortableVector

//Specific constructors
template<typename Data>
SortableVector<Data>::SortableVector(const unsigned long newSize) : Vector<Data>::Vector(newSize) {}

//A vector obtained from a TraversableContainer
template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& container) : Vector<Data>::Vector(container) {}

//A vector obtained from a MappableContainer
template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& container) : Vector<Data>::Vector(std::move(container)) {}

//Copy constructor
template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& vector) : Vector<Data>::Vector(vector) {}

//Move constructor
template <typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& vector) noexcept : Vector<Data>::Vector(std::move(vector)) {}

//Copy assignment
template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vector) {
    Vector<Data>::operator=(vector);
    return *this;
}

//Move assignment
template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& vector) noexcept {
    Vector<Data>::operator=(std::move(vector));
    return *this;
}

/* ************************************************************************** */
}