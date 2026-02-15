#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
#include"clsDate.h"
#include"clsPerson.h"
#include"clsUser.h"

using namespace std;

class clsBankClient : public clsPerson
{
	enum enMode{ EmptyMode = 0 , UpdateMode =1 , AddNewMode = 2};
	enMode _Mode ;

	string _AccountNumber ;
	string _PinCode ;
	float _AccountBalance ;
	bool _MarkedForDelete ;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string >vClientData ;

		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode , vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],vClientData[5],   stof(vClientData[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient vClientData ,string Seperator = "#//#" )
	{

		string Line = "";

		Line +=  vClientData.AccountNumber() + Seperator ;
		Line +=  vClientData.FirstName + Seperator ;
		Line +=  vClientData.LastName + Seperator ;
		Line +=  vClientData.Email + Seperator ;
		Line +=  vClientData.Phone + Seperator ;
		Line +=  vClientData.PinCode + Seperator ;
		Line +=	 to_string( vClientData.AccountBalance) + Seperator ;

		return Line ;
	}
	
	static vector<clsBankClient>_LoadClietnObjectFromFile()
	{

		vector<clsBankClient>vClient ;
		fstream MyFile ;

		MyFile.open("Clients.txt" , ios::in);

		if(MyFile.is_open())
		{
			string Line ;


			while (getline(MyFile , Line))
			{

			clsBankClient Client  = _ConvertLinetoClientObject(Line);

			vClient.push_back(Client);
			}


			MyFile.close();
		}


		return vClient ; 
	}

	static void _SaveCilensObjectsToFile(vector<clsBankClient>vClinet)
	{

		fstream MyFile ;

		MyFile.open("Clients.txt", ios::out);

		if(MyFile.is_open())
		{
			string Line ;

			for(clsBankClient &C : vClinet)
			{
				if (C._MarkedForDelete != true)
				{
					Line = _ConverClientObjectToLine(C);
					MyFile<<Line<<endl;
				}
			}

			MyFile.close();
		}



	}

	void _Update()
	{

		vector<clsBankClient>_vClient  = _LoadClietnObjectFromFile();

		for(clsBankClient &C : _vClient)
		{
			if(C.AccountNumber() == AccountNumber())
			{
				C = *this ;
				break ;
			}

			
		}

			_SaveCilensObjectsToFile(_vClient);

	}

	void _AddNew()
	{
		_AddDateToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDateToFile(string DateLine)
	{
	
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if(MyFile.is_open())
		{
		
			MyFile<<DateLine<<endl;

			MyFile.close();
		}


	}


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode , "" ,"","" ,"","" ,"",0);
	}

	
	string _PepareTransferLogInRecord(float Amount , clsBankClient &DestiantionClient , string UserName, string Seperator = "#//#" )
	{

		string Line = "";

		Line+= clsDate::GetSystemDateTimeString() + Seperator;

		Line += AccountNumber() + Seperator ;
		Line += DestiantionClient.AccountNumber() + Seperator ;
		Line += to_string(Amount) + Seperator ;
		Line += to_string(AccountBalance) + Seperator ;
		Line += to_string(DestiantionClient.AccountBalance) + Seperator ;
		Line +=  UserName + Seperator ;


		return Line ;
	}

	struct stRegisterTransferLog;

	 void _RegisterTransferLog(float Amount , clsBankClient &DestiantionClient , string UserName)
	  {
		  fstream MyFile;

		  MyFile.open("TransferLog.txt" , ios::out | ios::app);
			  string Line = ""; 
			  Line = _PepareTransferLogInRecord(Amount , DestiantionClient , UserName);

		  if(MyFile.is_open())
		  {

			 
				  MyFile<<Line<<endl;
				  MyFile.close();
		  }


	  }

	  static stRegisterTransferLog  _ConvertLinetoRegisterTransferLog(string Line, string Seperator = "#//#")
	  {
		  vector<string> vRegisterTransferLog ;
	  
			vRegisterTransferLog = clsString::Split(Line , Seperator); 
	  
			stRegisterTransferLog RegisterTransferLog ;

			RegisterTransferLog.Date = vRegisterTransferLog[0];
			RegisterTransferLog.SourceAccountNumber = vRegisterTransferLog[1];
			RegisterTransferLog.DestiantionAccountNumber = vRegisterTransferLog[2];
			RegisterTransferLog.Amount = stof(vRegisterTransferLog[3]);
			RegisterTransferLog.SourceAccountBalance = stof(vRegisterTransferLog[4]);
			RegisterTransferLog.DestiantionAccountBalance = stof(vRegisterTransferLog[5]);
			RegisterTransferLog.UserName = vRegisterTransferLog[6];

			return RegisterTransferLog;
	  }



