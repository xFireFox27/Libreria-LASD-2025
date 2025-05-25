
namespace lasd {

/* ************************************************************************** */

//Node

//Specific constructors
template <typename Data>
inline List<Data>::Node::Node(const Data& dat) : element{dat} {}

template <typename Data>
inline List<Data>::Node::Node(Data&& dat) noexcept : element(std::move(dat)) {}

//Copy constructor
template <typename Data>
  List<Data>::Node::Node(const Node& nod) : Node(nod.element)
  {
    if (nod.next != nullptr) 
      next = new Node(*(nod.next));
  }

//Move constructor
template <typename Data>
inline List<Data>::Node::Node(Node&& nod) noexcept {
    std::swap(element, nod.element);
    std::swap(next, nod.next);
}

//Destructor
template <typename Data>
List<Data>::Node::~Node() {
    delete next;
}

//Comparison operators
template <typename Data>
bool List<Data>::Node::operator==(const Node& nod) const noexcept {
    return element == nod.element && ((next == nullptr && nod.next == nullptr) || (next != nullptr && nod.next != nullptr && *next == *(nod.next)));
}

template <typename Data>
bool List<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}

//Specific member functions
//Copy a node. Return pointer to first and set pointer to last
template <typename Data>
List<Data>::Node* List<Data>::Node::CopyNSetLast(Node** const tempPtr) const {
    Node* nod = new Node(this->element);
    if (next != nullptr) {
        nod->next = next->CopyNSetLast(tempPtr);
    } else {
        *tempPtr = nod;
    }
    return nod;
}

/* ************************************************************************** */
//List

//Specific constructors
template <typename Data>
List<Data>::List(const TraversableContainer<Data>& container) {
    container.Traverse([this](const Data& dat) {
        InsertAtBack(dat);
    });
}

template <typename Data>
List<Data>::List(MappableContainer<Data>&& container) {
    container.Map([this](Data& dat) {
        InsertAtBack(std::move(dat));
    });
}

//Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& list) {
    if (list.head != nullptr) {  
        head = list.head->CopyNSetLast(&tail); 
    } else { 
        head = tail = nullptr;         
    }
    size = list.size; 
}

//Move constructor
template <typename Data>
List<Data>::List(List<Data>&& list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
}

//Destructor
template <typename Data>
List<Data>::~List() {
    delete head;
}

//Copy assignment
template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list){
    if(this != &list) {
        List<Data> temp {list};
        std::swap(temp, *this);
    }
    return *this;
}

//Move assignment
template <typename Data>
List<Data>& List<Data>::operator=(List<Data>&& list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
    return *this;
}

//Comparison operators
template<typename Data>
bool List<Data>::operator==(const List<Data> & list) const noexcept {
  return (size == list.size) && ((head == nullptr && list.head == nullptr) || ((head != nullptr && list.head != nullptr) && (*head == *list.head)));
}

template <typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}

//Specific member functions
template <typename Data>
void List<Data>::InsertAtFront(const Data& dat) {
    Node* newNode = new Node(dat);
    newNode->next = head;
    head = newNode;
    if(tail == nullptr)
        tail = head;
    ++size;
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& dat) {
    Node* newNode = new Node(std::move(dat));
    newNode->next = head;
    head = newNode;
    if(tail == nullptr)
        tail = head;
    ++size;
}

template <typename Data>
void List<Data>::RemoveFromFront() {
    if(head == nullptr)
        throw std::length_error("Empty list");
    else {
        Node* front = head;
        if(tail == head) 
            head = tail = nullptr;
        else
            head = head->next;
        --size;
        front->next = nullptr;
        delete front;
    }
}

template <typename Data>
Data List<Data>::FrontNRemove() {
    if(head == nullptr)
        throw std::length_error("Empty list");
    else {
        Node* front = head;
        if(tail == head) 
            head = tail = nullptr;
        else
            head = head->next;
        --size;
        front->next = nullptr;
        Data dat = std::move(front->element);       
        delete front;
        return dat;
    }
}

