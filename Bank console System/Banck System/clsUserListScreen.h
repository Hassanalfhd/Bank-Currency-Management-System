#pragma 
#include<iostream>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsUtil.h"

using namespace std;

class clsUserListScreen : protected clsScreen
{

	static void _PrintUserRecord(clsUser User)
	{

		cout<<setw(8)<<left<<""<<"| "<<left<<setw(15)<<User.UserName;
		cout<<"| "<<setw(20)<<left<<User.FullName();
		cout<<"| "<<setw(12)<<left<<User.Email;
		cout<<"| "<<setw(20)<<left<<User.Phone;
		cout<<"| "<<setw(10)<<left<<User.Password;
		cout<<"| "<<setw(12)<<left<<User.Permission;

	}

public:

	static void ShowUsersList()
	{
			vector<clsUser>vUsers = clsUser::GetUsersList();

			string Title = " User List Screen" ;
			string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vUsers.size()) + ") User(s)";
		
			_DrawScreenHeader(Title , SubTitle);
		cout<<"\n\t======================================================================================================\n";
		cout<<setw(8)<<left<<""<<"| "<<setw(12)<<left<<"UserName";
		cout<<"| "<<left<<setw(20)<<"Client Name";
		cout<<"| "<<left<<setw(12)<<"Email";
		cout<<"| "<<left<<setw(20)<<"Phone";
		cout<<"| "<<left<<setw(10)<<"Password";
		cout<<"| "<<left<<setw(13)<<"Permission";
		cout<<setw(8)<<left<<" "<<"\n\t====================================================================================================\n";


		if(vUsers.size() == 0)
			cout<<"\t\t\t\tNo User Avablie In The System!";
		else
		{
			for(clsUser &User : vUsers)
				{
		
					_PrintUserRecord(User);
		

						cout<<endl;
				}
		}


		cout<<setw(8)<<left<<" "<<"\n\t============================================================================================\n";

	}



};

