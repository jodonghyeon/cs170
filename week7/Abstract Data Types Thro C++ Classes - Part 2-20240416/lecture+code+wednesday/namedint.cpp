// HLP2
// 01/15/2022
// Example of a useful class NamedInt that is composed of a 
// well-defined user type [std::string] and a built-in type [int].
// The class is used to illustrate:
// 1) The idea and implementation of member-initialization lists.
// 2) Default copy construction, copy assignment.
// 3) Default destructor
// 4) When a default constructor is synthesized and what happens if
//    the class doesn't declare one.
// 5) Why there is no need to implement trivial copy constructor,
//    copy assignment, and destructor.
#include <iostream>
#include <string>

class NamedInt {
public:
  NamedInt(char const *nam, int val);
  NamedInt(std::string const& nam, int val);
  
  NamedInt(NamedInt const&)            = default;
  NamedInt& operator=(NamedInt const&) = default;
	~NamedInt()                          = default;

  std::string const& Name() const;
  std::string&       Name();
  int const&         Int() const;
  int&               Int();
private:
  std::string name;
  int ival;
};

// example of member initializer list!!!
NamedInt::NamedInt(char const *nam, int val) : name{nam}, ival{val} {
  // empty by design
}

NamedInt::NamedInt(std::string const& nam, int val) : name{nam}, ival{val} {
  // empty by design
}

std::string const& NamedInt::Name() const { return name; }
std::string&       NamedInt::Name()       { return name; }

int const&         NamedInt::Int() const { return ival; }
int&               NamedInt::Int()       { return ival; }

// overload operator << to write NamedInt to output stream ...
std::ostream& operator<<(std::ostream& os, NamedInt const& rhs) {
  os << '(' << rhs.Name() << ", " << rhs.Int() << ')';
  return os;
}

int main() {
  NamedInt ni1{"1st Prime Number", 2};
  NamedInt ni2{ni1}; // copy constructor generated
  NamedInt ni3{"2nd Prime Number", 3};
  ni2 = ni3;         // copy assignment generated
  std::cout << "ni1: " << ni1 << " | ni2: " << ni2 << " | ni3: " << ni3 << '\n';
}