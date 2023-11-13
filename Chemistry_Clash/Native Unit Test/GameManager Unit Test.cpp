#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{
	TEST_CLASS(GameManagerTests)
	{
	public:
        TEST_METHOD(TestPlayerConstructorSetsValues)
        {
            Player* player = new Player( 100, 10, 10, 50 );

            Assert::IsTrue(player->GetHealth() == 100);
            Assert::IsTrue(player->GetStrength() == 10);
            Assert::IsTrue(player->GetSpeed() == 10);
            Assert::IsTrue(player->GetArmour() == 50);
        }
        TEST_METHOD(TestPlayerHealthSetsCorrectly)
        {
            Player* player = new Player(100, 10, 10, 50);

            player->SetHealth(50);

            Assert::IsTrue(player->GetHealth() == 50);
        }
        TEST_METHOD(TestPlayerArmourSetsCorrectly)
        {
            Player* player = new Player(100, 10, 10, 50);

            player->SetArmour(100);

            Assert::IsTrue(player->GetArmour() == 100);
        }
	};
}
