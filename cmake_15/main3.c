// https://www.cs.uaf.edu/courses/cs301/2014-fall/notes/methods/
// https://www.cs.uaf.edu/courses/cs301/2014-fall/notes/
// https://docs.huihoo.com/doxygen/linux/kernel/3.7/include_2linux_2backlight_8h_source.html

struct parent;
typedef void (*fn_parent_bar)(struct parent *this);
struct parent_vtable { /* "virtual method table", listing function pointers to all virtual methods */
	fn_parent_bar bar;	
};

struct parent {
	const struct parent_vtable *vtable;
	int v;
};

void parent_bar(struct parent *this) { printf("I'm the parent (v=%d)\n",this->v); }
void child_bar(struct parent *this) { printf("I'm the child (v=%d)\n",this->v); }

int foo(void) {
	struct parent_vtable parent_class;  /* set up parent vtable */
	parent_class.bar=parent_bar;  /* set up parent's function pointer */
	struct parent_vtable child_class;
	child_class.bar=child_bar;

	struct parent p;
	p.vtable=&parent_class;
	p.v=10;
	p.vtable->bar(&p); /* call function pointer */
	
	struct parent c; /* "child class", with different methods */
	c.vtable=&child_class;
	c.v=11;
	c.vtable->bar(&c);

	return 0;
}