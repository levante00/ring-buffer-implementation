#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

class RingBuffer {
 public:
  explicit RingBuffer(size_t capacity);

  size_t Size() const;

  bool Empty() const;

  bool TryPush(int64_t element);

  bool TryPop(int64_t& element);

 private:
  std::vector<int64_t> buffer_;
  size_t size_;
  size_t start_index_;
  size_t end_index_;
};