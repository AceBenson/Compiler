/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define T_INT 1
	#define T_CHAR 2
	#define T_FLOAT 3
	#define T_STRING 4
	#define T_FUNCTION 4
	#define GLOBAL_MODE 1
	#define LOCAL_MODE 2
	#define ARGUMENT_MODE 3
	int yylex();
	extern int errline;
	int type=0;
	int c_type;
	int offset=0;
	typedef struct symbol {
  		char *name;
  		int scope;
		int type;
		int id;
		int totalArgs;
		char* funcName;
		int mode;
		int offset;
		struct symbol *next;
	} symbol;
	void codegen();
	void handleParams(char*);
	void funcBegin(char*);
	void funcEnd(char*);
	void callFunc(char*, int);
	symbol* put(char*);
	symbol* get(char*);
	symbol* lookup(char*);
	int check(char*);
	void printTable();
	void popScope(int);
	symbol* install(char*);
	
	symbol* table = (symbol*)0;
	int numOfSymbols = 0;
	int cur_scope=0;
	int argc=0;
	FILE *fptr;
#line 49 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int ival;
	double dval;
	char cval;
	char* sval;
	/*Constant val;*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 82 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFIER 257
#define FCONSTANT 258
#define CONSTANT 259
#define CCONSTANT 260
#define STRING_LITERAL 261
#define SIZEOF 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define TYPEDEF 278
#define EXTERN 279
#define STATIC 280
#define AUTO 281
#define REGISTER 282
#define CHAR 283
#define SHORT 284
#define INT 285
#define LONG 286
#define SIGNED 287
#define UNSIGNED 288
#define FLOAT 289
#define DOUBLE 290
#define CONST 291
#define VOID 292
#define STRUCT 293
#define UNION 294
#define ENUM 295
#define ELLIPSIS 296
#define CASE 297
#define DEFAULT 298
#define IF 299
#define ELSE 300
#define SWITCH 301
#define WHILE 302
#define DO 303
#define FOR 304
#define GOTO 305
#define CONTINUE 306
#define BREAK 307
#define RETURN 308
#define FUNCTION 309
#define SCSPEC 310
#define TYPESPEC 311
#define TYPEMOD 312
#define ASSIGN 313
#define ARITHCOMPARE 314
#define LSHIFT 315
#define RSHIFT 316
#define UNARY 317
#define HYPERUNARY 318
#define POINTSAT 319
#define THEN 320
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   44,   44,   45,   43,   46,   43,   47,   43,
   48,   43,   39,   39,   49,   50,   23,   51,   52,   23,
   24,   24,   24,   24,   21,   21,   21,   21,   21,   21,
   28,   28,   28,   53,   25,   54,   25,   55,   25,   27,
   27,   27,   27,   26,   26,   26,   26,   20,   20,   30,
   30,   31,   31,   31,   34,   34,   34,   34,   34,   34,
   34,   34,   34,   32,   32,   33,   33,   33,   57,    1,
   58,   56,   56,   35,   38,   38,   38,   40,   40,   41,
   41,   42,   42,   36,   36,   36,   37,   37,   19,   19,
   18,   18,   29,   29,   29,   29,   29,   29,   17,   17,
   16,   16,   15,   15,   14,   14,   13,   13,   12,   12,
   11,   11,   11,   10,   10,   10,   10,   10,    9,    9,
    9,    8,    8,    8,    7,    7,    7,    7,    6,    6,
    5,    5,    5,    5,    4,    4,    4,    4,    4,    4,
    3,    3,    3,    3,    3,    3,    3,   22,   22,    2,
    2,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    0,    4,    0,    5,    0,    3,
    0,    4,    1,    2,    0,    0,    4,    0,    0,    5,
    1,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    3,    4,    3,    0,    6,    0,    4,    0,    6,    5,
    7,    6,    7,    2,    2,    2,    3,    1,    2,    2,
    3,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    3,    0,    3,
    0,    4,    2,    1,    1,    3,    4,    1,    3,    1,
    3,    2,    1,    1,    3,    4,    1,    3,    1,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    5,
    1,    3,    1,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    3,    1,    3,    3,    3,    3,    1,    3,
    3,    3,    3,    1,    3,    3,    3,    1,    1,    4,
    1,    2,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    4,    3,    4,    2,    2,    1,    3,    3,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   69,   56,   57,   58,   59,   62,   63,   60,   61,    0,
   55,    0,    0,    4,    0,    0,    3,    1,    0,   54,
    2,   13,    0,    0,    0,    0,   50,    0,    0,    0,
   64,    0,    0,   53,    0,   70,   67,   14,    0,    0,
   10,   75,    0,    0,    0,   51,    0,    0,    0,   73,
    0,   12,   16,    0,   76,    0,    6,   65,  154,  153,
  151,  152,  155,    0,    0,  142,  135,  137,  138,  136,
    0,    0,  139,  140,  141,    0,    0,    0,  128,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   91,
   84,   68,  129,    0,    0,    0,    0,   80,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   48,   89,    0,   26,   21,   25,    0,    0,   30,   29,
   28,   22,    8,    0,  132,  133,   87,    0,    0,    0,
  146,  147,    0,    0,  134,   94,   95,   96,   97,   98,
   93,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   77,   82,   72,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0,   44,   45,   46,    0,   49,    0,
   23,   24,    0,   36,    0,   85,  150,    0,  144,  148,
    0,    0,   92,  125,  126,  127,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   79,   81,   31,    0,   33,    0,    0,    0,
    0,    0,   47,   90,   20,    0,   86,   88,  130,    0,
  145,  143,    0,   32,   34,   38,    0,    0,    0,   37,
  149,  100,    0,    0,   40,    0,    0,    0,   35,   39,
    0,   42,    0,   41,   43,
};
static const YYINT yydgoto[] = {                         12,
   13,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   90,  112,  113,  114,
  115,  191,  116,  117,  118,  119,  120,  121,  142,   14,
   23,   30,   31,   16,   32,   92,  128,   33,   24,   96,
   97,   98,   17,   18,   45,   56,   25,   39,   53,   99,
   54,  183,  243,  226,  244,   36,   19,   51,
};
static const YYINT yysindex[] = {                       234,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  720,
    0,  234,  720,    0,  -37,  720,    0,    0,   -6,    0,
    0,    0,  -37,  720,  -79,    0,    0,  -39,  720,   -3,
    0,   39,   49,    0,   93,    0,    0,    0,  -79,    0,
    0,    0,  101,  720,  -79,    0,  -38,   31,  438,    0,
  720,    0,    0,   73,    0,  -79,    0,    0,    0,    0,
    0,    0,    0,  455,  455,    0,    0,    0,    0,    0,
   31,  141,    0,    0,    0,  -16,  438,   25,    0,  116,
   80, -216,   -5,  -92,  106,   56,   51, -119,  -59,    0,
    0,    0,    0,   87,  -39,  144,  138,    0,   64,  137,
  438,  142,  161,  162,  168,   88,  170,  153,  156,  373,
    0,    0,   28,    0,    0,    0,   73,  -83,    0,    0,
    0,    0,    0,  438,    0,    0,    0,  -36,    1,  182,
    0,    0,  401,  438,    0,    0,    0,    0,    0,    0,
    0,  438,  438,  438,  438,  438,  438,  438,  438,  438,
  438,  438,  438,  438,  438,  438,  438,  438,  438,  438,
  438,    0,    0,    0,  318,    0,   88,  171,   88,  438,
  438,  438,  -70,  414,    0,    0,    0,   58,    0,  438,
    0,    0,  115,    0,  -22,    0,    0,  438,    0,    0,
   47,  -25,    0,    0,    0,    0,  116,  116,   80,   80,
 -216, -216, -216, -216,   -5,   -5,  -92,  106,   56,   51,
 -119,   -4,    0,    0,    0,   88,    0,   66,  120,  121,
  203,  414,    0,    0,    0,  -79,    0,    0,    0,  438,
    0,    0,  438,    0,    0,    0,   88,  438,  427,    0,
    0,    0,  -79,  -79,    0,  126,   88,  128,    0,    0,
  187,    0,   88,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  149,    0,    0,   40,    0,    0,    0,    0,
    0,    0,    0,  159,    0,   68,    0,    0,   26,    0,
    0,   65,  107,    0,  781,    0,    0,    0,    0,  -33,
    0,    0,    0,  163,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  500,    0,  690,    0,  662,
  791,  907,   97, 1126,  -27, 1194,  -11, 1240,   78,    0,
    0,    0,    0,    0,  132,    0,  208,    0,    0,  528,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  160,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  768,  778,  819,  860,
  930,  958, 1056, 1079,  491, 1124, 1150, 1152, 1196, 1220,
 1247,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   36,    0,    0,    0, 1231,  -49,   41,   45,   54,   43,
  140,  136,  155,  157,  154,    0,  -24,  415, 1097, -161,
  858,    0,  -10,    0,    0,    0,    0,    0,    0,  461,
   27,    0,  268,  248,   10,  -65,    0,    0,  296,    0,
    0,  173,    0,  323,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1519
static const YYINT yytable[] = {                         18,
   28,   28,   28,  161,   18,  127,   18,  185,   18,   18,
   74,   18,  222,  107,   41,   67,  107,   72,  180,   70,
   68,   27,   69,  133,   94,   18,   15,  135,   52,  103,
  107,  107,  103,   35,   57,  107,   20,   43,   15,  180,
   47,  187,   34,   40,  180,  123,  103,  103,  148,  149,
   29,  103,   27,  233,  153,   46,  152,   27,   37,   27,
  239,   27,   27,   74,   27,  107,  107,  232,   67,   67,
   72,  180,   70,   68,  134,   69,  168,   95,   27,   52,
   52,  103,   37,   52,   67,  141,  179,  231,  186,   18,
  230,   15,   18,  194,  195,  196,  107,  107,   52,   48,
   71,  180,  227,   73,  163,   74,  235,   69,   66,  180,
   67,   75,   72,  103,   70,   68,  223,   69,   99,  228,
   74,   99,  146,   66,  147,   67,   75,   72,   75,   70,
   68,  111,   69,   50,  111,   99,   99,  111,  229,   49,
  111,   55,   27,  156,   27,   27,  111,   74,    5,  157,
   74,  159,  145,   71,  111,  111,   73,  143,   75,  111,
  236,  237,  144,  180,  180,   74,  251,   74,  253,  180,
   99,  180,   83,   74,  158,   83,  154,  155,   67,  162,
   72,  165,   70,   68,  164,   69,  197,  198,  166,  111,
  111,   95,  199,  200,  167,   40,  205,  206,   73,  169,
  170,  171,   99,  201,  202,  203,  204,  172,  242,  174,
   40,  175,  160,   73,  176,  240,  184,   42,   26,   26,
  111,  111,  188,   18,   18,   18,   18,   18,  216,   18,
   18,  221,  249,  250,   59,   60,   61,   62,   63,  225,
   64,   65,  238,  107,  107,  254,  131,  132,   78,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,  103,
  103,  150,  151,   18,   18,   18,   73,   18,   18,   18,
   18,    9,   18,   18,   18,   18,   27,   27,   27,   27,
   27,   11,   27,   27,   19,    7,   66,   59,   60,   61,
   62,   63,  208,   64,   65,  207,   52,  136,  137,  138,
  139,  140,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   27,  209,  211,   58,  210,   27,   27,   27,  130,
   27,   27,   27,   27,   44,   27,   27,   27,   27,  100,
   60,   61,   62,   63,   21,   64,   65,  214,    0,   66,
    0,    0,    0,    0,  100,   60,   61,   62,   63,    0,
   64,   65,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,  111,  111,  111,  111,  101,
  102,  103,    0,  104,  105,  106,  107,    0,  108,  109,
  110,   66,    0,    0,  101,  102,  103,    0,  104,  105,
  106,  107,    0,  108,  109,  110,   66,   59,   60,   61,
   62,   63,    0,   64,   65,   74,    0,    0,    0,    0,
   67,    0,   72,    0,   70,   68,    0,   69,    0,    0,
    0,    0,    0,    2,    3,    4,    5,    6,    7,    8,
    9,  177,   11,   74,    0,    0,    0,    0,   67,    0,
   72,  189,   70,   68,    0,   69,   74,    0,    0,   66,
    0,   67,    0,   72,    0,   70,   68,    0,   69,   74,
    0,    0,   91,    0,   67,    0,   72,  247,   70,   68,
   74,   69,  111,   22,    0,   67,    0,   72,    0,   70,
   68,    0,   69,    0,   38,   91,    0,   74,    0,   22,
    1,    0,   67,    0,  124,    0,   70,   68,   73,   69,
    0,    0,    0,    0,   38,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  122,    0,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   73,    0,  112,    0,
    0,  112,    0,    0,  112,    0,  131,  131,    0,   73,
  131,  131,  131,  131,  131,    0,  131,  190,  112,  112,
    0,    0,   73,  112,    0,    0,  193,  131,  131,  131,
  131,  131,  131,   73,  154,  154,    0,  154,    0,  154,
  154,  154,  154,    0,  154,    0,    0,  182,    0,    0,
   73,    0,    0,  112,  112,    0,  154,  154,  154,  154,
  154,    0,  131,  131,  224,    0,    0,    0,    0,   91,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
    0,    0,    0,  213,  112,  112,    0,    0,  154,    0,
    0,  154,    0,  131,  131,    0,    0,    0,    0,   59,
   60,   61,   62,   63,    0,   64,   65,    0,    0,    0,
    0,    0,    0,    0,  241,    0,    0,    0,    0,    0,
    0,  154,    0,    0,    0,    0,    0,   59,   60,   61,
   62,   63,    0,   64,   65,    0,    0,    0,    0,    0,
   59,   60,   61,   62,   63,    0,   64,   65,    0,    0,
    0,   66,    0,   59,   60,   61,   62,   63,    0,   64,
   65,    0,    0,    0,   59,   60,   61,   62,   63,  124,
   64,   65,  124,    0,  124,  124,  124,    0,    0,   66,
    0,   59,   60,   61,   62,   63,    0,   64,   65,  124,
  124,  124,   66,  124,  124,    0,  129,  129,    0,    0,
  129,  129,  129,  129,  129,   66,  129,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,  129,  129,  129,
    0,  129,  129,    0,  124,  124,    0,    0,    0,  112,
  112,  112,  112,   66,  131,  131,  131,  131,  131,  131,
  131,  131,  131,  131,  131,  131,  131,    0,    0,    0,
    0,    0,  129,  129,    0,  124,  124,    0,    0,    0,
  154,  154,  154,  154,  154,  154,  154,  154,  154,  154,
  154,  154,  154,  154,  154,  122,    0,    0,  122,    0,
  122,  122,  122,  129,  129,  123,    0,    0,  123,    0,
  123,  123,  123,    0,    0,  122,  122,  122,  119,  122,
  122,  119,    0,    0,  119,  123,  123,  123,    0,  123,
  123,    0,    0,    0,    0,    0,    0,    0,  119,  119,
  119,    0,  119,  119,    0,    0,  120,    0,    0,  120,
  122,  122,  120,    0,    0,    0,    0,    0,    0,    0,
  123,  123,    0,    0,    0,    0,  120,  120,  120,    0,
  120,  120,    0,  119,  119,    0,    0,    0,    0,    0,
    0,  122,  122,    0,    0,    0,    0,  121,    0,    0,
  121,  123,  123,  121,    0,    0,    0,    0,    0,    0,
    0,  120,  120,    0,  119,  119,    0,  121,  121,  121,
    0,  121,  121,    0,    0,    0,  124,  124,  124,  124,
  124,  124,  124,  124,    0,    0,    0,    0,    0,    0,
    0,    0,  120,  120,  114,    0,    0,  114,    0,    0,
  114,    0,  121,  121,  129,  129,  129,  129,  129,  129,
  129,  129,    0,  173,  114,  114,  114,  117,  114,  114,
  117,    0,    0,  117,  181,    0,    0,    0,    0,    0,
    0,    0,    0,  121,  121,    0,    0,  117,  117,  117,
    0,  117,  117,    0,    0,  118,    0,    0,  118,  114,
  114,  118,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,    0,    0,    0,  118,  118,  118,    0,  118,
  118,    0,  117,  117,  215,    0,  217,    0,    0,    0,
  114,  114,  122,  122,  122,  122,  122,  122,  122,  122,
    0,    0,  123,  123,  123,  123,  123,  123,  123,  123,
  118,  118,    0,  117,  117,  119,  119,  119,  119,  119,
  119,  119,  119,   71,   71,   71,   71,   71,   71,   71,
   71,   71,   71,  234,    0,    0,    0,    0,    0,    0,
    0,  118,  118,  120,  120,  120,  120,  120,  120,  120,
  120,    0,    0,  116,  245,    0,  116,    0,    0,  116,
    0,    0,    0,    0,  252,    0,    0,    0,    0,    0,
  255,    0,    0,  116,  116,  116,  115,  116,  116,  115,
    0,    0,  115,    0,  121,  121,  121,  121,  121,  121,
  121,  121,    0,    0,    0,    0,  115,  115,  115,    0,
  115,  115,    0,    0,    0,    0,    0,    0,  116,  116,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  113,    0,  109,  113,    0,  109,  113,  129,  109,
    0,  115,  115,  114,  114,  114,  114,  114,  114,  116,
  116,  113,  113,  109,  109,    0,  113,  110,  109,    0,
  110,    0,  108,  110,    0,  108,  117,  117,  117,  117,
  117,  117,  115,  115,    0,    0,  178,  110,  110,  108,
  108,    0,  110,    0,  108,    0,  113,  113,  109,  109,
  129,    0,    0,    0,  118,  118,  118,  118,  118,  118,
  192,    0,    0,    0,  105,    0,  106,  105,    0,  106,
    0,    0,  110,  110,  108,  108,    0,  113,  113,  109,
  109,  105,  105,  106,  106,    0,  105,  212,  106,    0,
  104,    0,    0,  104,    0,    0,  218,  219,  220,    0,
    0,    0,    0,  110,  110,  108,  108,  104,  104,   93,
  101,    0,  104,  101,    0,    0,  105,  102,  106,    0,
  102,    0,    0,    0,  125,  126,    0,  101,  101,    0,
    0,    0,  101,    0,  102,  102,    0,   93,    0,  102,
    0,    0,  104,    0,    0,    0,    0,  105,  105,  106,
  106,    0,  116,  116,  116,  116,  116,  116,    0,    0,
    0,   93,  101,    0,  246,  248,    0,    0,    0,  102,
    0,    0,    0,    0,  104,  115,  115,  115,  115,  115,
  115,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  101,    0,    0,    0,    0,    0,
    0,  102,    0,   93,   93,   93,   93,   93,   93,   93,
   93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
   93,    0,  113,  113,  113,  113,  109,  109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   93,    0,
  110,  110,  108,  108,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   93,  105,  105,  106,  106,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  104,  104,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  101,    0,    0,    0,    0,    0,    0,  102,
};
static const YYINT yycheck[] = {                         33,
   40,   40,   40,   63,   38,   71,   40,   44,   42,   43,
   33,   45,  174,   41,   25,   38,   44,   40,   44,   42,
   43,   59,   45,   40,   49,   59,    0,   77,   39,   41,
   58,   59,   44,   40,   45,   63,   10,   28,   12,   44,
   44,   41,   16,  123,   44,   56,   58,   59,  265,  266,
   15,   63,   33,   58,   60,   59,   62,   38,   23,   40,
  222,   42,   43,   33,   45,   93,   94,   93,   38,   44,
   40,   44,   42,   43,   91,   45,  101,   51,   59,   40,
   41,   93,   47,   44,   59,   61,   59,   41,  125,  123,
   44,  125,  126,  143,  144,  145,  124,  125,   59,   61,
  123,   44,  125,  126,   95,   33,   41,   40,   44,   44,
   38,   44,   40,  125,   42,   43,   59,   45,   41,  185,
   33,   44,   43,   59,   45,   38,   59,   40,   61,   42,
   43,   59,   45,   41,   38,   58,   59,   41,  188,   91,
   44,   41,  123,   38,  125,  126,   59,   41,  123,   94,
   44,  271,   37,  123,   58,   59,  126,   42,   91,   63,
   41,   41,   47,   44,   44,   59,   41,   61,   41,   44,
   93,   44,   41,   33,  124,   44,  269,  270,   38,   93,
   40,   44,   42,   43,   41,   45,  146,  147,  125,   93,
   94,  165,  148,  149,   58,  123,  154,  155,  126,   58,
   40,   40,  125,  150,  151,  152,  153,   40,  233,   40,
  123,   59,  272,  126,   59,  226,  300,  257,  257,  257,
  124,  125,   41,  257,  258,  259,  260,  261,   58,  263,
  264,  302,  243,  244,  257,  258,  259,  260,  261,  125,
  263,  264,   40,  271,  272,   59,  263,  264,   41,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  271,
  272,  267,  268,  297,  298,  299,  126,  301,  302,  303,
  304,  123,  306,  307,  308,  309,  257,  258,  259,  260,
  261,  123,  263,  264,  125,  123,  309,  257,  258,  259,
  260,  261,  157,  263,  264,  156,  257,  273,  274,  275,
  276,  277,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  158,  160,   47,  159,  297,  298,  299,   72,
  301,  302,  303,  304,   29,  306,  307,  308,  309,  257,
  258,  259,  260,  261,   12,  263,  264,  165,   -1,  309,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
  263,  264,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  269,  270,  271,  272,  297,
  298,  299,   -1,  301,  302,  303,  304,   -1,  306,  307,
  308,  309,   -1,   -1,  297,  298,  299,   -1,  301,  302,
  303,  304,   -1,  306,  307,  308,  309,  257,  258,  259,
  260,  261,   -1,  263,  264,   33,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   59,  292,   33,   -1,   -1,   -1,   -1,   38,   -1,
   40,   41,   42,   43,   -1,   45,   33,   -1,   -1,  309,
   -1,   38,   -1,   40,   -1,   42,   43,   -1,   45,   33,
   -1,   -1,   48,   -1,   38,   -1,   40,   41,   42,   43,
   33,   45,   59,   13,   -1,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   24,   71,   -1,   33,   -1,   29,
  257,   -1,   38,   -1,   40,   -1,   42,   43,  126,   45,
   -1,   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   54,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  126,   -1,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,   37,   38,   -1,  126,
   41,   42,   43,   44,   45,   -1,   47,  133,   58,   59,
   -1,   -1,  126,   63,   -1,   -1,  142,   58,   59,   60,
   61,   62,   63,  126,   37,   38,   -1,   40,   -1,   42,
   43,   44,   45,   -1,   47,   -1,   -1,  117,   -1,   -1,
  126,   -1,   -1,   93,   94,   -1,   59,   60,   61,   62,
   63,   -1,   93,   94,  180,   -1,   -1,   -1,   -1,  185,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  292,
   -1,   -1,   -1,  296,  124,  125,   -1,   -1,   91,   -1,
   -1,   94,   -1,  124,  125,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  230,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,
   -1,  309,   -1,  257,  258,  259,  260,  261,   -1,  263,
  264,   -1,   -1,   -1,  257,  258,  259,  260,  261,   38,
  263,  264,   41,   -1,   43,   44,   45,   -1,   -1,  309,
   -1,  257,  258,  259,  260,  261,   -1,  263,  264,   58,
   59,   60,  309,   62,   63,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   44,   45,  309,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  309,   58,   59,   60,
   -1,   62,   63,   -1,   93,   94,   -1,   -1,   -1,  269,
  270,  271,  272,  309,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,   -1,   -1,   -1,
   -1,   -1,   93,   94,   -1,  124,  125,   -1,   -1,   -1,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,  275,  276,  277,   38,   -1,   -1,   41,   -1,
   43,   44,   45,  124,  125,   38,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   -1,   58,   59,   60,   38,   62,
   63,   41,   -1,   -1,   44,   58,   59,   60,   -1,   62,
   63,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   59,
   60,   -1,   62,   63,   -1,   -1,   38,   -1,   -1,   41,
   93,   94,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   94,   -1,   -1,   -1,   -1,   58,   59,   60,   -1,
   62,   63,   -1,   93,   94,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,  124,  125,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   94,   -1,  124,  125,   -1,   58,   59,   60,
   -1,   62,   63,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,  125,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,   93,   94,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  106,   58,   59,   60,   38,   62,   63,
   41,   -1,   -1,   44,  117,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,   -1,   -1,   58,   59,   60,
   -1,   62,   63,   -1,   -1,   38,   -1,   -1,   41,   93,
   94,   44,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,   -1,   -1,   -1,   58,   59,   60,   -1,   62,
   63,   -1,   93,   94,  167,   -1,  169,   -1,   -1,   -1,
  124,  125,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,   -1,  265,  266,  267,  268,  269,  270,  271,  272,
   93,   94,   -1,  124,  125,  265,  266,  267,  268,  269,
  270,  271,  272,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  216,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,   -1,   38,  237,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,  247,   -1,   -1,   -1,   -1,   -1,
  253,   -1,   -1,   58,   59,   60,   38,   62,   63,   41,
   -1,   -1,   44,   -1,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   58,   59,   60,   -1,
   62,   63,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   38,   41,   -1,   41,   44,   72,   44,
   -1,   93,   94,  267,  268,  269,  270,  271,  272,  124,
  125,   58,   59,   58,   59,   -1,   63,   38,   63,   -1,
   41,   -1,   41,   44,   -1,   44,  267,  268,  269,  270,
  271,  272,  124,  125,   -1,   -1,  110,   58,   59,   58,
   59,   -1,   63,   -1,   63,   -1,   93,   94,   93,   94,
  124,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
  134,   -1,   -1,   -1,   41,   -1,   41,   44,   -1,   44,
   -1,   -1,   93,   94,   93,   94,   -1,  124,  125,  124,
  125,   58,   59,   58,   59,   -1,   63,  161,   63,   -1,
   41,   -1,   -1,   44,   -1,   -1,  170,  171,  172,   -1,
   -1,   -1,   -1,  124,  125,  124,  125,   58,   59,   49,
   41,   -1,   63,   44,   -1,   -1,   93,   41,   93,   -1,
   44,   -1,   -1,   -1,   64,   65,   -1,   58,   59,   -1,
   -1,   -1,   63,   -1,   58,   59,   -1,   77,   -1,   63,
   -1,   -1,   93,   -1,   -1,   -1,   -1,  124,  125,  124,
  125,   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,
   -1,  101,   93,   -1,  238,  239,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,  125,  267,  268,  269,  270,  271,
  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,  143,  144,  145,  146,  147,  148,  149,
  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
  160,   -1,  269,  270,  271,  272,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  188,   -1,
  271,  272,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  233,  271,  272,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,  272,
};
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 320
#define YYUNDFTOKEN 381
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,
0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER",
"FCONSTANT","CONSTANT","CCONSTANT","STRING_LITERAL","SIZEOF","INC_OP","DEC_OP",
"LEFT_OP","RIGHT_OP","LE_OP","GE_OP","EQ_OP","NE_OP","AND_OP","OR_OP",
"MUL_ASSIGN","DIV_ASSIGN","MOD_ASSIGN","ADD_ASSIGN","SUB_ASSIGN","TYPEDEF",
"EXTERN","STATIC","AUTO","REGISTER","CHAR","SHORT","INT","LONG","SIGNED",
"UNSIGNED","FLOAT","DOUBLE","CONST","VOID","STRUCT","UNION","ENUM","ELLIPSIS",
"CASE","DEFAULT","IF","ELSE","SWITCH","WHILE","DO","FOR","GOTO","CONTINUE",
"BREAK","RETURN","FUNCTION","SCSPEC","TYPESPEC","TYPEMOD","ASSIGN",
"ARITHCOMPARE","LSHIFT","RSHIFT","UNARY","HYPERUNARY","POINTSAT","THEN",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : exts",
"exts : ext",
"exts : exts ext",
"ext : function_definition",
"ext : declaration",
"$$1 :",
"function_definition : declaration_specifiers func_definitor $$1 compound_statement",
"$$2 :",
"function_definition : declaration_specifiers func_definitor declaration_list $$2 compound_statement",
"$$3 :",
"function_definition : func_definitor $$3 compound_statement",
"$$4 :",
"function_definition : func_definitor declaration_list $$4 compound_statement",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"$$5 :",
"$$6 :",
"compound_statement : '{' $$5 $$6 '}'",
"$$7 :",
"$$8 :",
"compound_statement : '{' $$7 compound_list $$8 '}'",
"compound_list : statement",
"compound_list : declaration",
"compound_list : compound_list statement",
"compound_list : compound_list declaration",
"statement : compound_statement",
"statement : expression_statement",
"statement : selection_statement",
"statement : labeled_statement",
"statement : iteration_statement",
"statement : jump_statement",
"labeled_statement : IDENTIFIER ':' statement",
"labeled_statement : CASE conditional_expression ':' statement",
"labeled_statement : DEFAULT ':' statement",
"$$9 :",
"selection_statement : IF '(' expression ')' $$9 compound_statement",
"$$10 :",
"selection_statement : selection_statement ELSE $$10 compound_statement",
"$$11 :",
"selection_statement : SWITCH '(' expression ')' $$11 compound_statement",
"iteration_statement : WHILE '(' expression ')' statement",
"iteration_statement : DO statement WHILE '(' expression ')' ';'",
"iteration_statement : FOR '(' expression_statement expression_statement ')' statement",
"iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement",
"jump_statement : CONTINUE ';'",
"jump_statement : BREAK ';'",
"jump_statement : RETURN ';'",
"jump_statement : RETURN expression ';'",
"expression_statement : ';'",
"expression_statement : expression ';'",
"declaration : declaration_specifiers ';'",
"declaration : declaration_specifiers init_declarator_list ';'",
"declaration_specifiers : type_specifier",
"declaration_specifiers : type_specifier declaration_specifiers",
"declaration_specifiers : CONST declaration_specifiers",
"type_specifier : VOID",
"type_specifier : CHAR",
"type_specifier : SHORT",
"type_specifier : INT",
"type_specifier : LONG",
"type_specifier : FLOAT",
"type_specifier : DOUBLE",
"type_specifier : SIGNED",
"type_specifier : UNSIGNED",
"init_declarator_list : init_declarator",
"init_declarator_list : init_declarator_list ',' init_declarator",
"init_declarator : declarator",
"init_declarator : func_definitor",
"init_declarator : declarator '=' initializer",
"$$12 :",
"func_definitor : IDENTIFIER $$12 func_param_list",
"$$13 :",
"func_param_list : '(' $$13 parameter_type_list ')'",
"func_param_list : '(' ')'",
"declarator : direct_declarator",
"direct_declarator : IDENTIFIER",
"direct_declarator : '(' declarator ')'",
"direct_declarator : direct_declarator '[' conditional_expression ']'",
"parameter_type_list : parameter_list",
"parameter_type_list : parameter_list ',' ELLIPSIS",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers declarator",
"parameter_declaration : declaration_specifiers",
"initializer : assignment_expression",
"initializer : '{' initializer_list '}'",
"initializer : '{' initializer_list ',' '}'",
"initializer_list : initializer",
"initializer_list : initializer_list ',' initializer",
"expression : assignment_expression",
"expression : expression ',' assignment_expression",
"assignment_expression : conditional_expression",
"assignment_expression : unary_expression assignment_operator assignment_expression",
"assignment_operator : '='",
"assignment_operator : MUL_ASSIGN",
"assignment_operator : DIV_ASSIGN",
"assignment_operator : MOD_ASSIGN",
"assignment_operator : ADD_ASSIGN",
"assignment_operator : SUB_ASSIGN",
"conditional_expression : logical_or_expression",
"conditional_expression : logical_or_expression '?' expression ':' conditional_expression",
"logical_or_expression : logical_and_expression",
"logical_or_expression : logical_or_expression OR_OP logical_and_expression",
"logical_and_expression : inclusive_or_expression",
"logical_and_expression : logical_and_expression AND_OP inclusive_or_expression",
"inclusive_or_expression : exclusive_or_expression",
"inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression",
"exclusive_or_expression : and_expression",
"exclusive_or_expression : exclusive_or_expression '^' and_expression",
"and_expression : equality_expression",
"and_expression : and_expression '&' equality_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression EQ_OP relational_expression",
"equality_expression : equality_expression NE_OP relational_expression",
"relational_expression : shift_expression",
"relational_expression : relational_expression '<' shift_expression",
"relational_expression : relational_expression '>' shift_expression",
"relational_expression : relational_expression LE_OP shift_expression",
"relational_expression : relational_expression GE_OP shift_expression",
"shift_expression : additive_expression",
"shift_expression : shift_expression LEFT_OP additive_expression",
"shift_expression : shift_expression RIGHT_OP additive_expression",
"additive_expression : additive_expression '+' multiplicative_expression",
"additive_expression : additive_expression '-' multiplicative_expression",
"additive_expression : multiplicative_expression",
"multiplicative_expression : multiplicative_expression '*' cast_expression",
"multiplicative_expression : multiplicative_expression '/' cast_expression",
"multiplicative_expression : multiplicative_expression '%' cast_expression",
"multiplicative_expression : cast_expression",
"cast_expression : unary_expression",
"cast_expression : '(' type_specifier ')' cast_expression",
"unary_expression : postfix_expression",
"unary_expression : INC_OP unary_expression",
"unary_expression : DEC_OP unary_expression",
"unary_expression : unary_operator cast_expression",
"unary_operator : '&'",
"unary_operator : '*'",
"unary_operator : '+'",
"unary_operator : '-'",
"unary_operator : '~'",
"unary_operator : '!'",
"postfix_expression : primary_expression",
"postfix_expression : FUNCTION",
"postfix_expression : postfix_expression '[' expression ']'",
"postfix_expression : postfix_expression '(' ')'",
"postfix_expression : postfix_expression '(' argument_expression_list ')'",
"postfix_expression : postfix_expression INC_OP",
"postfix_expression : postfix_expression DEC_OP",
"argument_expression_list : assignment_expression",
"argument_expression_list : argument_expression_list ',' assignment_expression",
"primary_expression : '(' expression ')'",
"primary_expression : CONSTANT",
"primary_expression : CCONSTANT",
"primary_expression : FCONSTANT",
"primary_expression : IDENTIFIER",
"primary_expression : STRING_LITERAL",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 555 "parser.y"

void codeGen() {
}

void handleParams(char* name) {
	symbol* s = lookup(name);
	s->type = T_FUNCTION;
	char* fname = strdup(name);
	int totalArgs = s->totalArgs = numOfSymbols-s->id-1;
	int i;
	int index=s->id;
	for (i=totalArgs, s=table; i>0&&s!=NULL; i--, s=s->next) {
		s->scope = cur_scope;
		s->offset = i;
		s->mode = ARGUMENT_MODE;
		s->funcName = fname;
	}
	//printTable();
}

void funcBegin(char* name) {
	fprintf(fptr, "%s:\n", name);
	fprintf(fptr, "\tsw fp, -4(sp)\n");
	fprintf(fptr, "\tsw ra, -8(sp)\n");
	fprintf(fptr, "\taddi sp, sp, -8\n");
	fprintf(fptr, "\n");
}

void funcEnd(char* name) {
	fprintf(fptr, "\tlw ra, -4(fp)\n");
	fprintf(fptr, "\tlw fp, 0(fp)\n");	
	fprintf(fptr, "\taddi sp, sp, 8\n");
	fprintf(fptr, "\tjalr zero, 0(ra)\n");
	offset = 0;
}

void callFunc(char* name, int cnt) {
	//printf("%s's argc: %d", name, cnt);
	int i;
	for(i=0; i<cnt; i++) {
		fprintf(fptr, "\tlw a%d, 0(sp)\n", i);
		fprintf(fptr, "\taddi sp, sp, 4\n");
	}
	fprintf(fptr, "\tsw ra, -4(sp)\n");
	fprintf(fptr, "\taddi sp, sp, -4\n");
	fprintf(fptr, "\tjal ra, %s\n", name);
	fprintf(fptr, "\tlw ra, 0(sp)\n");
	fprintf(fptr, "\taddi sp, sp, 4\n");
	fprintf(fptr, "\n");
	argc=0;
}

symbol* put(char *name) {
  symbol *ptr;
  ptr = (symbol*)malloc(sizeof(symbol));
  ptr->name = strdup(name);
  ptr->next = (symbol*)table;
  table = ptr;
  return ptr;
}
symbol* get(char *name) {
	symbol *ptr;
	for (ptr=table; ptr!=(symbol *)0; ptr = (symbol *)ptr->next) {
    	if (strcmp(ptr->name, name) == 0)
      		return ptr;
  	}
	return 0;
}

symbol* lookup(char* name) {
	if(check(name)) {
		symbol* s;
		s = get(name);
		printf("lookup: %s\n", name);
		return s;
	}
	else {
    	printf("%s is not defined\n", name);
		return NULL;
	}
}

void popScope(int scope) {
	symbol* pre;
	symbol* s = table;
	while(s!=NULL) {
		if(s==table&&s->scope==scope) {
			symbol* tmp = s->next;
			free(s);
			s = tmp;
			table = s;
			numOfSymbols--;
		}
		else if(s->scope==scope) {
			symbol* tmp = s->next;
			pre->next = tmp;
			free(s);
			s = tmp;
			numOfSymbols--;
		}
		else {
			pre = s;
			s = s->next;
		}
	}
}

symbol* install(char *name) {  
	symbol* s;
   	s = get(name);
   	if(s == 0 || s->scope!=cur_scope) {
		printf("install %s\n", name);
    	s = put(name);
		s->scope = cur_scope;
		s->id = numOfSymbols;
		numOfSymbols++;
		if(cur_scope!=0) {
			offset++;
			s->offset = offset;
			s->mode = LOCAL_MODE;
		}
		return s;
	}
   	else if(s->type==T_FUNCTION) {
		s->id = numOfSymbols;
		numOfSymbols++;
		//printf("%s is already defined\n", name);
   		return s;
	}
	else {
		printf("%s is already defined\n", name);
	}
}

int check(char *name) { 
	if(get(name) == 0 && strcmp(name, "digitalWrite")==1 && strcmp(name, "delay")==1) {
    	printf("%s is an undeclared identifier\n", name);
		return 0;
	}
	return 1;
}

void printTable() {
	printf("Table:\n");
	symbol* s = table;
	while(s!=NULL) {
		printf("symbol: scope=%d, name=%s, type=%d, id=%d, mode=%d, offset=%d func=%s\n", s->scope, s->name, s->type, s->id, s->mode, s->offset, s->funcName);
		s = s->next;
	}
}

int main()
{
	fptr = fopen("codegen.S", "w+");
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	printf("YACC> Error at line %d.\n", errline);
	return 0;
}
#line 1012 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 103 "parser.y"
	{ }
break;
case 2:
#line 104 "parser.y"
	{ }
break;
case 3:
#line 107 "parser.y"
	{ }
break;
case 4:
#line 108 "parser.y"
	{ }
break;
case 5:
#line 111 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[0].sval);
		funcBegin(yystack.l_mark[0].sval);
	}
break;
case 6:
#line 115 "parser.y"
	{
		funcEnd(yystack.l_mark[-2].sval);
	}
break;
case 7:
#line 118 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[-1].sval);
		funcBegin(yystack.l_mark[-1].sval);
	}
break;
case 8:
#line 122 "parser.y"
	{
		funcEnd(yystack.l_mark[-3].sval);
	}
break;
case 9:
#line 125 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[0].sval);
		funcBegin(yystack.l_mark[0].sval);
	}
break;
case 10:
#line 129 "parser.y"
	{
		funcEnd(yystack.l_mark[-2].sval);
	}
break;
case 11:
#line 132 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[-1].sval);
		funcBegin(yystack.l_mark[-1].sval);
	}
break;
case 12:
#line 136 "parser.y"
	{
		funcEnd(yystack.l_mark[-3].sval);
	}
break;
case 13:
#line 141 "parser.y"
	{ }
break;
case 14:
#line 142 "parser.y"
	{ }
break;
case 15:
#line 145 "parser.y"
	{ /*setLocalVars();*/ }
