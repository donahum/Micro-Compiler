/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "src/parser.yy" /* yacc.c:339  */

  #include <stdio.h>
  #include <iostream>
  #include <string>
  #include <vector>
  #include <list>
  #include <stack>
  #include <cstring>
  #include "../src/SymbolTable.hpp"
  #include "../src/Node.hpp"
  extern int yylex();
  extern int yylineno;
  extern char * yytext;
  void yyerror(const char * s) {
      //printf("DECLARATION ERROR <%s>\n", s);
  }
  long long scope_iterator = 1;
  std::stack<SymbolTable*> ststack; 
  SymbolTable* global;
  long long currentBlockID = 0;
  //int slot_count = 1;

#line 89 "generated/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_GENERATED_PARSER_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.yy" /* yacc.c:355  */

  #include "../src/SymbolTable.hpp"
  #include "../src/Node.hpp"

#line 124 "generated/parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _PROGRAM = 258,
    _BEGIN = 259,
    _END = 260,
    _FUNCTION = 261,
    _READ = 262,
    _WRITE = 263,
    _IF = 264,
    _ELSE = 265,
    _ENDIF = 266,
    _WHILE = 267,
    _ENDWHILE = 268,
    _RETURN = 269,
    _TRUE = 270,
    _FALSE = 271,
    _FOR = 272,
    _ENDFOR = 273,
    _CONTINUE = 274,
    _BREAK = 275,
    _ASSIGN = 276,
    _NEQ = 277,
    _LEQ = 278,
    _GEQ = 279,
    _EQ = 280,
    _LT = 281,
    _GT = 282,
    _OPAREN = 283,
    _CPAREN = 284,
    _SEMICOLON = 285,
    _COMMA = 286,
    _IDENTIFIER = 287,
    _STRINGLITERAL = 288,
    _FLOATLITERAL = 289,
    _INTLITERAL = 290,
    _INT = 291,
    _VOID = 292,
    _STRING = 293,
    _FLOAT = 294,
    _MUL = 295,
    _DIV = 296,
    _PLUS = 297,
    _MINUS = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "src/parser.yy" /* yacc.c:355  */

  std::string* s;
  std::list<std::string> * str_list;
  ASTNode * node;
  WhileNode * while_node;
  IfNode * if_node;
  ElseNode * else_node;
  std::vector<ASTNode*> * ast_list;
  JumpType * jtype;
  Conditional * condition;
  //std::vector<FuncSTE> * func_ste_vec;
  //FuncSTE * func_ste;
  std::vector<SymbolTableEntry *> * ste_vec;
  SymbolTableEntry * ste;

