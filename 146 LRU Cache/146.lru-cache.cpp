/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;  // Maximum capacity of the cache
    std::list<std::pair<int, int>> cacheList;  // Doubly linked list of (key, value) pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;  // Map key to list iterator

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) : capacity(capacity) {}

    // Get the value of a key if it exists, otherwise return -1
    int get(int key) {
        // 1. If key is not in cacheMap, return -1.
        // 2. If key is in cacheMap, move it to the front of cacheList and return its value.
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    // Put a key-value pair in the cache
    void put(int key, int value) {
        // 1. If key already exists, update its value and move to front.
        // 2. If key doesn't exist, add (key, value) to the front of cacheList.
        // 3. If adding causes cache to exceed capacity, remove the last item.
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
        } else {
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
            if (cacheList.size() > capacity) {
                cacheMap.erase(cacheList.back().first);
                cacheList.pop_back();
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

