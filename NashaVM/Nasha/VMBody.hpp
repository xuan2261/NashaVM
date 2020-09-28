#pragma once
#include <msclr\marshal_cppstd.h>
#include "Stack.hpp"
#include "Globals.hpp"

using namespace std;
using namespace msclr::interop;
using namespace System;
using namespace System::IO;

public ref class VMBody
{
public:
	VMBody(msclr::gcroot<BinaryReader^> reader, msclr::gcroot<cli::array<Object^>^> parameters, GSC* gsc);
private:
	msclr::gcroot<cli::array<Object^>^>* _parameters;
	msclr::gcroot<BinaryReader^>* _reader;
	msclr::gcroot<Object^>* _return;
	msclr::gcroot<Int32^>* _flow;
	bool _isReturning;
	NStack* _stack;
	GSC* _glob;
public:
	msclr::gcroot<cli::array<Object^>^> GetParameters();
	msclr::gcroot<BinaryReader^> GetReader();
	bool IsMethodReturning();
	msclr::gcroot<Object^> GetReturnedObject();
	void SetReturnedObject(msclr::gcroot<Object^> object);
	msclr::gcroot<Int32^> GetActualFlow();
	void SetActualFlow(msclr::gcroot<Int32^> flowValue);
	NStack* GetStack();
	GSC* Global();
};