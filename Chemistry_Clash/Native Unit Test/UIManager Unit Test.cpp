#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{

	TEST_CLASS(UIManagerTests)
	{
	public:

		TEST_METHOD_CLEANUP(Cleanup)
		{
			std::shared_ptr<UIManager> uiManager = UIManager::GetInstance();

			uiManager->UpdateLists();
		}
		TEST_METHOD(TestUIManagerAddText)
		{
			std::shared_ptr<UIManager> uiManager = UIManager::GetInstance();

			uiManager->AddText(new Text("New Text", 20, { 100, 100 }, BLACK));

			Assert::IsTrue(uiManager->GetTextList().size() == 1);
		}
		TEST_METHOD(TestUIManagerUpdateLists)
		{
			std::shared_ptr<UIManager> uiManager = UIManager::GetInstance();

			uiManager->AddText(new Text("New Text", 20, { 100, 100 }, BLACK));

			uiManager->UpdateLists();

			Assert::IsTrue(uiManager->GetTextList().size() == 0);
		}
		TEST_METHOD(TestUIManagerToggleFullscreen)
		{
			std::shared_ptr<UIManager> uiManager = UIManager::GetInstance();

			uiManager->ToggleFullScreen();

			Assert::IsTrue(uiManager->GetShouldFullscreen());
		}
	};
}