#line 196 "generated/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "generated/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    62,    76,    79,    79,   102,   112,   127,
     133,   143,   148,   164,   165,   168,   169,   172,   179,   184,
     188,   192,   197,   205,   210,   216,   221,   225,   230,   224,
     252,   252,   272,   277,   280,   281,   282,   285,   286,   287,
     288,   292,   295,   304,   307,   310,   317,   328,   338,   341,
     353,   369,   372,   373,   376,   381,   385,   388,   389,   392,
     393,   394,   395,   398,   399,   402,   403,   408,   416,   407,
     432,   431,   445,   448,   453,   458,   465,   469,   473,   477,
     481,   485,   492,   491,   508,   511
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PROGRAM", "_BEGIN", "_END",
  "_FUNCTION", "_READ", "_WRITE", "_IF", "_ELSE", "_ENDIF", "_WHILE",
  "_ENDWHILE", "_RETURN", "_TRUE", "_FALSE", "_FOR", "_ENDFOR",
  "_CONTINUE", "_BREAK", "_ASSIGN", "_NEQ", "_LEQ", "_GEQ", "_EQ", "_LT",
  "_GT", "_OPAREN", "_CPAREN", "_SEMICOLON", "_COMMA", "_IDENTIFIER",
  "_STRINGLITERAL", "_FLOATLITERAL", "_INTLITERAL", "_INT", "_VOID",
  "_STRING", "_FLOAT", "_MUL", "_DIV", "_PLUS", "_MINUS", "$accept",
  "program", "$@1", "id", "pgm_body", "$@2", "decl", "string_decl", "str",
  "var_decl", "var_type", "any_type", "id_list", "id_tail",
  "param_decl_list", "param_decl", "param_decl_tail", "func_declarations",
  "func_decl", "$@3", "$@4", "func_body", "$@5", "stmt_list", "stmt",
  "base_stmt", "assign_stmt", "assign_expr", "read_stmt", "write_stmt",
  "return_stmt", "expr", "expr_prefix", "factor", "factor_prefix",
  "postfix_expr", "call_expr", "expr_list", "expr_list_tail", "primary",
  "addop", "mulop", "if_stmt", "@6", "$@7", "else_part", "@8", "cond",
  "compop", "while_stmt", "@9", "control_stmt", "loop_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -19,    19,   -62,    25,   -62,   -62,   -16,   -62,   -19,
     -62,    31,   -62,   -16,   -16,   -19,    26,   -62,    40,   -62,
     -62,    18,    20,    28,    -6,   -62,    40,   -19,   -62,   -62,
     -62,    21,   -62,   -62,   -19,   -62,    18,   -62,    24,   -62,
     -62,    -2,   -19,   -62,    22,   -62,    34,    -2,   -62,    58,
      22,   -16,   -62,   -62,    59,     0,   -62,    41,    42,    43,
      44,   -62,    47,   -62,     0,   -62,   -62,    45,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -19,   -19,     9,     9,    49,
     -62,   -62,   -62,   -62,    51,    52,   -62,   -62,    33,    53,
      55,   -62,    -3,   -17,   -62,    56,    57,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -16,   -16,   -62,   -62,   -62,   -62,
     -62,   -62,    46,     4,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,    60,    61,   -62,   -62,   -62,     0,     0,   -62,    54,
      64,   -62,    75,   -62,   -62,   -62,    63,   -62,    54,   -16,
      84,   -62,   -62,   -62,     0,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     9,    14,     0,
      13,     0,     5,     9,     9,     0,     0,     3,    26,     7,
       8,    19,     0,     0,     0,     6,    26,     0,    17,    12,
      11,     0,    16,    15,     0,    25,    19,    10,     0,    18,
      27,    21,     0,    28,    24,    22,     0,     0,    20,     0,
      24,     9,    23,    30,     0,    33,    29,     0,     0,     0,
       0,    48,     0,    31,    33,    34,    37,     0,    38,    39,
      84,    35,    85,    40,    36,     0,     0,    48,    48,     0,
      51,    48,    32,    41,     0,     0,    74,    75,     0,     0,
       0,    45,    46,     0,    42,     0,     0,    79,    80,    81,
      78,    76,    77,    48,     9,     9,    63,    64,    47,    48,
      62,    61,    60,    49,    53,    52,    43,    44,    73,    67,
      82,     0,    48,    65,    66,    50,    33,    33,    59,    58,
       0,    68,     0,    48,    55,    54,    72,    83,    58,     9,
       0,    57,    70,    69,    33,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,     1,   -62,   -62,   -13,   -62,   -62,   -62,
     -20,   -62,   -34,    62,   -62,    50,    65,    70,   -62,   -62,
     -62,   -62,   -62,   -61,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -55,   -62,   -62,   -62,   -62,   -62,   -62,   -39,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    23,   -62,   -62,
     -62,   -62,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    62,    11,    18,    12,    13,    31,    14,
      15,    34,    22,    28,    43,    44,    48,    25,    26,    41,
      46,    54,    55,    63,    64,    65,    66,    67,    68,    69,
      70,    88,    80,    92,    93,   113,   114,   130,   134,   115,
     108,   125,    71,   126,   136,   140,   144,    89,   103,    72,
     127,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    20,     4,    82,    33,     1,    79,    57,    58,    59,
      16,   109,    60,     3,    61,     3,    21,   110,   111,     5,
       8,    42,     9,    10,    86,    87,    94,    42,    36,     6,
       8,    32,     3,    10,     8,    38,    17,    10,    53,   106,
     107,    84,    85,    45,   123,   124,    24,    23,   118,    27,
      29,    37,    40,    47,   121,    97,    98,    99,   100,   101,
     102,    30,    51,    49,    56,   131,   132,   129,    81,    75,
      76,    77,    78,   139,   122,    83,    21,    21,   138,    91,
      95,    96,   104,   145,   105,   133,   116,   117,   137,   128,
     -56,   119,   120,   135,   112,   143,    35,    50,    39,   141,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      13,    14,     1,    64,    24,     3,    61,     7,     8,     9,
       9,    28,    12,    32,    14,    32,    15,    34,    35,     0,
      36,    41,    38,    39,    15,    16,    81,    47,    27,     4,
      36,    37,    32,    39,    36,    34,     5,    39,    51,    42,
      43,    75,    76,    42,    40,    41,     6,    21,   103,    31,
      30,    30,    28,    31,   109,    22,    23,    24,    25,    26,
      27,    33,     4,    29,     5,   126,   127,   122,    21,    28,
      28,    28,    28,    10,    28,    30,    75,    76,   133,    30,
      29,    29,    29,   144,    29,    31,    30,    30,    13,    29,
      29,   104,   105,    29,    93,    11,    26,    47,    36,   138,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    45,    32,    47,     0,     4,    46,    36,    38,
      39,    48,    50,    51,    53,    54,    47,     5,    49,    50,
      50,    47,    56,    21,     6,    61,    62,    31,    57,    30,
      33,    52,    37,    54,    55,    61,    47,    30,    47,    57,
      28,    63,    54,    58,    59,    47,    64,    31,    60,    29,
      59,     4,    60,    50,    65,    66,     5,     7,     8,     9,
      12,    14,    47,    67,    68,    69,    70,    71,    72,    73,
      74,    86,    93,    95,    96,    28,    28,    28,    28,    75,
      76,    21,    67,    30,    56,    56,    15,    16,    75,    91,
      91,    30,    77,    78,    75,    29,    29,    22,    23,    24,
      25,    26,    27,    92,    29,    29,    42,    43,    84,    28,
      34,    35,    47,    79,    80,    83,    30,    30,    75,    50,
      50,    75,    28,    40,    41,    85,    87,    94,    29,    75,
      81,    67,    67,    31,    82,    29,    88,    13,    75,    10,
      89,    82,    50,    11,    90,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    49,    48,    50,    50,    50,
      51,    52,    53,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    63,    64,    62,
      66,    65,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    70,    71,    72,    73,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    87,    88,    86,
      90,    89,    89,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    94,    93,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     0,     3,     2,     2,     0,
       5,     1,     3,     1,     1,     1,     1,     2,     3,     0,
       2,     0,     2,     3,     0,     2,     0,     0,     0,    11,
       0,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     5,     5,     3,     2,     3,     0,     2,
       3,     0,     1,     1,     4,     2,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     0,    10,
       0,     4,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     8,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "src/parser.yy" /* yacc.c:1646  */
    {
                      global = new SymbolTable("GLOBAL", NULL);
                      ststack.push(global);
                    }
