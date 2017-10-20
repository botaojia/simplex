#include <algorithm>
#include <iterator>
#include <iostream>

template<class Container>
void printcon(const Container& c)
{
	std::cout.precision(12);
	std::copy(c.begin(),
			  c.end(), 
			  std::ostream_iterator<typename Container::value_type>(std::cout, " "));
	std::cout << std::endl;
}
