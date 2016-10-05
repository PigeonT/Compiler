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
"[a-zA-Z0-9.]"  {return 'VALUE'}

/lex

%start TABLEBUILDER

%%

TABLEBUILDER 
    : CREATE_STATEMENT {return $1;}
    ;



