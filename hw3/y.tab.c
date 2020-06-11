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
    0,   45,   45,   44,   44,   46,   43,   47,   43,   48,
   43,   49,   43,   39,   39,   50,   51,   23,   52,   53,
   23,   24,   24,   24,   24,   21,   21,   21,   21,   21,
   21,   28,   28,   28,   54,   25,   55,   25,   56,   25,
   27,   27,   27,   27,   26,   26,   26,   26,   20,   20,
   30,   30,   31,   31,   31,   34,   34,   34,   34,   34,
   34,   34,   34,   34,   32,   32,   33,   33,   33,   58,
    1,   59,   57,   57,   35,   38,   38,   38,   40,   40,
   41,   41,   42,   42,   36,   36,   36,   37,   37,   19,
   19,   18,   18,   29,   29,   29,   29,   29,   29,   17,
   17,   16,   16,   15,   15,   14,   14,   13,   13,   12,
   12,   11,   11,   11,   10,   10,   10,   10,   10,    9,
    9,    9,    8,    8,    8,    7,    7,    7,    7,    6,
    6,    5,    5,    5,    5,    4,    4,    4,    4,    4,
    4,    3,    3,    3,    3,    3,    3,    3,   22,   22,
    2,    2,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    0,    4,    0,    5,    0,
    3,    0,    4,    1,    2,    0,    0,    4,    0,    0,
    5,    1,    1,    2,    2,    1,    1,    1,    1,    1,
    1,    3,    4,    3,    0,    6,    0,    4,    0,    6,
    5,    7,    6,    7,    2,    2,    2,    3,    1,    2,
    2,    3,    1,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    1,    1,    3,    0,
    3,    0,    4,    2,    1,    1,    3,    4,    1,    3,
    1,    3,    2,    1,    1,    3,    4,    1,    3,    1,
    3,    1,    3,    1,    1,    1,    1,    1,    1,    1,
    5,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    1,    3,    3,    1,    3,    3,    3,    3,    1,
    3,    3,    3,    3,    1,    3,    3,    3,    1,    1,
    4,    1,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    3,    4,    2,    2,    1,    3,
    3,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   70,   57,   58,   59,   60,   63,   64,   61,   62,    0,
   56,    0,    0,    5,    0,    0,    4,    2,    0,    0,
   55,   14,    0,    0,    0,    0,   51,    0,    0,    0,
   65,    0,    0,   54,    3,    0,   71,   68,   15,    0,
    0,   11,   76,    0,    0,    0,   52,    0,    0,    0,
   74,    0,   13,   17,    0,   77,    0,    7,   66,  155,
  154,  152,  153,  156,    0,    0,  143,  136,  138,  139,
  137,    0,    0,  140,  141,  142,    0,    0,    0,  129,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   92,   85,   69,  130,    0,    0,    0,    0,   81,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   49,   90,    0,   27,   22,   26,    0,    0,   31,
   30,   29,   23,    9,    0,  133,  134,   88,    0,    0,
    0,  147,  148,    0,    0,  135,   95,   96,   97,   98,
   99,   94,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   78,   83,   73,    0,   18,    0,    0,    0,
    0,    0,    0,    0,    0,   45,   46,   47,    0,   50,
    0,   24,   25,    0,   37,    0,   86,  151,    0,  145,
  149,    0,    0,   93,  126,  127,  128,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   80,   82,   32,    0,   34,    0,    0,
    0,    0,    0,   48,   91,   21,    0,   87,   89,  131,
    0,  146,  144,    0,   33,   35,   39,    0,    0,    0,
   38,  150,  101,    0,    0,   41,    0,    0,    0,   36,
   40,    0,   43,    0,   42,   44,
};
static const YYINT yydgoto[] = {                         12,
   13,   76,   77,   78,   79,   80,   81,   82,   83,   84,
   85,   86,   87,   88,   89,   90,   91,  113,  114,  115,
  116,  192,  117,  118,  119,  120,  121,  122,  143,   14,
   23,   30,   31,   16,   32,   93,  129,   33,   24,   97,
   98,   99,   17,   18,   19,   46,   57,   25,   40,   54,
  100,   55,  184,  244,  227,  245,   37,   20,   52,
};
static const YYINT yysindex[] = {                       227,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  319,
    0,    0,  319,    0,  -37,  319,    0,    0,  227,    3,
    0,    0,  -37,  319,  -77,    0,    0,  -39,  319,   24,
    0,   -2,  -21,    0,    0,   48,    0,    0,    0,  -77,
    0,    0,    0,   54,  319,  -77,    0,  -38,   31,  438,
    0,  319,    0,    0,   73,    0,  -77,    0,    0,    0,
    0,    0,    0,    0,  455,  455,    0,    0,    0,    0,
    0,   31,  141,    0,    0,    0,  -16,  438,   25,    0,
    2,   62,  -93,   -5,  -94,   79,   29,   18, -103,  -59,
    0,    0,    0,    0,   84,  -39,  148,  138,    0,   70,
  139,  438,  145,  165,  166,  172,   88,  183,  170,  175,
  373,    0,    0,   81,    0,    0,    0,   73,  -57,    0,
    0,    0,    0,    0,  438,    0,    0,    0,  -29,   -6,
  205,    0,    0,  401,  438,    0,    0,    0,    0,    0,
    0,    0,  438,  438,  438,  438,  438,  438,  438,  438,
  438,  438,  438,  438,  438,  438,  438,  438,  438,  438,
  438,  438,    0,    0,    0,  723,    0,   88,  191,   88,
  438,  438,  438,  -30,  414,    0,    0,    0,   85,    0,
  438,    0,    0,  157,    0,  -22,    0,    0,  438,    0,
    0,   -4,  -15,    0,    0,    0,    0,    2,    2,   62,
   62,  -93,  -93,  -93,  -93,   -5,   -5,  -94,   79,   29,
   18, -103,  -17,    0,    0,    0,   88,    0,   10,   50,
   93,  253,  414,    0,    0,    0,  -77,    0,    0,    0,
  438,    0,    0,  438,    0,    0,    0,   88,  438,  427,
    0,    0,    0,  -77,  -77,    0,  117,   88,  121,    0,
    0,  237,    0,   88,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  197,    0,    0,   40,    0,    0,  325,    0,
    0,    0,    0,  212,    0,  119,    0,    0,   41,    0,
    0,   92,  126,    0,    0,  781,    0,    0,    0,    0,
  -33,    0,    0,    0,  215,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  500,    0,  690,    0,
  662,  791,  907,   97, 1126,  -27, 1194,  -11, 1240,  554,
    0,    0,    0,    0,    0,  125,    0,  298,    0,    0,
  528,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  216,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  768,  778,  819,
  860,  930,  958, 1056, 1079,  491, 1124, 1150, 1152, 1196,
 1220, 1247,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  104,    0,    0,    0, 1230,  -36,   46,   51,  162,  130,
  185,  186,  184,  190,  192,    0,  -25,  458,  -23, -167,
  -46,    0,  -12,    0,    0,    0,    0,    0,    0,  390,
  188,    0,  307,  300,   -9,  -66,    0,    0,  349,    0,
    0,  217,    0,  365,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1519
static const YYINT yytable[] = {                         19,
   28,   28,   28,  162,   19,  128,   19,  223,   19,   19,
   75,   19,   42,  108,  186,   68,  108,   73,   44,   71,
   69,   27,   70,  134,   95,   19,  181,   53,  181,  104,
  108,  108,  104,   58,  188,  108,  232,  181,  146,  231,
  234,  136,   36,  144,  124,   41,  104,  104,  145,  130,
  236,  104,   28,  181,  154,  240,  153,   28,   49,   28,
  174,   28,   28,   75,   28,  108,  108,   48,   68,   50,
   73,  182,   71,   69,  135,   70,  169,  233,   28,   53,
   53,  104,   47,   53,   68,  142,  164,  179,   51,   19,
  237,   16,   19,  181,   56,  187,  108,  108,   53,   68,
   72,  130,  228,   74,  147,   75,  148,  195,  196,  197,
   68,  193,   73,  104,   71,   69,  157,   70,   29,  229,
   75,  216,  158,  218,  181,   68,   38,   73,  181,   71,
   69,  112,   70,  238,  112,   67,  181,  112,  213,  180,
  112,  159,   28,  224,   28,   28,  112,  219,  220,  221,
   67,   38,  230,   72,  112,  112,   74,  252,   70,  112,
  181,  254,   76,    6,  181,   84,   75,  160,   84,   75,
  235,  149,  150,   75,  155,  156,  163,   76,   68,   76,
   73,  166,   71,   69,   75,   70,   75,   15,  165,  112,
  112,  246,  198,  199,  167,   41,  168,   21,   74,  200,
  201,  253,  170,   34,  171,  172,   15,  256,  243,   76,
   41,  173,  161,   74,  241,  247,  249,   43,   26,   26,
  112,  112,  175,   19,   19,   19,   19,   19,  176,   19,
   19,  250,  251,  177,   60,   61,   62,   63,   64,   96,
   65,   66,  185,  108,  108,  189,  132,  133,  217,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,  104,
  104,  151,  152,   19,   19,   19,   74,   19,   19,   19,
   19,  222,   19,   19,   19,   19,   28,   28,   28,   28,
   28,  226,   28,   28,  206,  207,   67,   60,   61,   62,
   63,   64,  239,   65,   66,  255,   53,  137,  138,  139,
  140,  141,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,  202,  203,  204,  205,   28,   28,   28,   10,
   28,   28,   28,   28,    1,   28,   28,   28,   28,  101,
   61,   62,   63,   64,   12,   65,   66,    8,   79,   67,
   20,  208,  210,  209,  101,   61,   62,   63,   64,  211,
   65,   66,  212,   96,   59,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,  112,  112,  112,  112,  102,
  103,  104,  131,  105,  106,  107,  108,   45,  109,  110,
  111,   67,  215,   35,  102,  103,  104,    0,  105,  106,
  107,  108,    0,  109,  110,  111,   67,   60,   61,   62,
   63,   64,   22,   65,   66,   75,    0,    0,    0,    0,
   68,    0,   73,   39,   71,   69,    0,   70,   22,    0,
    0,    0,    0,    2,    3,    4,    5,    6,    7,    8,
    9,  178,   11,   75,   39,    0,    0,    0,   68,    0,
   73,  190,   71,   69,  123,   70,   75,    0,    0,   67,
    0,   68,    0,   73,    0,   71,   69,    0,   70,   75,
    0,    0,    0,    0,   68,    0,   73,  248,   71,   69,
   75,   70,  112,    0,    0,   68,    0,   73,    0,   71,
   69,    0,   70,    1,    0,    0,    0,   75,    0,    0,
    0,    0,   68,    0,  125,    0,   71,   69,   74,   70,
    0,    0,    0,    0,    0,    0,   92,  183,    0,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,    0,
    0,    0,    0,    0,    0,    0,   74,    0,  113,   92,
    0,  113,    0,    0,  113,    0,  132,  132,    0,   74,
  132,  132,  132,  132,  132,    0,  132,    0,  113,  113,
    0,    0,   74,  113,    0,    0,    0,  132,  132,  132,
  132,  132,  132,   74,  155,  155,    0,  155,    0,  155,
  155,  155,  155,    0,  155,    0,    0,    0,    0,    0,
   74,    0,    0,  113,  113,    0,  155,  155,  155,  155,
  155,  191,  132,  132,  100,    0,    0,  100,    0,    0,
  194,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,  100,  100,    0,  113,  113,    0,    0,  155,    0,
    0,  155,    0,  132,  132,    0,    0,    0,    0,   60,
   61,   62,   63,   64,    0,   65,   66,    0,  225,    0,
    0,    0,    0,   92,    0,    0,  100,    0,    0,    0,
    0,  155,    0,    0,    0,    0,    0,   60,   61,   62,
   63,   64,    0,   65,   66,    0,    0,    0,    0,    0,
   60,   61,   62,   63,   64,    0,   65,   66,  100,    0,
    0,   67,    0,   60,   61,   62,   63,   64,  242,   65,
   66,    0,    0,    0,   60,   61,   62,   63,   64,  125,
   65,   66,  125,    0,  125,  125,  125,    0,    0,   67,
    0,   60,   61,   62,   63,   64,    0,   65,   66,  125,
  125,  125,   67,  125,  125,    0,  130,  130,    0,    0,
  130,  130,  130,  130,  130,   67,  130,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,  130,  130,  130,
    0,  130,  130,    0,  125,  125,    0,    0,    0,  113,
  113,  113,  113,   67,  132,  132,  132,  132,  132,  132,
  132,  132,  132,  132,  132,  132,  132,    0,    0,    0,
    0,    0,  130,  130,    0,  125,  125,    0,    0,    0,
  155,  155,  155,  155,  155,  155,  155,  155,  155,  155,
  155,  155,  155,  155,  155,  123,    0,    0,  123,    0,
  123,  123,  123,  130,  130,  124,    0,    0,  124,    0,
  124,  124,  124,    0,    0,  123,  123,  123,  120,  123,
  123,  120,    0,    0,  120,  124,  124,  124,    0,  124,
  124,    0,    0,    0,    0,    0,    0,    0,  120,  120,
  120,    0,  120,  120,    0,    0,  121,    0,    0,  121,
  123,  123,  121,    0,    0,    0,    0,    0,    0,    0,
  124,  124,    0,    0,    0,    0,  121,  121,  121,    0,
  121,  121,    0,  120,  120,    0,    0,    0,    0,    0,
    0,  123,  123,    0,    0,    0,    0,  122,    0,    0,
  122,  124,  124,  122,    0,    0,    0,    0,    0,    0,
    0,  121,  121,    0,  120,  120,    0,  122,  122,  122,
    0,  122,  122,    0,    0,    0,  125,  125,  125,  125,
  125,  125,  125,  125,    0,    0,    0,    0,    0,    0,
    0,    0,  121,  121,  115,    0,    0,  115,    0,    0,
  115,    0,  122,  122,  130,  130,  130,  130,  130,  130,
  130,  130,    0,    0,  115,  115,  115,  118,  115,  115,
  118,    0,    0,  118,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  122,  122,    0,    0,  118,  118,  118,
    0,  118,  118,    0,    0,  119,    0,    0,  119,  115,
  115,  119,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,  119,  119,  119,  214,  119,
  119,    0,  118,  118,    0,    0,    0,    0,    0,    0,
  115,  115,  123,  123,  123,  123,  123,  123,  123,  123,
    0,    0,  124,  124,  124,  124,  124,  124,  124,  124,
  119,  119,    0,  118,  118,  120,  120,  120,  120,  120,
  120,  120,  120,   72,   72,   72,   72,   72,   72,   72,
   72,   72,   72,    0,    0,    0,    0,    0,    0,    0,
    0,  119,  119,  121,  121,  121,  121,  121,  121,  121,
  121,    0,    0,  117,    0,    0,  117,    0,    0,  117,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  117,  117,  117,  116,  117,  117,  116,
    0,    0,  116,    0,  122,  122,  122,  122,  122,  122,
  122,  122,    0,    0,    0,    0,  116,  116,  116,    0,
  116,  116,    0,    0,    0,    0,    0,    0,  117,  117,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  114,    0,  110,  114,    0,  110,  114,    0,  110,
    0,  116,  116,  115,  115,  115,  115,  115,  115,  117,
  117,  114,  114,  110,  110,    0,  114,  111,  110,    0,
  111,    0,  109,  111,    0,  109,  118,  118,  118,  118,
  118,  118,  116,  116,    0,    0,    0,  111,  111,  109,
  109,    0,  111,    0,  109,    0,  114,  114,  110,  110,
    0,    0,    0,    0,  119,  119,  119,  119,  119,  119,
    0,    0,    0,    0,  106,    0,  107,  106,    0,  107,
    0,    0,  111,  111,  109,  109,    0,  114,  114,  110,
  110,  106,  106,  107,  107,    0,  106,    0,  107,    0,
  105,    0,    0,  105,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  111,  111,  109,  109,  105,  105,   94,
  102,    0,  105,  102,    0,    0,  106,  103,  107,    0,
  103,    0,    0,    0,  126,  127,    0,  102,  102,    0,
    0,    0,  102,    0,  103,  103,    0,   94,    0,  103,
    0,    0,  105,    0,    0,    0,    0,  106,  106,  107,
  107,    0,  117,  117,  117,  117,  117,  117,    0,    0,
    0,   94,  102,    0,    0,    0,    0,    0,    0,  103,
    0,    0,    0,    0,  105,  116,  116,  116,  116,  116,
  116,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  102,    0,    0,    0,    0,    0,
    0,  103,    0,   94,   94,   94,   94,   94,   94,   94,
   94,   94,   94,   94,   94,   94,   94,   94,   94,   94,
   94,    0,  114,  114,  114,  114,  110,  110,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   94,    0,
  111,  111,  109,  109,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,  106,  106,  107,  107,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  105,  105,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  102,    0,    0,    0,    0,    0,    0,  103,
};
static const YYINT yycheck[] = {                         33,
   40,   40,   40,   63,   38,   72,   40,  175,   42,   43,
   33,   45,   25,   41,   44,   38,   44,   40,   28,   42,
   43,   59,   45,   40,   50,   59,   44,   40,   44,   41,
   58,   59,   44,   46,   41,   63,   41,   44,   37,   44,
   58,   78,   40,   42,   57,  123,   58,   59,   47,   73,
   41,   63,   33,   44,   60,  223,   62,   38,   61,   40,
  107,   42,   43,   33,   45,   93,   94,   44,   38,   91,
   40,  118,   42,   43,   91,   45,  102,   93,   59,   40,
   41,   93,   59,   44,   44,   61,   96,  111,   41,  123,
   41,  125,  126,   44,   41,  125,  124,  125,   59,   59,
  123,  125,  125,  126,   43,   33,   45,  144,  145,  146,
   38,  135,   40,  125,   42,   43,   38,   45,   15,  186,
   33,  168,   94,  170,   44,   38,   23,   40,   44,   42,
   43,   59,   45,   41,   38,   44,   44,   41,  162,   59,
   44,  124,  123,   59,  125,  126,   59,  171,  172,  173,
   59,   48,  189,  123,   58,   59,  126,   41,   40,   63,
   44,   41,   44,  123,   44,   41,   41,  271,   44,   44,
  217,  265,  266,   33,  269,  270,   93,   59,   38,   61,
   40,   44,   42,   43,   59,   45,   61,    0,   41,   93,
   94,  238,  147,  148,  125,  123,   58,   10,  126,  149,
  150,  248,   58,   16,   40,   40,   19,  254,  234,   91,
  123,   40,  272,  126,  227,  239,  240,  257,  257,  257,
  124,  125,   40,  257,  258,  259,  260,  261,   59,  263,
  264,  244,  245,   59,  257,  258,  259,  260,  261,   52,
  263,  264,  300,  271,  272,   41,  263,  264,   58,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  271,
  272,  267,  268,  297,  298,  299,  126,  301,  302,  303,
  304,  302,  306,  307,  308,  309,  257,  258,  259,  260,
  261,  125,  263,  264,  155,  156,  309,  257,  258,  259,
  260,  261,   40,  263,  264,   59,  257,  273,  274,  275,
  276,  277,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  151,  152,  153,  154,  297,  298,  299,  123,
  301,  302,  303,  304,    0,  306,  307,  308,  309,  257,
  258,  259,  260,  261,  123,  263,  264,  123,   41,  309,
  125,  157,  159,  158,  257,  258,  259,  260,  261,  160,
  263,  264,  161,  166,   48,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  269,  270,  271,  272,  297,
  298,  299,   73,  301,  302,  303,  304,   29,  306,  307,
  308,  309,  166,   19,  297,  298,  299,   -1,  301,  302,
  303,  304,   -1,  306,  307,  308,  309,  257,  258,  259,
  260,  261,   13,  263,  264,   33,   -1,   -1,   -1,   -1,
   38,   -1,   40,   24,   42,   43,   -1,   45,   29,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   59,  292,   33,   45,   -1,   -1,   -1,   38,   -1,
   40,   41,   42,   43,   55,   45,   33,   -1,   -1,  309,
   -1,   38,   -1,   40,   -1,   42,   43,   -1,   45,   33,
   -1,   -1,   -1,   -1,   38,   -1,   40,   41,   42,   43,
   33,   45,   59,   -1,   -1,   38,   -1,   40,   -1,   42,
   43,   -1,   45,  257,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   43,  126,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   49,  118,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  126,   -1,   38,   72,
   -1,   41,   -1,   -1,   44,   -1,   37,   38,   -1,  126,
   41,   42,   43,   44,   45,   -1,   47,   -1,   58,   59,
   -1,   -1,  126,   63,   -1,   -1,   -1,   58,   59,   60,
   61,   62,   63,  126,   37,   38,   -1,   40,   -1,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  126,   -1,   -1,   93,   94,   -1,   59,   60,   61,   62,
   63,  134,   93,   94,   41,   -1,   -1,   44,   -1,   -1,
  143,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,   58,   59,   -1,  124,  125,   -1,   -1,   91,   -1,
   -1,   94,   -1,  124,  125,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,  181,   -1,
   -1,   -1,   -1,  186,   -1,   -1,   93,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,  264,  125,   -1,
   -1,  309,   -1,  257,  258,  259,  260,  261,  231,  263,
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
  271,  272,   -1,   -1,   58,   59,   60,   38,   62,   63,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,   -1,   -1,   58,   59,   60,
   -1,   62,   63,   -1,   -1,   38,   -1,   -1,   41,   93,
   94,   44,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   58,   59,   60,  296,   62,
   63,   -1,   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  125,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,   -1,  265,  266,  267,  268,  269,  270,  271,  272,
   93,   94,   -1,  124,  125,  265,  266,  267,  268,  269,
  270,  271,  272,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   58,   59,   60,   38,   62,   63,   41,
   -1,   -1,   44,   -1,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   58,   59,   60,   -1,
   62,   63,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   38,   41,   -1,   41,   44,   -1,   44,
   -1,   93,   94,  267,  268,  269,  270,  271,  272,  124,
  125,   58,   59,   58,   59,   -1,   63,   38,   63,   -1,
   41,   -1,   41,   44,   -1,   44,  267,  268,  269,  270,
  271,  272,  124,  125,   -1,   -1,   -1,   58,   59,   58,
   59,   -1,   63,   -1,   63,   -1,   93,   94,   93,   94,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   -1,   41,   -1,   41,   44,   -1,   44,
   -1,   -1,   93,   94,   93,   94,   -1,  124,  125,  124,
  125,   58,   59,   58,   59,   -1,   63,   -1,   63,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,  124,  125,   58,   59,   50,
   41,   -1,   63,   44,   -1,   -1,   93,   41,   93,   -1,
   44,   -1,   -1,   -1,   65,   66,   -1,   58,   59,   -1,
   -1,   -1,   63,   -1,   58,   59,   -1,   78,   -1,   63,
   -1,   -1,   93,   -1,   -1,   -1,   -1,  124,  125,  124,
  125,   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,
   -1,  102,   93,   -1,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,  125,  267,  268,  269,  270,  271,
  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,  144,  145,  146,  147,  148,  149,  150,
  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,
  161,   -1,  269,  270,  271,  272,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  189,   -1,
  271,  272,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  234,  271,  272,  271,  272,   -1,   -1,
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
#define YYUNDFTOKEN 382
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : translation_unit",
"translation_unit : external_declaration",
"translation_unit : translation_unit external_declaration",
"external_declaration : function_definition",
"external_declaration : declaration",
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
#line 475 "parser.y"

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
#line 1013 "y.tab.c"

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
#line 102 "parser.y"
	{ }
break;
case 2:
#line 105 "parser.y"
	{ }
break;
case 3:
#line 106 "parser.y"
	{ }
break;
case 4:
#line 109 "parser.y"
	{ }
break;
case 5:
#line 110 "parser.y"
	{ }
break;
case 6:
#line 113 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[0].sval);
		funcBegin(yystack.l_mark[0].sval);
	}
break;
case 7:
#line 117 "parser.y"
	{
		funcEnd(yystack.l_mark[-2].sval);
	}
break;
case 8:
#line 120 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[-1].sval);
		funcBegin(yystack.l_mark[-1].sval);
	}
