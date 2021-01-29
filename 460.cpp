#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LFUCache {
     struct Node {
         int key;
         int value;
         int freq;
         Node(int k, int v) : key(k), value(v), freq(1) {}
     };
     int cap, minFreq;
     unordered_map<int, list<Node>::iterator> keys;
     unordered_map<int, list<Node>> freqs;
 public:
     LFUCache(int capacity) {
         //哈希表
         cap = capacity;
         minFreq = 0;
         keys.clear();
         freqs.clear();
     }

     void update(list<Node>::iterator p) {
         int val = p->value, fre = p->freq;
         int key = p->key;

         p->freq++;

         auto& newlist = freqs[fre + 1];
         auto& oldlist = freqs[fre];

         newlist.splice(newlist.begin(), oldlist, p);

         if (oldlist.size() == 0) {
             freqs.erase(fre);
             if (minFreq == fre) minFreq++;
         }
     }


     int get(int key) {
         if (cap == 0) return -1;
         auto it = keys.find(key);
         if (it == keys.end()) return -1;
         int val = it->second->value;
         update(it->second);
         return val;
     }

     void put(int key, int value) {
         if (cap == 0) return;
         auto it = keys.find(key);
         if (it == keys.end()) {
             if (keys.size() == cap) {
                 auto p = freqs[minFreq].back();
                 keys.erase(p.key);
                 freqs[minFreq].pop_back();
                 if (freqs[minFreq].size() == 0) freqs.erase(minFreq);
             }
             freqs[1].emplace_front(key, value);
             keys[key] = freqs[1].begin();
             minFreq = 1;
         }
         else {
             it->second->value = value;
             update(it->second);
         }
     }
 };