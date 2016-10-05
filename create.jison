%lex

%%
\s+ {}
"create" {return 'CREATE_TABLE'}
"{"    {return '{'}
"}"    {return '}'}
"title" {return 'TITLE'}
"data" {return 'DATA'}
","    {return ','}
";"    {return ';'}
"[a-zA-Z0-9.]"  {return 'TEXT'}

/lex

%start TABLEBUILDER

%%

TABLEBUILDER 
    : CREATE_STATEMENT {return $1;}
    ;

CREATE_STATEMENT 
    : { TITLE_STATEMENT } {$$ = $2;}
    ;

{
    : '{'    {$$ = $1;}
    ;

} 
    : '}'    {$$ = $1;}
    ;

TITLE_STATEMENT 
    : { VALUES } {$$ = $2;}
    ;

VALUES 
    : TEXT ';' {$$ = $1;}
    | TEXT ',' VALUES {$$?}//DOTO FURTHER 

    ;
