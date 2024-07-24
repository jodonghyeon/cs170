#include <cstddef>

class Str {
public:
  using value_type = char;
  using reference = value_type&;
  using const_reference = const reference;
  using pointer = value_type*;
  using const_pointer = const pointer;
  using iterator = pointer;
  using const_iterator = const_pointer;

public:
  Str();
  Str(char const*);
  Str(Str const&);
  ~Str();

  Str& operator=(Str const&);
  Str& operator=(char const*);

  Str& operator+=(Str const&);
  Str& operator+=(char const*);

  const char& operator[](size_t index) const { return ptr[index]; } // Str const lisa{"lisa"}; char ch = lisa[2];
  char&       operator[](size_t index) { //return ptr[index];
    return const_cast<char&>(static_cast<Str const&>(*this)[index]);
  } // Str lisa{"lisa"}; lisa[0] = 'L'

  void swap(Str&);

  char const* c_str() const;
  bool empty() const { return len==0; }
  size_t size() const { return len; }

  iterator       begin()       { return ptr; }
  const_iterator begin() const { return ptr; }
  iterator       end()         { return ptr + len; }
  const_iterator end()   const { return ptr + len; }


private:
  size_t len;
  char   *ptr;
};