break;
case 16:
#line 145 "parser.y"
	{ popScope(cur_scope); cur_scope--; }
break;
case 17:
#line 145 "parser.y"
	{}
break;
case 18:
#line 146 "parser.y"
	{ /*setLocalVars();*/ }
break;
case 19:
#line 146 "parser.y"
	{ popScope(cur_scope); cur_scope--; }
break;
case 20:
#line 146 "parser.y"
	{}
break;
case 21:
#line 149 "parser.y"
	{ }
break;
case 22:
#line 150 "parser.y"
	{ }
break;
case 23:
#line 151 "parser.y"
	{ }
break;
case 24:
#line 152 "parser.y"
	{ }
break;
case 25:
#line 155 "parser.y"
	{ }
break;
case 26:
#line 156 "parser.y"
	{ }
break;
case 27:
#line 157 "parser.y"
	{ }
break;
case 28:
#line 158 "parser.y"
	{ }
break;
case 29:
#line 159 "parser.y"
	{ }
break;
case 30:
#line 160 "parser.y"
	{ }
break;
case 31:
#line 163 "parser.y"
	{ }
break;
case 32:
#line 164 "parser.y"
	{ }
break;
case 33:
#line 165 "parser.y"
	{ }
break;
case 34:
#line 168 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tli t1, 0\n");
		fprintf(fptr, "\tbeq t0 t1, Else\n");
		cur_scope++; 
	}
