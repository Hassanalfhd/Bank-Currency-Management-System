#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"

using namespace std; 


class clsCurrency
{
	enum enMode{ EmptyMode = 0 , UpdateMode =1 };

	enMode _Mode;

	string _Country ;
	string _CurrencyCode ;
	string _CurrencyName ;
	float _Rate ;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line , string Spreter)
	{
		vector<string> vCurrencyData = clsString::Split(Line , Spreter);

		return clsCurrency(enMode::UpdateMode ,vCurrencyData[0] ,vCurrencyData[1] , vCurrencyData[2], stof(vCurrencyData[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency , string Spreter)
	{
		string Line  = "";

		Line += Currency.Country() + Spreter ;
		Line += Currency.CurrencyCode() + Spreter ;
		Line += Currency.CurrencyName() + Spreter ;
		Line += to_string(Currency.Rate()) ;

		return Line ;
	}

	static vector<clsCurrency>_LoadCurrencyObjectFromFile()
	{
		vector<clsCurrency>vCurrency ;
		fstream MyFile ;

		MyFile.open("Currencies.txt", ios::in );

		if(MyFile.is_open())
		{
			string Line = "" ;

			while (getline(MyFile , Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line , "#//#"); 
					
				vCurrency.push_back(Currency);
			}

			MyFile.close();
		}


		return vCurrency ;
	}


	static void SavCurrencyObiectToFile(vector<clsCurrency>vCurrencyDate)
	{
		fstream MyFile ;

		MyFile.open("Currencies.txt" , ios::out );

		if(MyFile.is_open())
		{
			string Line ; 

			for(clsCurrency &Currency :vCurrencyDate)
			{
				Line = _ConvertCurrencyObjectToLine(Currency , "#//#") ;
				
				MyFile<<Line<<endl;
			}


			MyFile.close();
		}



	}

	void _Update()
	{
		vector<clsCurrency>vCurrency  = _LoadCurrencyObjectFromFile();

		for(clsCurrency &C : vCurrency)
		{
			if(C.CurrencyCode() == CurrencyCode())
			{
				C = *this ;
				break ;
			}


		}

		SavCurrencyObiectToFile(vCurrency);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode , "" ,"","",0);
	}


public:

	
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode ;
		_Country = Country ;
		_CurrencyCode = CurrencyCode ;
		_CurrencyName  = CurrencyName;
		_Rate = Rate ; 
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country ;
	}

	string CurrencyCode()
	{
		return _CurrencyCode ;
	}

	string CurrencyName()
	{
		return _CurrencyName ;
	}

	void UpdateRaet(float Rate)
	{

		_Rate = Rate ;
		_Update();
	}

	float Rate()
	{
		return _Rate ;
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		vector<clsCurrency>vCurrency ;
		fstream MyFile ;

		MyFile.open("Currencies.txt", ios::in );

		if(MyFile.is_open())
		{
			string Line = "" ;

			while (getline(MyFile , Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line , "#//#"); 
					
				if(clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}


			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		vector<clsCurrency>vCurrency ;
		fstream MyFile ;

		MyFile.open("Currencies.txt", ios::in );

		if(MyFile.is_open())
		{
			string Line = "" ;

			while (getline(MyFile , Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line , "#//#"); 
					
				if(clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}


			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}


	static bool IsExistByCountry(string CountryName)
	{
		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

		return (!Currency.IsEmpty());
	}


	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencyObjectFromFile();
	}

	 float ConvertToUSD(float Amount)
	{
		return (float) Amount  / Rate(); 
	}

	

	 float ConvertFromCurrencyToCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountRate = ConvertToUSD(Amount) ;

		if(Currency2.CurrencyCode() == "USD")
		{
			return AmountRate ;
		}

		float AmountCurrency2 = (AmountRate * Currency2.Rate());
		return  AmountCurrency2; 
		
	}


};

