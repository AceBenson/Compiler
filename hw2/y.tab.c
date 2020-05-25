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
	int yylex();
	extern int errline;
	char* get_buf();
	int type=0;
#line 11 "parser.y"
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "y.tab.c"

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
    0,   46,   46,   45,   45,   44,   44,   44,   44,   39,
   39,   23,   23,   24,   24,   24,   24,   21,   21,   21,
   21,   21,   21,   28,   28,   28,   25,   25,   25,   27,
   27,   27,   27,   26,   26,   26,   26,   20,   20,   30,
   30,   31,   31,   31,   34,   34,   34,   34,   34,   34,
   34,   34,   34,   32,   32,   33,   33,   35,   38,   38,
   38,   38,   38,   38,   41,   41,   42,   42,   43,   43,
   40,   40,   36,   36,   36,   37,   37,   19,   19,   18,
   18,   29,   29,   29,   29,   29,   29,   17,   17,   16,
   16,   15,   15,   14,   14,   13,   13,   12,   12,   11,
   11,   11,   10,   10,   10,   10,   10,    9,    9,    9,
    8,    8,    8,    7,    7,    7,    7,    6,    6,    5,
    5,    5,    5,    4,    4,    4,    4,    4,    4,    3,
    3,    3,    3,    3,    3,    3,   22,   22,    2,    2,
    2,    2,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    3,    4,    2,    3,    1,
    2,    2,    3,    1,    1,    2,    2,    1,    1,    1,
    1,    1,    1,    3,    4,    3,    5,    7,    5,    5,
    7,    6,    7,    2,    2,    2,    3,    1,    2,    2,
    3,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    3,    1,    1,    3,
    4,    4,    4,    3,    1,    3,    1,    3,    2,    1,
    1,    3,    1,    3,    4,    1,    3,    1,    3,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    5,    1,
    3,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    3,    1,    3,    3,    3,    3,    1,    3,    3,
    3,    3,    1,    3,    3,    3,    1,    1,    4,    1,
    2,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    4,    3,    4,    2,    2,    1,    3,    3,    1,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   59,   46,   47,   48,   49,   52,   53,   50,   51,    0,
   45,    0,    0,    5,    0,    0,    0,    0,    4,    2,
    0,   44,    0,   40,    0,   54,    0,   43,    0,    8,
   10,    0,    0,    0,    0,    3,   60,   41,    0,    0,
    6,    0,    0,  145,  143,  144,  142,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  131,
   38,  124,  126,  127,  125,   12,    0,  128,  129,  140,
  130,    0,    0,    0,  117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   80,   78,    0,   19,   14,
   18,    0,   20,   23,   22,   21,   15,    0,    9,   11,
   71,   64,    0,    0,    0,    0,   67,  141,  118,    0,
   55,    0,   73,   57,    7,    0,    0,  121,  122,    0,
    0,    0,    0,    0,    0,    0,   34,   35,   36,    0,
    0,    0,  135,  136,    0,    0,  123,   83,   84,   85,
   86,   87,   82,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   39,    0,   13,   16,   17,   69,    0,
   62,   63,    0,   61,   76,    0,   24,    0,   26,    0,
    0,    0,    0,    0,   37,  139,    0,  133,  137,    0,
    0,   81,  114,  115,  116,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   79,   72,   66,   68,    0,   74,   25,    0,    0,
    0,    0,    0,  119,    0,  134,  132,    0,   75,   77,
    0,   29,   30,    0,    0,    0,  138,   89,    0,    0,
   32,    0,   28,   31,   33,
};
static const YYINT yydgoto[] = {                         13,
   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,  190,   91,   92,   93,   94,   95,   96,  144,   14,
   32,   25,   26,   16,   17,  114,  176,   18,   33,  104,
  105,  106,  107,   19,   20,   21,
};
static const YYINT yysindex[] = {                       221,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1009,
    0,  -39,    0,    0,  -37, 1009,  471,   -3,    0,    0,
  221,    0,    4,    0,   -5,    0,  690,    0,  -33,    0,
    0,  -37,  471,  245,  439,    0,    0,    0,  -39,   31,
    0,  471,    1,    0,    0,    0,    0,  455,  455,  439,
   14,    7,   60,   79,   88,   85,   70,   81,  373,    0,
    0,    0,    0,    0,    0,    0,  141,    0,    0,    0,
    0,  -16,  439,   23,    0,   52,  -30, -214,  -35, -192,
  104,   54,   35, -113,  -59,    0,    0,   -2,    0,    0,
    0,   20,    0,    0,    0,    0,    0,  105,    0,    0,
    0,    0,  -39,   -1,  129,  127,    0,    0,    0,   80,
    0,   31,    0,    0,    0,   88,  439,    0,    0,  114,
   88,  439,  439,  439, -127,  401,    0,    0,    0,    2,
   61,  136,    0,    0,  414,  439,    0,    0,    0,    0,
    0,    0,    0,  439,  439,  439,  439,  439,  439,  439,
  439,  439,  439,  439,  439,  439,  439,  439,  439,  439,
  439,  439,  439,    0,  439,    0,    0,    0,    0,  -79,
    0,    0,  621,    0,    0,  -42,    0,   88,    0,   68,
   76,   83,  140,  401,    0,    0,  439,    0,    0,   93,
   -6,    0,    0,    0,    0,   52,   52,  -30,  -30, -214,
 -214, -214, -214,  -35,  -35, -192,  104,   54,   35, -113,
   -9,    0,    0,    0,    0,  -22,    0,    0,   59,   59,
   88,  439,  428,    0,  439,    0,    0,  439,    0,    0,
 -115,    0,    0,   95,   88,  108,    0,    0,   59,  128,
    0,   88,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -11,    0,  482,    0,    0,
  188,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  515,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  555,    0,  683,    0,  528,  832,  900,   97, 1191,
  -27, 1217, 1285, 1310,  526,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,  109,    0,    0,  148,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  795,  803,  840,  877,  928,
  954,  996, 1092, 1115, 1189, 1215, 1117, 1228, 1287, 1350,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   73,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0, 1357,  -65,  -53,  -43,   10,   12,
   36,   33,   37,   32,   38,    0,    6,  -21,  959,  -98,
  764,    0,  134,    0,    0,    0,    0,    0,    0, 1002,
   34,    0,  162,  135,  507, -106,    0,    0,  176,    0,
    0,    0,   39,    0,  184,    0,
};
#define YYTABLESIZE 1622
static const YYINT yytable[] = {                         69,
   12,  216,   12,  163,   62,  175,   67,  137,   65,   63,
   69,   64,  148,   96,  149,   62,   96,   67,  113,   65,
   63,   24,   64,  135,  155,   61,  154,  184,   42,   42,
   96,   96,   42,   15,  165,   96,   34,  165,   39,  171,
  110,  165,  170,   22,   37,  165,  122,   42,  228,   28,
  150,  151,   69,   38,   15,  120,  164,   62,  116,   67,
  185,   65,   63,   69,   64,   96,   96,  103,   62,   56,
   67,  121,   65,   63,  136,   64,  156,  157,   61,  193,
  194,  195,  217,  143,   56,  223,  227,   35,  147,   29,
  113,   66,   68,  145,  196,  197,   96,   96,  146,  123,
  112,  186,  229,   68,  165,   27,  198,  199,  219,  230,
   27,  165,   27,  189,   27,   27,  220,   27,  124,  165,
   69,  224,  192,  221,  126,   62,  165,   67,  127,   65,
   63,   27,   64,  226,  100,  240,  225,  100,  165,  128,
  100,  158,   29,  212,  166,   68,   61,  159,  242,   70,
   30,  165,   70,  112,  100,  100,   68,  161,  160,  100,
   41,  200,  201,  202,  203,   40,   99,  204,  205,  172,
  173,  178,  174,   69,  183,  115,  187,  213,   62,  222,
   67,   29,   65,   63,  239,   64,  244,    1,   65,  100,
  100,  207,  209,  206,  113,   27,  208,   27,   27,  210,
  111,  132,   42,  237,   36,    0,  103,    0,    0,    0,
   29,  215,  162,   68,    0,    0,    0,    1,    0,    1,
  100,  100,    0,   43,   44,   45,   46,   47,    0,   48,
   49,  152,  153,  238,  108,   44,   45,   46,   47,    0,
   48,   49,    0,   96,   96,   42,  133,  134,    0,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,    0,
   12,    0,    0,   50,   51,   52,   68,   53,   54,   55,
   56,    0,   57,   58,   59,   60,   43,   44,   45,   46,
   47,    0,   48,   49,    0,  102,   60,  108,   44,   45,
   46,   47,    0,   48,   49,  138,  139,  140,  141,  142,
    0,    0,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,    0,    0,    0,    0,   50,   51,   52,    0,
   53,   54,   55,   56,    0,   57,   58,   59,   60,   27,
   27,   27,   27,   27,    0,   27,   27,    0,    0,   60,
    0,    0,    0,    0,   43,   44,   45,   46,   47,    0,
   48,   49,  231,  232,    0,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,  100,  100,  100,  100,   27,
   27,   27,  243,   27,   27,   27,   27,    0,   27,   27,
   27,   27,    0,    0,   50,   51,   52,    0,   53,   54,
   55,   56,    0,   57,   58,   59,   60,  108,   44,   45,
   46,   47,    0,   48,   49,   69,    0,    0,    0,    0,
   62,    0,   67,    0,   65,   63,    0,   64,    0,    0,
    0,    0,    0,    2,    3,    4,    5,    6,    7,    8,
    9,  129,   11,   69,    0,    0,    0,    0,   62,    0,
   67,    0,   65,   63,    0,   64,   69,    0,    0,   60,
    0,   62,    0,   67,  188,   65,   63,    0,   64,   61,
   69,    0,    0,    0,    0,   62,    0,   67,  235,   65,
   63,   69,   64,    0,    0,    0,   62,    1,   67,    0,
   65,   63,    0,   64,    0,    0,    0,   69,    0,    0,
    0,    0,   62,    0,  117,    0,   65,   63,   68,   64,
    0,  101,    0,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   11,    0,    0,    0,    0,    0,   23,    0,
    0,   27,   58,    0,    0,   58,   68,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,    0,   98,   68,
   58,    0,   58,    0,    0,   98,    0,    0,    0,    0,
    0,  141,  141,   68,  141,    0,  141,  141,  141,  141,
    0,  141,    0,    0,   68,  113,   88,    0,  113,   88,
  113,  113,  113,  141,  141,  141,  141,  141,    0,    0,
   68,    0,    0,   88,   88,  113,  113,  113,    0,  113,
  113,  120,  120,   29,    0,  120,  120,  120,  120,  120,
    0,  120,    0,    0,   58,  141,    0,    0,  141,  169,
    0,    0,  120,  120,  120,  120,  120,  120,   88,    0,
  113,  113,    0,    0,    0,    0,    0,    0,    0,  108,
   44,   45,   46,   47,    0,   48,   49,    0,  141,    0,
    0,    0,    0,    0,    0,    0,    0,  120,  120,    0,
   88,  113,  113,    0,    0,    0,    0,  108,   44,   45,
   46,   47,    0,   48,   49,    0,    0,    0,    0,    0,
  108,   44,   45,   46,   47,    0,   48,   49,  120,  120,
    0,   60,    0,    0,  108,   44,   45,   46,   47,    0,
   48,   49,    0,    0,    0,  108,   44,   45,   46,   47,
    0,   48,   49,    0,    0,    0,    0,    0,    0,   60,
    0,  108,   44,   45,   46,   47,    0,   48,   49,  118,
  118,    0,   60,  118,  118,  118,  118,  118,    0,  118,
    0,    0,    0,    0,    0,    0,   60,    0,    0,    0,
  118,  118,  118,    0,  118,  118,    0,   60,    0,    0,
   40,    0,    0,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   11,   60,   58,   58,   58,   58,   58,   58,
   58,   58,   58,   58,    0,  118,  118,  141,  141,  141,
  141,  141,  141,  141,  141,  141,  141,  141,  141,  141,
  141,  141,  113,  113,  113,  113,  113,  113,  113,  113,
    0,    0,    0,    0,    0,    0,  118,  118,    0,    0,
    0,    0,   29,    0,    0,    0,    0,    0,  125,  120,
  120,  120,  120,  120,  120,  120,  120,  120,  120,  120,
  120,  120,  111,    0,    0,  111,    0,  111,  111,  111,
  112,    0,    0,  112,    0,  112,  112,  112,    0,    0,
    0,    0,  111,  111,  111,  167,  111,  111,    0,    0,
  112,  112,  112,    0,  112,  112,    0,    0,    0,  108,
    0,    0,  108,    0,    0,  108,    0,  109,    0,  177,
  109,    0,    0,  109,  179,    0,    0,  111,  111,  108,
  108,  108,    0,  108,  108,  112,  112,  109,  109,  109,
    0,  109,  109,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   11,    0,  110,    0,  214,  110,  111,  111,
  110,    0,    0,    0,  108,  108,  112,  112,    0,    0,
    0,    0,  109,  109,  110,  110,  110,  103,  110,  110,
  103,  218,    0,  103,    0,    0,    0,  118,  118,  118,
  118,  118,  118,  118,  118,  108,  108,  103,  103,  103,
    0,  103,  103,  109,  109,  106,    0,    0,  106,  110,
  110,  106,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,    0,    0,  233,  106,  106,  106,    0,  106,
  106,  107,  103,  103,  107,    0,    0,  107,  241,    0,
  110,  110,    0,    0,    0,  245,    0,    0,    0,    0,
    0,  107,  107,  107,    0,  107,  107,  130,   31,    0,
  106,  106,    0,  103,  103,  131,    0,    0,   31,    0,
   97,    0,    0,  105,  100,    0,  105,    0,    0,  105,
    0,    0,    0,  100,    0,    0,  107,  107,    0,    0,
    0,  106,  106,  105,  105,  105,    0,  105,  105,  111,
  111,  111,  111,  111,  111,  111,  111,  112,  112,  112,
  112,  112,  112,  112,  112,  131,    0,  107,  107,    0,
  180,  181,  182,    0,    0,    0,    0,    0,  105,  105,
    0,    0,    0,  168,  191,    0,  108,  108,  108,  108,
  108,  108,  108,  108,  109,  109,  109,  109,  109,  109,
  109,  109,    0,    0,    0,    0,    0,    0,    0,  105,
  105,  211,    0,    0,    0,    0,    0,    0,    0,  104,
    0,    0,  104,    0,    0,  104,    0,    0,    0,    0,
    0,  110,  110,  110,  110,  110,  110,  110,  110,  104,
  104,  104,  101,  104,  104,  101,    0,   97,  101,    0,
   97,    0,    0,    0,    0,    0,  103,  103,  103,  103,
  103,  103,  101,  101,   97,   97,    0,  101,    0,   97,
  234,  236,    0,    0,  104,  104,    0,    0,    0,    0,
    0,    0,    0,    0,  106,  106,  106,  106,  106,  106,
    0,    0,    0,    0,    0,    0,    0,  101,  101,   97,
   97,    0,    0,    0,    0,  104,  104,    0,    0,    0,
  107,  107,  107,  107,  107,  107,  102,    0,   98,  102,
    0,   98,  102,    0,   98,    0,    0,    0,  101,  101,
   97,   97,    0,    0,    0,    0,  102,  102,   98,   98,
    0,  102,   99,   98,    0,   99,    0,   94,   99,    0,
   94,    0,  105,  105,  105,  105,  105,  105,   95,    0,
    0,   95,   99,   99,   94,   94,    0,   99,    0,   94,
    0,  102,  102,   98,   98,   95,   95,    0,    0,    0,
   95,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,    0,    0,    0,    0,    0,    0,   99,   99,   94,
    0,    0,  102,  102,   98,   98,    0,    0,    0,    0,
   95,    0,    0,    0,    0,   92,    0,   93,   92,    0,
   93,    0,    0,    0,    0,    0,    0,    0,   99,   99,
   94,   94,   92,   92,   93,   93,    0,   92,    0,   93,
   90,   95,   95,   90,    0,    0,    0,    0,  104,  104,
  104,  104,  104,  104,    0,    0,    0,   90,   90,    0,
    0,    0,   90,    0,    0,    0,    0,   92,    0,   93,
    0,    0,    0,  101,  101,  101,  101,   97,   97,    0,
   91,  109,    0,   91,    0,    0,    0,    0,    0,    0,
    0,    0,   90,    0,  118,  119,  109,   91,   91,   92,
    0,   93,   91,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  109,
    0,    0,    0,    0,   90,    0,    0,    0,    0,    0,
    0,    0,   91,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  102,  102,  102,
  102,   98,   98,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   91,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,   99,   94,   94,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,   95,
    0,  109,  109,  109,  109,  109,  109,  109,  109,  109,
  109,  109,  109,  109,  109,  109,  109,  109,  109,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  109,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   92,   92,   93,   93,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   90,    0,    0,  109,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   91,
};
static const YYINT yycheck[] = {                         33,
   40,   44,   40,   63,   38,  112,   40,   73,   42,   43,
   33,   45,   43,   41,   45,   38,   44,   40,   40,   42,
   43,   59,   45,   40,   60,   59,   62,  126,   40,   41,
   58,   59,   44,    0,   44,   63,   40,   44,   44,   41,
   35,   44,   44,   10,   41,   44,   40,   59,   58,   16,
  265,  266,   33,   59,   21,   50,   59,   38,   58,   40,
   59,   42,   43,   33,   45,   93,   94,   34,   38,   44,
   40,   58,   42,   43,   91,   45,  269,  270,   59,  145,
  146,  147,  125,   61,   59,  184,   93,   91,   37,  123,
  112,  125,  126,   42,  148,  149,  124,  125,   47,   40,
  123,   41,  125,  126,   44,   33,  150,  151,   41,  216,
   38,   44,   40,  135,   42,   43,   41,   45,   40,   44,
   33,  187,  144,   41,   40,   38,   44,   40,   59,   42,
   43,   59,   45,   41,   38,   41,   44,   41,   44,   59,
   44,   38,  123,  165,  125,  126,   59,   94,   41,   41,
   17,   44,   44,  123,   58,   59,  126,  271,  124,   63,
   27,  152,  153,  154,  155,   61,   33,  156,  157,   41,
   44,   58,   93,   33,  302,   42,   41,  257,   38,   40,
   40,  123,   42,   43,  300,   45,   59,    0,   41,   93,
   94,  159,  161,  158,  216,  123,  160,  125,  126,  162,
   39,   67,   27,  225,   21,   -1,  173,   -1,   -1,   -1,
  123,  173,  272,  126,   -1,   -1,   -1,  257,   -1,  257,
  124,  125,   -1,  257,  258,  259,  260,  261,   -1,  263,
  264,  267,  268,  228,  257,  258,  259,  260,  261,   -1,
  263,  264,   -1,  271,  272,  257,  263,  264,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,   -1,
   40,   -1,   -1,  297,  298,  299,  126,  301,  302,  303,
  304,   -1,  306,  307,  308,  309,  257,  258,  259,  260,
  261,   -1,  263,  264,   -1,   41,  309,  257,  258,  259,
  260,  261,   -1,  263,  264,  273,  274,  275,  276,  277,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,
  301,  302,  303,  304,   -1,  306,  307,  308,  309,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,  309,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
  263,  264,  219,  220,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  269,  270,  271,  272,  297,
  298,  299,  239,  301,  302,  303,  304,   -1,  306,  307,
  308,  309,   -1,   -1,  297,  298,  299,   -1,  301,  302,
  303,  304,   -1,  306,  307,  308,  309,  257,  258,  259,
  260,  261,   -1,  263,  264,   33,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   59,  292,   33,   -1,   -1,   -1,   -1,   38,   -1,
   40,   -1,   42,   43,   -1,   45,   33,   -1,   -1,  309,
   -1,   38,   -1,   40,   41,   42,   43,   -1,   45,   59,
   33,   -1,   -1,   -1,   -1,   38,   -1,   40,   41,   42,
   43,   33,   45,   -1,   -1,   -1,   38,  257,   40,   -1,
   42,   43,   -1,   45,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   43,  126,   45,
   -1,  257,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,   -1,   -1,   -1,   -1,   -1,   12,   -1,
   -1,   15,   41,   -1,   -1,   44,  126,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,   -1,   32,  126,
   59,   -1,   61,   -1,   -1,   39,   -1,   -1,   -1,   -1,
   -1,   37,   38,  126,   40,   -1,   42,   43,   44,   45,
   -1,   47,   -1,   -1,  126,   38,   41,   -1,   41,   44,
   43,   44,   45,   59,   60,   61,   62,   63,   -1,   -1,
  126,   -1,   -1,   58,   59,   58,   59,   60,   -1,   62,
   63,   37,   38,  123,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,  123,   91,   -1,   -1,   94,  103,
   -1,   -1,   58,   59,   60,   61,   62,   63,   93,   -1,
   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,
  125,  124,  125,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,  264,  124,  125,
   -1,  309,   -1,   -1,  257,  258,  259,  260,  261,   -1,
  263,  264,   -1,   -1,   -1,  257,  258,  259,  260,  261,
   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,  309,
   -1,  257,  258,  259,  260,  261,   -1,  263,  264,   37,
   38,   -1,  309,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,  309,   -1,   -1,   -1,
   58,   59,   60,   -1,   62,   63,   -1,  309,   -1,   -1,
   61,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  309,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,   -1,   93,   94,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  276,  277,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,   -1,   -1,
   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,   55,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  276,  277,   38,   -1,   -1,   41,   -1,   43,   44,   45,
   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   -1,   58,   59,   60,   92,   62,   63,   -1,   -1,
   58,   59,   60,   -1,   62,   63,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   38,   -1,  116,
   41,   -1,   -1,   44,  121,   -1,   -1,   93,   94,   58,
   59,   60,   -1,   62,   63,   93,   94,   58,   59,   60,
   -1,   62,   63,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,   -1,   38,   -1,  296,   41,  124,  125,
   44,   -1,   -1,   -1,   93,   94,  124,  125,   -1,   -1,
   -1,   -1,   93,   94,   58,   59,   60,   38,   62,   63,
   41,  178,   -1,   44,   -1,   -1,   -1,  265,  266,  267,
  268,  269,  270,  271,  272,  124,  125,   58,   59,   60,
   -1,   62,   63,  124,  125,   38,   -1,   -1,   41,   93,
   94,   44,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,   -1,   -1,  221,   58,   59,   60,   -1,   62,
   63,   38,   93,   94,   41,   -1,   -1,   44,  235,   -1,
  124,  125,   -1,   -1,   -1,  242,   -1,   -1,   -1,   -1,
   -1,   58,   59,   60,   -1,   62,   63,   59,   17,   -1,
   93,   94,   -1,  124,  125,   67,   -1,   -1,   27,   -1,
   29,   -1,   -1,   38,   33,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   42,   -1,   -1,   93,   94,   -1,   -1,
   -1,  124,  125,   58,   59,   60,   -1,   62,   63,  265,
  266,  267,  268,  269,  270,  271,  272,  265,  266,  267,
  268,  269,  270,  271,  272,  117,   -1,  124,  125,   -1,
  122,  123,  124,   -1,   -1,   -1,   -1,   -1,   93,   94,
   -1,   -1,   -1,   92,  136,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
  125,  163,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,  265,  266,  267,  268,  269,  270,  271,  272,   58,
   59,   60,   38,   62,   63,   41,   -1,   41,   44,   -1,
   44,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,   58,   59,   58,   59,   -1,   63,   -1,   63,
  222,  223,   -1,   -1,   93,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,   93,
   94,   -1,   -1,   -1,   -1,  124,  125,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,   38,   -1,   38,   41,
   -1,   41,   44,   -1,   44,   -1,   -1,   -1,  124,  125,
  124,  125,   -1,   -1,   -1,   -1,   58,   59,   58,   59,
   -1,   63,   38,   63,   -1,   41,   -1,   41,   44,   -1,
   44,   -1,  267,  268,  269,  270,  271,  272,   41,   -1,
   -1,   44,   58,   59,   58,   59,   -1,   63,   -1,   63,
   -1,   93,   94,   93,   94,   58,   59,   -1,   -1,   -1,
   63,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,   93,
   -1,   -1,  124,  125,  124,  125,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   41,   -1,   41,   44,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,
  124,  125,   58,   59,   58,   59,   -1,   63,   -1,   63,
   41,  124,  125,   44,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   58,   59,   -1,
   -1,   -1,   63,   -1,   -1,   -1,   -1,   93,   -1,   93,
   -1,   -1,   -1,  269,  270,  271,  272,  271,  272,   -1,
   41,   35,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   -1,   48,   49,   50,   58,   59,  125,
   -1,  125,   63,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   73,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,
  272,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  271,  272,  271,  272,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,  272,
   -1,  145,  146,  147,  148,  149,  150,  151,  152,  153,
  154,  155,  156,  157,  158,  159,  160,  161,  162,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  187,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  271,  272,  271,  272,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,   -1,  228,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 320
#define YYUNDFTOKEN 369
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
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : translation_unit",
"translation_unit : external_declaration",
"translation_unit : translation_unit external_declaration",
"external_declaration : function_definition",
"external_declaration : declaration",
"function_definition : declaration_specifiers declarator compound_statement",
"function_definition : declaration_specifiers declarator declaration_list compound_statement",
"function_definition : declarator compound_statement",
"function_definition : declarator declaration_list compound_statement",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"compound_statement : '{' '}'",
"compound_statement : '{' compound_list '}'",
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
"selection_statement : IF '(' expression ')' compound_statement",
"selection_statement : IF '(' expression ')' compound_statement ELSE compound_statement",
"selection_statement : SWITCH '(' expression ')' compound_statement",
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
"init_declarator : declarator '=' initializer",
"declarator : direct_declarator",
"direct_declarator : IDENTIFIER",
"direct_declarator : '(' declarator ')'",
"direct_declarator : direct_declarator '[' conditional_expression ']'",
"direct_declarator : direct_declarator '(' identifier_list ')'",
"direct_declarator : direct_declarator '(' parameter_type_list ')'",
"direct_declarator : direct_declarator '(' ')'",
"parameter_type_list : parameter_list",
"parameter_type_list : parameter_list ',' ELLIPSIS",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers declarator",
"parameter_declaration : declaration_specifiers",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list ',' IDENTIFIER",
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
"primary_expression : constant",
"primary_expression : IDENTIFIER",
"primary_expression : STRING_LITERAL",
"constant : CONSTANT",
"constant : CCONSTANT",
"constant : FCONSTANT",

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
#line 326 "parser.y"

char* get_buf()
{
	char* buf=(char*)malloc(sizeof(char)*10000);
	return buf;
}

char* get_nbuf(int n)
{
	char* buf = (char*)malloc(sizeof(char)*n);
	return buf;
}

int main()
{
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	printf("YACC> Error at line %d.\n", errline);
	return 0;
}
#line 838 "y.tab.c"

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
#line 63 "parser.y"
	{ printf("%s", yystack.l_mark[0].sval); free(yystack.l_mark[0].sval); }
break;
case 2:
#line 66 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 3:
#line 67 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 4:
#line 70 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 5:
#line 71 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 6:
#line 74 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s</func_def>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 7:
#line 75 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s%s</func_def>", yystack.l_mark[-3].sval, yystack.l_mark[-2].sval, yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-2].sval); free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 8:
#line 76 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s</func_def>", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 9:
#line 77 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s</func_def>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 10:
#line 80 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 11:
#line 81 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 12:
#line 84 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "{}"); yyval.sval=buf; }
break;
case 13:
#line 85 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "{%s}", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 14:
#line 88 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval;}
break;
case 15:
#line 89 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 16:
#line 90 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 17:
#line 91 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 18:
#line 94 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 19:
#line 95 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 20:
#line 96 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 21:
#line 97 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 22:
#line 98 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 23:
#line 99 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 24:
#line 102 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s:%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 25:
#line 103 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "case%s:%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 26:
#line 104 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "default:%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 27:
#line 107 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "if(%s)%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 28:
#line 108 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "if(%s)%selse%s", yystack.l_mark[-4].sval, yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-4].sval); free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 29:
#line 109 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "switch(%s)%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 30:
#line 112 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "while(%s)%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 31:
#line 113 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "do%swhile(%s);", yystack.l_mark[-5].sval, yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-5].sval); free(yystack.l_mark[-2].sval); }
break;
case 32:
#line 114 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "for(%s%s)%s", yystack.l_mark[-3].sval, yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 33:
#line 115 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "for(%s%s%s)%s", yystack.l_mark[-4].sval, yystack.l_mark[-3].sval, yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-4].sval); free(yystack.l_mark[-3].sval); free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 34:
#line 118 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "continue;"); yyval.sval=buf; }
break;
case 35:
#line 119 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "break;"); yyval.sval=buf; }
break;
case 36:
#line 120 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "return;"); yyval.sval=buf; }
break;
case 37:
#line 121 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "return%s;", yystack.l_mark[-1].sval); yyval.sval=buf;}
break;
case 38:
#line 124 "parser.y"
	{ char* buf=get_nbuf(2); strcpy(buf, ";"); yyval.sval=buf; }
break;
case 39:
#line 125 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s;", yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 40:
#line 129 "parser.y"
	{ 
		char* buf=get_buf();
		switch(type) { 
			case 0: sprintf(buf, "<scalar_decl>%s;</scalar_decl>", yystack.l_mark[-1].sval); break;
			case 1: sprintf(buf, "<array_decl>%s;</array_decl>", yystack.l_mark[-1].sval); break;
			case 2: sprintf(buf, "<func_decl>%s;</func_decl>", yystack.l_mark[-1].sval); break;
			case 3: sprintf(buf, "<const_decl>%s;</const_decl>", yystack.l_mark[-1].sval); break;
		}
		type=0;
		yyval.sval=buf;
		free(yystack.l_mark[-1].sval);
	}
break;
case 41:
#line 142 "parser.y"
	{ 
		char* buf=get_buf();
		switch(type) {
			case 0: sprintf(buf, "<scalar_decl>%s%s;</scalar_decl>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval); break;
			case 1: sprintf(buf, "<array_decl>%s%s;</array_decl>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval); break;
			case 2: sprintf(buf, "<func_decl>%s%s;</func_decl>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval); break;
			case 3: sprintf(buf, "<const_decl>%s%s;</const_decl>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval); break;		
		}
		type=0;
		yyval.sval=buf; 
		free(yystack.l_mark[-2].sval);
	}
break;
case 42:
#line 156 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 43:
#line 157 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 44:
#line 158 "parser.y"
	{ type=3; char* buf=get_buf(); sprintf(buf, "const%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 45:
#line 161 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "void"); yyval.sval=buf; }
break;
case 46:
#line 162 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "char"); yyval.sval=buf; }
break;
case 47:
#line 163 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "short"); yyval.sval=buf; }
break;
case 48:
#line 164 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "int"); yyval.sval=buf; }
break;
case 49:
#line 165 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "long"); yyval.sval=buf; }
break;
case 50:
#line 166 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "float"); yyval.sval=buf; }
break;
case 51:
#line 167 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "double"); yyval.sval=buf; }
break;
case 52:
#line 168 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "signed"); yyval.sval=buf; }
break;
case 53:
#line 169 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, "unsigned"); yyval.sval=buf; }
break;
case 54:
#line 172 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 55:
#line 173 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 56:
#line 176 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 57:
#line 177 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s=%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 58:
#line 180 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 59:
#line 183 "parser.y"
	{ if(type!=3) type=0; yyval.sval=yystack.l_mark[0].sval; }
break;
case 60:
#line 184 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "(%s)", yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 61:
#line 185 "parser.y"
	{ if(type!=3) type=1; char* buf = get_buf(); sprintf(buf, "%s[%s]", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 62:
#line 186 "parser.y"
	{ type=2; char* buf = get_buf(); sprintf(buf, "%s(%s)", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 63:
#line 187 "parser.y"
	{ type=2; char* buf = get_buf(); sprintf(buf, "%s(%s)", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 64:
#line 188 "parser.y"
	{ type=2; char* buf = get_buf(); sprintf(buf, "%s()", yystack.l_mark[-2].sval); yyval.sval=buf; }
break;
case 65:
#line 191 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 66:
#line 192 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,...", yystack.l_mark[-2].sval); yyval.sval=buf; }
break;
case 67:
#line 195 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 68:
#line 196 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 69:
#line 199 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 70:
#line 200 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 71:
#line 203 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 72:
#line 204 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 73:
#line 207 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 74:
#line 208 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "{%s}", yystack.l_mark[-1].sval); yyval.sval=buf; }
break;
case 75:
#line 209 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "{%s,}", yystack.l_mark[-2].sval); yyval.sval=buf; }
break;
case 76:
#line 212 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 77:
#line 213 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf;}
break;
case 78:
#line 216 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 79:
#line 217 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 80:
#line 220 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>", yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 81:
#line 221 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s%s%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 82:
#line 224 "parser.y"
	{ yyval.sval="=";}
break;
case 83:
#line 225 "parser.y"
	{ yyval.sval="*="; }
break;
case 84:
#line 226 "parser.y"
	{ yyval.sval="/="; }
break;
case 85:
#line 227 "parser.y"
	{ yyval.sval="%="; }
break;
case 86:
#line 228 "parser.y"
	{ yyval.sval="+="; }
break;
case 87:
#line 229 "parser.y"
	{ yyval.sval="-="; }
break;
case 88:
#line 232 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 89:
#line 233 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s?%s:%s", yystack.l_mark[-4].sval, yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 90:
#line 236 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 91:
#line 237 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 92:
#line 240 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 93:
#line 241 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 94:
#line 244 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 95:
#line 245 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 96:
#line 248 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 97:
#line 249 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>^<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 98:
#line 252 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 99:
#line 253 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 100:
#line 256 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 101:
#line 257 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 102:
#line 258 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 103:
#line 261 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 104:
#line 262 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 105:
#line 263 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 106:
#line 264 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 107:
#line 265 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 108:
#line 268 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 109:
#line 269 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 110:
#line 270 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>><expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 111:
#line 273 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 112:
#line 274 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 113:
#line 275 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 114:
#line 278 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 115:
#line 279 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 116:
#line 280 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 117:
#line 281 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 118:
#line 284 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 119:
#line 285 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "(%s)%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 120:
#line 288 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 121:
#line 289 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "++%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 122:
#line 290 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "--%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 123:
#line 291 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s<expr>%s</expr>", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 124:
#line 294 "parser.y"
	{ yyval.sval="&"; }
break;
case 125:
#line 295 "parser.y"
	{ yyval.sval="*"; }
break;
case 126:
#line 296 "parser.y"
	{ yyval.sval="+"; }
break;
case 127:
#line 297 "parser.y"
	{ yyval.sval="-"; }
break;
case 128:
#line 298 "parser.y"
	{ yyval.sval="~"; }
break;
case 129:
#line 299 "parser.y"
	{ yyval.sval="!"; }
break;
case 130:
#line 302 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 131:
#line 303 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 132:
#line 304 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s[%s]", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 133:
#line 305 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s()", yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); }
break;
case 134:
#line 306 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s(%s)", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 135:
#line 307 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s++", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 136:
#line 308 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s--", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 137:
#line 311 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 138:
#line 312 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 139:
#line 315 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "(%s)", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 140:
#line 316 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 141:
#line 317 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 142:
#line 318 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 143:
#line 321 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%d", yystack.l_mark[0].ival); yyval.sval=buf; }
break;
case 144:
#line 322 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%c", yystack.l_mark[0].cval); yyval.sval=buf; }
break;
case 145:
#line 323 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%f", yystack.l_mark[0].dval); yyval.sval=buf; }
break;
#line 1642 "y.tab.c"
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
