#pragma once

#include <ostream>
#include <cmath>
#include "utility.hpp"

class Vector {
public:
  static const Vector ZERO, INVALID;

  float x, y, z;

  Vector(float x = 0, float y = 0, float z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vector& operator += (const Vector &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vector& operator -= (const Vector &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  Vector& operator *= (const Vector &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  Vector& operator *= (float k) {
    x *= k;
    y *= k;
    z *= k;
    return *this;
  }

  Vector& operator /= (const Vector &v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  Vector& operator /= (float k) {
    x /= k;
    y /= k;
    z /= k;
    return *this;
  }

  friend Vector operator + (Vector u, const Vector &v) {
    return u += v;
  }

  friend Vector operator - (Vector u, const Vector &v) {
    return u -= v;
  }

  friend Vector operator * (Vector u, const Vector &v) {
    return u *= v;
  }

  friend Vector operator * (Vector u, float k) {
    return u *= k;
  }

  friend Vector operator * (float k, Vector u) {
    return u *= k;
  }

  friend Vector operator / (Vector u, const Vector &v) {
    return u /= v;
  }

  friend Vector operator / (Vector u, float k) {
    return u /= k;
  }

  Vector operator - () const {
    return Vector(-x, -y, -z);
  }

  const float& operator [] (int i) const {
    return (&x)[i];
  }

  float& operator [] (int i) {
    return (&x)[i];
  }

  bool operator == (const Vector &v) {
    return x == v.x && y == v.y && z == v.z;
  }

  bool operator != (const Vector &v) {
    return !(*this == v);
  }

  float dot(const Vector &v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  Vector det(const Vector &v) const {
    return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
  }

  float length() const {
    return sqrtf(x * x + y * y + z * z);
  }

  Vector normalize() const {
    auto factor = length();
    if (factor < numeric_eps) {
      return Vector::ZERO;
    }
    return Vector(x / factor, y / factor, z / factor);
  }

  Vector reflect(const Vector &normal) const {
    return ((*this) - 2 * dot(normal) * normal).normalize();
  }

  Vector refract(Vector normal, float index) const {
    auto cos = fabsf(dot(normal));
    auto k = 1 - index * index * (1 - cos * cos);
    if (k < numeric_eps) {
      return Vector::INVALID;
    }
    return (index * (*this) + (index * cos - sqrtf(k)) * normal).normalize();
  }

  friend std::ostream& operator << (std::ostream &os, const Vector &v) {
    os << "[" << v.x << " " << v.y << " " << v.z << "]";
    return os;
  }
};

const Vector Vector::ZERO = Vector(0, 0, 0);
const Vector Vector::INVALID = Vector(0, 0, 0);