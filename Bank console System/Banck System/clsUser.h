#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsDate.h"
#include"clsString.h"
#include"clsPerson.h"
#include"clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{

	enum enMode{ EmptyMode = 0 , UpdateMode =1 , AddNewMode = 2};
	enMode _Mode ;

	string _UserName ; 
	string _Password ;
	int _Permission ;
	bool _MarkedForDelete ;

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string >vUserData ;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode , vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], 
			clsUtil::DecryptText(vUserData[5]),   stoi(vUserData[6]) );
	}
	
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode , "" ,"","" ,"","" ,"",0);
	}

	static string _ConverUserObjectToLine(clsUser User ,string Seperator = "#//#" )
	{

		string Line = "";

		Line +=  User.UserName + Seperator ;
		Line +=  User.FirstName + Seperator ;
		Line +=  User.LastName + Seperator ;
		Line +=  User.Email + Seperator ;
		Line +=  User.Phone + Seperator ;
		Line += clsUtil::EncryptText( User.Password )  + Seperator ;
		Line +=	 to_string( User.Permission) + Seperator ;

		return Line ;
	}
	
	static vector<clsUser>_LoadUserObjectFromFile()
	{

		vector<clsUser>vUser ;
		fstream MyFile ;

		MyFile.open("Users.txt" , ios::in);

		if(MyFile.is_open())
		{
			string Line ;


			while (getline(MyFile , Line))
			{

				clsUser User  = _ConvertLinetoUserObject(Line);

				vUser.push_back(User);
			}


			MyFile.close();
		}


		return vUser ; 
	}

	static void _SaveUserObjectsToFile(vector<clsUser>vUser)
	{

		fstream MyFile ;

		MyFile.open("Users.txt", ios::out | ios::app);

		if(MyFile.is_open())
		{
			string Line ;

			for(clsUser &User : vUser)
			{
				if (User._MarkedForDelete != true)
				{
					Line = _ConverUserObjectToLine(User);
					MyFile<<Line<<endl;
				}
			}

			MyFile.close();
		}



	}

	void _Update()
	{
		vector<clsUser>vUser = _LoadUserObjectFromFile();

		for(clsUser &User : vUser)
		{
			if(User.UserName == UserName)
			{
				User = *this;
				break;
			}

		}

		
		_SaveUserObjectsToFile(vUser);

	}

	void _AddNew()
	{
		_AddDateToFile(_ConverUserObjectToLine(*this));
	}

	void _AddDateToFile(string DateLine)
	{
	
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if(MyFile.is_open())
		{
		
			MyFile<<DateLine<<endl;

			MyFile.close();
		}


	}

	
	struct stLoginRegisterRecord ; 
	
	string _PrepareLogInRecord(string Seperator = "#//#" )
	{

		string Line = "";

		Line+= clsDate::GetSystemDateTimeString() + Seperator;

		Line += UserName + Seperator ;

		Line +=  clsUtil::EncryptText( Password )  + Seperator ;

		Line +=	 to_string(Permission) + Seperator ;

		return Line ;
	}

	 static stLoginRegisterRecord _ConvertLinetoLoginRegisterRecord(string Line, string Seperator = "#//#")
	{
		vector<string >vLoginRegisterRecord ;

		vLoginRegisterRecord = clsString::Split(Line, Seperator);

		stLoginRegisterRecord LoginRegisterRecord ; 
		
		LoginRegisterRecord.DateTime = vLoginRegisterRecord[0];
		LoginRegisterRecord.UserName = vLoginRegisterRecord[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterRecord[2]);
		LoginRegisterRecord.Permission = stoi(vLoginRegisterRecord[3]);

		return LoginRegisterRecord ;
	}
	


