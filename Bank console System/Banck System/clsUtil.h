#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include"clsDate.h"

using namespace std;

class clsUtil
{
public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
		
	 enum enTyapOfRandom{SmallLetter = 1 ,  CapitalLetter = 2 , Digit = 3 , SpecialCharacter = 4};

	static int RandomNumber(int From , int TO){
	
		int randNum = rand() % (TO - From + 1) + From ;
	
		return randNum;

	}

	static char GetRandomCharacter(  enTyapOfRandom TyapOfRandom){

		switch (TyapOfRandom)
		{

		case enTyapOfRandom::SmallLetter:
			return (char) RandomNumber(95, 120);  
			break;
		case enTyapOfRandom::CapitalLetter:
			 return (char) RandomNumber(65, 90);  
			break;
		case enTyapOfRandom::SpecialCharacter:	
			return (char) RandomNumber(1, 47); 
		break;

		case enTyapOfRandom::Digit:	
			return (int)RandomNumber(1, 100); 
		break;

		}

	
	}

	static string GrenetWord(enTyapOfRandom CharType ,int Length ){

		string word = "";
		for (int i = 1; i <= Length; i++)
		{

			word +=  GetRandomCharacter(CharType) ;
		}
		return word ; 

	}

	static string GrentenKey(){

		string Key = "";

		Key +=  GrenetWord(enTyapOfRandom::CapitalLetter , 4) + "-";
		Key += GrenetWord(enTyapOfRandom::CapitalLetter , 4)  + "-";
		Key += GrenetWord(enTyapOfRandom::CapitalLetter , 4) + "-";
		Key += GrenetWord(enTyapOfRandom::CapitalLetter , 4) ;
	
		return Key ;

	}

	static string GrenetKey(int Length ){

	string KeyFrsit = "";
	for (int i = 0; i <Length; i++)
	{

		KeyFrsit += RandomNumber(65 , 90) ;
	}
	return KeyFrsit ; 

}

	static void ArryWithGrenetKey(string arrKey[100] , int arrLength){

		for (int i = 0; i < arrLength; i++)
				arrKey[i] = GrentenKey()  ;	

	}

	static void PrintstingGrentenKey(string arrKey[100] , int Num , int key){


	for (int i = 0; i < Num; i++)
	{

		cout<<"Array ["<<i<<"] : "<<arrKey[i]+"-"<<arrKey[i]+"-"<<arrKey[i]+"-"<<arrKey[i]+"\n";
	
	}
}
	
	static void PrintGrentenKey(int Num , int key){


	for (int i = 0; i < Num; i++)
	{

		cout<<"Key ["<<i+1<<"] "<<GrenetKey(key)<<"-"<<GrenetKey(key)<<"-"<<GrenetKey(key)<<"-"<<GrenetKey(key)<<endl;
	}
}

	
	static	void FillArryWithRandomNumbers(int arry[100] ,  int &arrLength ) 
	{

		for (int i = 0; i < arrLength; i++)
		{
			arry[i] = RandomNumber(1 , 100);
		}

	}

	static	void FillArryWithRandomWords(string arry[100] ,  int &arrLength , enTyapOfRandom CharType, short WordLength  ) 
	{

		for (int i = 0; i < arrLength; i++)
		{
			arry[i] = GrenetWord(CharType , WordLength);
		}

	}

	static	void FillArryWithRandomKeys(string arry[100] ,  int &arrLength , enTyapOfRandom CharType ) 
	{

		for (int i = 0; i < arrLength; i++)
		{
			arry[i] = GrenetKey(CharType);
		}

	}

	static	int MaxNumberInRandomArry(int arr[100] , int arrLength){

		int Max  = 0 ; 
	
		for (int i = 0; i < arrLength; i++)
		{
		

			if(arr[i] > Max)
			{
			Max = arr[i];  
			}
		
		}
		return Max ;
	}

	static	int MinNumberInRandomArry(int arr[100] , int arrLength){

		int Min  ; 
		Min = arr[0] ;
		for (int i = 0; i < arrLength; i++)
		{
		
		
			if(arr[i] < Min )
			{
			Min = arr[i];  
			}
		
		}
		return Min ;
	}

	static	void Swap(int &A , int &B){

		int Temp ;
		Temp = A ;
		A = B ;
		B = Temp ; 


	}

	static	void Swap(double &A , double &B)
	{

		double Temp ;
		Temp = A ;
		A = B ;
		B = Temp ; 

	}

	static	void Swap(bool &A , bool &B)
	{

		bool Temp ;
		Temp = A ;
		A = B ;
		B = Temp ; 

	}

	static	void Swap(string &A , string &B)
	{

		string Temp ;
		Temp = A ;
		A = B ;
		B = Temp ; 

	}

	static void ShuffleArray(int arr[100] ,  int &arrLength )
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength)-1] , arr[RandomNumber(1 , arrLength)-1]);
	
		}
	}

	static void SwapDate(clsDate &Date1 , clsDate &Date2 )
	{
		clsDate::SwapDate(Date1 , Date2);
	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 0; i < NumberOfTabs; i++)
		{
			t += "\t";

			cout<<t;

		}

		return t ;
	}



	static string NumberToText(int Number)
{

	if(Number == 0 )
	{
		return " "; 
	}

	if(Number >=1 && Number <=19)
	{
		string arr[] = {" ","One","Two","Three","Four","Five","Six","seven","Eight"
						
					,"Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
					"Sixteen","Seventeen","Eighteen","Nineteen"		
		};

		return arr[Number]+" ";
	}


	if(Number >=20 && Number <=99)
	{
		string arr[] = {
			" "," ","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
		};

		return arr[Number/10]+" "+ NumberToText(Number%10);
	}

	if(Number >=100 && Number <=199)
	{
		return "One Hundred "+NumberToText(Number%100);
	}

	if(Number >=200 && Number <=999)
	{
		return NumberToText(Number/100)+ " Hundreds "+NumberToText(Number%100);
	}

	if(Number >=1000 && Number <=1999)
	{
		return "One Thousand "+NumberToText(Number%1000);
	}

	if(Number >=2000 && Number <=999999)
	{
		return NumberToText(Number/1000)+ " Thousand "+NumberToText(Number%1000);
	}


	if(Number >=1000000 && Number <=1999999)
	{
		return "One Milion "+NumberToText(Number%100000);
	}

	if(Number >=2000000 && Number <=9999999)
	{
		return NumberToText(Number/1000000)+ " Milion "+NumberToText(Number%1000000);
	}

	if(Number >=1000000000 && Number <=1999999999)
	{
		return "One Bilion "+NumberToText(Number%1000000000);
	}


	if(Number >=2000000000 && Number <=999999999999)
	{
		return NumberToText(Number/1000000000)+ " Milion "+NumberToText(Number%1000000000);
	}
}


	 static string EncryptText( string Text , short EncrptKey = 2)
	 {

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncrptKey);


		}

		return Text ; 
	}

	 
	static string DecryptText( string Text , short EncrptKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncrptKey);


		}

		return Text ;
	}

};


