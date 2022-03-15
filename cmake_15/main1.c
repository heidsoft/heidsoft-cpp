int someFun(short param) 
{
	return param+3;
}

typedef int (*funPtr)(short param);

long foo(void) {
	funPtr f; // f is a function pointer, of type "funPtr"
	f=someFun; // f points to existing function
	return f(10); // call existing function
}