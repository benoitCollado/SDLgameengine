#include "Vector2D.hpp"

Vector2D::Vector2D() {
  x = .0f;
  y = .0f;
}

Vector2D::Vector2D(float x, float y) {
  this->x = x;
  this->y = y;
}

float Vector2D::norme() { return std::sqrt(x * x + y * y); }

void Vector2D::normalize() {
  float n = this->norme();
  if (n != 0) {
    this->x /= n;
    this->y /= n;
  }
}

Vector2D &Vector2D::Add(const Vector2D &vec) {
  this->x += vec.x;
  this->y += vec.y;

  return *this;
}

Vector2D &Vector2D::Substract(const Vector2D &vec) {
  this->x -= vec.x;
  this->y -= vec.y;

  return *this;
}

Vector2D &Vector2D::Multiply(const Vector2D &vec) {
  this->x *= vec.x;
  this->y *= vec.y;

  return *this;
}

Vector2D &Vector2D::Divide(const Vector2D &vec) {
  this->x /= vec.x;
  this->y /= vec.y;

  return *this;
}

Vector2D &operator+(Vector2D &vec1, const Vector2D &vec2) {
  return vec1.Add(vec2);
}

Vector2D &operator-(Vector2D &vec1, const Vector2D &vec2) {
  return vec1.Substract(vec2);
}

Vector2D &operator*(Vector2D &vec1, const Vector2D &vec2) {
  return vec1.Multiply(vec2);
}

Vector2D &operator/(Vector2D &vec1, const Vector2D &vec2) {
  return vec1.Divide(vec2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vec) { return this->Add(vec); }

Vector2D &Vector2D::operator-=(const Vector2D &vec) {
  return this->Substract(vec);
}

Vector2D &Vector2D::operator*=(const Vector2D &vec) {
  return this->Multiply(vec);
}

Vector2D &Vector2D::operator/=(const Vector2D &vec) {
  return this->Divide(vec);
}

Vector2D &Vector2D::operator+(int x){
  this->x += x;
  this->y += x;
  return *this;
}

Vector2D &Vector2D::operator-(int x){
  this->x -= x;
  this->y -= x;
  return *this;
}

Vector2D &Vector2D::operator*(int x){
  this->x *= x;
  this->y *= x;
  return *this;
}

Vector2D &Vector2D::operator/(int x){
  this->x /= x;
  this->y /= x;
  return *this;
}

Vector2D &Vector2D::operator+(float x){
  this->x += x;
  this->y += x;
  return *this;
}

Vector2D &Vector2D::operator-(float x){
  this->x -= x;
  this->y -= x;
  return *this;
}

Vector2D &Vector2D::operator*(float x){
  this->x *= x;
  this->y *= x;
  return *this;
}

Vector2D &Vector2D::operator/(float x){
  this->x /= x;
  this->y /= x;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vec) {
  os << "Vector2D(" << vec.x << ", " << vec.y << ")";
  return os;
}