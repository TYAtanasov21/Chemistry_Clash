
#include "Manager.h"
#include <functional>

int main() 
{

	std::shared_ptr<Manager> manager = Manager::GetInstance();

	manager->Initialize();

	while (!manager->ShouldWindowClose()) 
	{
		manager->Update();
	}

	return 0;
}