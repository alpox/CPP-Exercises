
#include "formatstream.h"
#include <vector>
#include <ostream>
#include <iostream>

/* buf: [ , , , , , , , , , ]
 *		 ^       ^         ^
 *     pbase   pptr      epptr
 */     

// on construction, sets stream_buf of sink to this, and saves sink's old stream_buf in original_streambuf
formatstream::formatstream(std::ostream &sink) : sink(&sink), original_steambuf(sink.rdbuf(this)), indent_level(0) {
	// sets pbase to beggining of buf and epptr to end of buf
	setp(buf, buf + sizeof(buf));
}

// on desctruction, sets stream_buf of sink to sink's original stream_buf
formatstream::~formatstream(){
	if(sink) sink->rdbuf(original_steambuf);
}

// buf is full
formatstream::int_type formatstream::overflow(formatstream::int_type ch){
	if (ch != traits_type::eof() && *sink && sync() == 0) return sputc(ch);
	return traits_type::eof();
}

// process buf's entries and put them in original_steambuf
int formatstream::sync(){
	if (pbase() == pptr()) return 0;
	std::vector<char> rendered;
	bool escaped_single_q = false;
	bool escaped_double_q = false;
	bool new_line = false;

	// iterate though buf
	for (char* c_ptr = pbase(); c_ptr < pptr(); ++c_ptr) {
		bool ignore = false;

		// if single quote and is not escaped by double quote
		if (*c_ptr == '\'' && !escaped_double_q){
			escaped_single_q = !escaped_single_q;

		// if double quote and is not escaped by single quote
		} else if (*c_ptr == '\"' && !escaped_single_q) {
			escaped_double_q = !escaped_double_q;

		// if ( or { or [ and is not escaped by single or double quote
		} else if (!escaped_single_q && !escaped_double_q && (*c_ptr == '(' || *c_ptr == '{' || *c_ptr == '[')) {
			++indent_level;

		// if ) or } or ] and is not escaped by single or double quote
		} else if (!escaped_single_q && !escaped_double_q && (*c_ptr == ')' || *c_ptr == '}' || *c_ptr == ']')) {
			--indent_level;

		// if new line
		} else if (*c_ptr == '\n') {
			new_line = true;

		// if no more whitespace after new line
		} else if (new_line && *c_ptr != ' ') {
			new_line = false;

			// add indent
			for(int indent_idx = 0; indent_idx < indent_level; ++indent_idx) rendered.push_back('\t');

		// if whitespace after new line
		} else if (new_line && *c_ptr == ' ') {
			ignore = true;
		}

		// add to rendered if not ignored
		if (!ignore) rendered.push_back(*c_ptr);
	}

	// write rendered content to original_steambuf
	std::streamsize n = original_steambuf->sputn(&rendered.front(), rendered.size());

	// puts the pptr back to pbase
	setp(buf, buf + sizeof(buf));
	
	return n ? 0 : -1;
}