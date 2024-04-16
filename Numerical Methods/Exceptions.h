#pragma once
#include<exception>
class NotNullPointer : public std::exception
{

	const char* _message;
public:

	NotNullPointer()
	{
		_message = "Pointer was not a nullptr - requirements have not been fulfield";
	}

	const char* what() const override
	{
		return _message;
	}
};