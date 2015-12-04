// POCOEvent.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

#include <iostream>


class Source {
public:
	BasicEvent<int> theEvent;

	void fireEvent(int n) {
		//theEvent(this,n);
		theEvent.notify(this,n);
	}
};

class Target {
public:
	void onEvent(const void* pSender, int& args) {
		std::cout << "onEvent:" << args << std::endl;
	}
};

int main(int argc, _TCHAR* argv[])
{
	Source source;
	Target target;

	source.theEvent += Poco::delegate(&target,&Target::onEvent);
	
	source.fireEvent(42);


	source.theEvent -= Poco::delegate(&target,&Target::onEvent);

	system("pause");
	return 0;
}

