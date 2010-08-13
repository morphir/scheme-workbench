typedef struct {
	  int row;   // x-axis
	  int column; // y-axis
      int items[STACKSIZE];
  } PAREN_STACK;

/**
 * Edit-mode in REPL should dynamically expand the matrix
 */ 

function repl(char_input){

 while(char_input){
	cursor_buffer++; 
	PAREN_STACK[0]; //initialize parentheses stack
	if(input_char=='('){ //have to keep track of parentheses coordinates at all time.
	  PAREN_STACK[++];
	}
	while(char_input=='enter'){
		newlinebuffer(); //make buffer span over a new line   
		if(y_buffer==null && char_input=='enter'){
			exit();// two enters in a row ends the function editing
			}
			else {
				sexpr_indent(PAREN_STACK);      //set cursor to its respective coordinates
				balance_cursor(PAREN_STACK);
				}
				}}

}

/**
 * Proper lisp indention has two rules.
 * See page 160, A.2 'Scheme Style Guide' in Sketchy Lisp by Nils Holm
 */
function sexpr_ident(PAREN_STACK)
{
	// indention-rule 1
	if (input_char == 'enter' && PAREN_STACK==1)
	{
		move_cursor(PAREN_STACK.column[+2]); //2 spaces
	}
    //indention-rule 2
	if (input_char == 'enter' && PAREN_STACK>=2)
	{
		move_cursor(PAREN_STACK.column[+1]
		            PAREN_STACK.row[+1])
	}
}

/**
 * Highlight cursor when parens are balanced
 */
function balance_cursor(PAREN_STACK)
{
		if(char_input=='(')
		{  
			PUSH_PAREN_TO_STACK(); // counts matching parens.
		}
		if(char_input==')')
		{
			POP_PAREN_OFF_STACK();
			if (PAREN_STACK !< 0)
			blink_closest_matching_paren();
		}
}

int pop(STACK *ps)
{
    if (ps->size == 0){
        fputs("Error: stack underflow\n", stderr);
        abort();
    } else 
        return ps->items[--ps->size];
}

void push(STACK *ps, int x)
{
    if (ps->size == STACKSIZE) {
        fputs("Error: stack overflow\n", stderr);
        abort();
    } else 
        ps->items[ps->size++] = x;
}

