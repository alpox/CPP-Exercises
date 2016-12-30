
#ifndef FORMATSTREAM_H
#define FORMATSTREAM_H

#include <streambuf>
#include <vector>

class formatstream : public std::streambuf {
public:
	formatstream(std::ostream &sink);
private:
	formatstream::int_type overflow(formatstream::int_type ch);
	int sync();

	std::ostream &sink;
	char buf[256];
	int indent_level;
};

#endif // FORMATSTREAM_H