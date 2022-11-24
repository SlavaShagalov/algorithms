#pragma once
#include <iostream>

size_t str_hash(const std::string &data) {
  size_t hash = 0;
  for (char i : data) {
    hash = hash * 13 + i;
  }
  return hash;
}

// hash
template <typename Key>
struct hash {
  size_t operator()(const Key &key) {
    return key;
  }
};

template <>
struct hash<typename std::string> {
  size_t operator()(const std::string &key) {
    return str_hash(key);
  }
};

template <typename Key, typename Value, typename Hash = hash<Key>>
class HashMap {
  static constexpr size_t MAX_LEN = 7;
  static constexpr size_t BUCKETS_SIZES_LIST[] = {
      7,    17,   37,   73,    149,   251,   509,
      1021, 2027, 5003, 10837, 21491, 45007, 100003};

  enum State { BUSY, EMPTY, DEL };

  struct Bucket {
    Bucket() : key(), value(), state(EMPTY) {
    }
    Bucket(const Bucket &bucket) = default;
    Bucket &operator=(const Bucket &bucket) = default;

    Key key;
    Value value;
    State state;
  };

 public:
  // constructors
  HashMap() : _arr(nullptr), _size(0), _capacity(0), _sizesListIdx(0) {
  }

  HashMap(const HashMap &) = delete;

  HashMap(HashMap &&) = delete;

  HashMap &operator=(const HashMap &) = delete;

  HashMap &operator=(HashMap &&) = delete;

  // destructor
  ~HashMap() {
    delete[] _arr;
  }

  // basic methods
  Value *find(const Key &key) {
    if (!_arr) {
      return nullptr;
    }
    size_t idx = hasher(key) % _capacity;
    for (size_t i = 0; i < _capacity; ++i) {
      if (_arr[idx].state == EMPTY) {
        return nullptr;
      } else if (_arr[idx].state == BUSY && _arr[idx].key == key) {
        return &_arr[idx].value;
      }
      idx = (idx + 1) % _capacity;
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
    for (size_t i = 0; i < _capacity; ++i) {
      if (_arr[idx].state == EMPTY || _arr[idx].state == DEL) {
        _arr[idx].key = key;
        _arr[idx].value = value;
        _arr[idx].state = BUSY;
        _size++;
        return true;
      }
      idx = (idx + 1) % _capacity;
    }
    return false;
  }

  bool erase(const Key &key) {
    if (!_arr) {
      return false;
    }
    size_t idx = hasher(key) % _capacity;
    for (size_t i = 0; i < _capacity; ++i) {
      if (_arr[idx].state == EMPTY) {
        return false;
      } else if (_arr[idx].state == BUSY && _arr[idx].key == key) {
        _arr[idx].state = DEL;
        _size--;
        return true;
      }
      idx = (idx + 1) % _capacity;
    }
    return false;
  }

  size_t size() const {
    return _size;
  }

 private:
  void grow() {
    size_t newCapacity = BUCKETS_SIZES_LIST[_sizesListIdx++];
    auto *newArr = new Bucket[newCapacity];
    for (size_t i = 0; i < _capacity; ++i) {
      size_t newIdx = hasher(_arr[i].key) % newCapacity;
      for (size_t j = 0; j < newCapacity; ++j) {
        if (newArr[newIdx].state == EMPTY) {
          newArr[newIdx] = _arr[i];
          break;
        }
        newIdx = (newIdx + 1) % newCapacity;
      }
    }

    delete[] _arr;
    _arr = newArr;
    _capacity = newCapacity;
  }

  Bucket *_arr;
  size_t _size;
  size_t _capacity;

  size_t _sizesListIdx;

  Hash hasher;
};

//+ hello
//+ bye
//? bye
//+ bye
//- bye
//? bye
//? hello