#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUserListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUser.h"


class clsManageUserMenueScreen  : protected clsScreen
{

	static int _ReadMangaeUsersMenueOpation()
	{
		int Option = 0 ; 
		cout<<"\t\t\t\tChoice From 1 To 6 : ";
		Option = clsInputValidate::ReadIntNumberBetween(1 , 6 , "\t\t\t\tVailed Number, Choese Another Option: ");
		return Option;
	}

	static void _GoToBackToManageMenue()
	{
		cout<<"\n\nprass any key to back Manage Menue....";
		system("pause>0");
		ShowMangaeUsersMenueScreen();
	}

	static void _ShowListUsersScreen()
	{
		//cout<<"List Users Will be her\n";
		clsUserListScreen::ShowUsersList();
	}

	static void _ShowAddUserScreen()
	{
		//cout<<"Add Users Will be her\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUsersScreen()
	{
		//cout<<"Delete Users Will be her\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}

	static void _ShowUpdateUsersScreen()
	{
	//	cout<<"Update Users Will be her\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen()
	{
		//cout<<"Find Users Will be her\n";
		clsFindUserScreen::ShowFindUserScreen();
	}


	enum  _enManageMenueOpation
	{
		eListUsers = 1 ,   eAddUser = 2,
		eDeleteUser = 3, eUpdataUser = 4,
		eFindUser = 5, eMainMenue = 6 
	};

	static void _PerformManageMenueOptin(_enManageMenueOpation ManageMenueOpation)
	{

		switch (ManageMenueOpation)
		{
		case clsManageUserMenueScreen::eListUsers:
			{
				system("cls");
				_ShowListUsersScreen();
				_GoToBackToManageMenue();
				break;
			}

		case clsManageUserMenueScreen::eAddUser:
			{
				system("cls");
				_ShowAddUserScreen();
				_GoToBackToManageMenue();
				break;
			}
		case clsManageUserMenueScreen::eDeleteUser:
			{
				system("cls");
				_ShowDeleteUsersScreen();
				_GoToBackToManageMenue();
				break;
			}

		case clsManageUserMenueScreen::eUpdataUser:
			{
				system("cls");
				_ShowUpdateUsersScreen();
				_GoToBackToManageMenue();
				break;
			}

		case clsManageUserMenueScreen::eFindUser:
			{
				system("cls");
				_ShowFindUsersScreen();
				_GoToBackToManageMenue();
				break;
			}

		case clsManageUserMenueScreen::eMainMenue:
			{
				/// 
			}

		
		}
	}


public:

	static void ShowMangaeUsersMenueScreen()
	{
		
		
		if(!CheckAcsessPermisionRight(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		
		system("cls");
		_DrawScreenHeader("Mangae Users Menue");
		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\tManage Menue Secren \n";
		cout<<"\t\t\t========================================================\n";
		cout<<"\t\t\t\t\t(1)- List Users. \n";
		cout<<"\t\t\t\t\t(2)- Add New User.\n";
		cout<<"\t\t\t\t\t(3)- Delete User.\n";
		cout<<"\t\t\t\t\t(4)- Update User.\n";
		cout<<"\t\t\t\t\t(5)- Find User.\n";
		cout<<"\t\t\t\t\t(6)- Main Menue.\n";
		cout<<"\n\t\t\t=========================================================\n";
	
		_PerformManageMenueOptin((_enManageMenueOpation)_ReadMangaeUsersMenueOpation());

	}

};

