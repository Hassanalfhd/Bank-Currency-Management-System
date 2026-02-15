#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"




class clsDeleteUserScreen : protected clsScreen
{
	static void _PrintUsertCard(clsUser Client)
	{
		cout<<"\nUser Card: ";
		cout<<"\n---------------------------------";
		cout<<"\nFirstName		 :"<<Client.FirstName;
		cout<<"\nLastName		 :"<<Client.LastName;
		cout<<"\nFullName		 :"<<Client.FullName();
		cout<<"\nEnail			 :"<<Client.Email;
		cout<<"\nPhone			 :"<<Client.Phone;
		cout<<"\nPassword		 :"<<Client.Password;
		cout<<"\nPermission		 :"<<Client.Permission;
		cout<<"\n---------------------------------";

	}

public:


	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\n\t\t\t\t\tDelete User Screen");

		string UserName  = ""; 

		cout<<"\nEnter UserName : ";
		UserName = clsInputValidate::ReadStreing();

		while(!clsUser::IsUserExists(UserName))
		{
			cout<<"\nThe User Is not Exists, please Enter Another UserName : ";
			UserName = clsInputValidate::ReadStreing();

		}

		clsUser User = clsUser::Find(UserName);

		_PrintUsertCard(User);

		char Anser = 'Y' ;

		cout<<"\nAre you sure you want delete this User:[Y/N]: ";
		cin>>Anser;

		if(Anser == 'Y' || Anser == 'y')
		{

			if(User.Delete())
			{
				cout<<"\nThe User Deleted Succssfuly.";
				_PrintUsertCard(User);
			}
			else
			{
					cout<<"\nErorr User was not  Deleted :-(";

			}

		}




	}


	
};

