#pragma once
#include <EdgeNode.hpp>

template <typename T>
class Edge {
public:
  T value;
  float weight;

  Edge() {}
  Edge(T value, float weight = 0.0F) {
      this->value = value;
      this->weight = weight;
  }
  Edge(EdgeNode<T>* edge) {
      value = edge->getVertex()->getValue();
      weight = edge->getWeight();
  }

  T getValue() const { return value; }
  float getWeight() const { return weight; }

  bool operator==(const Edge<T>& other) const { return value == other.value && weight == other.weight; }
  bool operator!=(const Edge<T>& other) const { return !(*this == other);}
};



#include <functional>

namespace std {
    template <typename T>
    struct hash<Edge<T>> {
        size_t operator()(const Edge<T>& edge) const {
            return std::hash<T>()(edge.getValue());
        }
    };
}

