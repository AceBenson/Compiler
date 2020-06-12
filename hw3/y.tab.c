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
   28,   28,   28,   53,   25,   54,   25,   55,   25,   56,
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
    1,    2,    1,    1,    0,    4,    0,    5,    0,    3,
    0,    4,    1,    2,    0,    0,    4,    0,    0,    5,
    1,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    3,    4,    3,    0,    6,    0,    4,    0,    6,    0,
    6,    7,    6,    7,    2,    2,    2,    3,    1,    2,
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
   56,    0,    0,    4,    0,    0,    3,    1,    0,   55,
    2,   13,    0,    0,    0,    0,   51,    0,    0,    0,
   65,    0,    0,   54,    0,   71,   68,   14,    0,    0,
   10,   76,    0,    0,    0,   52,    0,    0,    0,   74,
    0,   12,   16,    0,   77,    0,    6,   66,  155,  154,
  152,  153,  156,    0,    0,  143,  136,  138,  139,  137,
    0,    0,  140,  141,  142,    0,    0,    0,  129,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   92,
   85,   69,  130,    0,    0,    0,    0,   81,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   90,    0,   26,   21,   25,    0,    0,   30,   29,
   28,   22,    8,    0,  133,  134,   88,    0,    0,    0,
  147,  148,    0,    0,  135,   95,   96,   97,   98,   99,
   94,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   78,   83,   73,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0,   45,   46,   47,    0,   50,    0,
   23,   24,    0,   36,    0,   86,  151,    0,  145,  149,
    0,    0,   93,  126,  127,  128,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   80,   82,   31,    0,   33,    0,    0,    0,
    0,    0,   48,   91,   20,    0,   87,   89,  131,    0,
  146,  144,    0,   32,   34,   38,   40,    0,    0,   37,
  150,  101,    0,    0,    0,    0,    0,    0,   35,   39,
   41,    0,   43,    0,   42,   44,
};
static const YYINT yydgoto[] = {                         12,
   13,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   90,  112,  113,  114,
  115,  191,  116,  117,  118,  119,  120,  121,  142,   14,
   23,   30,   31,   16,   32,   92,  128,   33,   24,   96,
   97,   98,   17,   18,   45,   56,   25,   39,   53,   99,
   54,  183,  243,  226,  244,  245,   36,   19,   51,
};
static const YYINT yysindex[] = {                       234,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  318,
    0,  234,  318,    0,  -37,  318,    0,    0,   -6,    0,
    0,    0,  -37,  318,  -74,    0,    0,  -39,  318,   -3,
    0,   22,  -40,    0,   66,    0,    0,    0,  -74,    0,
    0,    0,   71,  318,  -74,    0,  -38,   31,  438,    0,
  318,    0,    0,   73,    0,  -74,    0,    0,    0,    0,
    0,    0,    0,  455,  455,    0,    0,    0,    0,    0,
   31,  141,    0,    0,    0,  -16,  438,   25,    0,    3,
   -1,  -78,   -5,  -76,   23,   35,   -7, -152,  -59,    0,
    0,    0,    0,   32,  -39,   95,   98,    0,   24,  113,
  438,  120,  142,  145,  149,   88,  157,  151,  153,  373,
    0,    0,   41,    0,    0,    0,   73,  -92,    0,    0,
    0,    0,    0,  438,    0,    0,    0,  -36,   47,  174,
    0,    0,  401,  438,    0,    0,    0,    0,    0,    0,
    0,  438,  438,  438,  438,  438,  438,  438,  438,  438,
  438,  438,  438,  438,  438,  438,  438,  438,  438,  438,
  438,    0,    0,    0,  723,    0,   88,  165,   88,  438,
  438,  438,  -85,  414,    0,    0,    0,   64,    0,  438,
    0,    0,  107,    0,  -22,    0,    0,  438,    0,    0,
   96,  -25,    0,    0,    0,    0,    3,    3,   -1,   -1,
  -78,  -78,  -78,  -78,   -5,   -5,  -76,   23,   35,   -7,
 -152,  108,    0,    0,    0,   88,    0,  117,  118,  123,
  189,  414,    0,    0,    0,  -74,    0,    0,    0,  438,
    0,    0,  438,    0,    0,    0,    0,  438,  427,    0,
    0,    0,  -74,  -74,   88,  131,   88,  132,    0,    0,
    0,  181,    0,   88,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  126,    0,    0,   40,    0,    0,    0,    0,
    0,    0,    0,  170,    0,  104,    0,    0,   28,    0,
    0,   65,  109,    0,  781,    0,    0,    0,    0,  -33,
    0,    0,    0,  173,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  500,    0,  690,    0,  662,
  791,  907,   97, 1126,  -27, 1194,  -11, 1240,  555,    0,
    0,    0,    0,    0,  136,    0,  202,    0,    0,  528,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  121,   20,    0,    0,
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
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   87,    0,    0,    0, 1231,  -49,   59,  137,   51,  159,
  116,  125,  158,  156,  160,    0,  -24,  415, 1097, -168,
  -47,    0,  -10,    0,    0,    0,    0,    0,    0,  461,
   27,    0,  278,  263,   10,  -58,    0,    0,  309,    0,
    0,  176,    0,  327,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1519
static const YYINT yytable[] = {                         18,
   28,   28,   28,  161,   18,  222,   18,  185,   18,   18,
   74,   18,  127,  108,   41,   67,  108,   72,  180,   70,
   68,   27,   69,  133,   94,   18,   15,  135,   52,  104,
  108,  108,  104,   35,   57,  108,   20,   43,   15,  145,
   47,  146,   34,  147,  143,  123,  104,  104,   40,  144,
   49,  104,   27,  239,  153,   46,  152,   27,  173,   27,
  156,   27,   27,   74,   27,  108,  108,  232,   67,  181,
   72,   68,   70,   68,  134,   69,  168,   95,   27,   53,
   53,  104,   48,   53,  180,  141,   68,  187,  186,   18,
  180,   15,   18,  194,  195,  196,  108,  108,   53,  179,
   71,   29,  227,   73,  163,   74,   50,  180,   67,   37,
   67,   55,   72,  104,   70,   68,  158,   69,  159,  215,
   74,  217,  223,   67,  162,   67,  228,   72,  157,   70,
   68,  111,   69,   37,  112,  164,  231,  112,  229,  230,
  112,  165,   27,   70,   27,   27,  111,   76,  166,   75,
    5,  180,   75,   71,  112,  112,   73,  235,  236,  112,
  180,  180,   76,  237,   76,  233,  180,   75,  234,   75,
  167,  252,  254,   74,  180,  180,   84,  169,   67,   84,
   72,  170,   70,   68,  171,   69,  148,  149,  172,  112,
  112,   95,  154,  155,   76,   40,  174,  251,   73,  253,
  201,  202,  203,  204,  197,  198,  256,  184,  242,  175,
   40,  176,  160,   73,  188,  240,  221,   42,   26,   26,
  112,  112,  216,   18,   18,   18,   18,   18,  238,   18,
   18,  225,  249,  250,   59,   60,   61,   62,   63,  255,
   64,   65,   79,  108,  108,   19,  131,  132,    9,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,  104,
  104,  150,  151,   18,   18,   18,   73,   18,   18,   18,
   18,  207,   18,   18,   18,   18,   27,   27,   27,   27,
   27,  208,   27,   27,  199,  200,   66,   59,   60,   61,
   62,   63,   11,   64,   65,    7,   53,  136,  137,  138,
  139,  140,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   27,  205,  206,  210,  209,   27,   27,   27,  211,
   27,   27,   27,   27,   58,   27,   27,   27,   27,  100,
   60,   61,   62,   63,  130,   64,   65,   44,   21,   66,
  214,    0,    0,    0,  100,   60,   61,   62,   63,    0,
   64,   65,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,  112,  112,  112,  112,  101,
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
    6,    7,    8,    9,   10,   11,   73,    0,  113,    0,
    0,  113,    0,    0,  113,    0,  132,  132,    0,   73,
  132,  132,  132,  132,  132,    0,  132,  190,  113,  113,
    0,    0,   73,  113,    0,    0,  193,  132,  132,  132,
  132,  132,  132,   73,  155,  155,    0,  155,    0,  155,
  155,  155,  155,    0,  155,    0,    0,  182,    0,    0,
   73,    0,    0,  113,  113,    0,  155,  155,  155,  155,
  155,    0,  132,  132,  224,  100,    0,    0,  100,   91,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
    0,    0,  100,  100,  113,  113,    0,    0,  155,    0,
    0,  155,    0,  132,  132,    0,    0,    0,    0,   59,
   60,   61,   62,   63,    0,   64,   65,    0,    0,    0,
    0,    0,    0,    0,  241,    0,    0,  100,    0,    0,
    0,  155,    0,    0,    0,    0,    0,   59,   60,   61,
   62,   63,    0,   64,   65,    0,    0,    0,    0,    0,
   59,   60,   61,   62,   63,    0,   64,   65,    0,  100,
    0,   66,    0,   59,   60,   61,   62,   63,    0,   64,
   65,    0,    0,    0,   59,   60,   61,   62,   63,  125,
   64,   65,  125,    0,  125,  125,  125,    0,    0,   66,
    0,   59,   60,   61,   62,   63,    0,   64,   65,  125,
  125,  125,   66,  125,  125,    0,  130,  130,    0,    0,
  130,  130,  130,  130,  130,   66,  130,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,  130,  130,  130,
    0,  130,  130,    0,  125,  125,    0,    0,    0,  113,
  113,  113,  113,   66,  132,  132,  132,  132,  132,  132,
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
    7,    8,    9,   10,   11,  119,  119,  119,  213,  119,
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
    0,  114,    0,  110,  114,    0,  110,  114,  129,  110,
    0,  116,  116,  115,  115,  115,  115,  115,  115,  117,
  117,  114,  114,  110,  110,    0,  114,  111,  110,    0,
  111,    0,  109,  111,    0,  109,  118,  118,  118,  118,
  118,  118,  116,  116,    0,    0,  178,  111,  111,  109,
  109,    0,  111,    0,  109,    0,  114,  114,  110,  110,
  129,    0,    0,    0,  119,  119,  119,  119,  119,  119,
  192,    0,    0,    0,  106,    0,  107,  106,    0,  107,
    0,    0,  111,  111,  109,  109,    0,  114,  114,  110,
  110,  106,  106,  107,  107,    0,  106,  212,  107,    0,
  105,    0,    0,  105,    0,    0,  218,  219,  220,    0,
    0,    0,    0,  111,  111,  109,  109,  105,  105,   93,
  102,    0,  105,  102,    0,    0,  106,  103,  107,    0,
  103,    0,    0,    0,  125,  126,    0,  102,  102,    0,
    0,    0,  102,    0,  103,  103,    0,   93,    0,  103,
    0,    0,  105,    0,    0,    0,    0,  106,  106,  107,
  107,    0,  117,  117,  117,  117,  117,  117,    0,    0,
    0,   93,  102,    0,  246,  248,    0,    0,    0,  103,
    0,    0,    0,    0,  105,  116,  116,  116,  116,  116,
  116,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  102,    0,    0,    0,    0,    0,
    0,  103,    0,   93,   93,   93,   93,   93,   93,   93,
   93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
   93,    0,  114,  114,  114,  114,  110,  110,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   93,    0,
  111,  111,  109,  109,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   93,  106,  106,  107,  107,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  105,  105,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  102,    0,    0,    0,    0,    0,    0,  103,
};
static const YYINT yycheck[] = {                         33,
   40,   40,   40,   63,   38,  174,   40,   44,   42,   43,
   33,   45,   71,   41,   25,   38,   44,   40,   44,   42,
   43,   59,   45,   40,   49,   59,    0,   77,   39,   41,
   58,   59,   44,   40,   45,   63,   10,   28,   12,   37,
   44,   43,   16,   45,   42,   56,   58,   59,  123,   47,
   91,   63,   33,  222,   60,   59,   62,   38,  106,   40,
   38,   42,   43,   33,   45,   93,   94,   93,   38,  117,
   40,   44,   42,   43,   91,   45,  101,   51,   59,   40,
   41,   93,   61,   44,   44,   61,   59,   41,  125,  123,
   44,  125,  126,  143,  144,  145,  124,  125,   59,   59,
  123,   15,  125,  126,   95,   33,   41,   44,   44,   23,
   38,   41,   40,  125,   42,   43,  124,   45,  271,  167,
   33,  169,   59,   59,   93,   38,  185,   40,   94,   42,
   43,   59,   45,   47,   38,   41,   41,   41,  188,   44,
   44,   44,  123,   40,  125,  126,   59,   44,  125,   41,
  123,   44,   44,  123,   58,   59,  126,   41,   41,   63,
   44,   44,   59,   41,   61,   58,   44,   59,  216,   61,
   58,   41,   41,   33,   44,   44,   41,   58,   38,   44,
   40,   40,   42,   43,   40,   45,  265,  266,   40,   93,
   94,  165,  269,  270,   91,  123,   40,  245,  126,  247,
  150,  151,  152,  153,  146,  147,  254,  300,  233,   59,
  123,   59,  272,  126,   41,  226,  302,  257,  257,  257,
  124,  125,   58,  257,  258,  259,  260,  261,   40,  263,
  264,  125,  243,  244,  257,  258,  259,  260,  261,   59,
  263,  264,   41,  271,  272,  125,  263,  264,  123,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  271,
  272,  267,  268,  297,  298,  299,  126,  301,  302,  303,
  304,  156,  306,  307,  308,  309,  257,  258,  259,  260,
  261,  157,  263,  264,  148,  149,  309,  257,  258,  259,
  260,  261,  123,  263,  264,  123,  257,  273,  274,  275,
  276,  277,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  154,  155,  159,  158,  297,  298,  299,  160,
  301,  302,  303,  304,   47,  306,  307,  308,  309,  257,
  258,  259,  260,  261,   72,  263,  264,   29,   12,  309,
  165,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
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
   63,   -1,   93,   94,  180,   41,   -1,   -1,   44,  185,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  292,
   -1,   -1,   58,   59,  124,  125,   -1,   -1,   91,   -1,
   -1,   94,   -1,  124,  125,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  230,   -1,   -1,   93,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,  264,   -1,  125,
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
"$$12 :",
"iteration_statement : WHILE '(' expression ')' $$12 statement",
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
"$$13 :",
"func_definitor : IDENTIFIER $$13 func_param_list",
"$$14 :",
"func_param_list : '(' $$14 parameter_type_list ')'",
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
#line 560 "parser.y"

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
	fprintf(fptr, "\tsw s0, -4(sp)\n");
	fprintf(fptr, "\taddi sp, sp, -4\n");
	fprintf(fptr, "\taddi s0, sp, 0\n");
	fprintf(fptr, "\tsw sp, -4(s0)\n");
	int i;
	for(i=1; i<12; i++)
		fprintf(fptr, "\tsw s%d, %d(s0)\n", i, -4+(-4)*i);
	fprintf(fptr, "\taddi sp, s0, %d\n", -48);
	fprintf(fptr, "\n");
}

void funcEnd(char* name) {
	int i;
	for(i=11; i>=1; i--)
		fprintf(fptr, "\tlw s%d, %d(s0)\n", i, -4+(-4)*i);
	fprintf(fptr, "\tlw sp, -4(s0)\n");
	fprintf(fptr, "\taddi sp, sp, 4\n");
	fprintf(fptr, "\tlw s0, -4(sp)\n");	
	fprintf(fptr, "\n");
	fprintf(fptr, "\tjalr zero, 0(ra)\n");
	offset = 0;
}

void callFunc(char* name, int cnt) {
	//printf("%s's argc: %d", name, cnt);
	int i;
	for(i=cnt-1; i>=0; i--) {
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
#line 1022 "y.tab.c"

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
	{ 
		fprintf(fptr, "Exit:\n");
	}
break;
case 28:
#line 160 "parser.y"
	{ }
break;
case 29:
#line 161 "parser.y"
	{ }
break;
case 30:
#line 162 "parser.y"
	{ }
break;
case 31:
#line 165 "parser.y"
	{ }
break;
case 32:
#line 166 "parser.y"
	{ }
break;
case 33:
#line 167 "parser.y"
	{ }
break;
case 34:
#line 170 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tli t1, 0\n");
		fprintf(fptr, "\tbeq t0 t1, Else\n");
		cur_scope++; 
	}
break;
case 35:
#line 176 "parser.y"
	{ 
		fprintf(fptr, "\tj Exit\n");
		fprintf(fptr, "Else:\n");
	}
break;
case 36:
#line 180 "parser.y"
	{ 
		cur_scope++; 
	}
break;
case 37:
#line 182 "parser.y"
	{ 
	}
break;
case 38:
#line 184 "parser.y"
	{ cur_scope++; }
break;
case 39:
#line 184 "parser.y"
	{ }
break;
case 40:
#line 187 "parser.y"
	{
		fprintf(fptr, "Loop:\n");
	}
break;
case 41:
#line 189 "parser.y"
	{ 
		fprintf(fptr, "\tbeq , , Loop");
	}
break;
case 42:
#line 192 "parser.y"
	{ }
break;
case 43:
#line 193 "parser.y"
	{ }
break;
case 44:
#line 194 "parser.y"
	{ }
break;
case 45:
#line 197 "parser.y"
	{ }
break;
case 46:
#line 198 "parser.y"
	{ }
break;
case 47:
#line 199 "parser.y"
	{ }
break;
case 48:
#line 200 "parser.y"
	{ }
break;
case 49:
#line 203 "parser.y"
	{ }
break;
case 50:
#line 204 "parser.y"
	{ }
break;
case 51:
#line 208 "parser.y"
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
#line 218 "parser.y"
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
#line 229 "parser.y"
	{ }
break;
case 54:
#line 230 "parser.y"
	{ }
break;
case 55:
#line 231 "parser.y"
	{ }
break;
case 56:
#line 234 "parser.y"
	{ yyval.sval="void"; 	}
break;
case 57:
#line 235 "parser.y"
	{ yyval.sval="char"; 	}
break;
case 58:
#line 236 "parser.y"
	{ yyval.sval="short"; 	}
break;
case 59:
#line 237 "parser.y"
	{ yyval.sval="int"; 	}
break;
case 60:
#line 238 "parser.y"
	{ yyval.sval="long"; 	}
break;
case 61:
#line 239 "parser.y"
	{ yyval.sval="float"; 	}
break;
case 62:
#line 240 "parser.y"
	{ yyval.sval="double"; 	}
break;
case 63:
#line 241 "parser.y"
	{ yyval.sval="signed"; 	}
break;
case 64:
#line 242 "parser.y"
	{ yyval.sval="unsigned";}
break;
case 65:
#line 245 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 66:
#line 246 "parser.y"
	{ }
break;
case 67:
#line 249 "parser.y"
	{ }
break;
case 68:
#line 250 "parser.y"
	{ type=T_FUNCTION; yyval.sval=yystack.l_mark[0].sval; }
break;
case 69:
#line 251 "parser.y"
	{ 
		symbol* id = lookup(yystack.l_mark[-2].sval);
		/*fprintf(fptr, "\tsw  t0, %d(fp) \n", id->offset*(-4)-8);*/
		/*fprintf(fptr, "\n");*/
	}
break;
case 70:
#line 258 "parser.y"
	{ 
		symbol* f = install(yystack.l_mark[0].sval);
		f->type = T_FUNCTION;
		yyval.sval=yystack.l_mark[0].sval;
	}
break;
case 71:
#line 262 "parser.y"
	{ yyval.sval=yystack.l_mark[-2].sval; }
break;
case 72:
#line 265 "parser.y"
	{ cur_scope++; }
break;
case 73:
#line 265 "parser.y"
	{ cur_scope--; }
break;
case 74:
#line 266 "parser.y"
	{}
break;
case 75:
#line 269 "parser.y"
	{ }
break;
case 76:
#line 272 "parser.y"
	{ install(yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval;}
break;
case 77:
#line 273 "parser.y"
	{ }
break;
case 78:
#line 274 "parser.y"
	{ install(yystack.l_mark[-3].sval); if(type!=3) type=1; }
break;
case 79:
#line 277 "parser.y"
	{ }
break;
case 80:
#line 278 "parser.y"
	{ }
break;
case 81:
#line 281 "parser.y"
	{ }
break;
case 82:
#line 282 "parser.y"
	{ }
break;
case 83:
#line 285 "parser.y"
	{ }
break;
case 84:
#line 286 "parser.y"
	{ }
break;
case 85:
#line 289 "parser.y"
	{ }
break;
case 86:
#line 290 "parser.y"
	{ }
break;
case 87:
#line 291 "parser.y"
	{ }
break;
case 88:
#line 294 "parser.y"
	{ }
break;
case 89:
#line 295 "parser.y"
	{ }
break;
case 90:
#line 298 "parser.y"
	{ }
break;
case 91:
#line 299 "parser.y"
	{ }
break;
case 92:
#line 302 "parser.y"
	{ }
break;
case 93:
#line 303 "parser.y"
	{
		/*printf("%s = %d", );*/
 	}
break;
case 94:
#line 308 "parser.y"
	{ }
break;
case 95:
#line 309 "parser.y"
	{ }
break;
case 96:
#line 310 "parser.y"
	{ }
break;
case 97:
#line 311 "parser.y"
	{ }
break;
case 98:
#line 312 "parser.y"
	{ }
break;
case 99:
#line 313 "parser.y"
	{ }
break;
case 100:
#line 316 "parser.y"
	{ }
break;
case 101:
#line 317 "parser.y"
	{ }
break;
case 102:
#line 320 "parser.y"
	{ }
break;
case 103:
#line 321 "parser.y"
	{ }
break;
case 104:
#line 324 "parser.y"
	{ }
break;
case 105:
#line 325 "parser.y"
	{ }
break;
case 106:
#line 328 "parser.y"
	{ }
break;
case 107:
#line 329 "parser.y"
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
case 108:
#line 341 "parser.y"
	{ }
break;
case 109:
#line 342 "parser.y"
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
case 110:
#line 354 "parser.y"
	{ }
break;
case 111:
#line 355 "parser.y"
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
case 112:
#line 367 "parser.y"
	{ }
break;
case 113:
#line 368 "parser.y"
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
case 114:
#line 378 "parser.y"
	{ }
break;
case 115:
#line 381 "parser.y"
	{ }
break;
case 116:
#line 382 "parser.y"
	{ }
break;
case 117:
#line 383 "parser.y"
	{ }
break;
case 118:
#line 384 "parser.y"
	{ }
break;
case 119:
#line 385 "parser.y"
	{ }
break;
case 120:
#line 388 "parser.y"
	{ }
break;
case 121:
#line 389 "parser.y"
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
case 122:
#line 399 "parser.y"
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
case 123:
#line 411 "parser.y"
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
#line 421 "parser.y"
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
#line 431 "parser.y"
	{ }
break;
case 126:
#line 434 "parser.y"
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
#line 444 "parser.y"
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
#line 454 "parser.y"
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
#line 464 "parser.y"
	{ }
break;
case 130:
#line 467 "parser.y"
	{ }
break;
case 131:
#line 468 "parser.y"
	{ }
break;
case 132:
#line 471 "parser.y"
	{ }
break;
case 133:
#line 472 "parser.y"
	{ }
break;
case 134:
#line 473 "parser.y"
	{ }
break;
case 135:
#line 474 "parser.y"
	{ }
break;
case 136:
#line 477 "parser.y"
	{ }
break;
case 137:
#line 478 "parser.y"
	{ }
break;
case 138:
#line 479 "parser.y"
	{ }
break;
case 139:
#line 480 "parser.y"
	{ }
break;
case 140:
#line 481 "parser.y"
	{ }
break;
case 141:
#line 482 "parser.y"
	{ }
break;
case 142:
#line 485 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 143:
#line 486 "parser.y"
	{ printf("%s\n", yystack.l_mark[0].sval); yyval.sval=yystack.l_mark[0].sval; }
break;
case 144:
#line 487 "parser.y"
	{ }
break;
case 145:
#line 488 "parser.y"
	{ callFunc(yystack.l_mark[-2].sval, 0); }
break;
case 146:
#line 489 "parser.y"
	{ callFunc(yystack.l_mark[-3].sval, argc); }
break;
case 147:
#line 490 "parser.y"
	{ 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, 1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
break;
case 148:
#line 498 "parser.y"
	{
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, -1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	
	}
break;
case 149:
#line 509 "parser.y"
	{ argc++; }
break;
case 150:
#line 510 "parser.y"
	{ argc++; }
break;
case 151:
#line 513 "parser.y"
	{ }
break;
case 152:
#line 514 "parser.y"
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
#line 523 "parser.y"
	{
		
	}
break;
case 154:
#line 526 "parser.y"
	{
		
	}
break;
case 155:
#line 529 "parser.y"
	{
		symbol* id = lookup(yystack.l_mark[0].sval);
		symbol* f = NULL;
		if(id!=NULL) {
			switch(id->mode) {
				case ARGUMENT_MODE:					
					f = lookup(id->funcName);
					fprintf(fptr, "\tlw t0, %d(s0)\n", f->totalArgs *(-4)-48 +id->offset*(-4)-4);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t0, 0(sp)\n");
				break;
		  		case LOCAL_MODE:
					fprintf(fptr, "\tlw  t0, %d(s0) \n",id->offset*(-4)-48);
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
#line 556 "parser.y"
	{ }
break;
#line 2068 "y.tab.c"
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
