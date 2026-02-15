#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include<string>
#include<ctime>
#include"clsString.h"

using namespace std;


class clsDate
{

		short _Day ;
		short _Mointh ;
		short _Year ;
		

public:
	 
	
	clsDate()
	{
		
		time_t t = time(0) ; // get time now 
		tm* TimeNow= localtime(&t); // converting now to tm struct for UTC date/time 
		_Year = TimeNow->tm_year+1900 ;
		_Mointh = TimeNow->tm_mon+1 ; 
		_Day = TimeNow->tm_mday ;
		

	};
	
	clsDate(short Day , short Mointh , short Year)
	{
		_Day = Day ;
		_Mointh = Mointh;
		_Year  = Year ;
	}

	clsDate(string DateText)
	{
		vector<string>vDate;
		vDate = clsString::Split(DateText , "/");

		_Day = stoi(vDate[0]);
		_Mointh = stoi(vDate[1]);
		_Year = stoi(vDate[2]);


	}

	clsDate(short Day , short Year)
	{
		
		clsDate Date1;
		 Date1 = GetDateFromDayOrderInYear(Day , Year);

		_Day = Date1._Day ;
		_Mointh = Date1._Mointh;
		_Year = Date1._Year ; 

	}

	void Print()
	{
		cout<<_Day<<"/"<<_Mointh<<"/"<<_Year<<endl;
	}
	
	void SetDay(short Day)
	{
		_Day = Day ;
	}

	short GetDay()
	{
		return _Day;
	}

	_declspec(property(get = GetDay , put = SetDay)) short Day;

	short GetMointh()
	{
		return _Mointh;
	}

	void SetMointh(short Mointh)
	{
		_Mointh = Mointh ;
	}

	_declspec(property(get = GetMointh , put = SetMointh)) short Mointh;

	short GetYear()
	{
		return _Year;
	}

	void SetYear(short Year)
	{
		_Year = Year ;
	}

	_declspec(property(get = GetYear , put = SetYear)) short Year;

	static bool IsLeapYera(int Year)
	{
	return  ((Year % 400 == 0 )||(Year % 100 != 0 && Year % 4 == 0));   
	}

	bool IsLeapYera()
	{
		return IsLeapYera(_Year);
	}

	static int NumberOfDay(short Year)
	{
		return IsLeapYera(Year) ? 366 : 365;
	
	}
	
	int NumberOfDay()
	{
		return NumberOfDay(_Year);
	}
	
	static short NumberOfDayInMointh(int Mointh , short Year)
	{
		if(Mointh < 1 ||  Mointh > 12)
		{
			return 0;
		}

		int days[12] ={31,28,31,30,31,30,31,31,30,31,30,31}; 

		return (Mointh == 2)?(IsLeapYera(Year)?29:28):days[Mointh - 1];
	}
	
	short NumberOfDayInMointh()
	{
		return NumberOfDayInMointh(_Year , _Mointh);
	}

	static int NumberOfHouersInMointh(short Year, short Mointh)
	{
		return NumberOfDayInMointh(Year,Mointh) * 24  ;
	}

	int NumberOfHouersInMointh()
	{
		return NumberOfHouersInMointh(_Year , _Mointh);
	}

	static int NumberOfMintesInMointh(short Year, short Mointh)
	{
		return NumberOfHouersInMointh(Year,Mointh) * 60 ;
	}

	int NumberOfMintesInMointh()
	{
		return NumberOfMintesInMointh(_Year , _Mointh);
	}

	static int NumberOfSecondesInMointh(short Year, short Mointh)
	{

		return NumberOfMintesInMointh(Year,Mointh) * 60 ;
	}

	int NumberOfSecondesInMointh()
	{
		return NumberOfSecondesInMointh(_Year , _Mointh);
	}

	void PrintNumberOfDayAndHouers(short Year, short Mointh)
	{



		cout<<"\nNumber Of Days	    in Mointh ["<<Mointh<<"] is : "<< NumberOfDayInMointh(Year,Mointh);

		cout<<"\nNumber Of Houers    in Mointh ["<<Mointh<<"] is : "
			<<NumberOfHouersInMointh(Year,Mointh);

		cout<<"\nNumber Of Minutes   in Mointh ["<<Mointh<<"] is : "
			<<NumberOfMintesInMointh(Year,Mointh);

		cout<<"\nNumber Of Seconds   in Mointh ["<<Mointh<<"] is : "
			<<NumberOfSecondesInMointh(Year,Mointh);  

	}

	static string NameOfDay(short Days)
	{
		string arrDaysName[] = {"Sun","Mon","Tu","Wen","Thur","Frid","Star"};

		return arrDaysName[Days];
	}

