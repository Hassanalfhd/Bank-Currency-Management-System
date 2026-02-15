#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std; 

class clsString
{
	 string _Value ;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value ;

	}

	void SetValue(string Value)
	{
		_Value = Value ;
	}

	 string GetValue()
	{
		return _Value ;
	}

	_declspec(property(get = GetValue , put = SetValue) ) string Value;

	static short Length(string Value)
	{
		return Value.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static short CountWords(string S1)
	{
		short Count = 0;
		string delim = " ";

		short pos = 0 ;

		string sWord ; 
		while ((pos = S1.find(delim)) != std::string::npos)
		{

			sWord = S1.substr(0 , pos);

			if(sWord!=" ")
			{
				Count++;
			}
			S1.erase(0 , pos +delim.length());

		}

		if(S1 !=" ")
		{
			Count++;
		}
	
		return Count;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static string TrimLeft(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{

			if(S1[i] !=' ')
			{
				return S1.substr(i , S1.length() - i);
			}

		}
		return " ";
	}

	void TrimLeft()
	{
		_Value  =  TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (int i =S1.length()-1 ; i >=0 ; i--)
		{

			if(S1[i] !=' ')
			{
				return S1.substr(0 , i + 1);
			}

		}
		return " ";
	  
	}

	void TrimRight()
	{
		_Value =  TrimRight(_Value);
	}

  static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1)) ; 
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	////
	static vector<string> Split(string S1 , string delim)
	{
		vector<string>vString ;
	
		short pos = 0 ;

		string sWord ; 
		while ((pos = S1.find(delim)) != std::string::npos)
		{

			sWord = S1.substr(0 , pos);

			if(sWord!=" ")
			{
				vString.push_back(sWord);  
			}
			S1.erase(0 , pos +delim.length());

		}

		if(S1 != "")
		{
			vString.push_back(S1) ;
		}


		return vString;
	}
	
	vector<string> Split(string Delim)
	{
		return  Split(_Value , Delim);
	}

	static string ReversString(string S1)
{
	string S2 = "" ;
	vector<string>vString  = Split(S1 , " ");

	vector<string>::iterator vRevresString = vString.end() ;

	while(vRevresString != vString.begin())
		{

			--vRevresString ; 
			S2 += *vRevresString + " "; 
			 
	
		}

	
		return S2.substr(0 , S1.length() - 1);
}
	 
	void  ReversString()
	{
		_Value =  ReversString(_Value);
	}

	//////
	static string JoinString(vector<string>vString, string delim)
{
	string S1 ;
	 


		for (string &S2 : vString)
		{
			S1 += S2 + delim ;
		}
		
	
		return S1.substr(0 , S1.length() - delim.length());
}

	static string ReplaceWordInStringByBulitFunction(string S1 , string StringToReplace , string ReplaceTo )
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{

		S1.replace(pos , StringToReplace.length() ,ReplaceTo);

	 pos = S1.find(StringToReplace);
		
	}

	return S1;
}


	static char UpperCase(char S1)
	{

	if(S1<=12 || S1 >=96)
		return S1-32 ;
	

	}
	
	static string  UpperFirstLetterOfEachWord(string S1 )
{
	bool IsfirstLetter = true ;
	for (int i = 0; i < S1.length(); i++)
	{
		if(S1[i] != ' ' && IsfirstLetter )
		{	
			S1[i] = UpperCase(S1[i]);
		}
		IsfirstLetter = (S1[i] == ' ' ?true : false );
		
	}

	return S1 ;
}

	void  UpperFirstLetterOfEachWord()
	{
		_Value =  UpperFirstLetterOfEachWord(_Value);
	}

	static char toLower(char S1)
{

	if(S1>=120 || S1 <=65)
		return S1+32 ;
	

}

	static string  LowerFirstLetterOfEachWord(string S1 )
{
	bool IsfirstLetter = true ;
	for (int i = 0; i < S1.length(); i++)
	{
		if(S1[i] != ' ' && IsfirstLetter )
		{	
			S1[i] = tolower(S1[i]);
		}
		IsfirstLetter = (S1[i] == ' ' ?true : false );
		
	}

	return S1 ;
}

	void  LowerFirstLetterOfEachWord()
	{
		_Value =  LowerFirstLetterOfEachWord(_Value);
	}

	static string  LowerAllString(string S1 )
{
	for (int i = 0; i < S1.length(); i++)
	{
		
			S1[i] = tolower(S1[i]);
		
	}

	return S1 ;
}

	void  LowerAllString()
	{
		_Value =  LowerAllString(_Value);
	}

	static string  UpperAllString(string S1 )
{
	for (int i = 0; i < S1.length(); i++)
	{
		
			S1[i] = toupper(S1[i]);
		
	}

	return S1 ;
}

	void  UpperAllString()
	{
		_Value =  UpperAllString(_Value);
	}

	static char InvertCharCase(char C1)
{
	return 	isupper(C1)?tolower(C1) : toupper(C1);
}

	static string InvertAllStringLettersCase(string S1)
{
	
	for (int i = 0; i < S1.length(); i++)
	{

		S1[i] = InvertCharCase(S1[i]);
	}

	return S1 ;

}
	
	void  InvertAllStringLettersCase()
	{
		_Value = InvertAllStringLettersCase(_Value);
	}

	static bool IsVowels(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u') || (Ch1 == 'e'));
	

}

	short CountVowels(string S1)
{
	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		
		if(IsVowels(S1[i]))
			Count++;
	}

	return Count;
}
	
	short CountVowels()
	{
		return	CountVowels(_Value);
	}

	static string RemoverSpaicalCharInString(string S1)
{
	string S2 = "";
	for (int i = 0; i < S1.length(); i++)
	{

		if(!ispunct(S1[i]))
			S2 +=  S1[i]; 
	}

	return S2;
}

	void  RemoverSpaicalCharInString()
	{
		_Value =   RemoverSpaicalCharInString(_Value);
	}


	enum enWhatToCount{SmalLetters = 0 , CapitalLetters = 1 , All =3};

	static short CountLetters(string S1, enWhatToCount WhatToCount = All)
	{
	
		if(WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Count = 0 ;
		for (short i = 0; i < S1.length(); i++)
		{

			if(isupper(S1[i])&& WhatToCount == enWhatToCount::CapitalLetters)
				Count++;

			if(islower(S1[i])&& WhatToCount == enWhatToCount::SmalLetters)
				Count++;
		}

		return Count;
	}

	short CountLetters(enWhatToCount WhatToCount = All)
	{
		return CountLetters(_Value , WhatToCount);
	}

	static short CountCapitalLetters(string S1)
	{
	
		short Count = 0 ;
		for (short i = 0; i < S1.length(); i++)
		{

			if(isupper(S1[i]))
				Count++;
		
		}

		return Count;
	}
	 
	short CountCapitalLetters()
	 {
		 return CountCapitalLetters(_Value);
	 }

	static short CountSmalLetters(string S1)
	{
	
		short Count = 0 ;
		for (short i = 0; i < S1.length(); i++)
		{

			if(islower(S1[i]))
				Count++;
		
		}

		return Count;
	}

	short CountSmalLetters()
	 {
		 return CountSmalLetters(_Value);
	 }

};