break;
case 9:
#line 124 "parser.y"
	{
		funcEnd(yystack.l_mark[-3].sval);
	}
break;
case 10:
#line 127 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[0].sval);
		funcBegin(yystack.l_mark[0].sval);
	}
break;
case 11:
#line 131 "parser.y"
	{
		funcEnd(yystack.l_mark[-2].sval);
	}
break;
case 12:
#line 134 "parser.y"
	{
		cur_scope++;
		handleParams(yystack.l_mark[-1].sval);
		funcBegin(yystack.l_mark[-1].sval);
	}
break;
case 13:
#line 138 "parser.y"
	{
		funcEnd(yystack.l_mark[-3].sval);
	}
break;
case 14:
#line 143 "parser.y"
	{ }
break;
case 15:
#line 144 "parser.y"
	{ }
break;
case 16:
#line 147 "parser.y"
	{ /*setLocalVars();*/ }
break;
case 17:
#line 147 "parser.y"
	{ popScope(cur_scope); cur_scope--; }
break;
case 18:
#line 147 "parser.y"
	{}
break;
case 19:
#line 148 "parser.y"
	{ /*setLocalVars();*/ }
break;
case 20:
#line 148 "parser.y"
	{ popScope(cur_scope); cur_scope--; }
break;
case 21:
#line 148 "parser.y"
	{}
