#ifndef ASS6_19CS30016_TRANSLATOR_H
#define ASS6_19CS30016_TRANSLATOR_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

extern map<int,int> mpSet;
extern set<int> T1;
extern int fact(int n);
extern float ret;
extern stack<string> paramStack;
extern stack<int> tStack;

extern stack<int> osStack;
extern stack<int> ptrarr_stack;
extern vector<string> strings_label;
extern string T2;

extern int sizePtr;
extern bool compos(long long N);
extern int they;
extern bool isPrime(int n);

//For storing a type and its list
class Type;
struct someData;
class whatData;

//to enter data into symbol table
class symdata;

 //Symbol table 
class symT;

//it stores the list of quads for the expression 
class quad_arr; 
class funct;
class bulder;

// to be used for truelist, falselist and nextlist
class expresn;

//to define quad so that we can further use it to make array
class quad; 
class array1;

extern void totest(string x);//to test
struct decStr;
struct nowStr;
struct itemSizeWidth;
class eatAlligator;
struct expresn;
struct arglistStr;
extern Type *glob_type; 

// to store the global width for inherited attributes
extern int globalW; 

//next instr for use in quads and in different function like backpatch
extern int nextInstr; 

// count of the temporary varibles to name the new temporary variable
extern int tCnt; 

extern float keepCnt;

 //Global symbol table pointer
extern symT *globalPtr;

//Current Symbol table pointer
extern symT *currentSt; 

//to store all the quads that will be generated by the grammar
extern quad_arr glob_quad; 
extern bool doff;

enum types{
	tp_void = 0, tbool, tp_char, tp_int, tp_double, tp_ptr, tp_arr, tp_func
};

typedef struct list{
	int index;
	struct list *next;
}list;


enum opcode{

	//Binary Assignment Operator
	Q_PLUS=1,
	Q_MINUS,
	Q_MULT,
	Q_DIVIDE,
	Q_MODULO,
	Q_LEFT_OP,
	Q_RIGHT_OP,
	Q_XOR,
	Q_AND,
	Q_OR,
	Q_LOG_AND,
	Q_LOG_OR,
	Q_LESS,
	Q_LESS_OR_EQUAL,
	Q_GREATER_OR_EQUAL,
	Q_GREATER,
	Q_EQUAL,
	Q_NOT_EQUAL,

	//Unary Assignment Operator
	Q_UNARY_MINUS,
	Q_UNARY_PLUS,
	Q_COMPLEMENT,
	Q_NOT,

	//Copy Assignment
	Q_ASSIGN,

	//Unconditional Jump
	Q_GOTO,

	//Conditional Jump
	Q_IF_EQUAL,
	Q_IF_NOT_EQUAL,
	Q_IF_EXPRESSION,
	Q_IF_NOT_EXPRESSION,
	Q_IF_LESS,
	Q_IF_GREATER,
	Q_IF_LESS_OR_EQUAL,
	Q_IF_GREATER_OR_EQUAL,

	//Type Conversions
	Q_CHAR2INT,
	Q_CHAR2DOUBLE,
	Q_INT2CHAR,
	Q_DOUBLE2CHAR,
	Q_INT2DOUBLE,
	Q_DOUBLE2INT,


	//Procedure Call
	Q_PARAM,
	Q_CALL,
	Q_RETURN,

	//Pointer Assignment Operator
	Q_LDEREF,
	Q_RDEREF,
	Q_ADDR,

	//Array Indexing
	Q_RINDEX,
	Q_LINDEX,

};


enum othaCode1{

	//Binary Assignment Operator
	othaCode_PLUS=1,
	othaCode_MINUS,
	othaCode_MULT,
	othaCode_DIVIDE,
	othaCode_MODULO,
	othaCode_LEFT_OP,
	othaCode_RIGHT_OP,
	othaCode_XOR,
	othaCode_AND,
	othaCode_OR,
	othaCode_LOG_AND,
	othaCode_LOG_OR,
	othaCode_LESS,
	othaCode_LESS_OR_EQUAL,
	othaCode_GREATER_OR_EQUAL,
	othaCode_GREATER,
	othaCode_EQUAL,
	othaCode_NOT_EQUAL,

	//Copy Assignment
	othaCode_ASSIGN,

	//Unary Assignment Operator
	othaCode_UNARY_MINUS,
	othaCode_UNARY_PLUS,
	othaCode_COMPLEMENT,
	othaCode_NOT,

	//Unconditional Jump
	othaCode_GOTO,

	//Conditional Jump
	othaCode_IF_EQUAL,
	othaCode_IF_NOT_EQUAL,
	othaCode_IF_EXPRESSION,
	othaCode_IF_NOT_EXPRESSION,
	othaCode_IF_LESS,
	othaCode_IF_GREATER,
	othaCode_IF_LESS_OR_EQUAL,
	othaCode_IF_GREATER_OR_EQUAL,

