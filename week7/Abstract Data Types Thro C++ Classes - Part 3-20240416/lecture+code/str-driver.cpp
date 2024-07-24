#include <string>
#include <iostream>
#include "str.hpp"
#include <cctype>

namespace {
std::ostream& operator<<(std::ostream&, Str const&);
Str operator+(Str const&, Str const&);
Str operator+(Str const&, char const*);
Str operator+(char const*, Str const&);
}

int main() {
  Str empty, janet{"janet"}, lisa{"lisa"}, full_name;
  std::cout << "lisa: " << lisa << " | janet: " << janet << "\n";

  for (size_t i{}; i < janet.size(); ++i) {
    janet[i] = std::toupper(janet[i]);
  }
  std::cout << "janet: " << janet << "\n";

  for (char& ch : janet) {
    ch = std::tolower(ch);
  }
  std::cout << "janet: " << janet << "\n";

  full_name = (lisa + " ") + "simpson";
  std::cout << "full name: " << full_name << "\n";

}

namespace {
Str operator+(Str const& lhs, Str const& rhs) {
  Str tmp{lhs};
  tmp += rhs;
  return tmp;
}

Str operator+(Str const& lhs, char const *rhs) {
  Str tmp{lhs};
  tmp += rhs;
  return tmp;
}

Str operator+(char const *lhs, Str const& rhs) {
  Str tmp{lhs};
  tmp += rhs;
  return tmp;
}

std::ostream& operator<<(std::ostream& os, Str const& rhs) {
  os << '<' << rhs.c_str() << '>';
  return os;
}
}