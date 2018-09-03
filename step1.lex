/*** Definition Section has one variable
which can be accessed inside yylex() 
and main() ***/
%{
int count = 0;
%}
 
/*** Rule Section has three rules, first rule 
matches with capital letters, second rule
matches with any character except newline and 
third rule does not take input after the enter***/
%%
//--.\n {printf("Token Type: COMMENT\nValue: %s\n", yytext);}
//'"[d]\"yo"' {printf("Token Type: STRINGLITERAL\nValue: %s\n", yytext);}
(PROGRAM|BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|ENDIF|WHILE|ENDWHILE|RETURN|INT|VOID|STRING|FLOAT|TRUE|FALSE|FOR|ENDFOR|CONTINUE|BREAK) {printf("Token Type: KEYWORD\nValue: %s\n", yytext);}
([a-zA-Z]+[^ \n=;]) {printf("Token Type: IDENTIFIER\nValue: %s\n", yytext);} //identifier
[0-9]+ {printf("Token Type: INTLITERAL\nValue: %s\n", yytext);} //intliteral
[0-9]*\.[0-9]+ {printf("Token Type: FLOATLITERAL\nValue: %s\n", yytext);} //floatliteral
:= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
!= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
\<= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
\>= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
[=;\+\-\*\<\>\,\(\)]{1} {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
[<<EOF>>]    {printf("END\n");}
[ \n]		 
%%
 
/*** Code Section prints the number of
capital letter present in the given input***/
//int yywrap(){}
int yywrap(){}
int main(int argc, char **argv){
// Explanation:
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer 
          which contains the input*/
/* yylex() - this is the main flex function
          which runs the Rule Section*/
// yytext is the text in the buffer
 
// Uncomment the lines below 
// to take input from file
 FILE *fp;
 //char filename[50];
 //printf("Enter the filename: \n");
 //scanf("%s",filename);
 fp = fopen(argv[1],"r");
 yyin = fp;
/*if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
else
        yyin = stdin;
    yylex();
*/
yylex();
printf("Finished, found %d tokens\n", count);
 
return 0;
}
