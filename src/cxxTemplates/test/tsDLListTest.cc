


#include <tsDLList.h>
#include <assert.h>
#include <stdio.h>

class fred : public tsDLNode<fred> {
public:
	fred(const char * const pNameIn) : pName(pNameIn){}
	void show () {printf("%s\n", pName);}
private:
	const char * const pName;
};

class jane : public fred, public tsDLNode<jane> {
public:
	jane(const char * const pNameIn) : fred(pNameIn){}
private:
};

main ()
{
	tsDLList<fred>	list;
	tsDLIter<fred>	iter(list);
	fred		*pFred;
	fred		*pFredII;
	fred		*pFredBack;
	tsDLList<jane>	janeList;
	tsDLIter<jane>	janeIter(janeList);
	jane		*pJane;

	pFred = new fred("A");
	pFredII = new fred("B");

	list.add(*pFred);
	list.add(*pFredII);
	pFredBack = list.first();
	assert(pFredBack == pFred);
	pFredBack = list.last();
	assert(pFredBack == pFredII);
	list.remove(*pFred);
	list.add(*pFred);
	pFredBack = list.get();
	assert (pFredBack == pFredII);
	pFredBack = list.get();
	assert (pFredBack == pFred);
	assert (list.count() == 0u);
	list.add(*pFred);
	list.add(*pFredII);
	list.add(* new fred("C"));
	list.add(* new fred("D"));

	while (pFredBack = iter()) {
		pFredBack->show();
	}

	pJane = new jane("JA");
	janeList.add(*pJane);	
	pJane = new jane("JB");
	janeList.add(*pJane);	

	while (pJane = janeIter()) {
		pJane->show();
	}

	iter = list;
	while (pFredBack = iter()) {
		pFredBack->show();
	}
}