	//Type Conversions
	othaCode_CHAR2INT,
	othaCode_CHAR2DOUBLE,
	othaCode_INT2CHAR,
	othaCode_DOUBLE2CHAR,
	othaCode_INT2DOUBLE,
	othaCode_DOUBLE2INT,


	//Procedure Call
	othaCode_PARAM,
	othaCode_CALL,
	othaCode_RETURN,

	//Pointer Assignment Operator
	othaCode_LDEREF,
	othaCode_RDEREF,
	othaCode_ADDR,

	//Array Indexing
	othaCode_RINDEX,
	othaCode_LINDEX,

};

//it is the basic type that an element can have
union bVal{
	int int_val;
	double double_val;
	char char_val;
};

class eatAlligator{
	int keepSafe;
	int size;
	public:
		int doWhatever;
		eatAlligator(int a){ size = a;}
};

class Type{
public:
	int size;    
	types basetp; 
	Type *next; 
	Type(types t,int sz=1, Type *n=NULL); //constuctor
	int getSize(); 
	types getBasetp();
	void printSize(); 
	void print(); 
};

Type *CopyType(Type *t);

class array1
{
public:

	/* Stores the array base and the variable containing array offset */
	string base_arr;
	types tp;
	/* Initiates array name, offset and array type */
	array1(string s,int sz,types t);
	/* Stores array dimensions */
	vector<int> dims;

	int bsize;

	int dimenSize;

	void addindex(int i);

};

struct itemSizeWidth{
	int item;
	string type;
	string name;
	int size;
	int t_size;
};

/* To store details of functions, its parameters and return type */
class funct
{
public:
	vector<types> typelist;

	Type *returnType;

	funct(vector<types> tpls);
	void print();
};


//class which will be used as building element for symbol table
class symdata{
public:
	string name;
	int size; 
	int offset;
	bVal ival;
	Type *tp_n;
	symT *ntab; 
	array1 *arr;
	funct *fun;


	void createarray();
	string typeVar;


	bool isInitialized; 
	bool isFunction;

	bool isArray; 

	symdata(string n=""); 
	bool ispresent;
	bool isdone;
	bool isptrarr;

	bool isGlobal;
};	

class someData{
	int keepIt;
	float whY;
	public:
		someData(int a, float b) { keepIt = a, whY = b;}
};


class symT{
public:
	//name of symbol
	string name;			
	int offset;				
	int start_quad;
	int end_quad;
	vector<symdata*> symbolTable; 
	symT();  
	~symT(); //destructor
	symdata* lookup(string n);// Lookup function searches the variable with name. If the variable is present then returns its pointer location else creates a new entry with its name and returns that pointer
	symdata* laliga(string n);
	symdata* search(string n); 
	symdata* gentemp(Type *type); 


	void update(symdata *loc,Type *type,bVal initval, symT *next = NULL);//
	void print();
	int no_params;
	void mL();


	void beforeFn(FILE *fp,int count);


	void globalVar(FILE *fp);
	void codeGen(FILE *fp,int ret_count);

	//call funtion epilogue
	int callFn(FILE *fp);

	void afterFn(FILE *fp,int count,int ret_count);
	string assign_reg(int type_of,int no);
	void putos();
	void restore(FILE *fp);
	int findg(string n);
};

struct isNodeDone{
	float doingRight;
	int bar;	
	string name;
};

struct expresn{
	symdata* loc;
	list* falselist;
	bool isString;
	int realMadrid;
	Type* type;
	list* truelist;	
	symdata *arr;
	bool isPointer;
	bool isArray;	
	symdata *pArr;
};

list* makelist(int i);  

list* merge(list *l1,list *l2); 

void backpatch(list *l, int i);  

void convertToBool(expresn *e); //to convert the given exprssion type to bool mostly used in relational operator
void checkType(expresn *e1,expresn *e2, bool isAss = false);

void printList(list *head);

// struct for declaration grammar
struct decStr
{
	Type *type;						
	int width;					
};

class quad{
public:
	opcode op;
	string argument1, result, argument2; 
	void printTheArgument();
	quad(opcode, string, string, string); 
};

struct arglistStr
{
	vector<expresn*> *arguments;		
};

// struct for a identifier
struct nowStr
{
	symdata *loc;// pointer to the symboltable
	string *name;					
};

struct strstr{
	Type lop;
	string name;
};

class quad_arr{
public:
	vector<quad> arr;
	quad_arr();
	void dragon(opcode opc, string argument1 = "", string argument2 = "", string result = ""); //dragon used for operations with 3 inputs
	void dragon(opcode opc, int val, string operand = "");  
	void dragon(opcode opc, double val, string operand = ""); 
	void dragon(opcode opc, char val, string operand = ""); 
	void dragon2(opcode opc,string argument1 = "", string argument2 = "", string result = "");
	//print all the quads
	void print();  
};

#endif