break;
case 35:
#line 174 "parser.y"
	{ 
		fprintf(fptr, "\tj Exit\n");
	}
break;
case 36:
#line 177 "parser.y"
	{ 
		fprintf(fptr, "Else: ");
		cur_scope++; 
	}
break;
case 37:
#line 180 "parser.y"
	{ 
		fprintf(fptr, "Exit :");
	}
break;
case 38:
#line 183 "parser.y"
	{ cur_scope++; }
break;
case 39:
#line 183 "parser.y"
	{ }
break;
case 40:
#line 186 "parser.y"
	{ }
break;
case 41:
#line 187 "parser.y"
	{ }
break;
case 42:
#line 188 "parser.y"
	{ }
break;
case 43:
#line 189 "parser.y"
	{ }
break;
case 44:
#line 192 "parser.y"
	{ }
break;
case 45:
#line 193 "parser.y"
	{ }
break;
case 46:
#line 194 "parser.y"
	{ }
break;
case 47:
#line 195 "parser.y"
	{ }
break;
case 48:
#line 198 "parser.y"
	{ }
break;
case 49:
#line 199 "parser.y"
	{ }
break;
case 50:
#line 203 "parser.y"
	{ 
		switch(type) { 
			case 0: break;
			case 1: break;
			case 2: break;
			case 3: break;
		}
		type=0;
	}
