#ifndef LEXER_HPP_
#define LEXER_HPP_

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.hpp"
using namespace yy;

#undef  YY_DECL
#define YY_DECL int Lexer::yylex()
#define YY_NO_UNISTD_H		// So it's compiled by VC as well

class Lexer : public yyFlexLexer
{
private:
	int yylex ();
	Parser::semantic_type *yylval;
	yy::location location_;

public:
	Lexer (std::istream *input) : yyFlexLexer (input), yylval (NULL) { };

	// Get and set location
	yy::location getLocation () const { return location_; }
	void setLocation (yy::location loc) { location_ = loc; }

	int yylex (Parser::semantic_type *lval)
	{
		yylval = lval;
		return yylex ();
	}
};

#endif