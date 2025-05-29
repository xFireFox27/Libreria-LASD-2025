
namespace lasd {

/* ************************************************************************** */

//PreOrderMappableContainer
//specific member function (ineherited from MappableContainer)

template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFun function) {
    PreOrderMap(function);
}

/* ************************************************************************** */

//PostOrderMappableContainer
//specific member function (ineherited from MappableContainer)

template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFun function) {
    PostOrderMap(function);
}

/* ************************************************************************** */
}
