#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"

using namespace std;


class clsInputValidate
{
public:


	static bool IsNumberBetween(int Number, int From , int To )
	{
		if(Number >= From && Number <= To)return true ;

		return false;
	}

	static bool IsNumberBetween(short Number, short From , short To )
	{
		if(Number >= From && Number <= To)return true ;

		return false;
	}

	static bool IsNumberBetween(double Number, double From , double To )
	{
		if(Number >= From && Number <= To)return true ;

		return false;
	}

	static bool IsNumberBetween(float Number, float From , float To )
	{
		if(Number >= From && Number <= To)return true ;

		return false;
	}

	static bool IsDateBetween(clsDate Date,clsDate From , clsDate To)
	{
		if(  clsDate::IsDate1AfterDate2(Date , From) || clsDate::IsDate1EqualDate2(Date , From)
			&&
		  clsDate::IsDate1AfterDate2(Date , To) || clsDate::IsDate1EqualDate2(Date , To))
		{
			return true ;
		}


		if(  clsDate::IsDate1AfterDate2(Date , To) || clsDate::IsDate1EqualDate2(Date , To)
			&&
		  clsDate::IsDate1AfterDate2(Date , From) || clsDate::IsDate1EqualDate2(Date , From))
		{
			return true ;
		}


		return false ;

	}

	static int ReadInteNumber(string ErrorMessag = "Invalid Number, Enter again\n")
	{
		int Number ; 
		while (!(cin>>Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<ErrorMessag<<endl;
		}

		return Number;
	}
	
	static double ReadDbleNumber(string ErrorMessag = "Invalid Number, Enter again\n")
	{
		double Number ; 
		while (!(cin>>Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<ErrorMessag<<endl;
		}

		return Number;
	}

	static double ReadDbleNumberBetween(double From , double To , string Messag)
	{
		double Number ;

		cin>>Number;

		while (!(IsNumberBetween(Number , From , To)))
		{
			cout<<Messag;
			Number = ReadDbleNumber() ;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From , int To , string Messag)
	{
		int Number ;

		cin>>Number;

		while (!(IsNumberBetween(Number , From , To)))
		{
			cout<<Messag;
			Number = ReadInteNumber();
		}
		return Number;
	}

	static float ReadFloateNumber(string ErrorMessag = "Invalid Number, Enter again\n")
	{
		float Number ; 

		while (!(cin>>Number))
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout<<ErrorMessag<<endl;
			cin>>Number;
		
		}

		return Number;
	}

	static bool IsValidaDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadStreing()
	{
		string S1;
		getline(cin>>ws,S1);
		
		return S1 ; 
	}


};
