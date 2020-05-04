#include <iostream>
#include "Guest.h"
#include "User.h"
#include "PowerUser.h"
#include "Vip.h"
#include "Admin.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Guest guest1("12345");
	std::cout << "Guest1's ip adress is: " << guest1.getIpAdress()<<'\n';

	User user1("121212","user1","1user","USER");
	std::cout << "IP: " << user1.getIpAdress() << " Username: " << user1.getUsername() << " Title: " << user1.getTitle() << '\n';

	user1.changePassword("asfg", "1UsEr1"); //wrong old password
	user1.changePassword("1user", "1UsEr1"); //correct old password

	PowerUser powerUser1("131313", "PowerUser1", "1PowerUser", "POWERUSER");
	std::cout << "IP: " << powerUser1.getIpAdress() << " Username: " << powerUser1.getUsername() << " Title: " << powerUser1.getTitle() 
		   	  << " Reputation: " << powerUser1.getReputation() << '\n';

	powerUser1.increaseReputation(powerUser1); //trying to increase own reputation

	powerUser1.increaseReputation(user1);	//other user increasing reputation of PowerUser
	std::cout << powerUser1.getUsername() << "'s reputation is: " << powerUser1.getReputation() << '\n';

	VIP vip1("141414", "VipUser1", "1ViPuSeR", "VIP");
	std::cout << "IP: " << vip1.getIpAdress() << " Username: " << vip1.getUsername() << " Title: " << vip1.getTitle() << '\n';

	vip1.changeTitle("vIp");
	std::cout << "IP: " << vip1.getIpAdress() << " Username: " << vip1.getUsername() << " Title: " << vip1.getTitle() << '\n';

	Admin admin1("5555555", "admin1", "ADMINadmin", "ADMIN");
	std::cout << "IP: " << admin1.getIpAdress() << " Username: " << admin1.getUsername() << " Title: " << admin1.getTitle()
		<< " Reputation: " << admin1.getReputation() << '\n';

	admin1.increaseReputation(admin1); //trying to increase own reputation
	admin1.increaseReputation(powerUser1);
	admin1.increaseReputation(user1);
	admin1.increaseReputation(vip1); //admin1's reputation should be 3 after this line

	std::cout << "IP: " << admin1.getIpAdress() << " Username: " << admin1.getUsername() << " Title: " << admin1.getTitle()
		<< " Reputation: " << admin1.getReputation() << '\n';

	admin1.changeOtherUsername(user1, "obj1");
	admin1.changeOtherUsername(powerUser1, "obj2");
	admin1.changeOtherUsername(vip1, "obj3");

	std::cout << user1.getUsername() << " " << powerUser1.getUsername() << " " << vip1.getUsername();

	return 0;
}