break;
case 22:
#line 151 "parser.y"
	{ }
break;
case 23:
#line 152 "parser.y"
	{ }
break;
case 24:
#line 153 "parser.y"
	{ }
break;
case 25:
#line 154 "parser.y"
	{ }
break;
case 26:
#line 157 "parser.y"
	{ }
break;
case 27:
#line 158 "parser.y"
	{ }
break;
case 28:
#line 159 "parser.y"
	{ }
break;
case 29:
#line 160 "parser.y"
	{ }
break;
case 30:
#line 161 "parser.y"
	{ }
break;
case 31:
#line 162 "parser.y"
	{ }
break;
case 32:
#line 165 "parser.y"
	{ }
break;
case 33:
#line 166 "parser.y"
	{ }
break;
case 34:
#line 167 "parser.y"
	{ }
break;
case 35:
#line 170 "parser.y"
	{ cur_scope++; }
break;
case 36:
#line 170 "parser.y"
	{ }
break;
case 37:
#line 171 "parser.y"
	{ cur_scope++; }
break;
case 38:
#line 171 "parser.y"
	{ }
break;
case 39:
#line 172 "parser.y"
	{ cur_scope++; }
break;
case 40:
#line 172 "parser.y"
	{ }
break;
case 41:
#line 175 "parser.y"
	{ }
