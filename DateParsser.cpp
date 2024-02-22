#include <cctype>
#include <cstddef>
#include "DateParsser.hpp"

void is_all_digit( std::string const & to_chek ) {

	size_t length = to_chek.length();

	if (!length)
		throw "An Etymo: Messin";

	for (size_t i = 0; i < to_chek.length(); i++)
		if (!std::isdigit(to_chek[i]) )
			throw "Non_Digit_Values: Founded";
}

void FormatDate::YearValueChecker(void ) {

	is_all_digit(_year);
}

void FormatDate::MonthValueChecker( void ) {

	is_all_digit(_month);
	int ismonth = std::atoi( _month.c_str() );
	if ( ismonth > 12 || !ismonth )
		throw "Incorrect_Month_Number";
}

void FormatDate::DayValueChecker( void ) {

	is_all_digit( _day );
	int isday = std::atoi( _day.c_str() );
	if ( isday > 31 || !isday )
		throw "Incorrect_Day_Number";

}

void FormatDate::setEtymologie( void ) {

	int old_span, span;

	span		= _date.find('-', 0);
	_year		= _date.substr(0, span );

	old_span	= span + 1;
	span		= _date.find('-', old_span);
	_month		= _date.substr(old_span, span - old_span);

	old_span	= span + 1;
	span		= _date.find('-', old_span);
	_day		= _date.substr(old_span, span - old_span );

}

void FormatDate::DateForma( void ){

	int count = 0;
	for (size_t i = 0; i < _date.length(); i++)
		if (_date[i] == '-')
			count++;

	if (count != 2)
		throw "Error Format Date";

} 

FormatDate::FormatDate( std::string etymo ): _date( etymo ) {

	DateForma();
	setEtymologie();
	YearValueChecker();
	MonthValueChecker();
	DayValueChecker();
}
