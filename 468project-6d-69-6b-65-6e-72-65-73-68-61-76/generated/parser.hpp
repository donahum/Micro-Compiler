/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 18 "src/parser.yy" /* yacc.c:1909  */

    #ifndef ST_H
    #define ST_H
    #include "../src/SymbolTable.hpp"
    #endif

    #ifndef STE_H
    #define STE_H
    #include "../src/SymbolTableEntry.hpp"
    #endif

    //#ifndef AST_H
    //#define AST_H
    #ifndef AST_H
    #include "../src/ASTNode.hpp"
    #endif

    #ifndef ADDNODE_H
    #include "../src/AddExprNode.hpp"
    #endif

    #ifndef MULNODE_H
    #include "../src/MulExprNode.hpp"
    #endif

    #ifndef VARNODE_H
    #include "../src/VarRefNode.hpp"
    #endif

    #ifndef LITERALNODE_H
    #include "../src/LiteralNode.hpp"
    #endif


#line 79 "generated/parser.hpp" /* yacc.c:1909  */

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
#line 70 "src/parser.yy" /* yacc.c:1909  */

  SymbolTableEntry * s_entry;
  char * s;
  SymbolTable * s_table;
  std::vector<SymbolTable *> * st_list;
  std::vector<char *> * str_list;
  ASTNode * node;
  AddExprNode * add_node;
  MulExprNode * mul_node;
  VarRefNode * var_node;
  LiteralNode * lit_node;
  std::vector<ASTNode*>* astlist;

#line 149 "generated/parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */
