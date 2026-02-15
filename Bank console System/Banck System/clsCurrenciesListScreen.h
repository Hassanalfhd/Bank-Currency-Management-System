#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"


class clsCurrenciesListScreen : protected clsScreen
{
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{

		cout<<setw(8)<<left<<""<<"| "<<left<<setw(30)<<Currency.Country();
		cout<<"| "<<setw(17)<<left<<Currency.CurrencyCode();
		cout<<"| "<<setw(30)<<left<<Currency.CurrencyName();
		cout<<"| "<<setw(20)<<left<<Currency.Rate();

	}


public:

	static void ShowCurrenciesListScreen()
	{
			
		system("cls");
		vector<clsCurrency> vCurrenciesData = clsCurrency::GetCurrencyList();
	
		string Title = " Currencies List  Screen" ;
		string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vCurrenciesData.size()) + ") Currency";	
			_DrawScreenHeader(Title , SubTitle);

					cout<<"\n\t======================================================================================================\n";
		cout<<setw(8)<<left<<"|"<<left<<setw(30)<<"Country";
		cout<<"| "<<left<<setw(15)<<"Curreny Code";
		cout<<"| "<<left<<setw(30)<<"Currency Name";
		cout<<"| "<<left<<setw(30)<<"Rate ($1) = ";
		cout<<setw(8)<<left<<" "<<"\n\t====================================================================================================\n";


		if(vCurrenciesData.size() == 0)
		cout<<"\t\t\t\tNo Currency Avablie In The System!";
		else
		{

			for(clsCurrency &Currency :vCurrenciesData)
			{
				_PrintCurrencyRecord(Currency);
				cout<<endl;
			}

		}

		
		cout<<setw(8)<<left<<" "<<"\n\t============================================================================================\n";

	}

	
};

