struct student {
	int stress; // current stress level
	void (*response)(struct student *self); // response method
};

void response_check(struct student *self)
{
	if (self->stress<100)
		printf("I got this!\n");
	else
		printf("ARGH!\n");
}

void foo() {
	struct student s;
	s.stress=30;
	s.response=response_check; // set up method
	
	s.response(&s); // run response "method"
}