#include "ring_buffer.hpp"

RingBuffer::RingBuffer(size_t capacity)
    : buffer_(capacity), size_(0), start_index_(0), end_index_(0) {}

size_t RingBuffer::Size() const { return size_; }

bool RingBuffer::Empty() const { return size_ == 0; }

bool RingBuffer::TryPush(int64_t element) {
  if (size_ < buffer_.capacity()) {
    buffer_[end_index_] = element;
    end_index_ = (end_index_ + 1) % buffer_.capacity();
    ++size_;

    return true;
  }

  return false;
}

bool RingBuffer::TryPop(int64_t& element) {
  if (size_ > 0) {
    element = buffer_[start_index_];
    start_index_ = (start_index_ + 1) % buffer_.capacity();
    --size_;

    return true;
  }

  return false;
}