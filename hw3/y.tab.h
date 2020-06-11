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
extern YYSTYPE yylval;
