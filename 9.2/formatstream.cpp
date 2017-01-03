
#include "formatstream.h"
#include <vector>
#include <ostream>
#include <iostream>

formatstream::formatstream(std::ostream &sink) : sink(&sink), original_steambuf(sink.rdbuf(this)), indent_level(0) {
	setp(buf, buf + sizeof(buf));
}

formatstream::~formatstream(){
	if(sink) sink->rdbuf(original_steambuf);
}

formatstream::int_type formatstream::overflow(formatstream::int_type ch){
	if (ch != traits_type::eof() && *sink && sync() == 0) return sputc(ch);
	return traits_type::eof();
}

int formatstream::sync(){
	if (pbase() == pptr()) return 0;
	std::vector<char> rendered;
	bool escaped_single_q = false;
	bool escaped_double_q = false;
	bool new_line = false;
	for (char* c_ptr = pbase(); c_ptr < pptr(); ++c_ptr) {
		bool ignore = false;
		if (*c_ptr == '\"' && !escaped_double_q){
			escaped_single_q = !escaped_single_q;
			
		} else if (*c_ptr == '\'' && !escaped_single_q) {
			escaped_double_q = !escaped_double_q;
		} else if (!escaped_single_q && !escaped_double_q && (*c_ptr == '(' || *c_ptr == '{' || *c_ptr == '[')) {
			++indent_level;
		} else if (!escaped_single_q && !escaped_double_q && (*c_ptr == ')' || *c_ptr == '}' || *c_ptr == ']')) {
			--indent_level;
		} else if (*c_ptr == '\n') {
			new_line = true;
		} else if (new_line && *c_ptr != ' ') {
			new_line = false;
			for(int indent_idx = 0; indent_idx < indent_level; ++indent_idx) rendered.push_back('\t');
		} else if (new_line && *c_ptr == ' ') {
			ignore = true;
		}
		if (!ignore) rendered.push_back(*c_ptr);
	}

	// write rendered content to original_steambuf
	std::streamsize n = original_steambuf->sputn(&rendered.front(), rendered.size());

	// puts the pptr back to pbase
	setp(buf, buf + sizeof(buf));
	
	return n ? 0 : -1;
}