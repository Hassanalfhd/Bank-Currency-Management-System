#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsFindUserScreen : protected clsScreen
{

	
	static void _PrintUserCard(clsUser Client)
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\n\t\t\t\t\tFind User Screen");

		string UserName = "" ;

		cout<<"Enter UserName : ";
		UserName = clsInputValidate::ReadStreing();


		while(!clsUser::IsUserExists(UserName))
		{
			cout<<"The User Already Exists, Please Enter Anther UserName: ";
			UserName = clsInputValidate::ReadStreing();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUserCard(User);

		
		if(!User.IsEmpty())
		{
			cout<<"\nUser Found :-)\n";
		}else
		{
			cout<<"\nUser is Not  Found :-(\n";

		}
	}



};

