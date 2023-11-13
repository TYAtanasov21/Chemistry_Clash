#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{

	TEST_CLASS(SceneManagerTests)
	{
	public:
		TEST_METHOD(TestSceneManagerInitialization)
		{
			std::shared_ptr<SceneManager> sceneManager = std::make_shared<SceneManager>();

			Assert::IsTrue(sceneManager->GetSceneString() == "");
		}

		TEST_METHOD(TestSceneManagerChangeSceneNewScene)
		{
			std::shared_ptr<SceneManager> sceneManager = std::make_shared<SceneManager>();

			sceneManager->ChangeScene("New Scene");

			std::string scene = sceneManager->GetSceneString();

			Assert::IsTrue(scene == "New Scene");
		}
		TEST_METHOD(TestSceneManagerChangeSceneSettings)
		{
			std::shared_ptr<SceneManager> sceneManager = std::make_shared<SceneManager>();

			sceneManager->ChangeScene("Settings");

			std::string scene = sceneManager->GetSceneString();

			Assert::IsTrue(scene == "Settings");
		}
	};
}
