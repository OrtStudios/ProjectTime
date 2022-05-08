#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"

#include <imgui_internal.h>

#include "Oort/Settings.h"
#include "Oort/Logger.h"

class Menu : public Walnut::Layer
{
public:
	virtual void OnAttach() override
	{
		ProjectTimeLogoImage = std::make_shared<Walnut::Image>("Assets/Images/MenuLogo.png");
	}

	virtual void OnUIRender() override
	{
		// Set the Menu Window
		ImGuiWindowClass window_class;
		window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
		ImGuiWindowClass* window_class_ = &window_class;
		ImGui::SetNextWindowClass(window_class_);
		ImGui::Begin("ProjectTimeMenuWindow");
		
		/// Create a side bar
		ImGui::BeginChild("SideBar", ImVec2(100, 0), true);

		//* Create the HOME BUTTON on the side bar
		if (ImGui::ImageButton(ProjectTimeLogoImage->GetDescriptorSet(), ImVec2(80, 80)))
			HomeButtonPressed();

		/// End the side bar
		ImGui::EndChild();

		// End the Dear ImGui frame
		ImGui::End();
	}

private:
	void HomeButtonPressed()
	{
		Logger.Log("Log Test Debug", Logger.LOG_TYPE_DEBUG);
		Logger.Log("Log Test Info", Logger.LOG_TYPE_INFO);
		Logger.Log("Log Test Warning", Logger.LOG_TYPE_WARNING);
		Logger.Log("Log Test Error", Logger.LOG_TYPE_ERROR);
		Logger.Log("Log Test Fatal", Logger.LOG_TYPE_FATAL);
		Logger.Log("Log Test Master", Logger.LOG_TYPE_MASTER);
	}

private:
	std::shared_ptr<Walnut::Image> ProjectTimeLogoImage;
};


Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Logger.SetLogLevel(Logger.LOG_TYPE_DEBUG);


	//* Create the Walnut Application Specs
	Walnut::ApplicationSpecification ProjectTimeAppSpecs;
	ProjectTimeAppSpecs.Name = "ProjectTime";

	//* Create The Walnut Application
	Walnut::Application* ProjectTimeApp = new Walnut::Application(ProjectTimeAppSpecs);
	
	ProjectTimeApp->PushLayer<Menu>();
	return ProjectTimeApp;
}