#line 1403 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "src/parser.yy" /* yacc.c:1646  */
    {
                                      for(auto func : *(yyvsp[-1].ast_list)){
                                        if(func){
                                          func -> TO_IR(NULL);
                                        }
                                      }
                                    }
#line 1415 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.s) = new std::string(yytext);}
#line 1421 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "src/parser.yy" /* yacc.c:1646  */
    { //ststack.top()->printST();
                              for(auto entry : *(yyvsp[0].ste_vec))
                              {
                                  //std::cout << "adding to global " << entry->name << std::endl;
                                  //entry->printSTE();
                                  //std::cout << std::endl;
                                  ststack.top()->addEntry(entry);
                                  //entry->printSTE();
                                  //std::cout << std::endl;
                              }
                              ststack.top()->numLocals = (yyvsp[0].ste_vec)->size();
                              //ststack.top()->printST();
                            }
#line 1439 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "src/parser.yy" /* yacc.c:1646  */
    { 
                                            (yyval.ast_list) = (yyvsp[0].ast_list); 
                                            for(auto funcST : *(yyvsp[0].ast_list))
                                            {
                                              //static_cast<FuncNode *> (funcST)->table->printST();
                                            }
                                          }
#line 1451 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "src/parser.yy" /* yacc.c:1646  */
    {//std::cout << "str decl\n";
                                          (yyval.ste_vec) = (yyvsp[0].ste_vec);
                                          /*for(auto entry : *$2)
                                          {
                                            $$->push_back(entry);
                                          }*/
                                          (yyval.ste_vec)->push_back((yyvsp[-1].ste));
                                          //$$->push_back(*$1);

                                        }
