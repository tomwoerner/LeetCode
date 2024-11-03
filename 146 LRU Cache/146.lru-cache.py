#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#

# @lc code=start
# LRUCache class using OrderedDict to implement O(1) time complexity for get and put operations
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        # Initialize the capacity and the OrderedDict for storing key-value pairs
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        # Check if the key exists in the cache
        if key not in self.cache:
            return -1
        # Move the accessed item to the end to mark it as recently used
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        # If the key already exists, update it and move to the end
        if key in self.cache:
            self.cache.move_to_end(key)
        # Insert the key-value pair
        self.cache[key] = value
        # If the cache exceeds capacity, remove the oldest item (first item in OrderedDict)
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
            
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

