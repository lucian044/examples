#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle {
private:

  double base, height;
  
public:

  Triangle(double h, double b);

  // accessors
  double get_height() const;
  double get_base() const;

  // mutators
  void set_height(double h);
  void set_base(double b);

  // area
  double get_area() const;
};

bool operator==(Triangle t1, Triangle t2);

#endif
