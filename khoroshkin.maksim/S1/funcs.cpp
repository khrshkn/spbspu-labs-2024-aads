#include "funcs.hpp"
#include <limits>
#include <stdexcept>

using namespace khoroshkin;

void khoroshkin::printResult(std::ostream & out, List< std::pair< std::string, List< int > > > & allPairs, int maxLength, bool isOverflow)
{
  if (allPairs.getSize() == 0)
  {
    throw std::logic_error("Empty list");
  }
  for (auto it = allPairs.begin(); it != allPairs.end(); ++it)
  {
    out << (*it).first;
    allPairs.next(it) == allPairs.end() ? std::cout << "\n" : std::cout << " ";
  }

  if (allPairs[0].second.isEmpty())
  {
    throw std::logic_error("Empty list");
  }

  for (int i = 0; i < maxLength; i++)
  {
    for (auto it = allPairs.begin(); it != allPairs.end(); it++)
    {
      if ((*it).second.getSize() > i)
      {
        out << (*it).second[i];
        (allPairs.next(it) == allPairs.end() || !checkAllNext(i, it, allPairs)) ? out << "\n" : out << " ";
      }
    }
  }

  if (isOverflow)
  {
    throw std::out_of_range("overflow!\n");
  }

  for (int i = 0; i < maxLength; i++)
  {
    long long sum = 0;
    for (auto it = allPairs.begin(); it != allPairs.end(); it++)
    {
      if ((*it).second.getSize() > i)
      {
        if (std::numeric_limits<long long>::max() - sum < (*it).second[i])
        {
          throw std::overflow_error("overflow!");
        }
        sum += (*it).second[i];
      }
    }
    out << sum;
    (i + 1 == maxLength) ? out << "\n" : out << " ";
  }
}

template < typename T >
bool khoroshkin::checkAllNext(int index, ListIterator< T > it, List< std::pair< std::string, List< int > > > & allPairs)
{
  bool flag = false;
  while (allPairs.next(it) != allPairs.end())
  {
    if ((*allPairs.next(it)).second.getSize() - 1 >= index)
    {
      flag = true;
    }
    ++it;
  }
  return flag;
}