break;
case 51:
#line 213 "parser.y"
	{ 
		switch(type) {
			case 0: break;
			case 1: break;
			case 2: break;
			case T_FUNCTION: fprintf(fptr, ".global %s\n", yystack.l_mark[-1].sval); break;		
		}
		type=0;
	}
break;
case 52:
#line 224 "parser.y"
	{ }
break;
case 53:
#line 225 "parser.y"
	{ }
break;
case 54:
#line 226 "parser.y"
	{ }
break;
case 55:
#line 229 "parser.y"
	{ yyval.sval="void"; 	}
break;
case 56:
#line 230 "parser.y"
	{ yyval.sval="char"; 	}
break;
case 57:
#line 231 "parser.y"
	{ yyval.sval="short"; 	}
break;
case 58:
#line 232 "parser.y"
	{ yyval.sval="int"; 	}
break;
case 59:
#line 233 "parser.y"
	{ yyval.sval="long"; 	}
break;
case 60:
#line 234 "parser.y"
	{ yyval.sval="float"; 	}
break;
case 61:
#line 235 "parser.y"
	{ yyval.sval="double"; 	}
break;
case 62:
#line 236 "parser.y"
	{ yyval.sval="signed"; 	}
break;
case 63:
#line 237 "parser.y"
	{ yyval.sval="unsigned";}
