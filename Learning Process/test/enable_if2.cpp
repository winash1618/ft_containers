#include <iostream>
#include <type_traits>

template<typename T>

typename std::enable_if<std::is_integral<T>::value>::type display_output(T value) {
  std::cout << " Answer is: " << value <<  std::endl;
}

int main() {
  display_output<double>(100);
  return 0;
}