template <typename Data>
void List<Data>::InsertAtBack(const Data& dat) {
    Node* newNode = new Node(dat);
    if(head == nullptr)
        tail = head = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template <typename Data>
void List<Data>::InsertAtBack(Data&& dat) {
    Node* newNode = new Node(std::move(dat));
    if(head == nullptr)
        tail = head = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template <typename Data>
void List<Data>::RemoveFromBack() {
    if(tail == nullptr)
        throw std::length_error("Empty list");
    else {
        Node* back = tail;
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while(current->next != tail)
                current = current->next;
            current->next = nullptr;
            tail = current;
        }
        --size;
        back->next = nullptr;
        delete back;
    }
}

template <typename Data>
Data List<Data>::BackNRemove() {
    if(tail == nullptr)
        throw std::length_error("Empty list");
    else {
        Node* back = tail;
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while(current->next != tail)
                current = current->next;
            current->next = nullptr;
            tail = current;
        }
        --size;
        back->next = nullptr;
        Data dat = std::move(back->element);       
        delete back;
        return dat;
    }
}

//Specific member function (inherited from LinearContainer)
template <typename Data>
const Data& List<Data>::operator[](const unsigned long i) const {
    if(i >= size)
        throw std::out_of_range("Bad index");
    if(i == 0)
        return head->element;
    if(i == size - 1)
        return tail->element;
    Node* current = head->next;
    for(unsigned long j = 1; j < i; ++j, current = current->next);
    return current->element;
}

template <typename Data>
const Data& List<Data>::Front() const {
    if(head == nullptr)
        throw std::length_error("Empty list");
    return head->element;
}

template <typename Data>
const Data& List<Data>::Back() const {
    if(head == nullptr)
        throw std::length_error("Empty list");
    return tail->element;
}

//Specific member function (inherited from MutableLinearContainer)
template <typename Data>
Data& List<Data>::operator[](const unsigned long i) {
    return const_cast<Data&>(static_cast<const List<Data>*>(this)->operator[](i));
}

template <typename Data>
Data& List<Data>::Front() {
    return const_cast<Data&>(static_cast<const List<Data>*>(this)->Front());
}

template <typename Data>
Data& List<Data>::Back() {
    return const_cast<Data&>(static_cast<const List<Data>*>(this)->Back());
}

//Specific member function (inherited from MappableContainer)
template <typename Data>
void List<Data>::Map(MapFun function) {
    PreOrderMap(function);
}

//Specific member function (inherited from PreOrderMappableContainer)
template <typename Data>
void List<Data>::PreOrderMap(MapFun function) {
    PreOrderMap(function, head);
}

//Specific member function (inherited from PostOrderMappableContainer)
template <typename Data>
void List<Data>::PostOrderMap(MapFun function) {
    PostOrderMap(function, head);
}

//Specific member function (inherited from TraversableContainer)
template <typename Data>
void List<Data>::Traverse(TraverseFun function) const {
    PreOrderTraverse(function);
}

//Specific member function (inherited from PreOrderTraversableContainer)
template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun function) const {
    PreOrderTraverse(function, head);
}

//Specific member function (inherited from PostOrderTraversableContainer)
template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun function) const {
    PostOrderTraverse(function, head);
}

//Specific member function (inherited from ClearableContainer)
template <typename Data>
void List<Data>::Clear() {
    delete head;
    head = tail = nullptr;
    size = 0;
}

//Auxiliary member functions 
template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun function, Node* current) const {
    if(current == nullptr)
        return;
    function(current->element);
    PreOrderTraverse(function, current->next);
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun function, Node* current) const {
    if(current == nullptr)
        return;
    PostOrderTraverse(function, current->next);
    function(current->element);
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun function, Node* current) {
    if(current == nullptr)
        return;
    function(current->element);
    PreOrderMap(function, current->next);
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun function, Node* current) {
    if(current == nullptr)
        return;
    PostOrderMap(function, current->next);
    function(current->element);
}

/* ************************************************************************** */

}
