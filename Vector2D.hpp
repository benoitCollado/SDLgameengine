#include <iostream>
#include <cmath>

class Vector2D{
public:
  float x;
  float y;

  Vector2D();
  Vector2D(float x, float y);

  float norme();
  void normalize();

  Vector2D& Add(const Vector2D& vec);
  Vector2D& Substract(const Vector2D& vec);
  Vector2D& Multiply(const Vector2D& vec);
   Vector2D& Divide(const Vector2D& vec);

  friend Vector2D& operator+(Vector2D& vec1, const Vector2D& vec2);
  friend Vector2D& operator-(Vector2D& vec1, const Vector2D& vec2);
  friend Vector2D& operator*(Vector2D& vec1, const Vector2D& vec2);
  friend Vector2D& operator/(Vector2D& vec1, const Vector2D& vec2);

  Vector2D& operator+=(const Vector2D& vec);
  Vector2D& operator-=(const Vector2D& vec);
  Vector2D& operator*=(const Vector2D& vec);
  Vector2D& operator/=(const Vector2D& vec);

  Vector2D& operator+(int x);
  Vector2D& operator-(int x);
  Vector2D& operator*(int x);
  Vector2D& operator/(int x);

  Vector2D& operator+(float x);
  Vector2D& operator-(float x);
  Vector2D& operator*(float x);
  Vector2D& operator/(float x);

  friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);

};