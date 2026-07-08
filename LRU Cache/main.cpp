#include <cstdio>
#include <list>
#include <unordered_map>
#include <utility>

// Least Recently Used (LRU) cache.
//
// Fixed capacity. Every get/put touches the accessed key and marks it as the
// most recently used. When the cache is full and a brand-new key is inserted,
// the least recently used key is evicted to make room.
//
// Both operations run in O(1):
//   - a doubly linked list keeps keys ordered from most- to least-recently-used
//     (front = newest, back = oldest), and
//   - a hash map points each key straight at its node in that list, so we can
//     splice it to the front without walking the list.
class LRUCache
{
public:
    explicit LRUCache(int capacity) : cap(capacity) {}

    // Return the value for key, or -1 if it isn't cached. On a hit the key
    // becomes the most recently used.
    int get(int key)
    {
        auto it = index.find(key);
        if (it == index.end())
        {
            return -1; // miss
        }

        // move this key's node to the front (most recently used)
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    // Insert or update key -> value, marking key as most recently used. If the
    // cache is at capacity and key is new, evict the least recently used key.
    void put(int key, int value)
    {
        auto it = index.find(key);
        if (it != index.end())
        {
            // existing key: refresh value and bump to front
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }

        if ((int)index.size() == cap)
        {
            // full: drop the oldest entry (back of the list)
            int oldest = order.back().first;
            order.pop_back();
            index.erase(oldest);
        }

        order.emplace_front(key, value);
        index[key] = order.begin();
    }

private:
    int cap;
    // front = most recently used, back = least recently used
    std::list<std::pair<int, int>> order;
    // key -> iterator into `order`
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> index;
};

int main()
{
    // quick demo: capacity 2, walking through the classic access pattern.
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    printf("get(1) = %d\n", cache.get(1)); // 10, and 1 is now newest

    cache.put(3, 30);                      // evicts key 2 (least recently used)
    printf("get(2) = %d\n", cache.get(2)); // -1 (evicted)

    cache.put(4, 40);                      // evicts key 1
    printf("get(1) = %d\n", cache.get(1)); // -1 (evicted)
    printf("get(3) = %d\n", cache.get(3)); // 30
    printf("get(4) = %d\n", cache.get(4)); // 40
}
