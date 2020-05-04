#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Environment.h"

void playerAttacksMobs(Player & player, Environment & environment)
{
	environment.sortByDistanceTo(&player);

	for (int i = 0; i < environment.size(); ++i)
	{
		if (environment.getAt(i)->isAlive() && environment.getAt(i)->getType() == EntityType::mob)
		{
			player.moveTo(environment.getAt(i));//player has to go to location of other entity* to attack them
			Mob* castToMob = dynamic_cast<Mob*>(environment.getAt(i));
			player.attack(castToMob);
		}
	}
}

void test1()//attacking player with 2D location
{
	Player player1("pl1", &Point2D(0, 0), 10, 10);

	Environment environment;
	environment.add(&Player("pl2", &Point3D(1, 1, 0), 10, 10));
	environment.add(&Mob("mob1", &Point3D(-2, 3, 1), 20, 40));
	environment.add(&Mob("mob2", &Point3D(-15, 24, 54), 15, 40));
	environment.add(&Mob("mob3", &Point2D(4, 4), 20, 40)); //mob with 2D location
	environment.add(&NPC("npc1", &Point3D(1, 1, 1)));
	environment.add(&Player("pl3", &Point2D(4242, 1313), 102, 41));

	playerAttacksMobs(player1, environment);

	player1.moveTo(Point2D(0, 0));
}

void test2() //attacking player with 3D location
{
	Player player1("pl1", &Point3D(0, 0, 0) , 10, 10);

	Environment environment;
	environment.add(&Player("pl2", &Point3D(1, 1, 0), 10, 10));
	environment.add(&Mob("mob1", &Point3D(-2, 3, 1), 20, 40));
	environment.add(&Mob("mob2", &Point3D(-15, 24, 54), 15, 40));
	environment.add(&Mob("mob3", &Point2D(4, 4), 20, 40)); //mob with 2D location
	environment.add(&NPC("npc1", &Point3D(1, 1, 1)));
	environment.add(&Player("pl3", &Point2D(4242, 1313), 102, 41));

	playerAttacksMobs(player1, environment);

	player1.moveTo(Point2D(0, 0));
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	test1();

	test2();

	return 0;
}