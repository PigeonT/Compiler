%lex
%%

\s+                   /* skip whitespace */
"{"                   return '{'
"}"                   return '}'
[0-9]+                return 'NUMBER'
"+"                   return '+'
"-"                   return '-'
"*"                   return '*'
"/"                   return '/'
"pigeon"              return 'pigeon'
"quynh"               return 'quynh'

/lex


%left '+' '-'
%left '*' '/'

%start expressions2

%% 

expressions2
    : 'pigeon' e 'quynh' 
       {console.log($2); return $2;}
    ;
e  
    : NUMBER {$$ = Number(yytext);}
    | e '+' e {$$ = $1 + $3;}
    | e '-' e {$$ = $1 - $3;}
    | e '*' e {$$ = $1 * $3;}
    | e '/' e {$$ = $1 / $3;}
    ;



