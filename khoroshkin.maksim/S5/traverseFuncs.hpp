#ifndef TRAVERSEFUNCS_HPP
#define TRAVERSEFUNCS_HPP

#include <iosfwd>
#include <string>
#include "tree.hpp"

namespace khoroshkin
{
  void ascendingTraverse(const Tree< int, std::string > & data, std::ostream & out);
  void descendingTraverse(const Tree< int, std::string > & data, std::ostream & out);
  void breadthTraverse(const Tree< int, std::string > & data, std::ostream & out);
}

#endif