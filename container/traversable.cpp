
namespace lasd {

/* ************************************************************************** */
//TraversableContainer
//specific memeber function

template <typename Data>
template <typename Accumulator>
Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> function, Accumulator acc) const {
    Traverse(
        [&](const Data& dat) { 
            acc = function(dat, acc); 
        }
    );
    return acc;
}

///Specific member function (inherited from TestableContainer)
template <typename Data>
bool TraversableContainer<Data>::Exists(const Data& dat) const noexcept {
    bool found = false;
    Traverse(
        [dat, &found](const Data& val){
            found |= (val == dat);
        }
    );
    return found;
}


/* ************************************************************************** */
//PreOrderTraversableContainer
//specific member function

template <typename Data>
template <typename Accumulator>
Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> function, Accumulator acc) const {
    PreOrderTraverse(
        [&](const Data& dat) {
            acc = function(dat, acc);
        }
    );
    return acc;
}

//Specific member function (inherited from TraversableContainer)
template <typename Data>
void PreOrderTraversableContainer<Data>::Traverse(TraverseFun function) const {
    PreOrderTraverse(function);
}

/* ************************************************************************** */
//PostOrderTraversableContainer
// specific member function

template <typename Data>
template <typename Accumulator>
Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> function, Accumulator acc) const {
    PostOrderTraverse(
        [&](const Data& dat){
            acc = function(dat, acc);
        }
    );
    return acc;
}

//Specific member function (inherited from TraversableContainer)
template <typename Data>
void PostOrderTraversableContainer<Data>::Traverse(TraverseFun function) const{
    PostOrderTraverse(function);
}

};