public:

	struct stLoginRegisterRecord
	{
		string DateTime ;
		string UserName ;
		string Password ;
		int Permission ; 
	};

	enum enPermissions
	{
		pAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, 
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64 , pLoginRegisterRecord = 128,
		pCurrencyExchange = 256 
	};

	clsUser(enMode Mode , string UserName, string FirstName, string LastName, string Email, string Phone, string Password, int  Permission)
		: clsPerson( FirstName , LastName , Email , Phone )
	{
		
		_Mode = Mode ; 
		_UserName = UserName ;
		_Password = Password ;
		_Permission = Permission;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName ;
	}

	_declspec(property(get = GetUserName , put = SetUserName))string UserName ;


	void SetPassword(string Password)
	{
		_Password = Password ;
	}


	string GetPassword()
	{
		return _Password ;
	}

	_declspec(property(get = GetPassword , put = SetPassword)) string Password ;


	void SetPermission(int Permission)
	{
		_Permission = Permission ;
	}

	int GetPermission()
	{
		return _Permission ;
	}

	_declspec(property(get = GetPermission , put = SetPermission )) int Permission ;


	static clsUser Find(string UserName)
	{
		

		fstream MyFile ;

		MyFile.open("Users.txt" , ios::in);


		if(MyFile.is_open())
		{
			string Line ;

			while (getline(MyFile , Line ))
			{
				clsUser User = _ConvertLinetoUserObject(Line);

				if(User._UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName , string Password)
	{
		vector<clsUser>vUser ; 

		fstream MyFile ;

		MyFile.open("Users.txt" , ios::in);

		string Line ;

		if(MyFile.is_open())
		{

			while (getline(MyFile , Line ))
			{
				clsUser User = _ConvertLinetoUserObject(Line);

				if(User.UserName == UserName && User.Password == Password )
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExists(string UserName)
	{

		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}

	static clsUser GetAddNewUserObject(string UserName)
	{

		return clsUser(enMode::AddNewMode , UserName , "" , "" , "" , "" , "", 0);
	}


	enum enSaveRueslt{svFaildEmptyObject = 0 , svSccsuuded = 1  , svFaildAccountNumberExists = 2};

	enSaveRueslt Save()
	{

		switch (_Mode)
		{
		case  enMode::EmptyMode:
			{
				return enSaveRueslt::svFaildEmptyObject;
				break;

			}
		case enMode::UpdateMode:
			{
				_Update();
				return enSaveRueslt::svSccsuuded;
		
					break;
			}
		case enMode::AddNewMode:
			{
				if(clsUser::IsUserExists(UserName))
				{
					return enSaveRueslt::svFaildAccountNumberExists;
				}
				else
				{
					_AddNew();
					_Mode = enMode::UpdateMode;
					return enSaveRueslt::svSccsuuded;
				}

			break;
			}
		}
	}


	bool Delete()
	{

		vector<clsUser>vUser ;

		vUser = _LoadUserObjectFromFile();

		for(clsUser &User : vUser)
		{
			if(User.UserName == _UserName)
			{
				User._MarkedForDelete = true ;
				break; 
			}

		}


		_SaveUserObjectsToFile(vUser);

		*this = _GetEmptyUserObject();

		return true ; 
	}

	static vector<clsUser>GetUsersList()
	{
		return _LoadUserObjectFromFile();
	}


	 bool ChackAccessPermision(enPermissions Permision)
	{

		if(this->Permission == enPermissions::pAll )
			return true ;

		if((Permision & this->Permission )== Permision)
			return true ;
		else
			return false ;

	}


	 void RigsterLog()
	{

		fstream MyFile ;

		MyFile.open("RigserLog.txt" , ios::out |  ios::app);

		string Line = "" ; 
		
		Line = _PrepareLogInRecord();

		if(MyFile.is_open())
		{
			MyFile<<Line<<endl;

			MyFile.close();

		}

	}

	
	 static vector<stLoginRegisterRecord>GetLogRegisterUsersList()
	 {
		
		vector<stLoginRegisterRecord>vLoginRegisterRecord;
		fstream MyFile ;

		MyFile.open("RigserLog.txt" , ios::in);

		if(MyFile.is_open())
		{
			string Line ;
			stLoginRegisterRecord LoginRegisterRecord ;

			while (getline(MyFile , Line))
			{

			 LoginRegisterRecord = _ConvertLinetoLoginRegisterRecord(Line);

			vLoginRegisterRecord.push_back(LoginRegisterRecord);
				
			}


			MyFile.close();
		}


		return vLoginRegisterRecord ; 
	 }

	
};

