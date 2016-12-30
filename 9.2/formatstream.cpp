
#include "formatstream.h"
#include <vector>
#include <ostream>

formatstream::formatstream(std::ostream &sink) : sink(sink), indent_level(0) {
	setp(buf, buf + sizeof(buf));
}

formatstream::int_type formatstream::overflow(formatstream::int_type ch){
	if (ch != traits_type::eof() && sync() == 0) return sputc(ch);
	return traits_type::eof();
}

int formatstream::sync(){
	if (pbase() == pptr()) return 0;

	std::vector<char> rendered;
	bool escaped = false;
	bool new_line = false;
	for (char* c_ptr = pbase(); c_ptr < pptr(); ++c_ptr) {
		if (*c_ptr == '\""' || *c_ptr == '\''){
			escaped = !escaped;
			rendered.push_back(*c_ptr);
		} else if (!escaped && (*c_ptr == '(' || *c_ptr == '{' || *c_ptr == '[')) {
			++indent_level;
			rendered.push_back(*c_ptr);
		} else if (!escaped && (*c_ptr == ')' || *c_ptr == '}' || *c_ptr == ']')) {
			--indent_level;
			rendered.push_back(*c_ptr);
		} else if (*c_ptr == '\n') {
			new_line = true;
			rendered.push_back(*c_ptr);
			for(int indent_idx = 0; indent_idx < indent_level; ++indent_idx) rendered.push_back('\t');
		} else if (!new_line && *c_ptr != ' ') {
			new_line = false;
			rendered.push_back(*c_ptr);
		}
	}

	// puts the pptr back to pbase
	pbump(pbase() - pptr());
	
	// write rendered content to sink
	return sink.write(&rendered.front(), rendered.size()) ? 0 : -1;
}