#pragma once
#include<iostream>
#include<string>
#include"clsUser.h"
#include"clsGlobal.h"
#include"clsDate.h"

using namespace std;
class clsScreen
{
public:

	static void _DrawScreenHeader(string Title , string SubTitle = "")
	{
		cout<<"\n\t\t\t---------------------------------------------------------";
		cout<<"\n\t\t\t\t\t  "<<Title;

		if(SubTitle != "")
		{
		cout<<"\t\t\t\t\t  "<<SubTitle;
		}


		cout<<"\n\t\t\t---------------------------------------------------------";
		string UserName = CurrntUser.UserName ;

		//clsDate Date =  clsDate::GetSystemDate();
		cout<<"\n\t\t\tUser: "<<CurrntUser.UserName ;

		cout<<"\n\t\t\tDate: "<<clsDate::DateToString(clsDate()) <<"\n";

	}
	

	static bool CheckAcsessPermisionRight(clsUser::enPermissions Permision )
	{

		if(!CurrntUser.ChackAccessPermision(Permision) )
		{

			cout<<"\t\t\t========================================================\n";
			cout<<"\t\t\t\t\tAccess Denied! Contact your Access admin \n";
			cout<<"\t\t\t========================================================\n";
			return false ;
		}
		else
		{
			return true ;
		}
		
	}


};


