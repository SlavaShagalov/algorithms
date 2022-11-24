#pragma once
#include <iostream>

// 64 numbers max
static constexpr size_t BUCKETS_SIZES_LIST[] = {
    7, 17, 37, 73, 149, 251, 509, 1021, 2027, 5003, 10837, 21491, 45007, 100003
};

size_t str_hash(const std::string &data) {
  size_t hash = 0;
  for (char i: data) {
    hash = hash * 13 + i;
  }
  return hash;
}

// hash
template<typename Key>
struct hash {
  size_t operator()(const Key &key) {
    return key;
  }
};

template<>
struct hash<typename std::string> {
  size_t operator()(const std::string &key) {
    return str_hash(key);
  }
};

template<typename Key, typename Value, typename Hash=hash<Key>>
class HashMap {
  struct Node {
    Node(const Key &k, const Value &v, Node *n) : key(k), value(v), next(n) {
    }

    Key key;
    Value value;
    Node *next;
  };

  static constexpr size_t MAX_LEN = 7;

 public:
  // constructors
  HashMap() : _arr(nullptr),
              _capacity(0),
              buckets_sizes_list_idx(0),
              _size(0) {

  }

  HashMap(const HashMap &) = delete;

  HashMap(HashMap &&) = delete;

  HashMap &operator=(const HashMap &) = delete;

  HashMap &operator=(HashMap &&) = delete;

  // destructor
  ~HashMap() {
    for (int i = 0; i < _capacity; ++i) {
      Node *cur = _arr[i];
      while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        delete tmp;
      }
    }
    delete[] _arr;
  }

  // basic methods
  Value *find(const Key &key) {
    if (!_arr) {
      return nullptr;
    }
    size_t idx = hasher(key) % _capacity;
    Node *cur = _arr[idx];
    while (cur) {
      if (cur->key == key) {
        return &cur->value;
      }
      cur = cur->next;
    }
    return nullptr;
  }

  bool insert(const Key &key, const Value &value) {
    if (find(key)) {
      return false;
    }
    if (_size >= _capacity * MAX_LEN) {
      grow();
    }
    size_t idx = hasher(key) % _capacity;
    _arr[idx] = new Node(key, value, _arr[idx]);
    _size++;
    return true;
  }

  bool erase(const Key &key) {
    if (!_arr) {
      return false;
    }
    size_t idx = hasher(key) % _capacity;
    Node *cur = _arr[idx];
    Node **prev = &_arr[idx];
    while (cur) {
      if (cur->key == key) {
        *prev = cur->next;
        _size--;
        delete cur;
        return true;
      }
      prev = &cur->next;
      cur = cur->next;
    }
    return false;
  }

  // output
  //    friend operator<<(std::ostream os, const HashMap<T> &);

 private:
  void grow() {
    size_t newCapacity = BUCKETS_SIZES_LIST[buckets_sizes_list_idx++];
    Node **newArr = new Node *[newCapacity];
    for (int i = 0; i < newCapacity; ++i) {
      newArr[i] = nullptr;
    }
    for (int i = 0; i < _capacity; ++i) {
      Node *cur = _arr[i];
      while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        size_t newIdx = hasher(tmp->key) % newCapacity;
        tmp->next = newArr[newIdx];
        newArr[newIdx] = tmp;
      }
    }
    delete[] _arr;
    _arr = newArr;
    _capacity = newCapacity;
  }

  Node **_arr;
  size_t _capacity;

  size_t buckets_sizes_list_idx;
  size_t _size;

  Hash hasher;
};

//+ hello
//+ bye
//? bye
//+ bye
//- bye
//? bye
//? hello