	string NameOfDay()
	{
		return NameOfDay(_Day);
	}

	static  short  DayOfWeekOreder(short Days , short Mointh , short Year)
	{

		// معادلة التاريخ 
		short a , y ,m , d ;
		a = (14-Mointh)/12 ;
		y = Year - a ;
		m = Mointh + 12*a - 2 ;
		d = (Days + y +(y/4) - (y/100) + (y/400) + (31*m/12))%7;
	
		return d;	
	

	}

	short  DayOfWeekOreder()
	{
		return  DayOfWeekOreder(_Day, _Mointh, _Year);
	}

	static string NameOfMointh(short Mointh)
	{
	string arrNameOfMaointh[] = {" ","Jan","Feb","Mar","Apri","May","Jun","Jul","Agu","Sep","Oct","Nove","Des"};
	return arrNameOfMaointh[Mointh];
	}

	string NameOfMointh()
	{
		return  NameOfMointh(_Mointh);
	}

	void PrintMointhCalender(short Year , short Mointh )
	{
		short Currnt = DayOfWeekOreder(1,Mointh , Year);

		short NumberOfMointh = NumberOfDayInMointh(Year,Mointh); 
	
		cout<<"\n___________________________"<<NameOfMointh(Mointh)<<"_____________________________\n";

		printf("   Sun  Mon Tue  Wed  Thu  Fri  Sat \n");
		short i ;
		for(i = 0 ; i < Currnt ; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfMointh; j++)
		{
			printf("%5d",j);
		
			if(++i == 7)
			{
				i = 0 ;
				printf("\n");
			}

	
		}
				printf("\n  _________________________________________________________________\n");

	}

	void PrintYeraCalender(short Year)
	{


	printf("\n\t\t__________________________\n");
	printf("\n\t\t\tCalender %d\n",Year);
	printf("\n\t\t___________________________\n");
	for (int i = 1; i <= 12; i++)
	{
		PrintMointhCalender(Year , i);

	}

	}
	
	static int NumberOfDaysFromTheBeginningOfTheYear(short Days , short Mointh , short Year)
	{
		short SumOfDays = 0 ;

		for (int i = 1; i <=Mointh-1 ; i++)
		{
			SumOfDays += NumberOfDayInMointh(i , Year);
		}

		SumOfDays += Days ;

		return SumOfDays; 



	}

	int NumberOfDaysFromTheBeginningOfTheYear()
	{
		return NumberOfDaysFromTheBeginningOfTheYear(_Day, _Mointh, _Year);
	}

	 clsDate GetDateFromDayOrderInYear(short NumberOfDayInYear , short Year)
	{
			clsDate Date; 
			short ReaminngDays = NumberOfDayInYear ;
			short MointhOfDay = 0;
			
			Date._Year = Year ;
			Date._Mointh = 1 ;
			
			while (true)
			{
				MointhOfDay = NumberOfDayInMointh(Year , Date._Mointh );

				if(ReaminngDays > MointhOfDay)
				{

				ReaminngDays -= MointhOfDay ;
				Date._Mointh++;

				}
				else
				{

				Date._Day = ReaminngDays  ;
				break;
				}

			}

		return Date;
	}

	static bool  IsDate1BeforeDate2(clsDate Date1 , clsDate Date2)
	{

		return (Date1._Year<Date2._Year)?true : ((Date1._Year == Date2._Year)? (Date1._Mointh < Date2._Mointh)?true : (Date1._Mointh == Date2._Mointh ? Date1._Day < Date2._Day:false ) :false) ;
	}

