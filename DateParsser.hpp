#ifndef __DATE__PARSSER__HPP__
#define __DATE__PARSSER__HPP__

#include <string>


class FormatDate {

	public:

		FormatDate( std::string );
		void		DateForma( void );

		void		DayValueChecker  ( void );
		void		MonthValueChecker( void );
		void		YearValueChecker ( void );

		void		setEtymologie();

	private:

		std::string		_date;

		std::string		_day;
		std::string		_month;
		std::string		_year;

};

#endif