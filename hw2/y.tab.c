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
	int yylex();
	extern char yytext[];
	extern int column;
#line 7 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int token;
	double dval;
	char charv;
	char* ident;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

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
#define CONSTANT 258
#define STRING_LITERAL 259
#define SIZEOF 260
#define INC_OP 261
#define DEC_OP 262
#define LEFT_OP 263
#define RIGHT_OP 264
#define LE_OP 265
#define GE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define AND_OP 269
#define OR_OP 270
#define MUL_ASSIGN 271
#define DIV_ASSIGN 272
#define MOD_ASSIGN 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define TYPEDEF 276
#define EXTERN 277
#define STATIC 278
#define AUTO 279
#define REGISTER 280
#define CHAR 281
#define SHORT 282
#define INT 283
#define LONG 284
#define SIGNED 285
#define UNSIGNED 286
#define FLOAT 287
#define DOUBLE 288
#define CONST 289
#define VOID 290
#define STRUCT 291
#define UNION 292
#define ENUM 293
#define ELLIPSIS 294
#define CASE 295
#define DEFAULT 296
#define IF 297
#define ELSE 298
#define SWITCH 299
#define WHILE 300
#define DO 301
#define FOR 302
#define GOTO 303
#define CONTINUE 304
#define BREAK 305
#define RETURN 306
#define FUNCTION 307
#define SCSPEC 308
#define TYPESPEC 309
#define TYPEMOD 310
#define ASSIGN 311
#define ARITHCOMPARE 312
#define LSHIFT 313
#define RSHIFT 314
#define UNARY 315
#define HYPERUNARY 316
#define POINTSAT 317
#define THEN 318
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    3,    3,    3,    8,
    8,    7,    7,    7,    7,    9,    9,   10,   10,   10,
   10,   10,   10,   13,   13,   13,   12,   12,   12,   14,
   14,   14,   14,   15,   15,   15,   15,   11,   11,    4,
    4,    5,    5,    5,    5,   20,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   18,   18,   21,   21,    6,
   23,   23,   23,   23,   23,   23,   25,   25,   26,   26,
   27,   27,   24,   24,   22,   22,   22,   29,   29,   17,
   17,   28,   28,   31,   31,   31,   31,   31,   31,   16,
   16,   32,   32,   33,   33,   34,   34,   35,   35,   36,
   36,   37,   37,   37,   38,   38,   38,   38,   38,   39,
   39,   39,   40,   40,   40,   41,   41,   41,   41,   42,
   42,   30,   30,   30,   30,   44,   44,   44,   44,   44,
   44,   43,   43,   43,   43,   43,   43,   43,   46,   46,
   45,   45,   45,   45,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    3,    4,    2,    3,    1,
    2,    2,    3,    3,    4,    1,    2,    1,    1,    1,
    1,    1,    1,    3,    4,    3,    5,    7,    5,    5,
    7,    6,    7,    2,    2,    2,    3,    1,    2,    2,
    3,    1,    2,    1,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    1,    3,    1,
    1,    3,    4,    4,    4,    3,    1,    3,    1,    3,
    2,    1,    1,    3,    1,    3,    4,    1,    3,    1,
    3,    1,    3,    1,    1,    1,    1,    1,    1,    1,
    5,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    1,    3,    3,    1,    3,    3,    3,    3,    1,
    3,    3,    3,    3,    1,    3,    3,    3,    1,    1,
    4,    1,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    3,    4,    2,    2,    1,    3,
    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   61,   48,   49,   50,   51,   54,   55,   52,   53,   46,
   47,    0,    0,    0,    2,    4,    5,    0,    0,    0,
    0,    0,    0,    3,   40,    0,    0,   56,    0,   10,
    0,    8,    0,   43,   45,    0,    0,   62,    0,    6,
    0,   41,    0,    0,  142,  144,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  133,   38,
  126,  128,  129,  127,   12,    0,  130,  131,   18,    0,
    0,   16,   19,   20,   21,   22,   23,   82,    0,   80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  119,    0,    0,  132,    0,   11,    9,   73,   66,
    0,    0,    0,    0,   69,  143,    0,  120,    0,   59,
   75,    7,   57,    0,    0,  123,  124,    0,    0,    0,
    0,    0,    0,    0,   34,   35,   36,    0,    0,    0,
   14,    0,   13,   17,   39,    0,   85,   86,   87,   88,
   89,   84,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  137,  138,    0,    0,  125,   71,    0,   64,
   65,    0,   63,   78,    0,   24,    0,   26,    0,    0,
    0,    0,    0,   37,  141,    0,   15,   81,   83,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  116,  117,  118,  135,  139,
    0,    0,   74,   68,   70,    0,   76,   25,    0,    0,
    0,    0,    0,  121,    0,    0,  136,  134,   77,   79,
    0,   29,   30,    0,    0,    0,   91,  140,    0,    0,
   32,    0,   28,   31,   33,
};
static const YYINT yydgoto[] = {                         13,
   14,   15,   16,   30,   31,   19,   69,   33,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   27,   20,   21,
   28,  110,   22,  102,  103,  104,  105,   80,  175,   81,
  143,   82,   83,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,  211,
};
static const YYINT yysindex[] = {                       256,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -37,    0,  256,    0,    0,    0,  -36, -112,  384,
  384,  -32,   -2,    0,    0,  344,  -13,    0,  -33,    0,
  -36,    0, -112,    0,    0,  326,  448,    0,   93,    0,
 -112,    0,  -37,  -30,    0,    0,  456,  456,  448,    6,
   35,   51,   59,  158,   84,   -6,   47,  385,    0,    0,
    0,    0,    0,    0,    0,  245,    0,    0,    0,   18,
   36,    0,    0,    0,    0,    0,    0,    0,   13,    0,
  106,  -61, -121,   27,   64,  126, -223,  -19,  -59,   28,
   75,    0,  -39,  448,    0,  133,    0,    0,    0,    0,
  -37,   -4,  156,  155,    0,    0,  109,    0,   93,    0,
    0,    0,    0,  158,  448,    0,    0,  150,  158,  448,
  448,  448,  -89,  391,    0,    0,    0,   23,   70,  186,
    0,   87,    0,    0,    0,  448,    0,    0,    0,    0,
    0,    0,  448,  448,  448,  448,  448,  448,  448,  448,
  448,  448,  448,  448,  448,  448,  448,  448,  448,  448,
  448,  448,    0,    0,  428,  448,    0,    0,  -26,    0,
    0,  576,    0,    0,  -31,    0,  158,    0,   98,  119,
  124,  197,  391,    0,    0,  448,    0,    0,    0, -121,
   39,   27,   64,  126, -223,  -19,  -19,  -59,  -59,  -59,
  -59,   28,   28,   75,   75,    0,    0,    0,    0,    0,
  138,    3,    0,    0,    0,  -18,    0,    0,  158,  158,
  158,  448,  442,    0,  448,  448,    0,    0,    0,    0,
  -56,    0,    0,  139,  158,  149,    0,    0,  158,  206,
    0,  158,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  270,    0,    0,    0,    0,    0,  -23,
   69,  315,    0,    0,    0,   44,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  617,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  723,  526,  -25,  531, 1249,  810, 1159,   -9,  994,  870,
  713,    0,  684,    0,    0,   44,    0,    0,    0,    0,
  151,    0,    0,  241,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1300,
    0, 1277, 1275, 1229, 1161,   60, 1150, 1034, 1062, 1113,
 1122,  878,  966,  752,  781,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  107,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  272,    0,  522,   66,  535,   29,  108,  221, 1289,
 -118,    0,    0,    0,    0,   -7, 1356,    0,  226,    0,
  266,  -95,    0,    0,    0,    0,  140,  900,    0, 1302,
    0,    0,  166,  165,  169,  173,  185,   56,   34,   58,
   77,   -5,    0,    0,    0,    0,
};
#define YYTABLESIZE 1579
static const YYINT yytable[] = {                         68,
  165,  145,   12,   12,   61,  183,   66,   36,   64,   62,
   29,   63,  216,  174,   68,   92,   42,   42,   92,   61,
   42,   66,   25,   64,   62,   60,   63,  114,  102,  107,
   43,  102,   92,   92,  102,   42,  170,   92,   38,  169,
  155,  118,  154,  150,  151,   42,  136,   32,  102,  102,
   68,  166,  125,  102,   40,   61,  136,   66,   37,   64,
   62,   98,   63,  119,  223,   18,  136,   92,   68,  112,
  158,  135,  159,   61,  120,   66,   60,   64,   62,   18,
   63,  184,  136,  102,  102,   34,   35,   58,  167,   29,
  121,   65,   67,  217,   60,  228,  225,  103,  122,   92,
  103,  101,   58,  103,  109,  126,  229,   67,   44,   44,
  185,  162,   44,  136,  102,  102,  160,  103,  103,   68,
  230,  161,  103,  124,   61,   68,   66,   44,   64,   62,
   61,   63,   66,   41,   64,   62,   70,   63,  219,   27,
   29,  136,  131,   67,   27,   60,   27,  146,   27,   27,
  147,   27,  103,  103,  206,  207,  208,  148,   29,  220,
  133,   67,  136,  149,  221,   27,  142,  136,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,  227,  240,
  224,  226,  136,  103,  103,  198,  199,  200,  201,  242,
   68,   72,  136,   39,   72,   61,  171,   66,  172,   64,
   62,  173,   63,  156,  157,  196,  197,  177,  144,   29,
  182,  187,   67,  202,  203,  109,   60,  237,   67,    1,
    1,  163,  164,   44,   45,   46,  186,   47,   48,   27,
  213,   27,   27,   42,  204,  205,  222,  101,  106,   45,
   46,  239,   47,   48,   92,  152,  153,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,  102,  102,  102,
  102,   49,   50,   51,  244,   52,   53,   54,   55,    1,
   56,   57,   58,   59,   44,   45,   46,   68,   47,   48,
   29,   67,   61,   67,   66,   24,   64,   62,   59,   63,
  132,  130,   44,   45,   46,   12,   47,   48,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,  113,  190,
  192,  215,   49,   50,   51,  193,   52,   53,   54,   55,
  194,   56,   57,   58,   59,   44,  103,  103,  103,  103,
   49,   50,   51,  195,   52,   53,   54,   55,    0,   56,
   57,   58,   59,   44,   45,   46,    0,   47,   48,  106,
   45,   46,    0,   47,   48,   60,    0,    0,   60,    0,
    0,    0,    0,   27,   27,   27,  100,   27,   27,    0,
   67,    0,    0,   60,    0,   60,  137,  138,  139,  140,
  141,   49,   50,   51,    0,   52,   53,   54,   55,    0,
   56,   57,   58,   59,    0,    0,    0,    0,    0,   59,
    0,   27,   27,   27,   39,   27,   27,   27,   27,    0,
   27,   27,   27,   27,   44,   45,   46,   68,   47,   48,
    0,    0,   61,   68,   66,    0,   64,   62,   61,   63,
   66,    0,   64,   62,    0,   63,    0,   60,    0,    0,
    0,    0,    0,  127,    0,    0,    0,    0,    0,   60,
    0,    0,   49,   50,   51,    0,   52,   53,   54,   55,
   68,   56,   57,   58,   59,   61,   29,   66,  209,   64,
   62,    0,   63,    0,   68,    0,    0,    0,    0,   61,
   68,   66,  235,   64,   62,   61,   63,   66,   68,   64,
   62,    0,   63,   61,    0,  115,    0,   64,   62,    0,
   63,  106,   45,   46,    0,   47,   48,    0,    0,    0,
   67,    0,    1,    0,    0,    0,   67,    0,    0,    0,
    0,   17,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,    0,   11,   17,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   23,    0,    0,    0,
    0,   59,   26,   67,   97,    0,    0,    0,    0,    0,
    0,    0,   97,    0,    0,   96,   90,   67,    0,   90,
    0,   94,    0,   67,   94,    0,    0,   96,    0,    0,
    0,   67,   99,   90,   90,    0,    0,    0,   94,   94,
    0,   97,    0,   94,    0,   60,   60,   60,   60,   60,
   60,   60,   60,   60,   60,    0,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,    0,    0,   90,    0,
    0,    0,    0,   94,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,    0,  168,    0,    0,    0,    0,
    0,  106,   45,   46,    0,   47,   48,  106,   45,   46,
   90,   47,   48,  143,  143,   94,  143,    0,  143,  143,
  143,  143,    0,  143,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,    0,  143,  143,  143,  143,  143,
    0,    0,    0,    0,  106,   45,   46,    0,   47,   48,
    0,   59,    0,    0,    0,    0,    0,   59,  106,   45,
   46,    0,   47,   48,  106,   45,   46,  143,   47,   48,
  143,    0,  106,   45,   46,    0,   47,   48,    0,    0,
  122,  122,    0,    0,  122,  122,  122,  122,  122,    0,
  122,    0,    0,    0,   59,    0,    0,    0,    0,    0,
  143,  122,  122,  122,  122,  122,  122,    0,   59,    0,
  115,    0,    0,  115,   59,  115,  115,  115,    0,  120,
  120,    0,   59,  120,  120,  120,  120,  120,    0,  120,
  115,  115,  115,    0,  115,  115,  122,  122,    0,    0,
  120,  120,  120,    0,  120,  120,    0,    0,    0,  113,
    0,    0,  113,    0,  113,  113,  113,    0,    0,   94,
   94,    0,    0,    0,    0,  115,  115,  122,  122,  113,
  113,  113,    0,  113,  113,  120,  120,    0,  114,    0,
    0,  114,    0,  114,  114,  114,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  115,  115,  114,  114,
  114,    0,  114,  114,  113,  113,  120,  120,    0,    0,
   98,    0,    0,   98,    0,    0,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,    0,   98,   98,  214,
    0,    0,   98,  114,  114,  113,  113,  143,  143,  143,
  143,  143,  143,  143,  143,  143,  143,  143,  143,  143,
  143,  143,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   98,   98,  114,  114,    0,  110,    0,    0,
  110,    0,    0,  110,    0,  111,    0,    0,  111,    0,
    0,  111,    0,    0,    0,    0,    0,  110,  110,  110,
    0,  110,  110,   98,   98,  111,  111,  111,  111,  111,
  111,    0,    0,    0,    0,    0,  122,  122,  122,  122,
  122,  122,  122,  122,  122,  122,  122,  122,  122,    0,
    0,    0,  110,  110,    0,    0,    0,    0,    0,    0,
  111,  111,    0,    0,    0,  115,  115,  115,  115,  115,
  115,  115,  115,    0,    0,  120,  120,  120,  120,  120,
  120,  120,  120,  110,  110,    0,    0,    0,    0,    0,
    0,  111,  111,  112,    0,    0,  112,    0,  111,  112,
    0,    0,    0,    0,  113,  113,  113,  113,  113,  113,
  113,  113,    0,  112,  112,  112,    0,  112,  112,    0,
    0,  105,    0,    0,  105,  188,    0,  105,    0,    0,
    0,    0,  189,  114,  114,  114,  114,  114,  114,  114,
  114,  105,  105,  105,    0,  105,  105,    0,  112,  112,
    0,    0,    0,    0,  210,    0,    0,    0,    0,    0,
    0,  108,    0,    0,  108,    0,    0,  108,   98,   98,
    0,    0,    0,    0,    0,    0,  105,  105,    0,  112,
  112,  108,  108,  108,    0,  108,  108,    0,    0,  109,
    0,    0,  109,    0,    0,  109,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  111,    0,  105,  105,  109,
  109,  109,    0,  109,  109,  238,  108,  108,    0,    0,
    0,    0,  110,  110,  110,  110,  110,  110,  110,  110,
  111,  111,  111,  111,  111,  111,  111,  111,    0,    0,
  107,    0,    0,  107,  109,  109,  107,  108,  108,  106,
    0,    0,  106,    0,    0,  106,    0,    0,    0,    0,
  107,  107,  107,    0,  107,  107,    0,    0,    0,  106,
  106,  106,    0,  106,  106,  109,  109,  104,    0,    0,
  104,    0,    0,  104,    0,    0,  100,    0,  101,  100,
    0,  101,  100,    0,  101,  107,  107,  104,  104,    0,
    0,    0,  104,    0,  106,  106,  100,  100,  101,  101,
    0,  100,    0,  101,    0,    0,    0,    0,  112,  112,
  112,  112,  112,  112,  112,  112,  107,  107,    0,    0,
    0,    0,  104,  104,    0,  106,  106,    0,    0,    0,
    0,  100,  100,  101,  101,    0,    0,    0,  105,  105,
  105,  105,  105,  105,    0,    0,    0,    0,    0,   99,
    0,    0,   99,  104,  104,    0,    0,    0,    0,    0,
    0,    0,  100,  100,  101,  101,   99,   99,    0,   96,
    0,   99,   96,    0,    0,    0,    0,    0,  108,  108,
  108,  108,  108,  108,    0,    0,   96,   96,    0,    0,
    0,   96,    0,    0,    0,   97,    0,   95,   97,    0,
   95,   99,   99,    0,    0,    0,  109,  109,  109,  109,
  109,  109,   97,   97,   95,   95,    0,   97,  108,   95,
   93,   96,  123,   93,    0,    0,    0,    0,  116,  117,
  108,    0,   99,   99,    0,    0,    0,   93,   93,  134,
    0,    0,   93,    0,    0,    0,    0,   97,    0,   95,
    0,    0,   96,   96,    0,    0,    0,  107,  107,  107,
  107,  107,  107,    0,    0,    0,  106,  106,  106,  106,
  106,  106,   93,    0,    0,  108,    0,    0,   97,   97,
    0,   95,  176,    0,    0,    0,    0,  178,    0,    0,
    0,    0,    0,  128,    0,    0,  104,  104,  104,  104,
  134,  129,    0,    0,   93,    0,    0,  100,  100,  101,
  101,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  108,    0,  108,  108,  108,
  108,  108,  108,  108,  108,  108,  108,  108,  108,  108,
  108,  108,  108,  108,    0,  218,    0,    0,    0,    0,
  129,    0,    0,    0,    0,  179,  180,  181,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  108,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,   99,    0,
  191,    0,    0,    0,    0,    0,    0,  231,  232,  233,
    0,    0,    0,    0,    0,    0,    0,   96,   96,    0,
    0,  212,    0,  241,    0,    0,  108,  243,    0,    0,
  245,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   97,   97,   95,   95,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   93,
    0,    0,    0,    0,    0,    0,    0,  234,  236,
};
static const YYINT yycheck[] = {                         33,
   40,   63,   40,   40,   38,  124,   40,   40,   42,   43,
  123,   45,   44,  109,   33,   41,   40,   41,   44,   38,
   44,   40,   59,   42,   43,   59,   45,   58,   38,   37,
   44,   41,   58,   59,   44,   59,   41,   63,   41,   44,
   60,   49,   62,  267,  268,   59,   44,   19,   58,   59,
   33,   91,   59,   63,   26,   38,   44,   40,   91,   42,
   43,   33,   45,   58,  183,    0,   44,   93,   33,   41,
   43,   59,   45,   38,   40,   40,   59,   42,   43,   14,
   45,   59,   44,   93,   94,   20,   21,   44,   94,  123,
   40,  125,  126,  125,   59,   93,   58,   38,   40,  125,
   41,   36,   59,   44,  123,   59,  125,  126,   40,   41,
   41,   37,   44,   44,  124,  125,   42,   58,   59,   33,
  216,   47,   63,   40,   38,   33,   40,   59,   42,   43,
   38,   45,   40,   26,   42,   43,   29,   45,   41,   33,
  123,   44,  125,  126,   38,   59,   40,  269,   42,   43,
  124,   45,   93,   94,  160,  161,  162,   94,  123,   41,
  125,  126,   44,   38,   41,   59,   61,   44,  281,  282,
  283,  284,  285,  286,  287,  288,  289,  290,   41,   41,
  186,   44,   44,  124,  125,  152,  153,  154,  155,   41,
   33,   41,   44,   61,   44,   38,   41,   40,   44,   42,
   43,   93,   45,  263,  264,  150,  151,   58,  270,  123,
  300,  125,  126,  156,  157,  123,   59,  225,  126,  257,
  257,  261,  262,  257,  258,  259,   41,  261,  262,  123,
  257,  125,  126,  257,  158,  159,   40,  172,  257,  258,
  259,  298,  261,  262,  270,  265,  266,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  267,  268,  269,
  270,  295,  296,  297,   59,  299,  300,  301,  302,    0,
  304,  305,  306,  307,  257,  258,  259,   33,  261,  262,
  123,   41,   38,  126,   40,   14,   42,   43,  307,   45,
   70,   66,  257,  258,  259,   40,  261,  262,  281,  282,
  283,  284,  285,  286,  287,  288,  289,  290,   43,  144,
  146,  172,  295,  296,  297,  147,  299,  300,  301,  302,
  148,  304,  305,  306,  307,  257,  267,  268,  269,  270,
  295,  296,  297,  149,  299,  300,  301,  302,   -1,  304,
  305,  306,  307,  257,  258,  259,   -1,  261,  262,  257,
  258,  259,   -1,  261,  262,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,  257,  258,  259,   41,  261,  262,   -1,
  126,   -1,   -1,   59,   -1,   61,  271,  272,  273,  274,
  275,  295,  296,  297,   -1,  299,  300,  301,  302,   -1,
  304,  305,  306,  307,   -1,   -1,   -1,   -1,   -1,  307,
   -1,  295,  296,  297,   61,  299,  300,  301,  302,   -1,
  304,  305,  306,  307,  257,  258,  259,   33,  261,  262,
   -1,   -1,   38,   33,   40,   -1,   42,   43,   38,   45,
   40,   -1,   42,   43,   -1,   45,   -1,  123,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,  295,  296,  297,   -1,  299,  300,  301,  302,
   33,  304,  305,  306,  307,   38,  123,   40,   41,   42,
   43,   -1,   45,   -1,   33,   -1,   -1,   -1,   -1,   38,
   33,   40,   41,   42,   43,   38,   45,   40,   33,   42,
   43,   -1,   45,   38,   -1,   40,   -1,   42,   43,   -1,
   45,  257,  258,  259,   -1,  261,  262,   -1,   -1,   -1,
  126,   -1,  257,   -1,   -1,   -1,  126,   -1,   -1,   -1,
   -1,    0,   -1,   -1,   -1,  281,  282,  283,  284,  285,
  286,  287,  288,   -1,  290,   14,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,   12,   -1,   -1,   -1,
   -1,  307,   18,  126,   33,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   41,   -1,   -1,   31,   41,  126,   -1,   44,
   -1,   41,   -1,  126,   44,   -1,   -1,   43,   -1,   -1,
   -1,  126,  257,   58,   59,   -1,   -1,   -1,   58,   59,
   -1,   70,   -1,   63,   -1,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   93,   -1,
   -1,   -1,   -1,   93,  281,  282,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,  101,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,   -1,  261,  262,  257,  258,  259,
  125,  261,  262,   37,   38,  125,   40,   -1,   42,   43,
   44,   45,   -1,   47,  281,  282,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   59,   60,   61,   62,   63,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  261,  262,
   -1,  307,   -1,   -1,   -1,   -1,   -1,  307,  257,  258,
  259,   -1,  261,  262,  257,  258,  259,   91,  261,  262,
   94,   -1,  257,  258,  259,   -1,  261,  262,   -1,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,  307,   -1,   -1,   -1,   -1,   -1,
  124,   58,   59,   60,   61,   62,   63,   -1,  307,   -1,
   38,   -1,   -1,   41,  307,   43,   44,   45,   -1,   37,
   38,   -1,  307,   41,   42,   43,   44,   45,   -1,   47,
   58,   59,   60,   -1,   62,   63,   93,   94,   -1,   -1,
   58,   59,   60,   -1,   62,   63,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   43,   44,   45,   -1,   -1,  269,
  270,   -1,   -1,   -1,   -1,   93,   94,  124,  125,   58,
   59,   60,   -1,   62,   63,   93,   94,   -1,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,   58,   59,
   60,   -1,   62,   63,   93,   94,  124,  125,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   58,   59,  294,
   -1,   -1,   63,   93,   94,  124,  125,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   94,  124,  125,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   58,   59,   60,
   -1,   62,   63,  124,  125,   58,   59,   60,   39,   62,
   63,   -1,   -1,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   94,   -1,   -1,   -1,  263,  264,  265,  266,  267,
  268,  269,  270,   -1,   -1,  263,  264,  265,  266,  267,
  268,  269,  270,  124,  125,   -1,   -1,   -1,   -1,   -1,
   -1,  124,  125,   38,   -1,   -1,   41,   -1,  109,   44,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
  269,  270,   -1,   58,   59,   60,   -1,   62,   63,   -1,
   -1,   38,   -1,   -1,   41,  136,   -1,   44,   -1,   -1,
   -1,   -1,  143,  263,  264,  265,  266,  267,  268,  269,
  270,   58,   59,   60,   -1,   62,   63,   -1,   93,   94,
   -1,   -1,   -1,   -1,  165,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,  269,  270,
   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,  124,
  125,   58,   59,   60,   -1,   62,   63,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  216,   -1,  124,  125,   58,
   59,   60,   -1,   62,   63,  226,   93,   94,   -1,   -1,
   -1,   -1,  263,  264,  265,  266,  267,  268,  269,  270,
  263,  264,  265,  266,  267,  268,  269,  270,   -1,   -1,
   38,   -1,   -1,   41,   93,   94,   44,  124,  125,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   58,   59,   60,   -1,   62,   63,   -1,   -1,   -1,   58,
   59,   60,   -1,   62,   63,  124,  125,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   38,   -1,   38,   41,
   -1,   41,   44,   -1,   44,   93,   94,   58,   59,   -1,
   -1,   -1,   63,   -1,   93,   94,   58,   59,   58,   59,
   -1,   63,   -1,   63,   -1,   -1,   -1,   -1,  263,  264,
  265,  266,  267,  268,  269,  270,  124,  125,   -1,   -1,
   -1,   -1,   93,   94,   -1,  124,  125,   -1,   -1,   -1,
   -1,   93,   94,   93,   94,   -1,   -1,   -1,  265,  266,
  267,  268,  269,  270,   -1,   -1,   -1,   -1,   -1,   41,
   -1,   -1,   44,  124,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,  125,  124,  125,   58,   59,   -1,   41,
   -1,   63,   44,   -1,   -1,   -1,   -1,   -1,  265,  266,
  267,  268,  269,  270,   -1,   -1,   58,   59,   -1,   -1,
   -1,   63,   -1,   -1,   -1,   41,   -1,   41,   44,   -1,
   44,   93,   94,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,   58,   59,   58,   59,   -1,   63,   37,   63,
   41,   93,   54,   44,   -1,   -1,   -1,   -1,   47,   48,
   49,   -1,  124,  125,   -1,   -1,   -1,   58,   59,   71,
   -1,   -1,   63,   -1,   -1,   -1,   -1,   93,   -1,   93,
   -1,   -1,  124,  125,   -1,   -1,   -1,  265,  266,  267,
  268,  269,  270,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,   93,   -1,   -1,   94,   -1,   -1,  124,  125,
   -1,  125,  114,   -1,   -1,   -1,   -1,  119,   -1,   -1,
   -1,   -1,   -1,   58,   -1,   -1,  267,  268,  269,  270,
  132,   66,   -1,   -1,  125,   -1,   -1,  269,  270,  269,
  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  144,   -1,  146,  147,  148,
  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,
  159,  160,  161,  162,   -1,  177,   -1,   -1,   -1,   -1,
  115,   -1,   -1,   -1,   -1,  120,  121,  122,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  186,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,   -1,
  145,   -1,   -1,   -1,   -1,   -1,   -1,  219,  220,  221,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,   -1,
   -1,  166,   -1,  235,   -1,   -1,  225,  239,   -1,   -1,
  242,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  269,  270,  269,  270,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  222,  223,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 318
#define YYUNDFTOKEN 367
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
"CONSTANT","STRING_LITERAL","SIZEOF","INC_OP","DEC_OP","LEFT_OP","RIGHT_OP",
"LE_OP","GE_OP","EQ_OP","NE_OP","AND_OP","OR_OP","MUL_ASSIGN","DIV_ASSIGN",
"MOD_ASSIGN","ADD_ASSIGN","SUB_ASSIGN","TYPEDEF","EXTERN","STATIC","AUTO",
"REGISTER","CHAR","SHORT","INT","LONG","SIGNED","UNSIGNED","FLOAT","DOUBLE",
"CONST","VOID","STRUCT","UNION","ENUM","ELLIPSIS","CASE","DEFAULT","IF","ELSE",
"SWITCH","WHILE","DO","FOR","GOTO","CONTINUE","BREAK","RETURN","FUNCTION",
"SCSPEC","TYPESPEC","TYPEMOD","ASSIGN","ARITHCOMPARE","LSHIFT","RSHIFT","UNARY",
"HYPERUNARY","POINTSAT","THEN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"compound_statement : '{' statement_list '}'",
"compound_statement : '{' declaration_list '}'",
"compound_statement : '{' declaration_list statement_list '}'",
"statement_list : statement",
"statement_list : statement_list statement",
"statement : compound_statement",
"statement : expression_statement",
"statement : selection_statement",
"statement : labeled_statement",
"statement : iteration_statement",
"statement : jump_statement",
"labeled_statement : IDENTIFIER ':' statement",
"labeled_statement : CASE conditional_expression ':' statement",
"labeled_statement : DEFAULT ':' statement",
"selection_statement : IF '(' expression ')' statement",
"selection_statement : IF '(' expression ')' statement ELSE statement",
"selection_statement : SWITCH '(' expression ')' statement",
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
"declaration_specifiers : type_qualifier",
"declaration_specifiers : type_qualifier declaration_specifiers",
"type_qualifier : CONST",
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
"primary_expression : CONSTANT",
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
#line 293 "parser.y"

int main()
{
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
	return 0;
}
#line 811 "y.tab.c"

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
