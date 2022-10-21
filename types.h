#ifndef TYPES_H
#define TYPES_H

template <typename T>
struct DefaultComparator {
  bool operator()(const T &l, const T &r) const { return l > r; }
};

#endif  // TYPES_H
