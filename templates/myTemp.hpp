// a small ltemplated class example that can hold any data type

#ifndef MY_TEMP
#define MY_TEMP

template <class T>
class MyTemp {
public:
  T data; // holding whatever data type is given at creation
  MyTemp(T d);

  void print_data();
};

// this is like my cpp file now

// constructor
// you need a template prefix for every function
// scope resolution needs to have the <T> data type attached to it
template <class T>
MyTemp<T>::MyTemp(T d) {
  data = d;
}

template <class T>
void MyTemp<T>::print_data() {
  std::cout << data;
}

#endif
