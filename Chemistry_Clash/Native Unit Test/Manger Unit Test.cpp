#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{
	TEST_CLASS(ManagerTests)
	{
	public:
		
		TEST_METHOD(TestManagerInitialization)
		{
			std::shared_ptr<Manager> manager = std::make_shared<Manager>();

			manager->Initialize();

			Assert::IsFalse(manager->ShouldWindowClose());
		}
		TEST_METHOD(TestManagerClose)
		{
			std::shared_ptr<Manager> manager = std::make_shared<Manager>();

			manager->Initialize();
			manager->Close();

			Assert::IsTrue(manager->ShouldWindowClose());
		}
		TEST_METHOD(TestManagerSceneManagerIntegration)
		{
			std::shared_ptr<Manager> manager = std::make_shared<Manager>();

			manager->Initialize();
			manager->Update();

			std::string scene = SceneManager::GetInstance()->GetSceneString();
			Assert::IsTrue(scene == "Main Menu");
		}

	};
}
