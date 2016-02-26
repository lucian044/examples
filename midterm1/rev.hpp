#ifndef REV_HPP
#define REV_HPP

class Rev {
private:
  int x;

public:
  // default constructor
  Rev();
  
  // parameterized
  Rev(int data);
  
  void display_data();
  // mutator, setter
  void set_x(int x) { this->x = x; }

  // accessor, getter
  int get_x() { return x; }

  void pass_by_value(int x) { x += 10; }
  void pass_by_reference(int& x) { x += 10; }
};

Rev operator+(Rev r1, Rev r2);

void say_hi();
void show_data();
Rev make_rev();

#endif
