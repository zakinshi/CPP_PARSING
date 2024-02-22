#include "ValueParser.hpp"

bool sinshi::is_double() {

	char * conv_failed;

	std::strtod(value.c_str(), & conv_failed );
	if (!value.empty() && !(*conv_failed) )
		return true;
	return false;
}

double sinshi::to_double() {

	double my_num = atof( value.c_str() );
	if (my_num < 0)
		throw "Error: not a positive number.";
	else if ( my_num > 2147483647 )
		throw "Error: too large a number.";
	return my_num;
}

float sinshi::ValueCheckin( void ) {

	if (!is_double())
		throw "Invalid Input Value ..";
	return to_double();
}