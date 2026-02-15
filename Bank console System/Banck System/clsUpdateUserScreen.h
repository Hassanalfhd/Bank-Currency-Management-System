#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"


class clsUpdateUserScreen : protected clsScreen
{
	
	static void _ReadUsertInfo(clsUser &User)
	{
		
	
		cout<<"\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadStreing();

		cout<<"\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadStreing();

		cout<<"\nEnter Email: ";
		User.Email = clsInputValidate::ReadStreing();


		cout<<"\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadStreing();

		cout<<"\nEnter Password:";
		User.Password = clsInputValidate::ReadStreing();
	
		cout<<"\nEnter Permission:";
		User.Permission = _ReadPermissionInfo();

	
	}

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

	static int _ReadPermissionInfo()
	{
		char Choies ;
		int Permissions = 0;
	
		cout<<"\nAre Want Give Full Accsess? [Y/N]: ";
		cin>>Choies;
		if(Choies == 'Y' || Choies == 'y')
		{
			return -1 ;
		}
	
	
		cout<<"\nDo you want to give access to : \n";

		cout<<"\nClient List?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pListClient;
	
	
		cout<<"\nAdd New Client?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pAddNewClient;

		cout<<"\nDelete Client[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pDeleteClient;
	
	
		cout<<"\nUpdate Client?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pUpdateClient;
	
	
		cout<<"\nFind Cilent?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pFindClient;

		cout<<"\nTransactions?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pTransactions;


		cout<<"\nManage Users?[Y/N]: ";
		cin>>Choies;
		if(Choies == 'y' || Choies== 'Y')
		Permissions += clsUser::enPermissions::pManageUsers;

		return Permissions;


	}

public:

	static void ShowUpdateUserScreen()
	{

		_DrawScreenHeader("\n\t\t\t\t\tUpdate User Screen");

				string UserName = "" ;

		cout<<"Enter UserName : ";
		UserName = clsInputValidate::ReadStreing();

		while(!clsUser::IsUserExists(UserName))
		{
			cout<<"The User Is Not  Exists, Please Enter Anther UserName: ";
			UserName = clsInputValidate::ReadStreing();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUserCard(User);

		char Anser = 'Y' ;

		cout<<"\nAre you sure you want Update this User:[Y/N]: ";
		cin>>Anser;

		if(Anser == 'Y' || Anser == 'y')
		{
			
			cout<<"\nUpdate info: ";
			cout<<"\n----------------------------\n";
	
			_ReadUsertInfo(User);

			clsUser::enSaveRueslt SaveRueslt ; 
	
			SaveRueslt = User.Save();

		
			switch (SaveRueslt)
			{
				case clsUser::svSccsuuded:
					{
						cout<<"\nAccount Updated Successfully :-)\n";
	
						_PrintUserCard(User);
							break;
					}

					case clsUser::svFaildEmptyObject  :
					{
					cout<<"\nError account was not saved because it's Empty\n";

						break;
					}


				}

			}
		}


		

};