break;
case 42:
#line 176 "parser.y"
	{ }
break;
case 43:
#line 177 "parser.y"
	{ }
break;
case 44:
#line 178 "parser.y"
	{ }
break;
case 45:
#line 181 "parser.y"
	{ }
break;
case 46:
#line 182 "parser.y"
	{ }
break;
case 47:
#line 183 "parser.y"
	{ }
break;
case 48:
#line 184 "parser.y"
	{ }
break;
case 49:
#line 187 "parser.y"
	{ }
break;
case 50:
#line 188 "parser.y"
	{ }
break;
case 51:
#line 192 "parser.y"
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
case 52:
#line 202 "parser.y"
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
case 53:
#line 213 "parser.y"
	{ }
break;
case 54:
#line 214 "parser.y"
	{ }
break;
case 55:
#line 215 "parser.y"
	{ }
break;
case 56:
#line 218 "parser.y"
	{ yyval.sval="void"; 	}
break;
case 57:
#line 219 "parser.y"
	{ yyval.sval="char"; 	}
break;
case 58:
#line 220 "parser.y"
	{ yyval.sval="short"; 	}
break;
case 59:
#line 221 "parser.y"
	{ yyval.sval="int"; 	}
break;
case 60:
#line 222 "parser.y"
	{ yyval.sval="long"; 	}
