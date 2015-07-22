#include "parser\parser-index.hpp"

ParserIndex::ParserIndex () {
	table_ = NULL;
}

ParserIndex::ParserIndex (std::string name) {
	ParserIndex ();

	name_ = name;
}

std::string ParserIndex::ToString () {
	return name_;
}