#line 1466 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "src/parser.yy" /* yacc.c:1646  */
    {//std::cout << "var decl\n";
                                          (yyval.ste_vec) = (yyvsp[0].ste_vec);
                                          //int i = 0;
                                          //$$ = new std::vector<SymbolTableEntry>();
                                          for(auto entry : *(yyvsp[-1].ste_vec))
                                          {
                                            (yyval.ste_vec)->push_back(entry);
                                            //$$->insert($$->begin() + i, entry);
                                            //i++;
                                          }
                                          /*for(auto entry : *$2)
                                          {
                                            $$->push_back(entry);
                                          }*/
                                      }
#line 1486 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "src/parser.yy" /* yacc.c:1646  */
    { //std::cout << "empty decl\n";
                                (yyval.ste_vec) = new std::vector<SymbolTableEntry *>;
                              }
#line 1494 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "src/parser.yy" /* yacc.c:1646  */
    {
                      SymbolTableEntry* tmp = new SymbolTableEntry(*(yyvsp[-3].s), "STRING", *(yyvsp[-1].s), 0);
                      (yyval.ste) = tmp;
                      //tmp->printSTE();
                      //std::cout<<std::endl;
                      //ststack.top()->addEntry(tmp);
                    }
#line 1506 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.s) = new std::string(yytext);}
#line 1512 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "src/parser.yy" /* yacc.c:1646  */
    { 
                      (yyval.ste_vec) = new std::vector<SymbolTableEntry *>;
                      //for(auto &varName : *$2){
                      for(std::list<std::string>::reverse_iterator rit = (yyvsp[-1].str_list)->rbegin();  rit != (yyvsp[-1].str_list)->rend();  ++rit){
                        //std::cout << "Var Name: " << varName << std::endl;
                        SymbolTableEntry * varEntry = new SymbolTableEntry(*rit, *(yyvsp[-2].s), 0);
                        (yyval.ste_vec)->push_back(varEntry);
                        //ststack.top()->addEntry(varEntry);
                        //varEntry->printSTE();
                        //std::cout << std::endl;
                      }
                      //$$ = var_entries;
                    }
#line 1530 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.s) = new std::string("FLOAT");}
#line 1536 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 165 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.s) = new std::string("INT");}
#line 1542 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1548 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.s) = new std::string("VOID");}
#line 1554 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 173 "src/parser.yy" /* yacc.c:1646  */
    {
                      (yyval.str_list) = (yyvsp[0].str_list);
                      (yyval.str_list)->push_front(*(yyvsp[-1].s));
                    }
#line 1563 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 180 "src/parser.yy" /* yacc.c:1646  */
    {
                      (yyval.str_list) = (yyvsp[0].str_list);
                      (yyval.str_list)->push_front(*(yyvsp[-1].s));
                    }
#line 1572 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 184 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.str_list) = new std::list<std::string>;}
#line 1578 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 188 "src/parser.yy" /* yacc.c:1646  */
    {
                                                      (yyval.ste_vec) = (yyvsp[0].ste_vec);
                                                      (yyval.ste_vec)->insert((yyval.ste_vec)->begin(), (yyvsp[-1].ste));
                                                  }