break;
case 61:
#line 223 "parser.y"
	{ yyval.sval="float"; 	}
break;
case 62:
#line 224 "parser.y"
	{ yyval.sval="double"; 	}
break;
case 63:
#line 225 "parser.y"
	{ yyval.sval="signed"; 	}
break;
case 64:
#line 226 "parser.y"
	{ yyval.sval="unsigned";}
break;
case 65:
#line 229 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 66:
#line 230 "parser.y"
	{ }
break;
case 67:
#line 233 "parser.y"
	{ }
break;
case 68:
#line 234 "parser.y"
	{ type=T_FUNCTION; yyval.sval=yystack.l_mark[0].sval; }
break;
case 69:
#line 235 "parser.y"
	{ 
		symbol* id = lookup(yystack.l_mark[-2].sval);
		fprintf(fptr, "\tsw  t0, %d(fp) \n", id->offset*(-4)-8);
		fprintf(fptr, "\n");
	}
break;
case 70:
#line 242 "parser.y"
	{ 
		symbol* f = install(yystack.l_mark[0].sval);
		f->type = T_FUNCTION;
		yyval.sval=yystack.l_mark[0].sval;
	}
break;
case 71:
#line 246 "parser.y"
	{ yyval.sval=yystack.l_mark[-2].sval; }
