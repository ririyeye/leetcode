#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LRUCache {
public:

    LRUCache(int capacity)
    {
        _capacity = capacity;
        sz = 0;
    }

    int get(int key) {
        auto itr = table.find(key);
        if (itr != table.end())
        {
            lru.splice(lru.begin(), lru, itr->second);
            return itr->second->second;
        }
       return -1;
    }

    void put(int key, int value) 
    {
        auto itr = table.find(key);
        if (itr != table.end())
        {
            lru.splice(lru.begin(), lru, itr->second);
            itr->second->second = value;
            return;
        }

        lru.emplace_front(key, value);
        table[key] = lru.begin();
        sz++;

        if(sz > _capacity){
            table.erase(lru.back().first);
            lru.pop_back();
            sz--;
        }
    }
private:
    typedef std::list<std::pair<int,int> > dlist;
    dlist lru;
    std::unordered_map<int, dlist::iterator> table;
    int _capacity;
    int sz;
};

int main(int argc,char ** argv)
{
    LRUCache s(100);

    //auto ret = s.swapPairs(nd);
}



