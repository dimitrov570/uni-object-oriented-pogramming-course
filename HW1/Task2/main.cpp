#include <iostream>
#include "DNSRecord.h"
#include "DNSCache.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 

void testDNSRecord()
{
	DNSRecord a;
	DNSRecord b("bbbb", "11/230");
	DNSRecord c = b;
	DNSRecord d(b);


	std::cout << a.getName() << '\n' << a.getIpAdress() << '\n';

	std::cout << b.getName() << '\n' << b.getIpAdress() << '\n';

	c.setName("ccccc");
	c.setIpAdress("26.06");
	std::cout << c.getName() << '\n' << c.getIpAdress() << '\n';

	d.setName("dddDDddd"); d.setIpAdress("999/744lsf9");
	std::cout << d.getName() << '\n' << d.getIpAdress() << '\n';
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	//testDNSRecord();

	DNSRecord a;
	DNSRecord b("bBbB", "bb/23b0");
	DNSRecord c = b;
	c.setName("cCcC"); c.setIpAdress("cc/23c0");
	DNSRecord d(b);
	d.setName("dDdD"); d.setIpAdress("dd/23d0");
	DNSRecord e("eEeE", "ee/24e0");
	DNSRecord f("fFfF", "ff/23f0");
	DNSRecord g("gGgG", "gg/23g0");
	DNSRecord h("hHhH", "hh/23h0");
	DNSRecord i("iIiI", "ii/23i0");
	DNSRecord j("jJjJ", "jj/23j0");
	DNSRecord k("kKkK", "kk/23k4");
	DNSRecord l("lLlL", "ll/23l0");
	DNSRecord m("mMmM", "mm/23m0");
	DNSRecord n("nNnN", "nn/23n0");
	

	DNSCache cache1;
	cache1.add(b);
	cache1.add(c);
	cache1.add(d);
	cache1.add(e);
	cache1.add(f);
	cache1.add(g);
	cache1.add(i);
	cache1.add(h);
	cache1.add(j);
	cache1.add(k);

	std::cout << "Is full: " << cache1.full()<<"\n";
	std::cout << "Is empty: " << cache1.empty() << "\n\n";

	//cache1.add(l);
	//cache1.add(m);
	//cache1.add(n);
	
	std::cout << cache1.lookup("bBbB") << " == " << b.getIpAdress() << '\n';
	std::cout << cache1.lookup("cCcC") << " == " << c.getIpAdress() << '\n';

	std::cout << "\n\n";

	cache1.print();
	cache1.flush();

	std::cout << "Is full: " << cache1.full() << "\n";
	std::cout << "Is empty: " << cache1.empty() << "\n";
	
	//cache1.print();

	return 0;
}