/* $Id: global.h,v 1.1 2008/01/25 11:47:49 ruthe Exp $ */
#include "misc.h"
#include <R.h>

#ifndef GLOBAL_H
#define GLOBAL_H

extern bool debug;
extern bool trace;
extern bool verbose;
extern bool quiet;
extern bool adaptive;

#ifdef _MSC_VER // VisualStudio
	using namespace std;
	#define LOG(a) {if(debug) cout << a << endl;}
	#define LOGQ(a) {if(quiet) cout << a << endl;}
	#define LOGIF(a,b) {if(debug && (a)) cout << b << endl;}
	#define FLOG(a) {}
#else
	#include <Rcpp.h> 
	#define LOG(a) {if(debug) Rcpp::Rcout << a << endl;}
	#define LOGQ(a) {if(quiet) Rcpp::Rcout << a << endl;}
	#define LOGIF(a,b) {if(debug && (a)) Rcpp::Rcout << b << endl;}
	#define FLOG(a) {}
#endif

#define TRACE(a) {}//if(trace)cerr << a << endl;}

#ifdef TO_FILE
	using namespace std;
	#define LOG(a) {}
	#define LOGIF(a,b) {}
	#include <fstream>
	#include <sstream>
	#define FLOG(a) {if(debug)fout << a << endl;}
#endif

bool parse_arguments(int argc,char** argv);

const char* program_name();

int options();
const char* option(int idx);

int parameters();
const char* parameter(int idx);
	 
bool has_option(const char* opt);
int int_option(const char* opt,int def=0);
double double_option(const char* opt,double def=0);
const char* string_option(const char* opt,const char* def="");

#endif
