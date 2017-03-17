#ifndef __ITERATOR_LIST
#define __ITERATOR_LIST

template <class Container>
class IteratorChain {
    typedef typename Container::iterator Iterator;
    std::vector<Container> containers;

    class node {
        IteratorChain* chain;
        size_t chainIndex;
        Iterator i;
        Iterator thisStart;
        Iterator thisEnd;

       public:
        node(IteratorChain* c, Iterator i, int chainIndex)
            : chain(c), chainIndex(chainIndex), i(i) {
            if (chainIndex != -1) {
                Container& cont = chain->containers[chainIndex];
                thisStart = cont.begin();
                thisEnd = cont.end();
            }
        }

        node operator++() {
            i++;
            if (i == thisEnd) {
                chainIndex++;
                if (chainIndex < chain->containers.size()) {
                    Container& c = chain->containers[chainIndex];
                    thisStart = c.begin();
                    thisEnd = c.end();
                    i = thisStart;
                }
            }
            return *this;
        }

        node operator++(int num) { this->operator++(); }

        typename Iterator::reference operator*() { return i.operator*(); }

        typename Iterator::pointer operator->() { return i.operator->(); }

        bool operator==(const node& rhs) {
            return rhs.chainIndex == chainIndex && i == rhs.i;
        }

        bool operator!=(const node& rhs) { return i != rhs.i; }
    };

   public:
    IteratorChain(std::vector<Container> containers) : containers(containers) {}

    node begin() {
        if (containers.size() == 0) {
            return node(this, Iterator(), -1);
        }
        return node(this, containers[0].begin(), 0);
    }

    node end() {
        if (containers.size() == 0) {
            return node(this, Iterator(), -1);
        }
        size_t last_index = containers.size() - 1;
        return node(this, containers[last_index].end(), last_index);
    }
};

#endif
