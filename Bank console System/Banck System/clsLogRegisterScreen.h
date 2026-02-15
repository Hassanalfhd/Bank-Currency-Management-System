#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"



class clsLogRegisterScreen : clsScreen
{

	static void _PrintUserRecord(clsUser::stLoginRegisterRecord LogRegisterUsers)
	{

		cout<<setw(8)<<left<<""<<"| "<<left<<setw(20)<<LogRegisterUsers.DateTime;
		cout<<"| "<<setw(17)<<left<<LogRegisterUsers.UserName;
		cout<<"| "<<setw(17)<<left<<LogRegisterUsers.Password;
		cout<<"| "<<setw(20)<<left<<LogRegisterUsers.Permission;

	}

public:

	static void ShowLogRegisterList()
	{


		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pLoginRegisterRecord))
		{
			return;
		}

			vector<clsUser::stLoginRegisterRecord>vLogRegisterUsers  = clsUser::GetLogRegisterUsersList() ;

			string Title = " Log Register  Screen" ;
			string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vLogRegisterUsers.size()) + ") Record(s)";
		
			_DrawScreenHeader(Title , SubTitle);
		cout<<"\n\t======================================================================================================\n";
		cout<<setw(8)<<left<<""<<"| "<<setw(20)<<left<<"Date Time";
		cout<<"| "<<left<<setw(15)<<"UserName";
		cout<<"| "<<left<<setw(15)<<"Password";
		cout<<"| "<<left<<setw(30)<<"Permission";
		cout<<setw(8)<<left<<" "<<"\n\t====================================================================================================\n";


		if(vLogRegisterUsers.size() == 0)
			cout<<"\t\t\t\tNo Log Register Avablie In The System!";
		else
		{
			for(clsUser::stLoginRegisterRecord  &LoginRegisterRecord :vLogRegisterUsers)
				{
		
					_PrintUserRecord(LoginRegisterRecord);
						cout<<endl;
				}
		}


		cout<<setw(8)<<left<<" "<<"\n\t============================================================================================\n";

	}

};

