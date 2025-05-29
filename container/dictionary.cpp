
namespace lasd {

/* ************************************************************************** */

//DictionaryContainer
//specific member functions

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& container) {
    bool inserted = true;
    container.Traverse([this, &inserted](const Data& dat) {
        inserted &= Insert(dat);
    });
    return inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& container) {
    bool inserted = true;
    container.Map([this, &inserted](Data& dat) {
        inserted &= Insert(std::move(dat));
    });
    return inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& container) {
    bool removed = true;
    container.Traverse([this, &removed](const Data& dat) {
        removed &= Remove(dat);
    });
    return removed;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& container) {
    bool inserted = false;
    container.Traverse([this, &inserted](const Data& dat) {
        inserted |= Insert(dat);
    });
    return inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& container) {
    bool inserted = false;
    container.Map([this, &inserted](Data& dat) {
        inserted |= Insert(std::move(dat));
    });
    return inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& container) {
    bool removed = false;
    container.Traverse([this, &removed](const Data& dat) {
        removed |= Remove(dat);
    });
    return removed;
}

/* ************************************************************************** */

}
