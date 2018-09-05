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
--.* 
((PROGRAM|BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|ENDIF|WHILE|ENDWHILE|RETURN|INT|VOID|STRING|FLOAT|TRUE|FALSE|FOR|ENDFOR|CONTINUE|BREAK)[*]?) {printf("Token Type: KEYWORD\nValue: %s\n", yytext);}
[a-zA-Z]+[0-9]*[^ =;\+\-\*\<\>\,\(\)\n\/\:\!]* {printf("Token Type: IDENTIFIER\nValue: %s\n", yytext);} //identifier
[0-9]+ {printf("Token Type: INTLITERAL\nValue: %s\n", yytext);count++;} //intliteral
[0-9]*\.[0-9]+ {printf("Token Type: FLOATLITERAL\nValue: %s\n", yytext);} //floatliteral
:= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
!= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
\<= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
\>= {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
[=;\+\-\*\<\>\,\(\)\/]{1} {printf("Token Type: OPERATOR\nValue: %s\n", yytext);} //Operator
[ \t\r\n]	;
 
\".*\" {printf("Token Type: STRINGLITERAL\nValue: %s\n", yytext);}
%%
 
int yywrap(){}

int main(int argc, char * argv[])
{
    //FILE * outputFile = fopen(argv[2], "w+");
    //printf("argc = %d, input file = %s, output file = %s\n", argc, argv[1], argv[2]);
    //if(argc == 3){
        char * fileName = argv[1];
        FILE * fp = fopen(fileName, "r");
        yyin = fp;

        yylex();
        //printf("# of lines = %d\n", num_lines);
        //outputFile = yyout;
        fclose(fp);
        //fclose(outputFile);
    //}else{
    //    printf("Input incorrect, exiting.\n");
    //    fclose(outputFile);
    //    return 1;
    //}
    return 0;
}