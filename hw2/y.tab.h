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
extern YYSTYPE yylval;