	bool  IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this , Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1 , clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Mointh == Date2._Mointh )?((Date1._Day == Date2._Day)?true:false ) :false) :false;
	}

	bool  IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this , Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1 , clsDate Date2)
	{

	return (!IsDate1BeforeDate2(Date1 , Date2) && !IsDate1EqualDate2(Date1 , Date2));

	}
	
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return  IsDate1AfterDate2(*this , Date2);
	}

	static bool IsLastDayInMointh(clsDate Date)
	{
		return (Date._Day == NumberOfDayInMointh(Date._Mointh , Date._Year)) ;
	}

	static bool IsLastMointhInYear(short Mointh)
	{
		return Mointh == 12 ;
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{

		if(IsLastDayInMointh(Date))
		{

			if(IsLastMointhInYear(Date._Mointh))
			{
				Date._Mointh = 1;
				Date._Day = 1 ;
				Date._Year++;
			}
			else
			{
				Date._Day = 1 ;
				Date._Mointh++;
			}


		}else
		{
			Date._Day++;
		}

		return Date ; 
	}
	
	static void SwapDate(clsDate &Date1 , clsDate &Date2 )
	{

		clsDate TmpDate ;

		TmpDate._Year = Date1._Year ;
		TmpDate._Mointh = Date1._Mointh ;
		TmpDate._Day = Date1._Day ;

		Date1._Day = Date2._Day ; 
		Date1._Mointh = Date2._Mointh ; 
		Date1._Year = Date2._Year ;

		Date2._Day = TmpDate._Day ;
		Date2._Mointh = TmpDate._Mointh ;
		Date2._Year = TmpDate._Year ;

	
	}

	void SwapDate(clsDate Date2)
	{
		SwapDate(*this , Date2);
	}

	static short GetDeffrentBteweenDate1AndDate2(clsDate Date1 , clsDate Date2 , bool Includeing  = false)
	{

		short 	Days = 0 ;
		short SwapFlagValue = 1  ;

		if(!IsDate1BeforeDate2(Date1 , Date2))
		{
				SwapDate(Date1 , Date2);
				SwapFlagValue = -1 ; 
		}


			while (IsDate1BeforeDate2(Date1 , Date2) )
			{
				Days ++ ;
				Date1 = IncreaseDateByOneDay(Date1);
			}
	

		return (Includeing)? ++Days * SwapFlagValue : Days * SwapFlagValue   ;

	}
 
	short GetDeffrentBteweenDate1AndDate2(clsDate Date2 , bool Includeing = false )
	{
		return GetDeffrentBteweenDate1AndDate2(*this , Date2 , Includeing );
	}

	static clsDate IncreaseDateByXDays(clsDate Date , short XDays)
	{
		short C = 0 ;

		while (C < XDays)
		{
			Date = IncreaseDateByOneDay(Date);
			C++;
		}

		return	Date ; 
	}

	void  IncreaseDateByXDays(short XDays)
	{
		*this = IncreaseDateByXDays(*this , XDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		short C = 0 ;

		while (C < 7)
		{
			Date = IncreaseDateByOneDay(Date);
			C++;
		}
		return	Date ; 
	}

	void  IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this );
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date , short Weeks)
	{
	
		short C = 0 ;

		while (C < Weeks)
		{
			Date = IncreaseDateByOneWeek(Date);


			C++;
		}

		return	Date ; 
	}

	void  IncreaseDateByXWeeks(short Weeks)
	{
		*this = IncreaseDateByXWeeks(*this , Weeks);
	}

	static clsDate IncreaseDateByOneMointh(clsDate Date)
	{
	
		if(Date._Mointh == 12 )
		{
			Date._Mointh = 1 ; 
			Date._Year++;
		}else
		{
			Date._Mointh++;
		}
	
		short NumberOfDaysInCurrenMointh = NumberOfDayInMointh(Date._Mointh , Date._Year);

		if(Date._Day > NumberOfDaysInCurrenMointh )
		{
			Date._Day = NumberOfDaysInCurrenMointh ;
		}

		return Date ;
	}

	void  IncreaseDateByOneMointh()
	{
		*this = IncreaseDateByOneMointh(*this );
	}

	static clsDate IncreaseDateByXMoinths(clsDate Date, short Moniths )
	{
		short C = 0 ;

		while (C < Moniths)
		{
			Date = IncreaseDateByOneMointh(Date);
			C++;

		}

		return Date ;
	}

	void  IncreaseDateByXMoinths(short Moniths)
	{
		*this = IncreaseDateByXMoinths(*this , Moniths);
	}

	static clsDate IncreaseDateByOneYearFester( clsDate Date)
	{
		Date._Year++;
		return  Date ;
	}

	void  IncreaseDateByOneYearFester()
	{
		*this = IncreaseDateByOneYearFester(*this );
	}

	static clsDate IncreaseDateByXYears(clsDate Date, short Years)
	{
		short C = 0 ;

		while (C < Years)
		{
			Date =  IncreaseDateByOneYearFester(Date);
		
			C++;
		}

		return Date ; 
	}
	
	void  IncreaseDateByXYears(short Years)
	{
		*this = IncreaseDateByXMoinths(*this , Years);
	}

	static clsDate IncreaseDateByXYearsFester(clsDate Date , short Years)
	{
			Date._Year +=  Years; 

			return Date ; 
	}
	
	void  IncreaseDateByXYearsFester(short Years)
	{
		*this = IncreaseDateByXYearsFester(*this , Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date )
	{
		Date._Year += 10 ;
		return  Date ;
	}

	void  IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneYearFester(*this );
	}

	static clsDate IncreaseDateByXDecades(clsDate Date , short Decades)
	{
		short C = 0 ;

		while ( C < Decades)
		{
			Date = IncreaseDateByOneDecade(Date);
			C++ ; 
		}
		return  Date;
	}

	void  IncreaseDateByXDecades(short Decades)
	{
		*this = IncreaseDateByXYearsFester(*this , Decades);
	}

	static clsDate IncreaseDateByXDecadesFaster(clsDate Date , short Decades)
	{
		 Date._Year += (10*Decades);
		 return Date;
	}

	void  IncreaseDateByXDecadesFaster(short Decades)
	{
		*this = IncreaseDateByXDecadesFaster(*this , Decades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date )
	{
		Date._Year += 100 ;
		return Date ;
	}
	
	void  IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this );
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year += 1000 ; 
		return  Date;
	}

	void  IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this );
	}

	static bool IsFristDayInMointh(short Day)
	{
		return Day == 1 ; 
	}

	static bool IsFristMointhInYear(short Mointh)
	{
		return Mointh == 1 ;
	}

	static short LengthOfMointh(clsDate Date)
	{
		short SizOfMointh = 0 ;
		if(Date._Mointh ==1)
		{
			Date._Mointh = 12 ;
			Date._Year--;
			SizOfMointh = NumberOfDayInMointh(Date._Mointh , Date._Year); 
		}else
		{
			Date._Mointh--;
			SizOfMointh = NumberOfDayInMointh(Date._Mointh , Date._Year);
		}

		return SizOfMointh ;
	}

	static clsDate DecreaseDateByOneDay(clsDate Date) 
	{
									     
		if(Date._Day == 1)
		{

			if(Date._Mointh == 1)
			{
				Date._Mointh = 12 ;
				Date._Year--;
				Date._Day = 31 ;

			}else
			{
				Date._Mointh--;
				Date._Day = NumberOfDayInMointh(Date._Mointh , Date._Year );
			}


		}else
		{
			Date._Day--;
		}

	
	
		return Date ; 
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days , clsDate Date)
	{

		for (int i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date) ;
		}

		return Date ;

	}

	void DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days , *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{

		for (int i = 1; i <= 7 ; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}


		return Date ; 
	}
	
	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks , clsDate Date)
	{

		for (int i = 1; i <= Weeks ; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}


		return Date ; 
	}
	
	void DecreaseDateByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks , *this);
	}

	static clsDate DecreaseDateByOneMointh(clsDate Date)
	{

		if(Date._Mointh == 1 )
		{
			Date._Mointh = 12 ;
			Date._Year--;
		}else
		{
			Date._Mointh--;
		}

		
		short NumberOfDaysInCurrentMointh  = NumberOfDayInMointh(Date._Mointh , Date._Year);

		if(Date._Day > NumberOfDaysInCurrentMointh)
		{
			Date._Day = NumberOfDaysInCurrentMointh ;
		}
		return Date ; 
	}

	void DecreaseDateByOneMointh()
	{
		*this = DecreaseDateByOneMointh(*this);
	}

	static clsDate DecreaseDateByXMoinths(short Moinths , clsDate Date)
	{

		for (int i = 1; i <= Moinths ; i++)
		{
			Date = DecreaseDateByOneMointh(Date);
		}


		return Date ; 
	}
	
	void DecreaseDateByXMoinths(short Moinths)
	{
		*this = DecreaseDateByXMoinths(Moinths , *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{

		Date._Year--;

		return Date ;
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (int i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date ;
	}

	void DecreaseDateByXYears(short Years)
	{
		*this = DecreaseDateByXYears(Years , *this);
	}

	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date._Year -= Years ;
		return Date ;
	}

	void DecreaseDateByXYearsFaster(short Years)
	{
		*this = DecreaseDateByXYearsFaster(Years , *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date._Year -= 10 ;
		return Date ;
	}

	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByxDecades(short Decades, clsDate Date)
	{
		for (int i = 1; i <=Decades * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date ;
	}
	
	void DecreaseDateByxDecades(short Decades)
	{
		*this = DecreaseDateByxDecades(Decades , *this);
	}

	static clsDate DecreaseDateByXDecadesFaster(short Decades, clsDate Date)
	{
		Date._Year -= (10 * Decades);
		return Date ; 
	}
	
	void DecreaseDateByXDecadesFaster(short Decades)
	{
		*this = DecreaseDateByXDecadesFaster(Decades , *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100 ;
		return Date ;
	}
	
	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date ;
	}
	
	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	short  DayOfWeekOreder(clsDate Date)
	{

	// ?????? ??????? 
	short a , y ,m , d ;
	a = (14-Date._Mointh )/12 ;
	y = Date._Year  - a ;
	m = Date._Mointh + 12*a - 2 ;
	d = (Date._Day + y +(y/4) - (y/100) + (y/400) + (31*m/12))%7;
	
	return d;	
	

	}

	bool IsEndOfWeek(clsDate Date)
	{

		return DayOfWeekOreder(Date) == 6;  

	}

	bool IsWeekEnd(clsDate Date)
	{

		 short DayIndx = DayOfWeekOreder(Date);  
		 return DayIndx == 4 || DayIndx == 5 ;
	}

	bool IsBusinessDay(clsDate Date)
	{
	return !IsWeekEnd(Date);
	}

	short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6- DayOfWeekOreder(Date) ;
	}

	short DaysUntilTheEndOfMointh(clsDate Date)
	{
		clsDate EndOfMontDate ;
		EndOfMontDate._Day = NumberOfDayInMointh(Date._Mointh , Date._Year);
		EndOfMontDate._Mointh = Date._Mointh;
		EndOfMontDate._Year = Date._Year ; 

		return GetDeffrentBteweenDate1AndDate2(Date , EndOfMontDate , true);
	}

	short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31 ;
		EndOfYearDate._Mointh = 12 ;
		EndOfYearDate._Year = Date._Year ;

		return GetDeffrentBteweenDate1AndDate2(Date , EndOfYearDate , true);
	}

	static clsDate GetSystemDate()
	{

		clsDate DateNow ;
	
		time_t t = time(0) ; // get time now 

		tm* TimeNow= localtime(&t); // converting now to tm struct for UTC date/time 

		DateNow._Year = TimeNow->tm_year+1900 ;
		DateNow._Mointh = TimeNow->tm_mon+1 ; 
		DateNow._Day = TimeNow->tm_mday ;

	 
		return DateNow ; 
	
	}


	short NumberOfHowManyDaysOfVaction(clsDate DateFrom , clsDate DateTo)
	{
		short DaysCount = 0 ;
		while (IsDate1BeforeDate2(DateFrom , DateTo))
		{

			if(IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DaysCount ;
	}

	clsDate CalculateVactionReternDate(clsDate DateFrom ,  short DaysVaction)
	{
	
		short WeekEndCount = 0 ;
		for (short i = 1; i <=  DaysVaction; i++)
		{
			if(IsWeekEnd(DateFrom))
				WeekEndCount++;


			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <=  WeekEndCount; i++)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);

		}
	
		return DateFrom ;

	}

	enum enComperDate {enBefore = -1 , enAfter = 1 , enEucal = 0 };

	static enComperDate CompbersDates(clsDate Date1 , clsDate Date2)
	{


		if(IsDate1BeforeDate2(Date1 , Date2))
			return enComperDate::enBefore ;

		if(IsDate1EqualDate2(Date1 , Date2))
			return enComperDate::enEucal ;

		return enComperDate::enAfter ;

	}

	enComperDate CompbersDates(clsDate Date2)
	{
		return  CompbersDates(*this , Date2);
	}

	static bool IsValidDate(clsDate Date1)
	{
		if(Date1.Day < 1 || Date1.Day >31 )
			return false ;

		if(Date1.Mointh < 1 || Date1.Mointh > 12)
			return false ;

		if(Date1.Mointh == 2 )
		{

			if(IsLeapYera(Date1.Year))
			{
				if(Date1.Day > 29)
					return false ;

			}else
			{
				if(Date1.Day > 28 )
					return false ;
			}


		}

		short DaysInMonth = NumberOfDayInMointh(Date1.Mointh , Date1.Year);

		if(Date1.Day > DaysInMonth)
			return false ;


		return true ; 

	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
	 	string  DateString = to_string( Date.Day) + "/"  +  to_string( Date.Mointh) + "/"  + to_string(Date.Year) ; 
		return DateString;
	}

	static string GetSystemDateTimeString()
	{

		int Year , Mointh , Day , Hour , Min , Second ;

		time_t t = time(0) ; // get time now 
		tm* TimeNow= localtime(&t); // converting now to tm struct for UTC date/time 
		Year = TimeNow->tm_year+1900 ;
		Mointh = TimeNow->tm_mon+1 ; 
		Day = TimeNow->tm_mday ;
		Hour = TimeNow->tm_hour ;
		Min = TimeNow->tm_min ;
		Second = TimeNow->tm_sec ;

		return  to_string( Day) + "/"  +  to_string(Mointh) + "/"  + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Second); 
	}



};
