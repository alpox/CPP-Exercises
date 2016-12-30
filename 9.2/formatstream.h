
#ifndef FORMATSTREAM_H
#define FORMATSTREAM_H

#include <streambuf>
#include <vector>

class formatstream : public std::streambuf {
public:
	formatstream(std::ostream &sink);
	~formatstream();
private:
	formatstream::int_type overflow(formatstream::int_type ch);
	int sync();

	char buf[256];
	int indent_level;
	std::ostream *sink;
	std::streambuf *original_steambuf;
};

#endif // FORMATSTREAM_H