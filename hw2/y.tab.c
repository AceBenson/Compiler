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
    0,   52,   52,   51,   51,   50,   50,   50,   50,   45,
   45,   29,   29,   30,   30,   30,   30,   27,   27,   27,
   27,   27,   27,   34,   34,   34,   31,   31,   31,   33,
   33,   33,   33,   32,   32,   32,   32,   26,   26,   36,
   36,   36,   36,    1,    1,    2,    2,    3,    3,    4,
   37,   37,   40,   40,   40,   40,   40,   40,   40,   40,
   40,   38,   38,   39,   39,   41,   41,   41,   41,   44,
    5,    6,    6,   47,   47,   48,   48,   49,   49,   46,
   46,   42,   42,   42,   43,   43,   25,   25,   24,   24,
   35,   35,   35,   35,   35,   35,   23,   23,   22,   22,
   21,   21,   20,   20,   19,   19,   18,   18,   17,   17,
   17,   16,   16,   16,   16,   16,   15,   15,   15,   14,
   14,   14,   13,   13,   13,   13,   12,   12,   11,   11,
   11,   11,   10,   10,   10,   10,   10,   10,    9,    9,
    9,    9,    9,    9,    9,   28,   28,    8,    8,    8,
    8,    7,    7,    7,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    3,    4,    2,    3,    1,
    2,    2,    3,    1,    1,    2,    2,    1,    1,    1,
    1,    1,    1,    3,    4,    3,    5,    7,    5,    5,
    7,    6,    7,    2,    2,    2,    3,    1,    2,    2,
    2,    2,    2,    1,    2,    1,    2,    2,    2,    2,
    1,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    1,    3,    1,    1,    1,    3,    1,
    4,    4,    3,    1,    3,    1,    3,    2,    1,    1,
    3,    1,    3,    4,    1,    3,    1,    3,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    5,    1,    3,
    1,    3,    1,    3,    1,    3,    1,    3,    1,    3,
    3,    1,    3,    3,    3,    3,    1,    3,    3,    3,
    3,    1,    3,    3,    3,    1,    1,    4,    1,    2,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    4,    3,    4,    2,    2,    1,    3,    3,    1,    1,
    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   70,   54,   55,   56,   57,   60,   61,   58,   59,    0,
   53,    0,    0,    0,    0,    0,    0,   67,   68,    5,
    0,    0,    0,   66,    4,    2,    0,   48,   49,    0,
    0,   40,   41,   42,   43,    0,    0,   62,    0,   52,
    0,    0,    0,    8,   10,    0,    0,    3,    0,   69,
    0,    0,    6,    0,    0,  154,  152,  153,  151,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  140,   38,  133,  135,  136,  134,   12,    0,  137,
  138,  149,  139,    0,    0,    0,  126,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   89,   87,    0,
   19,   14,   18,    0,   20,   23,   22,   21,   15,   73,
    0,    0,    0,   76,  150,  127,    0,    9,   11,   63,
    0,   82,   65,    7,    0,    0,  130,  131,    0,    0,
    0,    0,    0,    0,    0,   34,   35,   36,    0,    0,
    0,  144,  145,    0,    0,  132,   92,   93,   94,   95,
   96,   91,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   39,    0,   13,   16,   17,    0,   72,    0,
   71,   85,    0,   24,    0,   26,    0,    0,    0,    0,
    0,   37,  148,    0,  142,  146,    0,    0,   90,  123,
  124,  125,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   88,   75,
   77,    0,   83,   25,    0,    0,    0,    0,    0,  128,
    0,  143,  141,    0,   84,   86,    0,   29,   30,    0,
    0,    0,  147,   98,    0,    0,   32,    0,   28,   31,
   33,
};
static const YYINT yydgoto[] = {                         13,
   14,   15,   16,   17,   18,   19,   82,   83,   84,   85,
   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,  100,  101,  102,  197,  103,  104,
  105,  106,  107,  108,  153,   20,   46,   37,   38,   22,
   49,  123,  183,   24,   47,    0,  112,  113,  114,   25,
   26,   27,
};
static const YYINT yysindex[] = {                       232,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  543,
    0,  -39,    0,  -44,  -18,  -10,   18,    0,    0,    0,
  -39,  543,  326,    0,    0,    0,  232,    0,    0,  -39,
   -6,    0,    0,    0,    0,    0,   50,    0,  467,    0,
  -33,  258,  439,    0,    0,  -39,  743,    0,   11,    0,
  -39,   31,    0,  743,   49,    0,    0,    0,    0,  455,
  455,  439,   61,   84,   89,  102,   88,  104,   90,   94,
  373,    0,    0,    0,    0,    0,    0,    0,  141,    0,
    0,    0,    0,  -16,  439,  146,    0,   58,   80, -221,
  -58, -213,  134,   86,   54,  -84,  -60,    0,    0,    2,
    0,    0,    0,   20,    0,    0,    0,    0,    0,    0,
  -39,  154,  158,    0,    0,    0,  110,    0,    0,    0,
   31,    0,    0,    0,   88,  439,    0,    0,  147,   88,
  439,  439,  439,  -98,  401,    0,    0,    0,   24,   -1,
  165,    0,    0,  414,  439,    0,    0,    0,    0,    0,
    0,    0,  439,  439,  439,  439,  439,  439,  439,  439,
  439,  439,  439,  439,  439,  439,  439,  439,  439,  439,
  439,  439,    0,  439,    0,    0,    0,   -3,    0, 1172,
    0,    0,  -36,    0,   88,    0,   95,   96,  118,  173,
  401,    0,    0,  439,    0,    0,  120,   -2,    0,    0,
    0,    0,   58,   58,   80,   80, -221, -221, -221, -221,
  -58,  -58, -213,  134,   86,   54,  -84,  -31,    0,    0,
    0,  -22,    0,    0,   93,   93,   88,  439,  428,    0,
  439,    0,    0,  439,    0,    0,  -83,    0,    0,  122,
   88,  132,    0,    0,   93,  161,    0,   88,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  164,   40,    0,    0,    0,    0,  229,    0,    0,  164,
    0,    0,    0,    0,    0,  443,  175,    0,   68,    0,
    0,    0,    0,    0,    0,  164,    0,    0,   68,    0,
    0,    0,    0,    0,  532,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  724,    0,  778,    0,  801,  892, 1042,
 1206,   97,  -27,  542,  -11, 1346,  494,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  144,    0,  191,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  148,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  824,  847,  915, 1016, 1084, 1110, 1152, 1178,
 1277, 1301, 1303, 1198,  583,  731, 1348,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  233,  236,    0,    0,    0,    8,    0,    0,    0,    0,
 1369,  -46,  -71,   34,    7,   35,   82,  114,  116,   92,
  115,    0,  -37,  791,  518, -113,   -8,    0,  128,    0,
    0,    0,    0,    0,    0,  111,   28,    0,  212,  214,
  453, -102,    0,    0,  257,    0,    0,    0,  121,    0,
  271,    0,
};
#define YYTABLESIZE 1620
static const YYINT yytable[] = {                         81,
   12,  164,  172,  163,   74,  117,   79,  222,   77,   75,
   81,   76,  174,  105,   32,   74,  105,   79,  182,   77,
   75,  191,   76,  144,  129,   73,  234,   21,   36,  101,
  105,  105,  101,   42,   50,  105,   42,   30,  146,  193,
   33,  174,  174,  159,  160,  174,  101,  101,   34,   40,
   42,  101,   81,   36,   21,  165,  166,   74,  134,   79,
  173,   77,   75,   81,   76,  105,  105,  174,   74,  111,
   79,   52,   77,   75,  145,   76,   35,  229,   73,   51,
   51,  101,  192,   51,   43,  203,  204,   43,  223,   41,
  233,   78,   80,   51,  156,  176,  105,  105,   51,  154,
  121,   43,  235,   80,  155,   27,  125,  200,  201,  202,
   27,   64,   27,  101,   27,   27,  184,   27,  130,  236,
   81,  186,  157,  131,  158,   74,   64,   79,  132,   77,
   75,   27,   76,   45,  107,  225,  226,  107,  174,  174,
  107,  133,   41,  135,  175,   80,   73,  230,  136,   45,
   44,  109,  137,  121,  107,  107,   80,  119,  227,  107,
  232,  174,  246,  231,  119,  174,   53,  207,  208,  209,
  210,  167,  248,   81,  118,  174,  224,  169,   74,  168,
   79,  124,   77,   75,   79,   76,  170,   79,   78,  107,
  107,   78,  205,  206,  179,   27,  244,   27,   27,  211,
  212,  180,  181,  190,  185,  194,  152,  111,  161,  162,
   41,  171,  228,   80,  177,   41,  245,    1,  239,  250,
  107,  107,   44,   55,   56,   57,   58,   59,    1,   60,
   61,   74,  247,   45,  115,   56,   57,   58,   59,  251,
   60,   61,   28,  105,  105,   29,  142,  143,  213,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,  101,
  101,  216,  120,   62,   63,   64,   80,   65,   66,   67,
   68,   12,   69,   70,   71,   72,   55,   56,   57,   58,
   59,  214,   60,   61,  215,  217,   72,  115,   56,   57,
   58,   59,  141,   60,   61,   54,   51,   48,  110,    0,
  221,    0,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,    0,    0,    0,    0,   62,   63,   64,    0,
   65,   66,   67,   68,    0,   69,   70,   71,   72,   27,
   27,   27,   27,   27,    0,   27,   27,    0,    0,   72,
    0,    0,    0,    0,   55,   56,   57,   58,   59,    0,
   60,   61,  237,  238,    0,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   42,    0,  107,  107,   27,
   27,   27,  249,   27,   27,   27,   27,    0,   27,   27,
   27,   27,    0,    0,   62,   63,   64,    0,   65,   66,
   67,   68,    0,   69,   70,   71,   72,  115,   56,   57,
   58,   59,    0,   60,   61,   81,    0,    0,    0,    0,
   74,    0,   79,    0,   77,   75,   43,   76,  147,  148,
  149,  150,  151,    2,    3,    4,    5,    6,    7,    8,
    9,  138,   11,   81,    0,    0,    0,    0,   74,    0,
   79,    0,   77,   75,    0,   76,   81,    0,   41,   72,
    0,   74,   23,   79,  195,   77,   75,    0,   76,   73,
   81,    0,    0,    0,   31,   74,    0,   79,  241,   77,
   75,   81,   76,   39,    0,    0,   74,    0,   79,   23,
   77,   75,   68,   76,    0,    0,   68,   81,    1,    0,
    0,    0,   74,    0,  126,    0,   77,   75,   80,   76,
    0,   50,    0,   68,    0,    0,   42,    0,    0,    0,
    0,    0,    0,    0,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,    0,    0,   80,   52,    0,    0,
    0,    0,    0,   68,   97,    0,    0,   97,    0,   80,
    2,    3,    4,    5,    6,    7,    8,    9,    0,   11,
    0,   97,   97,   80,    0,    0,    0,   43,    0,    0,
    0,    0,    0,  178,   80,   68,    0,    0,  150,  150,
    0,  150,    0,  150,  150,  150,  150,    0,  150,    0,
   80,    0,  103,    0,    0,  103,   97,    0,  139,   41,
  150,  150,  150,  150,  150,    0,  140,    0,    0,  103,
  103,    0,    0,    0,  103,    0,    0,    0,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   97,    0,
    0,    0,  150,  104,    0,  150,  104,    0,    0,  115,
   56,   57,   58,   59,  103,   60,   61,    0,    0,    0,
  104,  104,    0,  140,    0,  104,    0,    0,  187,  188,
  189,    0,    0,    0,    0,  150,    0,  115,   56,   57,
   58,   59,  198,   60,   61,  103,  103,    0,    0,    0,
  115,   56,   57,   58,   59,  104,   60,   61,    0,    0,
    0,   72,    0,    0,  115,   56,   57,   58,   59,  218,
   60,   61,    0,    0,    0,  115,   56,   57,   58,   59,
    0,   60,   61,    0,    0,    0,  104,  104,    0,   72,
    0,  115,   56,   57,   58,   59,    0,   60,   61,    0,
    0,    0,   72,    0,    0,   68,   68,   68,   68,   68,
   68,   68,   68,   68,   68,    0,   72,    0,    0,    0,
    0,    0,    0,    0,    0,  240,  242,   72,    0,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,    0,
  129,  129,    0,   72,  129,  129,  129,  129,  129,    0,
  129,  102,    0,    0,  102,    0,    0,    0,    0,    0,
    0,  129,  129,  129,  129,  129,  129,    0,  102,  102,
    0,    0,    0,  102,  150,  150,  150,  150,  150,  150,
  150,  150,  150,  150,  150,  150,  150,  150,  150,    0,
    0,    0,  103,  103,  127,  127,  129,  129,  127,  127,
  127,  127,  127,  102,  127,    2,    3,    4,    5,    6,
    7,    8,    9,    0,   11,  127,  127,  127,  122,  127,
  127,  122,  122,  122,  122,  122,    0,  129,  129,    0,
    0,    0,    0,  104,  104,  102,    0,    0,  122,  122,
  122,  120,  122,  122,  120,   41,  120,  120,  120,    0,
  127,  127,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  120,  120,  120,  121,  120,  120,  121,    0,  121,
  121,  121,    0,  122,  122,    0,    0,    0,    0,    0,
    0,  127,  127,    0,  121,  121,  121,    0,  121,  121,
    0,  122,    0,    0,    0,    0,  120,  120,    0,    0,
    0,    0,    0,    0,  122,  122,    0,    0,    0,  117,
    0,    0,  117,    0,  196,  117,    0,    0,    0,  121,
  121,    0,    0,  199,    0,    0,    0,  120,  120,  117,
  117,  117,  118,  117,  117,  118,    0,    0,  118,    0,
    0,    0,    0,    0,  219,    0,    0,    0,    0,    0,
  121,  121,  118,  118,  118,    0,  118,  118,    0,    0,
    0,    0,    0,    0,  117,  117,    0,    0,  129,  129,
  129,  129,  129,  129,  129,  129,  129,  129,  129,  129,
  129,  102,  102,    0,    0,    0,    0,  118,  118,    0,
    0,    0,  122,    0,    0,  117,  117,    0,    0,    0,
    0,  243,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,    0,    0,    0,  118,  118,
    0,    0,  127,  127,  127,  127,  127,  127,  127,  127,
    0,    0,    0,  119,    0,    0,  119,    0,    0,  119,
    0,    0,    0,    0,    0,  122,  122,  122,  122,  122,
  122,  122,  122,  119,  119,  119,    0,  119,  119,  112,
    0,    0,  112,    0,    0,  112,    0,    0,  120,  120,
  120,  120,  120,  120,  120,  120,    0,    0,    0,  112,
  112,  112,    0,  112,  112,    0,    0,    0,  119,  119,
    0,  121,  121,  121,  121,  121,  121,  121,  121,    0,
    0,  115,    0,    0,  115,    0,    0,  115,    0,    0,
    0,    0,    0,    0,  112,  112,    0,    0,    0,  119,
  119,  115,  115,  115,    0,  115,  115,  116,    0,    0,
  116,    0,    0,  116,    0,    0,  117,  117,  117,  117,
  117,  117,  117,  117,    0,  112,  112,  116,  116,  116,
    0,  116,  116,    0,    0,    0,  115,  115,    0,  118,
  118,  118,  118,  118,  118,  118,  118,    0,    0,  114,
    0,    0,  114,    0,    0,  114,    0,    0,    0,    0,
    0,    0,  116,  116,    0,    0,    0,  115,  115,  114,
  114,  114,    0,  114,  114,  113,    0,    0,  113,    0,
    0,  113,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  116,  116,  113,  113,  113,  106,  113,
  113,  106,    0,  109,  114,  114,  109,    0,    0,  109,
    0,    0,    0,    0,    0,  106,  106,    0,    0,    0,
  106,    0,    0,  109,  109,    0,    0,    0,  109,    0,
  113,  113,    0,    0,    0,  114,  114,    0,    0,    0,
  119,  119,  119,  119,  119,  119,  119,  119,    0,    0,
  106,  106,    0,    0,    0,    0,    0,    0,  109,  109,
    0,  113,  113,    0,    0,    0,    0,    0,  112,  112,
  112,  112,  112,  112,  110,    0,    0,  110,    0,    0,
  110,  106,  106,    0,    0,    0,    0,    0,    0,  109,
  109,    0,    0,    0,  110,  110,    0,    0,  111,  110,
  108,  111,    0,  108,  111,    0,  108,    0,    0,    0,
  115,  115,  115,  115,  115,  115,    0,    0,  111,  111,
  108,  108,    0,  111,    0,  108,    0,    0,    0,  110,
  110,    0,    0,    0,    0,    0,  116,  116,  116,  116,
  116,  116,    0,    0,    0,    0,   99,    0,  100,   99,
    0,  100,    0,  111,  111,  108,  108,    0,    0,    0,
  110,  110,    0,   99,   99,  100,  100,    0,   99,    0,
  100,  116,    0,    0,    0,    0,    0,    0,  114,  114,
  114,  114,  114,  114,  111,  111,  108,  108,  127,  128,
  116,    0,    0,    0,    0,    0,    0,    0,   99,    0,
  100,    0,    0,    0,  113,  113,  113,  113,  113,  113,
    0,    0,    0,  116,    2,    3,    4,    5,    6,    7,
    8,    9,    0,   11,    0,    0,    0,  220,  106,  106,
   99,    0,  100,    0,  109,  109,  109,  109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  116,  116,  116,  116,  116,  116,  116,  116,
  116,  116,  116,  116,  116,  116,  116,  116,  116,  116,
    0,    0,    0,    0,    0,  110,  110,  110,  110,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  116,    0,    0,    0,    0,    0,    0,  111,
  111,  111,  111,  108,  108,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  116,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,  100,
};
static const YYINT yycheck[] = {                         33,
   40,   60,   63,   62,   38,   43,   40,   44,   42,   43,
   33,   45,   44,   41,   59,   38,   44,   40,  121,   42,
   43,  135,   45,   40,   62,   59,   58,    0,   21,   41,
   58,   59,   44,   40,   41,   63,   40,   10,   85,   41,
   59,   44,   44,  265,  266,   44,   58,   59,   59,   22,
   40,   63,   33,   46,   27,  269,  270,   38,   67,   40,
   59,   42,   43,   33,   45,   93,   94,   44,   38,   42,
   40,   61,   42,   43,   91,   45,   59,  191,   59,   40,
   41,   93,   59,   44,   91,  157,  158,   91,  125,  123,
   93,  125,  126,   44,   37,  104,  124,  125,   59,   42,
  123,   91,  125,  126,   47,   33,   58,  154,  155,  156,
   38,   44,   40,  125,   42,   43,  125,   45,   58,  222,
   33,  130,   43,   40,   45,   38,   59,   40,   40,   42,
   43,   59,   45,   23,   38,   41,   41,   41,   44,   44,
   44,   40,  123,   40,  125,  126,   59,  194,   59,   39,
   23,   41,   59,  123,   58,   59,  126,   47,   41,   63,
   41,   44,   41,   44,   54,   44,   39,  161,  162,  163,
  164,   38,   41,   33,   47,   44,  185,  124,   38,   94,
   40,   54,   42,   43,   41,   45,  271,   44,   41,   93,
   94,   44,  159,  160,   41,  123,  234,  125,  126,  165,
  166,   44,   93,  302,   58,   41,   61,  180,  267,  268,
  123,  272,   40,  126,  104,  123,  300,  257,  227,   59,
  124,  125,   59,  257,  258,  259,  260,  261,    0,  263,
  264,   41,  241,   59,  257,  258,  259,  260,  261,  248,
  263,  264,   10,  271,  272,   10,  263,  264,  167,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  271,
  272,  170,   51,  297,  298,  299,  126,  301,  302,  303,
  304,   40,  306,  307,  308,  309,  257,  258,  259,  260,
  261,  168,  263,  264,  169,  171,  309,  257,  258,  259,
  260,  261,   79,  263,  264,   39,  257,   27,   41,   -1,
  180,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,
  301,  302,  303,  304,   -1,  306,  307,  308,  309,  257,
  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,  309,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
  263,  264,  225,  226,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   40,   -1,  271,  272,  297,
  298,  299,  245,  301,  302,  303,  304,   -1,  306,  307,
  308,  309,   -1,   -1,  297,  298,  299,   -1,  301,  302,
  303,  304,   -1,  306,  307,  308,  309,  257,  258,  259,
  260,  261,   -1,  263,  264,   33,   -1,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   43,   91,   45,  273,  274,
  275,  276,  277,  283,  284,  285,  286,  287,  288,  289,
  290,   59,  292,   33,   -1,   -1,   -1,   -1,   38,   -1,
   40,   -1,   42,   43,   -1,   45,   33,   -1,  123,  309,
   -1,   38,    0,   40,   41,   42,   43,   -1,   45,   59,
   33,   -1,   -1,   -1,   12,   38,   -1,   40,   41,   42,
   43,   33,   45,   21,   -1,   -1,   38,   -1,   40,   27,
   42,   43,   40,   45,   -1,   -1,   44,   33,  257,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,   43,  126,   45,
   -1,   59,   -1,   61,   -1,   -1,   40,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,   -1,   -1,  126,   61,   -1,   -1,
   -1,   -1,   -1,   91,   41,   -1,   -1,   44,   -1,  126,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,  292,
   -1,   58,   59,  126,   -1,   -1,   -1,   91,   -1,   -1,
   -1,   -1,   -1,  111,  126,  123,   -1,   -1,   37,   38,
   -1,   40,   -1,   42,   43,   44,   45,   -1,   47,   -1,
  126,   -1,   41,   -1,   -1,   44,   93,   -1,   71,  123,
   59,   60,   61,   62,   63,   -1,   79,   -1,   -1,   58,
   59,   -1,   -1,   -1,   63,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  125,   -1,
   -1,   -1,   91,   41,   -1,   94,   44,   -1,   -1,  257,
  258,  259,  260,  261,   93,  263,  264,   -1,   -1,   -1,
   58,   59,   -1,  126,   -1,   63,   -1,   -1,  131,  132,
  133,   -1,   -1,   -1,   -1,  124,   -1,  257,  258,  259,
  260,  261,  145,  263,  264,  124,  125,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   93,  263,  264,   -1,   -1,
   -1,  309,   -1,   -1,  257,  258,  259,  260,  261,  172,
  263,  264,   -1,   -1,   -1,  257,  258,  259,  260,  261,
   -1,  263,  264,   -1,   -1,   -1,  124,  125,   -1,  309,
   -1,  257,  258,  259,  260,  261,   -1,  263,  264,   -1,
   -1,   -1,  309,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   -1,  309,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  228,  229,  309,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,   -1,
   37,   38,   -1,  309,   41,   42,   43,   44,   45,   -1,
   47,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   58,   59,   60,   61,   62,   63,   -1,   58,   59,
   -1,   -1,   -1,   63,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  275,  276,  277,   -1,
   -1,   -1,  271,  272,   37,   38,   93,   94,   41,   42,
   43,   44,   45,   93,   47,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,  292,   58,   59,   60,   38,   62,
   63,   41,   52,   43,   44,   45,   -1,  124,  125,   -1,
   -1,   -1,   -1,  271,  272,  125,   -1,   -1,   58,   59,
   60,   38,   62,   63,   41,  123,   43,   44,   45,   -1,
   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   58,   59,   60,   38,   62,   63,   41,   -1,   43,
   44,   45,   -1,   93,   94,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,   -1,   58,   59,   60,   -1,   62,   63,
   -1,  121,   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,
   -1,   -1,   -1,   -1,  124,  125,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,  144,   44,   -1,   -1,   -1,   93,
   94,   -1,   -1,  153,   -1,   -1,   -1,  124,  125,   58,
   59,   60,   38,   62,   63,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   -1,  174,   -1,   -1,   -1,   -1,   -1,
  124,  125,   58,   59,   60,   -1,   62,   63,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  271,  272,   -1,   -1,   -1,   -1,   93,   94,   -1,
   -1,   -1,  222,   -1,   -1,  124,  125,   -1,   -1,   -1,
   -1,  231,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,   -1,   -1,   -1,  124,  125,
   -1,   -1,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,  265,  266,  267,  268,  269,
  270,  271,  272,   58,   59,   60,   -1,   62,   63,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,  265,  266,
  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,   58,
   59,   60,   -1,   62,   63,   -1,   -1,   -1,   93,   94,
   -1,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,   -1,  124,
  125,   58,   59,   60,   -1,   62,   63,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,  124,  125,   58,   59,   60,
   -1,   62,   63,   -1,   -1,   -1,   93,   94,   -1,  265,
  266,  267,  268,  269,  270,  271,  272,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   94,   -1,   -1,   -1,  124,  125,   58,
   59,   60,   -1,   62,   63,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,   58,   59,   60,   41,   62,
   63,   44,   -1,   38,   93,   94,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   58,   59,   -1,   -1,   -1,
   63,   -1,   -1,   58,   59,   -1,   -1,   -1,   63,   -1,
   93,   94,   -1,   -1,   -1,  124,  125,   -1,   -1,   -1,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,   -1,
   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,
   -1,  124,  125,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,  272,   38,   -1,   -1,   41,   -1,   -1,
   44,  124,  125,   -1,   -1,   -1,   -1,   -1,   -1,  124,
  125,   -1,   -1,   -1,   58,   59,   -1,   -1,   38,   63,
   38,   41,   -1,   41,   44,   -1,   44,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,   -1,   -1,   58,   59,
   58,   59,   -1,   63,   -1,   63,   -1,   -1,   -1,   93,
   94,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   41,   -1,   41,   44,
   -1,   44,   -1,   93,   94,   93,   94,   -1,   -1,   -1,
  124,  125,   -1,   58,   59,   58,   59,   -1,   63,   -1,
   63,   43,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,  272,  124,  125,  124,  125,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   93,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   85,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,  292,   -1,   -1,   -1,  296,  271,  272,
  125,   -1,  125,   -1,  269,  270,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  154,  155,  156,  157,  158,  159,  160,  161,
  162,  163,  164,  165,  166,  167,  168,  169,  170,  171,
   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  194,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  271,  272,  271,  272,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  234,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,  272,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 320
#define YYUNDFTOKEN 375
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
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"declaration : scalar_declaration ';'",
"declaration : array_declaration ';'",
"declaration : const_declaration ';'",
"declaration : function_declaration ';'",
"scalar_declaration : declaration_specifiers",
"scalar_declaration : declaration_specifiers init_declarator_list",
"array_declaration : declaration_specifiers",
"array_declaration : declaration_specifiers init_declarator_list",
"const_declaration : CONST scalar_declaration",
"const_declaration : CONST array_declaration",
"function_declaration : declaration_specifiers function_declarator",
"declaration_specifiers : type_specifier",
"declaration_specifiers : type_specifier declaration_specifiers",
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
"declarator : array_declarator",
"declarator : function_declarator",
"declarator : '(' declarator ')'",
"direct_declarator : IDENTIFIER",
"array_declarator : declarator '[' conditional_expression ']'",
"function_declarator : declarator '(' parameter_type_list ')'",
"function_declarator : declarator '(' ')'",
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
#line 321 "parser.y"

char* get_buf()
{
	char* buf=(char*)malloc(sizeof(char)*1000000);
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
#line 852 "y.tab.c"

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
	{ char* buf=get_nbuf(3); strcpy(buf, "{}"); yyval.sval=buf; }
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
	{ char* buf=get_nbuf(10); strcpy(buf, "continue;"); yyval.sval=buf; }
break;
case 35:
#line 119 "parser.y"
	{ char* buf=get_nbuf(7); strcpy(buf, "break;"); yyval.sval=buf; }
break;
case 36:
#line 120 "parser.y"
	{ char* buf=get_nbuf(8); strcpy(buf, "return;"); yyval.sval=buf; }
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
	{ char* buf=get_buf(); sprintf(buf, "%s;", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 40:
#line 128 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<scalar_decl>%s;</scalar_decl>", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 41:
#line 129 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<array_decl>%s;</array_decl>", yystack.l_mark[-1].sval); yyval.sval = buf; free(yystack.l_mark[-1].sval); }
break;
case 42:
#line 130 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<const_decl>%s;</const_decl>", yystack.l_mark[-1].sval); yyval.sval = buf; free(yystack.l_mark[-1].sval); }
break;
case 43:
#line 131 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<func_decl>%s;</func_decl>", yystack.l_mark[-1].sval); yyval.sval = buf; free(yystack.l_mark[-1].sval); }
break;
case 44:
#line 134 "parser.y"
	{ yyval.sval = yystack.l_mark[0].sval; }
break;
case 45:
#line 135 "parser.y"
	{char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval= buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 46:
#line 138 "parser.y"
	{}
break;
case 47:
#line 139 "parser.y"
	{}
break;
case 48:
#line 141 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "const%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 49:
#line 142 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "const%s", yystack.l_mark[0].sval); yyval.sval = buf; free(yystack.l_mark[0].sval); }
break;
case 50:
#line 144 "parser.y"
	{}
break;
case 51:
#line 147 "parser.y"
	{ char* buf=get_buf(); strcpy(buf, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 52:
#line 148 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 53:
#line 151 "parser.y"
	{ char* buf=get_nbuf(5); strcpy(buf, "void"); yyval.sval=buf; }
break;
case 54:
#line 152 "parser.y"
	{ char* buf=get_nbuf(5); strcpy(buf, "char"); yyval.sval=buf; }
break;
case 55:
#line 153 "parser.y"
	{ char* buf=get_nbuf(6); strcpy(buf, "short"); yyval.sval=buf; }
break;
case 56:
#line 154 "parser.y"
	{ char* buf=get_nbuf(4); strcpy(buf, "int"); yyval.sval=buf; }
break;
case 57:
#line 155 "parser.y"
	{ char* buf=get_nbuf(5); strcpy(buf, "long"); yyval.sval=buf; }
break;
case 58:
#line 156 "parser.y"
	{ char* buf=get_nbuf(6); strcpy(buf, "float"); yyval.sval=buf; }
break;
case 59:
#line 157 "parser.y"
	{ char* buf=get_nbuf(7); strcpy(buf, "double"); yyval.sval=buf; }
break;
case 60:
#line 158 "parser.y"
	{ char* buf=get_nbuf(7); strcpy(buf, "signed"); yyval.sval=buf; }
break;
case 61:
#line 159 "parser.y"
	{ char* buf=get_nbuf(9); strcpy(buf, "unsigned"); yyval.sval=buf; }
break;
case 62:
#line 162 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 63:
#line 163 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 64:
#line 166 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 65:
#line 167 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s=%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 66:
#line 170 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 67:
#line 171 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 68:
#line 172 "parser.y"
	{yyval.sval=yystack.l_mark[0].sval;}
break;
case 70:
#line 176 "parser.y"
	{ if(type!=3) type=0; yyval.sval=yystack.l_mark[0].sval; }
break;
case 71:
#line 179 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s[%s]", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval =buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 72:
#line 182 "parser.y"
	{char*buf=get_buf(); sprintf(buf, "%s(%s)", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 73:
#line 183 "parser.y"
	{char*buf=get_buf(); sprintf(buf, "%s()", yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); }
break;
case 74:
#line 186 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 75:
#line 187 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,...", yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); }
break;
case 76:
#line 190 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 77:
#line 191 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 78:
#line 194 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s%s", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); free(yystack.l_mark[0].sval); }
break;
case 79:
#line 195 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 80:
#line 198 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 81:
#line 199 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 82:
#line 202 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 83:
#line 203 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "{%s}", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 84:
#line 204 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "{%s,}", yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); }
break;
case 85:
#line 207 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 86:
#line 208 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 87:
#line 211 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 88:
#line 212 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 89:
#line 215 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>", yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 90:
#line 216 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s%s%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 91:
#line 219 "parser.y"
	{ char* buf=get_nbuf(2); strcpy(buf, "="); yyval.sval=buf;}
break;
case 92:
#line 220 "parser.y"
	{ char* buf=get_nbuf(3); strcpy(buf, "*="); yyval.sval=buf; }
break;
case 93:
#line 221 "parser.y"
	{ char* buf=get_nbuf(3); strcpy(buf, "/="); yyval.sval=buf; }
break;
case 94:
#line 222 "parser.y"
	{ char* buf=get_nbuf(3); strcpy(buf, "%="); yyval.sval=buf; }
break;
case 95:
#line 223 "parser.y"
	{ char* buf=get_nbuf(3); strcpy(buf, "+="); yyval.sval=buf; }
break;
case 96:
#line 224 "parser.y"
	{ char* buf=get_nbuf(3); strcpy(buf, "-="); yyval.sval=buf; }
break;
case 97:
#line 227 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 98:
#line 228 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s?%s:%s", yystack.l_mark[-4].sval, yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-4].sval); free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 99:
#line 231 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 100:
#line 232 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 101:
#line 235 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 102:
#line 236 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 103:
#line 239 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 104:
#line 240 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 105:
#line 243 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 106:
#line 244 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>^<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 107:
#line 247 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 108:
#line 248 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 109:
#line 251 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 110:
#line 252 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval);}
break;
case 111:
#line 253 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 112:
#line 256 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 113:
#line 257 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 114:
#line 258 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 115:
#line 259 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 116:
#line 260 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 117:
#line 263 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 118:
#line 264 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 119:
#line 265 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>><expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 120:
#line 268 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 121:
#line 269 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 122:
#line 270 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 123:
#line 273 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; }
break;
case 124:
#line 274 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 125:
#line 275 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 126:
#line 276 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 127:
#line 279 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 128:
#line 280 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "(%s)%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 129:
#line 283 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 130:
#line 284 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "++%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 131:
#line 285 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "--%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 132:
#line 286 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s<expr>%s</expr>", yystack.l_mark[-1].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 133:
#line 289 "parser.y"
	{ yyval.sval="&"; }
break;
case 134:
#line 290 "parser.y"
	{ yyval.sval="*"; }
break;
case 135:
#line 291 "parser.y"
	{ yyval.sval="+"; }
break;
case 136:
#line 292 "parser.y"
	{ yyval.sval="-"; }
break;
case 137:
#line 293 "parser.y"
	{ yyval.sval="~"; }
break;
case 138:
#line 294 "parser.y"
	{ yyval.sval="!"; }
break;
case 139:
#line 297 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 140:
#line 298 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s", yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[0].sval); }
break;
case 141:
#line 299 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s[%s]", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 142:
#line 300 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s()", yystack.l_mark[-2].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); }
break;
case 143:
#line 301 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s(%s)", yystack.l_mark[-3].sval, yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-3].sval); free(yystack.l_mark[-1].sval); }
break;
case 144:
#line 302 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s++", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 145:
#line 303 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s--", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 146:
#line 306 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 147:
#line 307 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%s,%s", yystack.l_mark[-2].sval, yystack.l_mark[0].sval); yyval.sval=buf; free(yystack.l_mark[-2].sval); free(yystack.l_mark[0].sval); }
break;
case 148:
#line 310 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "(%s)", yystack.l_mark[-1].sval); yyval.sval=buf; free(yystack.l_mark[-1].sval); }
break;
case 149:
#line 311 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 150:
#line 312 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 151:
#line 313 "parser.y"
	{ yyval.sval=yystack.l_mark[0].sval; }
break;
case 152:
#line 316 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%d", yystack.l_mark[0].ival); yyval.sval=buf; }
break;
case 153:
#line 317 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%c", yystack.l_mark[0].cval); yyval.sval=buf; }
break;
case 154:
#line 318 "parser.y"
	{ char* buf=get_buf(); sprintf(buf, "%f", yystack.l_mark[0].dval); yyval.sval=buf; }
break;
#line 1666 "y.tab.c"
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
