#include "str.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>

Str::Str() : len{0}, ptr{new char[len+1]} {
  *ptr = '\0';
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::Str(char const *rhs) : len{std::strlen(rhs)}, ptr{new char [len+1]} {
  std::strcpy(ptr, rhs);
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::Str(Str const& rhs) : len{rhs.len}, ptr{new char[len+1]} {
  std::strcpy(ptr, rhs.ptr);
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::~Str() {
  std::cout << __PRETTY_FUNCTION__ << " | " << ptr << '\n';
  delete[] ptr;
}

Str& Str::operator=(Str const& rhs) {
  Str tmp{rhs};
  swap(tmp);
  return *this;
}

Str& Str::operator=(char const *rhs) {
  Str tmp{rhs};
  swap(tmp);
  return *this;
}

Str& Str::operator+=(Str const& rhs) {
  size_t tmp_len{len+rhs.len};
  char*  tmp_ptr{new char[tmp_len+1]};
  std::strcpy(tmp_ptr, ptr); std::strcat(tmp_ptr, rhs.ptr);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;

  return *this;
}

Str& Str::operator+=(char const *rhs) {
  size_t tmp_len{len+std::strlen(rhs)};
  char*  tmp_ptr{new char[tmp_len+1]};
  std::strcpy(tmp_ptr, ptr); std::strcat(tmp_ptr, rhs);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;

  return *this;
}

void Str::swap(Str& rhs) {
  std::swap(len, rhs.len);
  std::swap(this->ptr, rhs.ptr);
}

char const* Str::c_str() const {
  return ptr;
}