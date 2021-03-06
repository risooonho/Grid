#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "12";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2012";
	static const char UBUNTU_VERSION_STYLE[] = "12.01";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 0;
	static const long BUILD = 3;
	static const long REVISION = 17;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 8;
	#define RC_FILEVERSION 0,0,3,17
	#define RC_FILEVERSION_STRING "0, 0, 3, 17\0"
	static const char FULLVERSION_STRING[] = "0.0.3.17";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 3;
	

}
#endif //VERSION_H