#line 1587 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 192 "src/parser.yy" /* yacc.c:1646  */
    {
                                (yyval.ste_vec) = new std::vector<SymbolTableEntry *>;
                              }
#line 1595 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 198 "src/parser.yy" /* yacc.c:1646  */
    {
                      SymbolTableEntry * tmp = new SymbolTableEntry(*(yyvsp[0].s), *(yyvsp[-1].s), 0);
                      //ststack.top()->addEntry(tmp);
                      (yyval.ste) = tmp;
                    }
#line 1605 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "src/parser.yy" /* yacc.c:1646  */
    {
                                                            (yyval.ste_vec) = (yyvsp[0].ste_vec);
                                                            (yyval.ste_vec)->insert((yyval.ste_vec)->begin(), (yyvsp[-1].ste));
                                                            //slot_count++;
                                                        }
#line 1615 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "src/parser.yy" /* yacc.c:1646  */
    {
                                  //slot_count = 1;
                                  (yyval.ste_vec) = new std::vector<SymbolTableEntry *>;
                              }
#line 1624 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 217 "src/parser.yy" /* yacc.c:1646  */
    {
                      (yyval.ast_list) = (yyvsp[0].ast_list);
                      (yyval.ast_list)->insert((yyval.ast_list)->begin(), (yyvsp[-1].node));
                    }