break;
case 64:
#line 240 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 65:
#line 241 "parser.y"
	{ }
break;
case 66:
#line 244 "parser.y"
	{ }
break;
case 67:
#line 245 "parser.y"
	{ type=T_FUNCTION; yyval.sval=yystack.l_mark[0].sval; }
break;
case 68:
#line 246 "parser.y"
	{ 
		symbol* id = lookup(yystack.l_mark[-2].sval);
		fprintf(fptr, "\tsw  t0, %d(fp) \n", id->offset*(-4)-8);
		fprintf(fptr, "\n");
	}
break;
case 69:
#line 253 "parser.y"
	{ 
		symbol* f = install(yystack.l_mark[0].sval);
		f->type = T_FUNCTION;
		yyval.sval=yystack.l_mark[0].sval;
	}
break;
case 70:
#line 257 "parser.y"
	{ yyval.sval=yystack.l_mark[-2].sval; }
break;
case 71:
#line 260 "parser.y"
	{ cur_scope++; }
break;
case 72:
#line 260 "parser.y"
	{ cur_scope--; }
break;
case 73:
#line 261 "parser.y"
	{}
break;
case 74:
#line 264 "parser.y"
	{ }
break;
case 75:
#line 267 "parser.y"
	{ install(yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval;}
break;
case 76:
#line 268 "parser.y"
	{ }
break;
case 77:
#line 269 "parser.y"
	{ install(yystack.l_mark[-3].sval); if(type!=3) type=1; }
break;
case 78:
#line 272 "parser.y"
	{ }
break;
case 79:
#line 273 "parser.y"
	{ }
break;
case 80:
#line 276 "parser.y"
	{ }
break;
case 81:
#line 277 "parser.y"
	{ }
break;
case 82:
#line 280 "parser.y"
	{ }
break;
case 83:
#line 281 "parser.y"
	{ }
break;
case 84:
#line 284 "parser.y"
	{ }
break;
case 85:
#line 285 "parser.y"
	{ }
break;
case 86:
#line 286 "parser.y"
	{ }
break;
case 87:
#line 289 "parser.y"
	{ }
break;
case 88:
#line 290 "parser.y"
	{ }
break;
case 89:
#line 293 "parser.y"
	{ }
break;
case 90:
#line 294 "parser.y"
	{ }
break;
case 91:
#line 297 "parser.y"
	{ }
break;
case 92:
#line 298 "parser.y"
	{
		/*printf("%s = %d", );*/
 	}
break;
case 93:
#line 303 "parser.y"
	{ }
break;
case 94:
#line 304 "parser.y"
	{ }
break;
case 95:
#line 305 "parser.y"
	{ }
break;
case 96:
#line 306 "parser.y"
	{ }
break;
case 97:
#line 307 "parser.y"
	{ }
break;
case 98:
#line 308 "parser.y"
	{ }
break;
case 99:
#line 311 "parser.y"
	{ }
break;
case 100:
#line 312 "parser.y"
	{ }
break;
case 101:
#line 315 "parser.y"
	{ }
break;
case 102:
#line 316 "parser.y"
	{ }
break;
case 103:
#line 319 "parser.y"
	{ }
break;
case 104:
#line 320 "parser.y"
	{ }
break;
case 105:
#line 323 "parser.y"
	{ }
break;
case 106:
#line 324 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
break;
case 107:
#line 336 "parser.y"
	{ }
break;
case 108:
#line 337 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\txor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
break;
case 109:
#line 349 "parser.y"
	{ }
break;
case 110:
#line 350 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tand t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
break;
case 111:
#line 362 "parser.y"
	{ }
break;
case 112:
#line 363 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\txor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
break;
case 113:
#line 373 "parser.y"
	{ }
break;
case 114:
#line 376 "parser.y"
	{ }
break;
case 115:
#line 377 "parser.y"
	{ }
break;
case 116:
#line 378 "parser.y"
	{ }
break;
case 117:
#line 379 "parser.y"
	{ }
break;
case 118:
#line 380 "parser.y"
	{ }
break;
case 119:
#line 383 "parser.y"
	{ }
break;
case 120:
#line 384 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tsll t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
break;
case 121:
#line 394 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tsrl t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	 }
break;
case 122:
#line 406 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tadd t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 123:
#line 416 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tsub t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 124:
#line 426 "parser.y"
	{ }
break;
case 125:
#line 429 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tmul t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");	
	}
