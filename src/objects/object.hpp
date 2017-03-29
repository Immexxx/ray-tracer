#pragma once

#include "../libraries/material.hpp"
#include "../libraries/vector.hpp"

class Ray;

class Object {
public:
  Material material;

  Object(const Material &material) {
    this->material = material;
  }

  virtual float intersect(const Ray &ray) const = 0;

  virtual Vector get_normal(const Vector &position, const Ray &ray) const = 0;

  virtual Color get_color(const Vector &position) const {
    return material.color;
  }
};