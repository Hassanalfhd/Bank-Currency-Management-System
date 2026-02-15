#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsMainMenueScreen.h"
#include"clsInputValidate.h"
#include"clsGlobal.h"



class clsLoginScreen : protected clsScreen
{

	static bool _Login()
	{

		 

		string UserName = "" ;
		string Password = "" ;

		
		bool FaildLogin = false ;
		short FaildLogCount = 0 ;
		do
		{


			if(FaildLogin)
			{
				FaildLogCount++ ;
				cout<<"\nInvaild UserName/Password";
				cout<<"\nYou have "<<(3-FaildLogCount)<<" Trial(s) To Login\n\n\n";
			}

			if(FaildLogCount == 3)
			{
				cout<<"\nYou are Locked after 3 falid Trial(s).";
				return false ;
			}


			cout<<"Enter UserName : ";
			UserName = clsInputValidate::ReadStreing();  

			cout<<"Enter Password : ";
			Password = clsInputValidate::ReadStreing();  

			 CurrntUser  = clsUser::Find(UserName , Password);

			FaildLogin  = CurrntUser.IsEmpty();


		} while ( FaildLogin);

			CurrntUser.RigsterLog();

			clsMainMenueScreen::ShowMainMenueScreen();
			
			

}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\n\t\t\t\t\tLogin Screen");

		return _Login();
	}

	
};