public:

	struct stRegisterTransferLog
	{
		string Date ;
		string SourceAccountNumber ;
		string DestiantionAccountNumber ;
		float Amount ;
		float SourceAccountBalance ;
		float DestiantionAccountBalance ;
		string UserName ; 

	};


	clsBankClient(enMode Mode , string AccountNumber, string FirstName, string LastName, string Email, string Phone, string PinCode, float AcconutBalance)
		: clsPerson( FirstName , LastName , Email , Phone )
	{
		
		_Mode = Mode ; 
		_AccountNumber = AccountNumber ;
		_PinCode = PinCode ;
		_AccountBalance = AcconutBalance;

	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber ;
	}


	void SetPinCode(string PinCode)
	{
		_PinCode  = PinCode ;
	}

	string GetPinCode()
	{
		return _PinCode ;
	}

	_declspec(property(get = GetPinCode , put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance ;

	}

	float GetAccountBalance()
	{
		return _AccountBalance ;
	}

	_declspec(property(get = GetAccountBalance , put = SetAccountBalance)) float AccountBalance;
	
	/*
	void Print()
	{
		cout<<"\nClient Card: ";
		cout<<"\n---------------------------------";
		cout<<"\nAccountNumber		 :"<<_AccountNumber;
		cout<<"\nFirstName		 :"<<FirstName;
		cout<<"\nLastName		 :"<<LastName;
		cout<<"\nFullName		 :"<<FullName();
		cout<<"\nEnail			 :"<<Email;
		cout<<"\nPhone			 :"<<Phone;
		cout<<"\nPinCode			 :"<<_PinCode;
		cout<<"\nAccountBalacne		 :"<<_AccountBalance;
		cout<<"\n---------------------------------";

	}
	*/
	

	static clsBankClient Find(string AccountNumber)
	{

		vector<clsBankClient>vClients;

		fstream Myfile;

		Myfile.open("Clients.txt" , ios::in);

		if(Myfile.is_open())
		{
			string Line ;

			while (getline(Myfile , Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line) ;

				if(Client.AccountNumber() == AccountNumber)
				{
					Myfile.close();
					return Client;
				}

				vClients.push_back(Client);
			}
		
			Myfile.close();
		}

		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{

		vector<clsBankClient>vClients;

		fstream Myfile;

		Myfile.open("Clients.txt" , ios::in);

		if(Myfile.is_open())
		{
			string Line ;

			while (getline(Myfile , Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line) ;

				if(Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					Myfile.close();
					return Client;
				}

				vClients.push_back(Client);
			}
		
			Myfile.close();
		}

		return _GetEmptyClientObject();

	}

	static bool IsClientExists(string AccountNumber )
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNubmer)
	{

		return clsBankClient(enMode::AddNewMode , AccountNubmer , "" , "" , "" , "" , "", 0);
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
				if(clsBankClient::IsClientExists(_AccountNumber))
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
			
		vector<clsBankClient>vClients = _LoadClietnObjectFromFile() ;

		for(clsBankClient &C :vClients)
		{
			if(C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true ;
				break;
			}

		}


		_SaveCilensObjectsToFile(vClients);

		*this = _GetEmptyClientObject();


		return true ; 
	}


	static vector<clsBankClient>GetClientList()
	{
		return _LoadClietnObjectFromFile();
	}


	static double GetToatleBalance()
	{

		vector<clsBankClient>vClient = _LoadClietnObjectFromFile();
		double ToatleBalance  = 0;

		for(clsBankClient&C : vClient)
		{
			ToatleBalance += C.AccountBalance;

		}


		return ToatleBalance ; 
	}

	  void Deposit(double amount)
	{

		_AccountBalance += amount ;
		Save();
	}

	  bool Withdraw(double amount)
	  {

		  if(amount > _AccountBalance)
		  {
			  return false ;
		  }else
		  {
			  _AccountBalance -= amount ; 

			Save();
		  }

		    return true ;
	  }


	

	  

	   bool Transfer(float Amount , clsBankClient &DestiantionClient,  string UserName)
	  {
		  if(Amount > AccountBalance)
			  return false ; 

		  Withdraw(Amount);

		  DestiantionClient.Deposit(Amount);

		  _RegisterTransferLog(Amount , DestiantionClient, UserName);

		  return true ; 
	  }

	   static vector<stRegisterTransferLog>GetRegisterTransferLog()
	   {
		   vector<stRegisterTransferLog> vRegisterTransferLog;

		   fstream MyFile ;

		   MyFile.open("TransferLog.txt" , ios::in);
		   
		   if(MyFile.is_open())
		   {
			      string Line  ;

		   stRegisterTransferLog RegisterTransferLog ;

				  while (getline(MyFile , Line))
				  {
					  
					  RegisterTransferLog = _ConvertLinetoRegisterTransferLog(Line);
					  vRegisterTransferLog.push_back(RegisterTransferLog);
				  }

				  MyFile.close();
		   }

				
			return vRegisterTransferLog ; 

			
	   }



};