break;
case 126:
#line 439 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tdiv t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 127:
#line 449 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\trem t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 128:
#line 459 "parser.y"
	{ }
break;
case 129:
#line 462 "parser.y"
	{ }
break;
case 130:
#line 463 "parser.y"
	{ }
break;
case 131:
#line 466 "parser.y"
	{ }
break;
case 132:
#line 467 "parser.y"
	{ }
break;
case 133:
#line 468 "parser.y"
	{ }
break;
case 134:
#line 469 "parser.y"
	{ }
break;
case 135:
#line 472 "parser.y"
	{ }
break;
case 136:
#line 473 "parser.y"
	{ }
break;
case 137:
#line 474 "parser.y"
	{ }
break;
case 138:
#line 475 "parser.y"
	{ }
break;
case 139:
#line 476 "parser.y"
	{ }
break;
case 140:
#line 477 "parser.y"
	{ }
break;
case 141:
#line 480 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 142:
#line 481 "parser.y"
	{ printf("%s\n", yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval; }
break;
case 143:
#line 482 "parser.y"
	{ }
break;
case 144:
#line 483 "parser.y"
	{ callFunc(yystack.l_mark[-2].sval, 0); }
break;
case 145:
#line 484 "parser.y"
	{ callFunc(yystack.l_mark[-3].sval, argc); }
break;
case 146:
#line 485 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, 1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 147:
#line 493 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, -1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	
	}