break;
case 72:
#line 249 "parser.y"
	{ cur_scope++; }
break;
case 73:
#line 249 "parser.y"
	{ cur_scope--; }
break;
case 74:
#line 250 "parser.y"
	{}
break;
case 75:
#line 253 "parser.y"
	{ }
break;
case 76:
#line 256 "parser.y"
	{ install(yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval;}
break;
case 77:
#line 257 "parser.y"
	{ }
break;
case 78:
#line 258 "parser.y"
	{ install(yystack.l_mark[-3].sval); if(type!=3) type=1; }
break;
case 79:
#line 261 "parser.y"
	{ }
break;
case 80:
#line 262 "parser.y"
	{ }
break;
case 81:
#line 265 "parser.y"
	{ }
break;
case 82:
#line 266 "parser.y"
	{ }
break;
case 83:
#line 269 "parser.y"
	{ }
break;
case 84:
#line 270 "parser.y"
	{ }
break;
case 85:
#line 273 "parser.y"
	{ }
break;
case 86:
#line 274 "parser.y"
	{ }
break;
case 87:
#line 275 "parser.y"
	{ }
break;
case 88:
#line 278 "parser.y"
	{ }
break;
case 89:
#line 279 "parser.y"
	{ }
break;
case 90:
#line 282 "parser.y"
	{ }
break;
case 91:
#line 283 "parser.y"
	{ }
break;
case 92:
#line 286 "parser.y"
	{ }
break;
case 93:
#line 287 "parser.y"
	{
		/*printf("%s = %d", );*/
 	}
break;
case 94:
#line 292 "parser.y"
	{ }
break;
case 95:
#line 293 "parser.y"
	{ }
break;
case 96:
#line 294 "parser.y"
	{ }
break;
case 97:
#line 295 "parser.y"
	{ }
break;
case 98:
#line 296 "parser.y"
	{ }
break;
case 99:
#line 297 "parser.y"
	{ }
break;
case 100:
#line 300 "parser.y"
	{ }
break;
case 101:
#line 301 "parser.y"
	{ }
break;
case 102:
#line 304 "parser.y"
	{ }
break;
case 103:
#line 305 "parser.y"
	{ }
break;
case 104:
#line 308 "parser.y"
	{ }
break;
case 105:
#line 309 "parser.y"
	{ }
break;
case 106:
#line 312 "parser.y"
	{ }
break;
case 107:
#line 313 "parser.y"
	{ }
break;
case 108:
#line 316 "parser.y"
	{ }
break;
case 109:
#line 317 "parser.y"
	{ }
break;
case 110:
#line 320 "parser.y"
	{ }
break;
case 111:
#line 321 "parser.y"
	{ }
break;
case 112:
#line 324 "parser.y"
	{ }
break;
case 113:
#line 325 "parser.y"
	{ }
break;
case 114:
#line 326 "parser.y"
	{ }
break;
case 115:
#line 329 "parser.y"
	{ }
break;
case 116:
#line 330 "parser.y"
	{ }
break;
case 117:
#line 331 "parser.y"
	{ }
break;
case 118:
#line 332 "parser.y"
	{ }
break;
case 119:
#line 333 "parser.y"
	{ }
break;
case 120:
#line 336 "parser.y"
	{ }
break;
case 121:
#line 337 "parser.y"
	{ }
break;
case 122:
#line 338 "parser.y"
	{ }
break;
case 123:
#line 341 "parser.y"
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
case 124:
#line 351 "parser.y"
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
case 125:
#line 361 "parser.y"
	{ }
break;
case 126:
#line 364 "parser.y"
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
case 127:
#line 374 "parser.y"
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
case 128:
#line 384 "parser.y"
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
case 129:
#line 394 "parser.y"
	{ }
break;
case 130:
#line 397 "parser.y"
	{ }
break;
case 131:
#line 398 "parser.y"
	{ }
break;
case 132:
#line 401 "parser.y"
	{ }
break;
case 133:
#line 402 "parser.y"
	{ }
break;
case 134:
#line 403 "parser.y"
	{ }
break;
case 135:
#line 404 "parser.y"
	{ }
break;
case 136:
#line 407 "parser.y"
	{ }
break;
case 137:
#line 408 "parser.y"
	{ }
break;
case 138:
#line 409 "parser.y"
	{ }
break;
case 139:
#line 410 "parser.y"
	{ }
break;
case 140:
#line 411 "parser.y"
	{ }
break;
case 141:
#line 412 "parser.y"
	{ }
break;
case 142:
#line 415 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 143:
#line 416 "parser.y"
	{ printf("%s\n", yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval; }
break;
case 144:
#line 417 "parser.y"
	{ }
break;
case 145:
#line 418 "parser.y"
	{ callFunc(yystack.l_mark[-2].sval, 0); }
break;
case 146:
#line 419 "parser.y"
	{ callFunc(yystack.l_mark[-3].sval, argc); }
break;
case 147:
#line 420 "parser.y"
	{ }
break;
case 148:
#line 421 "parser.y"
	{ }
break;
case 149:
#line 424 "parser.y"
	{ argc++; }
break;
case 150:
#line 425 "parser.y"
	{ argc++; }
break;
case 151:
#line 428 "parser.y"
	{ }
break;
case 152:
#line 429 "parser.y"
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
case 153:
#line 438 "parser.y"
	{
		
	}
break;
case 154:
#line 441 "parser.y"
	{
		
	}
break;
case 155:
#line 444 "parser.y"
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
case 156:
#line 471 "parser.y"
	{ }
break;
#line 1972 "y.tab.c"
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