#line 1633 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.ast_list) = new std::vector<ASTNode *>;}
#line 1639 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "src/parser.yy" /* yacc.c:1646  */
    {
                      SymbolTable* tmp = new SymbolTable(*(yyvsp[-1].s), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    }
#line 1649 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "src/parser.yy" /* yacc.c:1646  */
    { //std::cout << "Printing func params...\n";
                                      int i = 2;  //param slots start at 2, after return pc from link
                                      for(auto param : *(yyvsp[0].ste_vec))
                                      {
                                        //param->slot = i - $6->size();
                                        param->slot = i++;  
                                        ststack.top()->addEntry(param);
                                        //param->printSTE();
                                        //i++;
                                      }
                                      //std::cout << "Param Size: " << $6->size() << std::endl;
                                      ststack.top()->numParams = (yyvsp[0].ste_vec)->size();
                                    }
#line 1667 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 244 "src/parser.yy" /* yacc.c:1646  */
    {
                      //std::cout << "here's what the funcnode is getting...\n";
                      //ststack.top()->printST();
                      (yyval.node) = new FuncNode(*(yyvsp[-8].s), (yyvsp[-1].ast_list), ststack.top(), ASTNodeType::FUNC);
                      ststack.pop();
                    }
#line 1678 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 252 "src/parser.yy" /* yacc.c:1646  */
    {
                              int i = 0;
                              //std::cout << "Printing function locals\n";
                              for(auto local : *(yyvsp[0].ste_vec))
                              {
                                //local->slot = i++;
                                local->slot = i++ - (yyvsp[0].ste_vec)->size();
                                //local->printSTE();
                                ststack.top()->addEntry(local);
                                //std::cout<<std::endl;
                              }
                              //std::cout << "Local Size: " << $1->size() << std::endl;
                              ststack.top()->numLocals = (yyvsp[0].ste_vec)->size();
                              //std::cout << "here's what the func_body is getting...\n";
                              //ststack.top()->printST();
                            }
#line 1699 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 268 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.ast_list) = (yyvsp[0].ast_list);}
#line 1705 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 273 "src/parser.yy" /* yacc.c:1646  */
    {   
                      (yyval.ast_list) = (yyvsp[0].ast_list);
                      (yyval.ast_list)->insert((yyval.ast_list)->begin(), (yyvsp[-1].node));
                    }
#line 1714 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 277 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.ast_list) = new std::vector<ASTNode*>;}
#line 1720 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 280 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1726 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 281 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1732 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 282 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1738 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 285 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1744 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 286 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1750 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 287 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1756 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 288 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1762 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 292 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1768 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "src/parser.yy" /* yacc.c:1646  */
    {
                      VarRefNode* vid = new VarRefNode(*(yyvsp[-2].s), ASTNodeType::VAR_REF);
                      (yyval.node) = new AssignNode(vid, (yyvsp[0].node), ASTNodeType::ASSIGN);
                      //$$->printTree();
                      //std::cout << std::endl;
                    }
#line 1779 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 304 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = new ReadNode((yyvsp[-2].str_list), ASTNodeType::READ);}
#line 1785 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 307 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = new WriteNode((yyvsp[-2].str_list), ASTNodeType::WRITE);}
#line 1791 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 310 "src/parser.yy" /* yacc.c:1646  */
    {
                                                (yyval.node) = new ReturnNode(ASTNodeType::RET);
                                                (yyval.node)->Right = (yyvsp[-1].node);
                                              }
#line 1800 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 318 "src/parser.yy" /* yacc.c:1646  */
    {
                      if((yyvsp[-1].node) == NULL){
                        (yyval.node)=(yyvsp[0].node);
                      }else{
                        (yyvsp[-1].node)->Right=(yyvsp[0].node);
                        (yyval.node) = (yyvsp[-1].node);
                      }
                    }
#line 1813 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 329 "src/parser.yy" /* yacc.c:1646  */
    {
                      (yyval.node) = (yyvsp[0].node);
                      if((yyvsp[-2].node) == NULL){
                        (yyval.node)->Left=(yyvsp[-1].node);
                      }else{
                        (yyval.node)->Left=(yyvsp[-2].node);
                        (yyvsp[-2].node)->Right=(yyvsp[-1].node);
                      }
                    }
#line 1827 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 338 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1833 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 342 "src/parser.yy" /* yacc.c:1646  */
    {
                      if((yyvsp[-1].node) == NULL)
                      {
                        (yyval.node) = (yyvsp[0].node);
                      }else{
                        (yyvsp[-1].node)->Right=(yyvsp[0].node);
                        (yyval.node)= (yyvsp[-1].node);
                      }
                    }
#line 1847 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 354 "src/parser.yy" /* yacc.c:1646  */
    {
                      (yyval.node) = (yyvsp[0].node);
                      if((yyvsp[-2].node) == NULL) {
                          (yyval.node)->Left = (yyvsp[-1].node);
                      }else{
                        if((yyvsp[-2].node)->Right == NULL){
                          (yyvsp[-2].node)->Right = (yyvsp[-1].node);
                          (yyvsp[0].node)->Left = (yyvsp[-2].node);
                        }else{
                          //may need to fix strat here
                          (yyval.node)->Left = (yyvsp[-2].node);
                          (yyval.node)->Right=(yyvsp[-1].node);
                        }
                      }
                    }
#line 1867 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 369 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1873 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 372 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1879 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1885 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 376 "src/parser.yy" /* yacc.c:1646  */
    {
                                                      (yyval.node) = new CallNode((yyvsp[-1].ast_list), *(yyvsp[-3].s), ASTNodeType::CALL_EXPR);
                                                    }
#line 1893 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 381 "src/parser.yy" /* yacc.c:1646  */
    {
                                            (yyval.ast_list) = (yyvsp[0].ast_list);   
                                            (yyval.ast_list)->push_back((yyvsp[-1].node));
                                          }
#line 1902 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 385 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.ast_list) = new std::vector<ASTNode *>; }
#line 1908 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 388 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.ast_list) = (yyvsp[0].ast_list);  (yyval.ast_list)->push_back((yyvsp[-1].node)); }
#line 1914 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 389 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.ast_list) = new std::vector<ASTNode *>; }
#line 1920 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 392 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1926 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 393 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new VarRefNode(*(yyvsp[0].s), ASTNodeType::VAR_REF); }
#line 1932 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 394 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode(LiteralType::isINT, *(new std::string(yytext)), ASTNodeType::LITERAL);}
#line 1938 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 395 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new LiteralNode(LiteralType::isFLOAT, *(new std::string(yytext)), ASTNodeType::LITERAL); }
#line 1944 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 398 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new AddExprNode("+", ASTNodeType::ADD_EXPR); }
#line 1950 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 399 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new AddExprNode("-", ASTNodeType::ADD_EXPR); }
#line 1956 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 402 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new MulExprNode("*", ASTNodeType::MULT_EXPR); }
#line 1962 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 403 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = new MulExprNode("/", ASTNodeType::MULT_EXPR); }
#line 1968 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 408 "src/parser.yy" /* yacc.c:1646  */
    {
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      (yyval.if_node) = new IfNode((yyvsp[-2].condition)->left_expr, (yyvsp[-2].condition)->right_expr, currentBlockID, (yyvsp[-2].condition)->jtype, ASTNodeType::IF);
                    }
#line 1980 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 416 "src/parser.yy" /* yacc.c:1646  */
    {
                      ststack.pop();
                    }
#line 1988 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 420 "src/parser.yy" /* yacc.c:1646  */
    {            
                      //std::cout << "Stmt List Address: " << $7 << std::endl;
                      //std::cout << "Else Address: " << $9 << std::endl;
                      //if (!$7->empty()){
                        (yyvsp[-4].if_node)->copyStmtList(*(yyvsp[-3].ast_list));
                      //}else if ($9 != NULL){
                        (yyvsp[-4].if_node)->copyElseNode( (ElseNode *) (yyvsp[-1].node));
                     // }
                      (yyval.node) = (yyvsp[-4].if_node);
                    }
#line 2003 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 432 "src/parser.yy" /* yacc.c:1646  */
    { 
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      (yyval.else_node) = new ElseNode(currentBlockID, ASTNodeType::ELSE);
                    }
#line 2015 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 440 "src/parser.yy" /* yacc.c:1646  */
    {
                      ststack.pop();
                      (yyvsp[-1].else_node)->copyStmtList(*(yyvsp[0].ast_list));
                      (yyval.node) = (yyvsp[-1].else_node);
                    }
#line 2025 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 445 "src/parser.yy" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2031 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 449 "src/parser.yy" /* yacc.c:1646  */
    { 
                                          (yyval.condition) = new Conditional();
                                          (yyval.condition)->Fill((yyvsp[-2].node), (yyvsp[0].node), *(yyvsp[-1].jtype));
                                        }
#line 2040 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 454 "src/parser.yy" /* yacc.c:1646  */
    {
                                (yyval.condition) = NULL;
                                std::cout << "True cond found\n";
                              }
#line 2049 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 459 "src/parser.yy" /* yacc.c:1646  */
    {
                                (yyval.condition) = NULL;
                                std::cout << "False cond found\n";
                              }
#line 2058 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 466 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::L_T);
                            }
#line 2066 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 470 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::G_T);
                            }
#line 2074 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 474 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::E_Q);
                            }
#line 2082 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 478 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::N_E);
                            }
#line 2090 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 482 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::L_E);
                            }
#line 2098 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 486 "src/parser.yy" /* yacc.c:1646  */
    {
                              (yyval.jtype) = new JumpType(JumpType::G_E);
                            }
#line 2106 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 492 "src/parser.yy" /* yacc.c:1646  */
    { 
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      (yyval.while_node) = new WhileNode((yyvsp[-2].condition)->left_expr, (yyvsp[-2].condition)->right_expr, currentBlockID, (yyvsp[-2].condition)->jtype, ASTNodeType::WHILE);
                    }
#line 2118 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 500 "src/parser.yy" /* yacc.c:1646  */
    {  
                      ststack.pop(); 
                      (yyvsp[-2].while_node)->copyStmtList(*(yyvsp[-1].ast_list));
                      (yyval.node) = (yyvsp[-2].while_node);
                    }
#line 2128 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 508 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2134 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 511 "src/parser.yy" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2140 "generated/parser.cpp" /* yacc.c:1646  */
    break;


#line 2144 "generated/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 514 "src/parser.yy" /* yacc.c:1906  */