break;
case 148:
#line 504 "parser.y"
	{ argc++; }
break;
case 149:
#line 505 "parser.y"
	{ argc++; }
break;
case 150:
#line 508 "parser.y"
	{ }
break;
case 151:
#line 509 "parser.y"
	{ 
		fprintf(fptr, "\tli t0, %d\n",yystack.l_mark[0].ival);
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
		/*Constant c;*/
		/*c.type = T_INT;*/
		/*c.ival = $1;*/
	}
break;
case 152:
#line 518 "parser.y"
	{
		
	}
break;
case 153:
#line 521 "parser.y"
	{
		
	}
break;
case 154:
#line 524 "parser.y"
	{
		symbol* id = lookup(yystack.l_mark[0].sval);
		symbol* f = NULL;
		if(id!=NULL) {
			switch(id->mode) {
				case ARGUMENT_MODE:					
					f = lookup(id->funcName);
					fprintf(fptr, "\tlw t0, %d(fp)\n", f->totalArgs *(-4)-8 +id->offset*(-4)-4);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t0, 0(sp)\n");
				break;
		  		case LOCAL_MODE:
					fprintf(fptr, "\tlw  t0, %d(fp) \n",id->offset*(-4)-8);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t0, 0(sp)\n");
					fprintf(fptr, "\n");
				break;
		  		default: /* Global Vars */
					fprintf(fptr, "\tlui t0,%%hi(%s)\n", id->name);
					fprintf(fptr, "\tlw t1, %%lo(%s)(t0)\n", id->name);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t1, 0(sp)\n");

			}
		} 
		yyval.sval=yystack.l_mark[0].sval;
	}
break;
case 155:
#line 551 "parser.y"
	{ }
break;
#line 2049 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
