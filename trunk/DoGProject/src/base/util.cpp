/*
 * util.cpp
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#include "util.h"

void debug(string s0,string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8, string s9){
	#ifdef DEBUG
	cout << s0 << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s9 << endl;
	#endif
}
